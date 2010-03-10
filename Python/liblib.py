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

class Library:
    def __init__(self, language, resource):
        self.callable = getattr(liblib_dll, "load_library_%s" % language)
        self.lib_id   = self.callable( resource )

    def __call__(self, function, argument):
        assert type(argument) == int
        i = liblib_dll.call_lib_function( self.lib_id, function, argument )
        return i

