from kivymd.uix.screen import MDScreen
from kivy.properties import ColorProperty, StringProperty
from kivymd.theming import ThemableBehavior
from kivymd.uix.behaviors import RectangularRippleBehavior
from kivymd.uix.boxlayout import MDBoxLayout


class RallyListItem(ThemableBehavior, RectangularRippleBehavior, MDBoxLayout):
    text = StringProperty()
    secondary_text = StringProperty()
    tertiary_text = StringProperty()
    bar_color = ColorProperty((1, 0, 0, 1))


class RallySeeAllButton(RectangularRippleBehavior, MDBoxLayout):
    pass


class Root(MDScreen):
    """
    Root screen
    """
