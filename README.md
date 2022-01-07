# RPG_Game_SDL_C

This is a simple game app for now only for training my C and SDL skills

## 1. Environment

### System:
The app was written and tested on the Windows 10 environment

### Dependencies:
SDL2 library:

```bash
SDL2.dll
```

SDL2_image-2.0.1:

```bash
libpng16-16.dll
SDL2_image.dll
zlib1.dll
```

### Compiler and linker:
* Visual Studio Compiler
* MinGw compiler


## 2. Build

#### Visual Studio Compiler
Right click to the project and chose "Properties"

C/C++ -> General -> Additional Include Directories
Add:
C:\SDL2_image-2.0.1\include
C:\SDL2\include

Linker -> General -> Additional Library Directories
Add:
C:\SDL2_image-2.0.1\lib\x64
C:\SDL2\lib\x64

Linker -> Input -> Additional Dependencies 
Add:
SDL2.lib, SDL2main.lib, SDL@_image.lib

#### MinGw compiler
Download MinGw from site: https://sourceforge.net/projects/mingw/

Add MinGw to teh environment variavles;

In cmd:
```bash
cd RPG_Game_SDL_C\RPG_LOR_Game
make
```
## 3. Run
