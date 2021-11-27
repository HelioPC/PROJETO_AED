"""
Main screen
"""
__author__ = 'HelioPC'
__copyright__ = 'Copyright (C) 2021 BBANO'
__license__ = 'Public Domain'
__version__ = '1.0'
__all__ = ['Start']

import sys
import os
from pathlib import Path
from random import choice

from kivymd.uix.screen import MDScreen
from kivy.properties import ListProperty, StringProperty, ObjectProperty
from kivymd.uix.boxlayout import MDBoxLayout
from kivy.utils import get_color_from_hex as gch

from bano_c import *

if getattr(sys, "frozen", False):  # bundle mode with PyInstaller
    os.environ["BANO_ROOT"] = sys._MEIPASS
else:
    os.environ["BANO_ROOT"] = str(Path(__file__).parent)


DATA_PATH = os.path.join(os.environ["BANO_ROOT"], 'assets/data/')


class OverviewBox(MDBoxLayout):
    """
    OverviewBox from kivymd demo rally
    """
    title = StringProperty()
    money = StringProperty()
    text = ListProperty(["", "", ""])
    secondary_text = ListProperty(["", "", ""])
    tertiary_text = ListProperty(["", "", ""])
    bar_color = ListProperty([(0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0)])


class Start(MDScreen):
    """
    Main screen
    """
    stt = ObjectProperty()
    val = 0

    def on_enter(self, *args):
        self.reader()

    def reader(self):
        """
        Event when it starts
        :return:
        """
        with open('%s636C6966696C65.dat' % DATA_PATH, 'rb') as file:
            x = Client()
            while file.readinto(x) == sizeof(x):
                self.make_labels(
                    x.name.decode('utf-8'),
                    x.account.decode('utf-8'),
                    x.val
                )
    
    def get_val(self):
        with open('%s636C6966696C65.dat' % DATA_PATH, 'rb') as file:
            x = Client()
            while file.readinto(x) == sizeof(x):
                self.val += x.val
        return '%.2f' % self.val

    def make_labels(self, nome: str, id_c: str, val: float):
        """
        Label maker
        """
        a = OverviewBox()
        a.title = nome
        a.money = '$ %.2f' % val
        a.text = ['Account', 'Created on', 'Operations']
        a.secondary_text = ['•' * len(nome), '•' * (len(nome)-1), '•' * (len(nome)+1)]
        a.tertiary_text = [id_c, '12/08/2021', str(len(nome)*2)]
        a.bar_color = list(map(gch, self.mkhx()))
        self.ids.box.add_widget(a)
    
    def mkhx(self):
        colors = [str(x) for x in range(10)] + list(map(chr, range(97, 103)))
        result = []
        
        for i in range(3):
            color = '#'
            for i in range(6):
                color += choice(colors)
            result.append(color)
        
        return result
        
