# 2D Console Game Engine with ASCII graphics
## General info
This console game engine is a library of different modules, classes and structures that are cappable of:
- Handling user input from keyboard
- Rendering
- Creating basic objects
- Navigation and working with objects:
	- Recognizing collisions
   	- Setting / Updating objects' position in space, shape and size
  	- Destroying objects

## Classes
### Engine
Engine is the main class which helps you to access all other classes like `Screen`, `Keyboard` and `Objects`. 

**Example:**

 ```
 Engine myEngine;
 myEngine.screen.setSize(100,100);
 ```
### Keyboard
The Keyboard class allows you to detect keyboard input.

**Key methods:**
- `isKeyPressed(int key)`: Checks if a specific key (using hex virtual-key codes) is currently pressed. Returns a boolean.
- `currentKey()`: Waits for and returns the key pressed as a `char`.

**Example:**
```cpp
if (myEngine.keyboard.isKeyPressed(0x57)) {
   // 'W' key is pressed
}
char key = myEngine.keyboard.currentKey(); // Waits for a key press
```
### Screen
The Screen class handles all rendering and display operations for your game. It manages the game window size, drawing objects, and refreshing the display.

**Key Methods:**
- `setSize(int width, int height)`: Sets the dimensions of the game screen.
- `drawScreen()`: Renders all objects and updates the display.
- `drawRectangle(Objects::Rectangle)`: Draws a specific rectangle on the screen.
- `drawCircle(Objects::Circle)`: Draws a specific circle on the screen.
- `clear()`: Clears the screen and resets the drawing buffer.

**Example:**
```cpp
myEngine.screen.setSize(150, 100);
myEngine.screen.drawScreen();
```
### Objects
The Objects class manages game entities (only rectangles and circles for this version). It provides functionality to create, update, destroy, and check collisions between objects.

**Structures:**
- `Rectangle`: Contains `width`, `height`, `x` and `y` coordinates, and a unique `id`.
- `Circle`: Contains `radius`, `x` and `y` coordinates, and a unique `id`.

**Key Methods:**
- `createRectangle(int height, int width, int x, int y)`: Creates a new rectangle and adds it to the objects list.
- `updateRectangle(Rectangle, int delta_h, int delta_w, int delta_x, int delta_y)`: Updates the dimensions and position of an existing rectangle.
- `destroyRectangle(Rectangle)`: Removes the specific rectangle.
- `createCircle(int radius, int x, int y)`: Creates a new circle and adds it to the objects list.
- `isOnCollisionWith(Rectangle, Rectangle)`: Checks if two rectangles are colliding.

**Example:**
```cpp
// Create a player rectangle
auto player = myEngine.objects.createRectangle(10, 5, 0, 0);

// Move the player right
player = myEngine.objects.updateRectangle(player, 0, 0, 5, 0);

// Check collision with another object
if (myEngine.objects.isOnCollisionWith(player, enemy)) {
    // Handle collision
}
```
## Getting Started
1. Include the Engine: Start by creating an instance of the `Engine` class.
2. Setup Screen: Use `screen.setSize()` to define your game window dimensions.
3. Create Objects: Use the `objects` methods to create your game entities.
4. Game Loop: Implement a game loop that:
	- Checks for user input with `keyboard`
 	- Updates object positions and states
	- Checks for collisions
	- Calls `screen.drawScreen()` to render the frame

**Simple Game Loop:**
```cpp
Engine myEngine;
myEngine.screen.setSize(100, 50);
auto player = myEngine.objects.createRectangle(5, 5, 10, 25);

while (myEngine.gamestate) {
    // Handle input
    if (myEngine.keyboard.isKeyPressed(0x44)) { // D key
        player = myEngine.objects.updateRectangle(player, 0, 0, 1, 0);
    }
    
    // Game logic here
    
    // Render frame
    myEngine.screen.drawScreen();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
```

## Notes
- The coordinate system uses top-left as (0,0), with Y increasing downward.
- The `id` for objects is automatically calculated upon creation and used for internal management.
- The collision detection currently only supports rectangle-to-rectangle collisions.
- Feel free to contribute to project by implementing new classes, features and functions. Refactoring is also appreciated.

**For a complete working example, see the [Tester.cpp](Tester.cpp) file which implements a simple collectible game with player movement, object collection, and power-ups.**
