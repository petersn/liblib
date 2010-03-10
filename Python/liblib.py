#! /usr/bin/python

"""
Liblibrary Python bindings
"""

import ctypes

search = [ "liblib.so.1.0", "./liblib.so.1.0" ]

for option in search:
    try:
        liblib_dll = ctypes.cdll.LoadLibrary(option)
        break
    except:
        continue
else:
    raise Exception("couldn't open liblib.so anywhere on search path")

def instantiate( x ):
    return x()

@instantiate
class interface:
    def __getattr__(self, name):
        return getattr( liblib_dll, name )

