# Tile Tap

Piano Tiles inspired tile tapping game with keyboard controls.

## Features

-   [x] Infinite tile wave
-   [x] Customizable tile preloading
-   [x] Custom game loop
-   [x] Miss and wrong click handles
-   [x] Speed increments based on time
-   [x] User error feedback
-   [ ] Fully random tile sequence without repeats
-   [ ] Start, end, restart and score overview
-   [ ] Highscore tracking
-   [ ] Modular and conventional code style

<p float="left">
  <img width="45%" alt="Screenshot 2025-06-29 at 11 18 58" src="https://github.com/user-attachments/assets/5bfd17a7-1e41-43fc-83e9-416f949ad8d5" />
  <img width="45%" alt="Screenshot 2025-06-29 at 11 19 31" src="https://github.com/user-attachments/assets/a4577169-912a-4536-ac8d-fc1c85447ddb" />
</p>

## Usage

Install raylib and make sure the Makefile works on your system.

```bash
make run
```

### Controls

Use KEY_ONE, KEY_TWO etc to tap the lowest tile in a column.

After losing:

-   Use SPACE to restart game
-   Use ESCAPE to quit game

## Improvements

-   Better usage of DRY principle.
-   game->is_running can be combined with game->start_time, functionality wise.
-   More modular abstraction with helper functions.
-   Full code documentation.

## Learned

-   Raylib basics
-   Simple applied math
-   C program architecture
-   Custom game loops
-   Problem solving

Made without generative AI.
