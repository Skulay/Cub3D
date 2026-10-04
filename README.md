*This project has been created as part of the 42 curriculum by alehamad, tkhider.*

<div align="center">

# 🧱 cub3D

**A Wolfenstein 3D-style raycaster, written from scratch in C with MiniLibX.**

![Language](https://img.shields.io/badge/language-C-00599C?style=flat-square&logo=c)
![School](https://img.shields.io/badge/school-42-000000?style=flat-square)
![Norm](https://img.shields.io/badge/norminette-passing-success?style=flat-square)
![Platform](https://img.shields.io/badge/platform-Linux-FCC624?style=flat-square&logo=linux&logoColor=black)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-8A2BE2?style=flat-square)

[Overview](#-overview) •
[Features](#-features) •
[Getting started](#-getting-started) •
[Map format](#-the-cub-file) •
[Architecture](#-architecture) •
[Examples](#-examples) •
[Limitations](#-limitations) •
[Authors](#-authors)

</div>

---

## 📖 Overview

**cub3D** renders a first-person view of a maze described in a `.cub` scene file, in real time, using the same **raycasting** technique as *Wolfenstein 3D* (1992).

The goal of the project is to understand how a 2D grid becomes a convincing 3D image:

- how a `.cub` scene file is **validated** and **parsed** (textures, colours, map)
- how a map is checked to be **closed by walls**
- how one ray per screen column is cast through the grid with the **DDA** algorithm
- how the **perpendicular distance** to a wall gives the height of the slice to draw (and avoids the fish-eye effect)
- how a **texture column** is picked and stretched onto that slice
- how the camera is **moved** and **rotated** with a direction vector and a camera plane

Everything is written in C (Norm-compliant) on top of our own `libft`, with **MiniLibX** as the only graphics library.

---

## ✨ Features

### Rendering

| Feature | Details |
|---|---|
| Raycasting | One ray per column of an `800 × 800` window, walls found with DDA |
| Textured walls | A different `.xpm` texture for each face: **N**orth, **S**outh, **E**ast, **W**est |
| Floor & ceiling | Flat RGB colours read from the `.cub` file |
| No fish-eye | Distances are measured perpendicular to the camera plane |
| Off-screen buffer | Each frame is drawn into an image, then pushed to the window in one call |

### Controls

| Key | Action |
|---|---|
| <kbd>W</kbd> / <kbd>S</kbd> | Move forward / backward |
| <kbd>A</kbd> / <kbd>D</kbd> | Strafe left / right |
| <kbd>←</kbd> / <kbd>→</kbd> | Rotate the camera |
| <kbd>Esc</kbd> | Quit cleanly |
| Window ❌ button | Quit cleanly |

Keys are tracked as **pressed / released** states, so several keys can be held at once (e.g. move forward while turning) and movement stays smooth.

### Collisions

Movement on the X and Y axes is checked **separately**: walking into a wall at an angle makes you slide along it instead of stopping dead.

### Error handling

Every error prints `Error` on its own line, followed by an explicit message on `stderr`, and the program exits with status `1`.

| Case | Message |
|---|---|
| Wrong number of arguments / not a `.cub` file | `./cub3D "/path/map.cub"` |
| File cannot be opened | `opening file: <reason>` |
| Missing, duplicated or unknown identifier, map not last | `Invalid .cub file structure. Rules: …` |
| Bad texture path, bad colour (`256,0,0`, `1,,2`…), invalid map character, open map, empty line inside the map, 0 or several players | `Parsing: Invalid map or elements` |
| Texture file missing or not a valid `.xpm` | `Texture not found: <path>` |
| Allocation failure | `Malloc failed` |

All memory (parsing data, map, MiniLibX images, window, display) is freed before exiting, on errors as well as when quitting the game.

---

## 🚀 Getting started

### Requirements

- Linux with an X11 server (WSL2 + WSLg works too)
- `cc` / `gcc` / `clang`
- `make`, `git`
- X11 / Xext / zlib development headers (for MiniLibX)

```bash
# Debian / Ubuntu
sudo apt install build-essential libx11-dev libxext-dev zlib1g-dev
```

### Build & run

```bash
git clone <repository-url> cub3D
cd cub3D
make
./cub3D map/map_valid/map.cub
```

Both dependencies are **cloned automatically** the first time you run `make`: our [libft](https://github.com/Skulay/libft) and [MiniLibX](https://github.com/42Paris/minilibx-linux) from the 42Paris repository.

The program takes **exactly one argument**: the path to a `.cub` file.

### Make rules

| Rule | Action |
|---|---|
| `make` / `make all` | Clone libft and MiniLibX if needed, build `libft.a`, `libmlx`, then `cub3D` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files, the binary, and the cloned `libft/` and `minilibx-linux/` folders |
| `make re` | `fclean` then `all` |

---

## 🗺 The `.cub` file

A scene file contains **6 identifiers** (in any order, each exactly once), followed by the **map**, which must be the last element:

```
NO ./texture/north.xpm
SO ./texture/south.xpm
WE ./texture/west.xpm
EA ./texture/east.xpm

F 20,20,20
C 0,0,0

        1111111111111
        1000000000001
        1011000001111
111111111011000001
100000000011000001
11110111111111N01
11111111 11111111
```

| Identifier | Meaning |
|---|---|
| `NO` / `SO` / `WE` / `EA` | Path to the `.xpm` texture of the north / south / west / east walls |
| `F` | Floor colour, `R,G,B` with each value in `0–255` |
| `C` | Ceiling colour, `R,G,B` with each value in `0–255` |

| Map character | Meaning |
|---|---|
| `1` | Wall |
| `0` | Empty floor |
| `N` / `S` / `E` / `W` | Player start position, facing that direction (exactly **one**) |
| ` ` (space) | Void, outside the map |

Rules enforced on the map:

- it must be **closed**: no walkable cell may touch a space or the edge of the map
- lines can have **different lengths** and contain spaces
- no **empty line** inside the map, and nothing after it

Ready-made scenes live in [`map/map_valid/`](map/map_valid), and the ones that must be rejected in [`map/non_valid_map/`](map/non_valid_map).

---

## 🏗 Architecture

From the command line to the game loop:

```
  ./cub3D map.cub
        │
        ▼
  ┌────────────┐   ┌────────────┐   ┌────────────┐   ┌────────────┐
  │ Pre-parse  │──▶│  Parsing   │──▶│  Map check │──▶│    Init    │
  └────────────┘   └────────────┘   └────────────┘   └────────────┘
   6 ids present,   textures,        valid chars,     mlx, window,
   no duplicates,   F / C colours,   closed map,      image buffer,
   map is last      map lines        one player       player, textures
                                                            │
                     ┌──────────────────────────────────────┘
                     ▼
        ┌──────────────────────────────────────────────────┐
        │                mlx_loop (game loop)              │
        │                                                  │
        │  ┌────────────┐   ┌────────────┐   ┌──────────┐  │
        │  │ Key states │──▶│  Raycast   │──▶│ Put image│──┤
        │  └────────────┘   └────────────┘   └──────────┘  │
        │   move, strafe,    1 ray / column   to window    │
        │   rotate           DDA + textures                │
        └──────────────────────────────────────────────────┘
                     │ Esc / ❌
                     ▼
               ┌────────────┐
               │  Clean up  │  free map, images, window, display
               └────────────┘
```

### 1. Pre-parse — `src/check_cub_file/`

A first quick pass over the file that only checks its **structure**: the 6 identifiers are all present, none is duplicated, and the map comes after them. On failure, the expected format is printed.

### 2. Parsing — `src/parsing/`

A second pass fills a `t_arg` with the actual data:

```c
typedef struct s_arg
{
    char    *no, *so, *we, *ea;     // texture paths
    char    **map;                  // raw map lines
    int     f_color[3];             // floor RGB
    int     c_color[3];             // ceiling RGB
    int     f_defined, c_defined;
    int     map_size;
}   t_arg;
```

Then `validate_map` checks every character, counts the players, and makes sure each walkable cell is fully enclosed (no neighbour is a space or past the end of a shorter line). Any failure here is reported once, from `main`, as `Parsing: Invalid map or elements`.

### 3. Init — `src/utils/`

Opens the MiniLibX display and window, creates the image buffer, converts the colours to `0xRRGGBB`, sets up the player and loads the 4 textures:

| Start | `dir` | `plane` |
|---|---|---|
| `N` | `( 0, -1)` | `( 0.66,  0)` |
| `S` | `( 0,  1)` | `(-0.66,  0)` |
| `E` | `( 1,  0)` | `( 0,  0.66)` |
| `W` | `(-1,  0)` | `( 0, -0.66)` |

The `0.66` camera plane gives a field of view of about **66°**.

### 4. Raycasting — `src/render/`

For each screen column `x`:

1. **Ray direction**: `camera_x = 2x / WIDTH - 1`, `raydir = dir + plane × camera_x`
2. **DDA**: step from grid line to grid line on X or Y, whichever is closer, until a `1` is hit
3. **Distance**: perpendicular distance to the wall → `line_height = HEIGHT / perpwalldist`
4. **Texture**: the wall face hit (`side` + ray direction) selects N / S / E / W, and the exact hit point gives the texture column
5. **Draw**: ceiling colour above, stretched texture column in the middle, floor colour below

```c
typedef struct s_ray
{
    double  raydir_x, raydir_y;
    int     map_x, map_y;           // current grid cell
    double  sidedist_x, sidedist_y; // distance to the next X / Y grid line
    double  deltadist_x, deltadist_y;
    double  perpwalldist;
    int     step_x, step_y, side, hit;
    int     line_height, draw_start, draw_end;
}   t_ray;
```

### 5. Input — `src/hook/`

`key_press` / `key_release` only update a `t_key` state struct. On every frame, `key_handler` applies the movements (translation along `dir` or its perpendicular) and rotations (a 2D rotation matrix applied to both `dir` and `plane`).

### 6. Clean up — `src/free/`

`handle_close` (Esc or window close) destroys the textures, the image, the window and the display, frees the map, then exits.

---

## 📂 Project structure

```
.
├── include/
│   └── cube.h               # all types, constants and prototypes
├── libft/                   # our own C library, cloned by make (strings, memory, printf, get_next_line)
├── main.c                   # argument check, parsing, hooks, mlx_loop
├── map/
│   ├── map_valid/           # example scenes
│   └── non_valid_map/       # scenes that must be rejected
├── texture/                 # north / south / east / west .xpm textures
├── Makefile
└── src/
    ├── check_cub_file/      # pre-parsing: structure of the .cub file
    ├── parsing/             # textures, colours, map, map validation
    ├── utils/               # mlx / image / player / texture initialisation
    ├── render/              # game loop, raycasting, wall drawing
    ├── hook/                # key handling, movement, rotation
    ├── free/                # memory and mlx resources release
    ├── msg_error/           # error messages
    └── debug/               # parsed-data printer used during development
```

---

## 💻 Examples

```console
$ ./cub3D map/map_valid/map.cub
# opens an 800x800 window, WASD to move, arrows to turn, Esc to quit

$ ./cub3D
Error
./cub3D "/path/map.cub"

$ ./cub3D map/non_valid_map/invalid_duplicate_id.cub
Error
Invalid .cub file structure. Rules:
- 6 identifiers required: NO, SO, WE, EA, F, C
- Order of identifiers: Any
- Duplicates: Not allowed
- Map: Must be the very last element

$ ./cub3D map/non_valid_map/map_open.cub
Error
Parsing: Invalid map or elements
```

---

## 🚧 Limitations

This is the **mandatory part** of the subject only. Not implemented:

- Minimap, doors, animated sprites *(bonus)*
- Mouse rotation *(bonus)*
- Textured floor / ceiling (flat colours only)
- Linux only (the Makefile links against `minilibx-linux` and X11)

---

## 🧪 Testing

- every scene in `map/map_valid/` must open, every scene in `map/non_valid_map/` must print an error and exit
- edge cases by hand: open maps, spaces inside the map, duplicated identifiers, colours like `256,0,0` or `1,,2`, missing textures, wrong extension
- `valgrind` for leaks on parsing errors and after quitting the game:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./cub3D map/map_valid/map.cub
```

---

## 📚 Resources

- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html), the main reference for DDA and the rendering pipeline
- [Ray casting](https://en.wikipedia.org/wiki/Ray_casting) and [Digital differential analyzer](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) on Wikipedia
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- `man` pages: `open`, `read`, `close`, `math.h` (`cos`, `sin`, `fabs`, `floor`)

**AI use**: AI was used during debugging to help understand compiler error messages and trace memory issues. No code was generated by AI.

---

## 👥 Authors

| | Login | Main areas |
|---|---|---|
| 🧑‍💻 | **alehamad** | Pre-parsing, raycasting & rendering, input handling, movement |
| 🧑‍💻 | **tkhider** | Parsing (textures, colours, map), initialisation, textures |

<div align="center">

*Made with ☕ at 42*

</div>
