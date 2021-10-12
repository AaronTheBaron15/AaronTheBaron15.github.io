import kivy
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.scrollview import ScrollView
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.anchorlayout import AnchorLayout
### Imports for the Kivy and other libraries used ###

import Backend.Sql as Sql
### Importing separate files within the project ###

### Initial Window that user will come across first ###
#   Constructor defined for class                   
#   Future functions that might be added:
#   Sign_In, Authenticate, Register
class LoginWindow(Screen):
    def __init__(self, **kwargs):
        super(LoginWindow, self).__init__(**kwargs)

    def hello():
        return 'Hello'
    
### Main Window for user interaction and hub for different pages ###
#   Constructor defined for class
#   Future Functions to be defined:
#   Queries for output of songs
class MainPage(Screen):
    def __init__(self, **kwargs):
        super(MainPage, self).__init__(**kwargs)

    def Query(self):
        return Sql.ex01() 

### Settings Page ###
#   Constructor defined for class
#   Future Functions to be defined:

class UserSettings(Screen):
    def __init__(self, **kwargs):
        super(UserSettings, self).__init__(**kwargs)
    
### Manages the Page's transitions ###
class PageManager(ScreenManager):
    pass
    

### Loads the kivy foul ###
kv = Builder.load_file("WindowManager/PageManager.kv")

class RunApp(App):
    title = 'Scratch'
    def build(self):
        return kv

RunApp().run()

