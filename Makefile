# Mac, gcc och sdl2 genom homebrew
# Windows, gcc och sdl2 genom MSYS2 mingw-w64

SRC_DIR = src
BUILD_DIR = build/debug
# g++/g++-11/c++/c++-11 beroende på installation
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
# Mac INCLUDE_PATHS
INCLUDE_PATHS = -Iinclude -I/opt/homebrew/include -Iinclude/SDL2 -Iinclude/lSDL2_image -Iinclude/lSDL2_mixer -Iinclude/lSDL2_ttf
# Windows INCLUDE_PATHS
#INCLUDE_PATHS = -Iinclude -IC:/msys64/mingw64/include
# Mac LIBRARY_PATHS
LIBRARY_PATHS = -Llib -L/opt/homebrew/lib -Llib/SDL2 -Llib/SDL2_image -Llib/SDL2_mixer -Llib/SDL2_ttf
# Windows LIBRARY_PATHS
#LIBRARY_PATHS = -Llib -LC:/msys64/mingw64/lib
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
#LINKER_FLAGS = 
# Om SDL2 används, Mac LINKER_FLAGS!
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
# Om SDL2 används, Windows LINKER_FLAGS!
#LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf


all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)