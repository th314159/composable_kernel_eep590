import enum
import os.path
import shutil
import functools
import operator
import collections
import subprocess
import re
import gemm_op
from gemm_op import *
import user

def SubstituteTemplate(template, values):
    text = template
    changed = True
    while changed:
        changed = False
        for key, value in values.items():
            regex = "\\$\\{%s\\}" % key
            newtext = re.sub(regex, value, text)
            if newtext != text:
                changed = True
            text = newtext
    return text


class EmitMake:
    def __init__(self):
        self.make_template =     """
CFLAGS=-I ~/workspace/composable_kernel/include -I /opt/workspace/rocm-5.1.1/hip/include -I ~/workspace/composable_kernel/include/ -I ~/workspace/composable_kernel/include/ck/ -I ~/workspace/composable_kernel/example/01_gemm/ -I ~/workspace/composable_kernel/library/include/  -I ~/workspace/composable_kernel/library/src/utility/ -I ~/workspace/composable_kernel/include/ck/problem_transform/ -I ~/workspace/composable_kernel/include/ck/tensor/ -I ~/workspace/composable_kernel/include/ck/tensor_description/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/block/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/device/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/device/impl/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/element/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/grid/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/thread/ -I ~/workspace/composable_kernel/include/ck/tensor_operation/gpu/warp/ -I ~/workspace/composable_kernel/include/ck/host_utility -I /external/include/half/ -I ~/workspace/composable_kernel/library/include/ck/library/host/ -I ~/workspace/composable_kernel/library/include/ck/library/host_tensor/ -I ~/workspace/composable_kernel/library/include/ck/library/obselete_driver_offline/ -I ~/workspace/composable_kernel/library/include/ck/library/reference_tensor_operation/cpu/ -I ~/workspace/composable_kernel/library/include/ck/library/reference_tensor_operation/gpu/ -I ~/workspace/composable_kernel/library/include/ck/library/tensor_operation_instance/ -I ~/workspace/composable_kernel/library/include/ck/library/tensor_operation_instance/gpu/" + "reduce/ -I ~/workspace/composable_kernel/library/include/ck/library/tensor_op/ -I ~/workspace/composable_kernel/library/include/ck/library/utility/ -I ~/workspace/composable_kernel/profiler/include/

CXXFLAGS = -std=c++17

device_memory.o: ../../../../../library/src/utility/device_memory.cpp
        hipcc -fPIC -fvisibility=hidden $(CXXFLAGS) $(CFLAGS) -c ../../../../../library/src/utility/device_memory.cpp

host_tensor.o: ../../../../../library/src/utility/host_tensor.cpp
        hipcc -shared -fPIC -fvisibility=hidden $(CXXFLAGS) $(CFLAGS) -c ../../../../../library/src/utility/host_tensor.cpp

obj_files = 256.o

%.o : %.cpp
        hipcc -fPIC -fvisibility=hidden $(CXXFLAGS) -w /opt/rocm-5.3.0/amdgcn/bitcode/oclc_abi_version_400.bc $(CFLAGS) -L/opt/rocm-5.3.0/rocrand -lrocrand -x hip -c $<

all: test.so

test.so: $(obj_files) host_tensor.o device_memory.o
        hipcc -shared $(CXXFLAGS) $(CFLAGS) -o $@ $(obj_files) host_tensor.o device_memory.o

clean:
        rm -f *.o test.so
    """

    def emit(self,operation):
        values = {
            'temp' : ""
        }
        m_template = self.make_template
        cf = open("Makefile", 'w')
        print(SubstituteTemplate(m_template, values))
        cf.write(SubstituteTemplate(m_template, values))
        cf.close()

        PIPE = -1
        STDOUT = -2

        proc = subprocess.Popen(
        ["make"],
        shell=True,
        env=os.environ.copy(),
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        )

        out, err = proc.communicate()