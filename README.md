### Snake 3D overview

* this game was made as a part of a project in the university Jean Monnet of Saint-Etienne.
* it is made in c and just c, no c++ classes,no objects.
* it is made with OpenGL and glut library.

### the latest version contains

* browsing mode where you can have a free view of the "univers"/plan.
* two type of obstacles, trees and torus obstacles rotating around the y axis.
* A menu in the entry of game which describe the different **modes of the game (2D/3D)**.
* **you can switch between the 2 modes during the game**
* the camera in 3D mode is following from the back of the snake.

### errors to fix

*the fluidity of the following camera in 3D mode.

### how to run the game

* if you are using linux, you have to install openGL and(not sure) glut library, download or clone the project in a folder, open a terminal in the same path of the project folder, _run the command **make**_. 
* if you are using Windows,you have to install openGL and(not sure) glut library, include the windows library to snake3d.c file using  **#include<windows.h>**.

### how to play

1. choose your mode from the entry menu.
2. use **A** and **S** buttons to move the snake.
3. use **UP DOWN RIGHT LEFT**  buttons to navigate in the univers after choosing the navigation mode .
