"""
Bano's C struct module
"""
__author__ = 'HelioPC'
__copyright__ = 'Copyright (C) 2021 BBANO'
__license__ = 'Public Domain'
__version__ = '1.0'
__all__ = ['Data', 'Client', 'sizeof', 'Hist']


from ctypes import *

MAX = 250


class Data(Structure):
    """
    Date struct
    """
    _fields_ = [('v', c_int),
                ('t', c_int),
                ('c', c_int)]


class Client(Structure):
    """
    Client struct
    """
    _fields_ = [('name', c_char * 80),
                ('date', Data),
                ('date_b', Data),
                ('cel', c_long),
                ('val', c_double),
                ('gen', c_char),
                ('account', c_char * 15),
                ('id', c_char * 16)
                ]

class Hist(Structure):
    """
    History struct
    """
    _fields_ = [('type', c_char * MAX * 2),
                ('account', c_char * 15),
                ('date', Data)
                ]
