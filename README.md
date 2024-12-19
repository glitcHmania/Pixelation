# ProjDream

**ProjDream** is a project developed by [Ercan Mert Esen](https://github.com/glitcHmania) and [Ruzgar Koray Genc](https://github.com/Kokonotcu). 
this project is meant to practice and implement typical game engine features which is an ongoing process

## Table of Contents

- [Introduction](https://github.com/glitcHmania/ProjDream#introduction)
- [Capabilities](https://github.com/glitcHmania/ProjDream#capabilities)
- [Supported Features](https://github.com/glitcHmania/ProjDream#supported-features)

## Introduction

Our aim is to develop a 2d game engine from scratch using SFML and bring it into a useful state for our different game projects in the future.

## Capabilities

Our project use an entity component system to manage different features we add into our engine.
In its current state, one can use various components to render, manipulate and create interactive objects <br>
see [Supported Features](https://github.com/glitcHmania/ProjDream#supported-features) for the full list of features

## Supported Features

1-) AssetLoader <br>
  Manages the loading of textures and text fonts
  
2-) Camera <br>
  Provides functionality for handling the game camera, such as movement and viewport transformations.
  
3-) Component <br>
  Defines the base class for components that can be attached to game objects, such as transforming, rendering, or behavior components.

4-) ComponentIncluder <br>
  Includes and organizes different component header files for easy access in one place.

5-) FpsCounter <br>
  An inherited class which demonstrates how to use the start/update methods and the inheritance of GameObject

6-) Game <br>
  Contains the main logic and structure of the game including initialization, the game loop, and event handling.
  
7-) GameObject <br>
  Defines the structure and behavior of game objects, including their properties and interactions with components.

8-) Object <br>
  A base class for all, providing common functionality like unique IDs or general behavior.
  
9-) ObjectManager <br>
  Manages the lifecycle of objects, including creation, deletion, and updates for all objects in the game.

10-) Renderer <br>
  Defines the rendering queue and manages drawing objects, sprites, and other visual elements to the screen.
  
11-) SpriteRenderer - Component <br>
  Provides functionality for rendering 2D sprites.

12-) TextRenderer - Component <br>
  Provides functionality for rendering text in the game, such as UI text or in-game labels.

13-) Time <br>
  Manages timing-related functions: deltaTime and fps calculation etc.
  
14-) Transform - Component <br>
  Provides the transformation logic for game objects, including position, rotation, and scaling.
  
15-) UID <br>
  Generates unique identifiers (UIDs) for all objects to ensure they are distinctly identifiable. <br> 
  GameObjects use 16 digit ids while Components use 32 digit.
