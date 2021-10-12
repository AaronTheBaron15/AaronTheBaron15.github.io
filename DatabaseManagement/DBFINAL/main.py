import kivy
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.scrollview import ScrollView
from kivy.uix.screenmanager import ScreenManager, Screen, SlideTransition
from kivy.uix.anchorlayout import AnchorLayout
from kivy.properties import StringProperty
from kivy.uix.boxlayout import BoxLayout
from kivy.core.audio import SoundLoader
from kivy.uix.label import Label

#import kivy.properties as kyprops
#from kyprops import StringProperty

from kivy.uix.floatlayout import FloatLayout
from kivy.uix.gridlayout import GridLayout
from kivy.uix.button import Button
from kivy.core.window import Window
from kivy.core.image import Image
from kivy.graphics import Color, Rectangle

### Imports for the Kivy and other libraries used ###
import os
import Backend.Sql as Sql 
### Importing separate files within the project ###

### Initial Window that user will come across first ###
#   Constructor defined for class                   
#   Future functions that might be added:
#   Sign_In, Authenticate, Register
class LoginWindow(Screen):
    def __init__(self, **kwargs):
        super(LoginWindow, self).__init__(**kwargs)

    def do_login(self, loginText, passwordText):
        app = App.get_running_app()

        app.username = loginText
        app.password = passwordText

        self.manager.transition = SlideTransition(direction='left')
        self.manager.current = 'connected'

        app.config.read(app.get_application_config())
        app.config.write()

    def resetForm(self):
        self.ids['login'].text = ""
        self.ids['password'].text = ""    
    
### Main Window for user interaction and hub for different pages ###
#   Constructor defined for class
#   Future Functions to be defined:
#   Queries for output of songs
class MainPage(Screen):
    def __init__(self, **kwargs):
        super(MainPage, self).__init__(**kwargs)

    #def Query(self):
    #    songs = Sql.ex01() 
    #    for s in songs:
    #        self.trending.add_widget(Label(text = s))
        

### PlayScreen Page ###
#   Constructor defined for class
#   Future Functions to be defined:
class PlayScreen(Screen):
    #pos = 0.00
    def __init__(self, **kwargs):
        super(PlayScreen, self).__init__(**kwargs)

    sound = SoundLoader.load('audio/C2C.mp3') 
    file = 'audio/C2C.m4a'
    def play_sound(self): 
        
        if PlayScreen.sound.state == 'stop':
            PlayScreen.sound.play()
        else:
            PlayScreen.sound.stop()
        #if sound.on_stop: 
        #    sound.seek(self.pos)
        #    sound.play() 
            
        #else:
        #    pos = sound.get_pos()
        #    sound.stop()
            #sound.seek(0.00)
        


    #def pause_sound(self):
        #sound = SoundLoader.load('audio/meme.mp3')
        #if sound:
            #sound.stop()



class Album(Screen):
    def __init__(self, **kwargs):
        super(Album,  self).__init__(**kwargs)

### Manages the Page's transitions ###
class PageManager(ScreenManager):
    pass


class Connected(Screen):
    def disconnect(self):
        self.manager.transition = SlideTransition(direction='right')
        self.manager.current = 'login'
        self.manager.get_screen('login').resetForm()

### Loads the kivy foul ###
kv = Builder.load_file("WindowManager/PageManager.kv")
class SampleApp(App): 
  
    def build(self): 
        return PlayScreen()

class RunApp(App):
    title = 'Scratch'
    username = StringProperty(None)
    password = StringProperty(None)

    def build(self):
        manager = kv

        manager.add_widget(LoginWindow(name='login'))
        manager.add_widget(Connected(name='connected'))

        return manager

    def get_application_config(self):
        if(not self.username):
            return super(RunApp, self).get_application_config()

        conf_directory = self.user_data_dir + "/" + self.username
        
        if(not os.path.exists(conf_directory)):
            os.makedirs(conf_directory)

        return super(RunApp, self).get_application_config(
            '%s/config.cfg' % (conf_directory)
        )

RunApp().run()

