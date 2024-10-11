PROJECT = ptcgp

CC = g++
CFLAGS = -g -Wall -Wextra
LDFLAG = -lSDL2

BLD_DIR = ./out
SRC_DIR = ./src
LIB_DIR = ./lib

SRC_FILES = $(SRC_DIR)/main.cpp\
	    $(SRC_DIR)/sdl/sdl_boiler.cpp\
	    $(SRC_DIR)/engine/game_state.cpp

$(PROJECT):
	$(CC) $(CFLAGS) $(SRC_FILES) $(LDFLAG) -o $(BLD_DIR)/$(PROJECT)

config: SDL2
	mkdir ./$(BLD_DIR)

SDL2:
	cd $(LIB_DIR)/SDL2 &&\
	mkdir ./build &&\
	cd ./build &&\
	../configure
	$(MAKE) -C $(LIB_DIR)/SDL2/build
	cd $(LIB_DIR)/SDL2/build &&\
	sudo make install	

clean:
	rm -rf $(BLD_DIR)/*
	$(MAKE) clean -C $(LIB_DIR)/SDL2/build
	cd $(LIB_DIR)/SDL2 && rm -rf build
