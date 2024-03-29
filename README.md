# 42_SO_LONG 🕹️
A 2D game developed in C, using Minilibx (a minimal X-Window library) to handle graphics and inputs.


![so_long_demonstration](textures/so_long.gif "so_long demonstration")
# About ✍
So_long consists in creating a 2 dimensional game, where the player must collect every collectible present on the map and reach the exit. To achieve that, the player is able to move in 4 directions, up, down, right and left, by pressing W, S, D and A, respectively. To develop this project, I utilized the Minilibx, which is the official graphics library of 42 School. The Minilibx provides essential tools for opening windows, creating images, and handling keyboard and mouse events. n this project, I had the freedom to choose the resources I wanted. Inspired by my favorite cartoon, SpongeBob SquarePants, I decided to incorporate elements from the show into the game. SpongeBob himself became the player character, Krabby Patty served as the collectible, his pineapple house became the exit, jellyfish were introduced as enemies, sand acted as walls, and the sea bottom formed the backdrop for the game.
# Challenges and Learning Objectives 🧠
- Graphics Programming: This project provides an opportunity to learn about graphics programming, particularly in a 2D game environment. Understanding how to render images, create visual effects, and manage game elements on the screen are essential skills that can be developed through so_long.
- Event Handling: Capturing keyboard and mouse events, to control the player and close the game; implementing player movement logic based on these events; detecting colisions between the player and map elements. 
- Resource Management: Managing game resources such as textures and maps is a key aspect of the project development.
- Data Structures Organization: Working with different structs for position, image, map and game made the game logic easier to understand, modify, and potentially reuse in future projects.
# Map 🗺️
The map needs to be constructed with the following rules:
- Must contain these elements: WALL:``1``, FLOOR:``0``, PLAYER:``P``, COLLECTIBLE:``C``, EXIT:``E`` and, for the bonus part, ENEMY:``J``.
- Must be rectangular and surrounded by walls.
- Must contain a valid path, it means that the player can collect all the collectibles and reach the map exit.
- Example of a valid map:

  ```text
  111111111111111
  10001C0000000C1
  100010010110001
  1P00100101100E1
  11C000010C11111
  111111111111111
# Game Rules 🎮
The player starts at the spawn position ``P`` and needs to walk through the map avoiding the obstacles ``1`` and enemies (bonus) ``J``, collect all the collectibles ``C`` and reach the map exit ``E``. If you collide with an enemy, the game is over, the window is closed and a message indicates the user lost.

Movement:
- ``W`` or ⬆️ - Move the player up.
- ``A`` or ⬅️ - Move the player to the left.
- ``S`` or ⬇️ - Move the player down.
- ``D`` or ➡️ - Move the player to the right.

Close the window:
- ``ESC`` or click ❌

# Bonus ⭐
For the bonus section, we were required to add some extra features 

After performing the provided instructions, if ``stack a`` is sorted, and ``stack b`` is empty, the program displays ``OK`` followed by a new line. In any other scenario, the checker outputs ``KO`` followed by a new line. If an error occurs, the program follows the same behavior as push_swap, printing ``Error`` and a new line.

# Usage 🖥️
To install and use push_swap, follow these steps:
- Clone the repository:
```bash
git clone git@github.com:marcelofassbinder/42_PUSH_SWAP.git
```
- Navigate to the project directory and run ``make`` to compile the program:
```bash
cd 42_PUSH_SWAP
make
```
- Run the program providing a list of integers, for example:
```bash
./push_swap 42 24 -6 8 -50
```
- The program will output the operations applied to sort the given numbers, for example:
```bash
pb
pb
rra
pa
ra
pa
ra
```
- To use the checker, do:
```bash
make bonus
```
- Run the program, passing a list of integers as arguments, for example:
```bash
./checker 7 -12 35 42
```
- Now, give the instructions you think will sort the numbers, and press Ctrl + D to finish. For example:
 ```bash
 pb
rra
rra
pa
ra
ra
ra
```
If the operations sorted the stack, checker will print ``OK``. Otherwise ``KO``, and in case of error, ``Error``.

# Grade  <p><img height="30px" src="https://img.shields.io/badge/-125%20%2F%20100-success" /></p>

# Norminette 💂🏻
At 42 School, we need to follow some strict rules when writing our code. These rules are described in the Norm and checked by the formidable `norminette`. Here are some of them:
```
- No for, do...while, switch, case, goto, ternary operators and variable-length arrays are allowed
- Each function must be maximum 25 lines
- One single variable declaration per line
- You can’t declare more than 5 variables per function
- You can't write more than 5 functions per file
...
```
[Click here](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) to review the complete Norm document.