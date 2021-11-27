"""
Login Screen
"""
__author__ = 'HelioPC'
__copyright__ = 'Copyright (C) 2021 BBANO'
__license__ = 'Public Domain'
__version__ = '1.0'
__all__ = ['Login']

from hashlib import sha256
from os import name
from kivymd.uix.screen import MDScreen
from kivy.clock import Clock
from kivy.lang import Builder

from start import Start



LOG = b'\xb9\x9a\x82\x00\xce\xbe4\x11V5\x1b\xdb\x92\x7f\xd8\xc5\x11\x1cMM#' \
      b'\xce\xa7\xb3~\x18\xddxiqn\x8d'


class Login(MDScreen):
    """
    Login class
    """
    def __init__(self, **kwargs):
        super(Login, self).__init__(**kwargs)
        Clock.schedule_once(self.start_screen)
    
    def start_screen(self, arg):
        """
        Go to start screen
        """
        usr = self.ids.user.text
        pwd = self.ids.psd.text

        if self.validate(usr, pwd):
            Builder.load_file('assets/kv/start.kv')
            self.manager.get_screen('rtt').ids.rt_mng.add_widget(Start(name='stt'))
            self.manager.current = 'rtt'

    def validate(self, user: str, password: str) -> bool:
        """
        Validate login
        """
        hsh = sha256()
        hsh.update(password.encode('utf-8'))
        password = hsh.digest()
        if user == 'eliude' and password == LOG:
            return True
        return False
