# This console game engine is a library of different modules, classes and structures that are cappable of:
- Handling user input from keyboard
- Rendering
- Creating basic objects
- Navigation and working with objects:
	- Recognizing collisions
   	- Setting / Updating objects' position in space, shape and size
  	- Destroying objects

**To get started, you can check a sample game in [Tester.cpp](Tester.cpp) which will familiarize you with general possibilities of our library. However, if you want to learn how to use those possibilities by yourself, here is a documentation on commands and classes of our library:**

## Classes
### Engine
Engine is the main class which helps you to access all other classes like Screen, Keyboard and Objects. For example:
 ```
 Engine myEngine;
 myEngine.screen.setSize(100,100);
 ```
