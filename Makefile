TARGET = ptcgp

CC = g++
CFLAGS := -g -Wall -Wextra
LDFLAGS := -lSDL2

BLD_DIR := ./out
SRC_DIR := ./src
LIB_DIR := ./lib

SRC_FILES := $(SRC_DIR)/main.cpp\
	     $(SRC_DIR)/sdl/sdl_boiler.cpp\
	     $(SRC_DIR)/engine/game_state.cpp

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(BLD_DIR)/$@

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

cleanSDL2:
	$(MAKE) clean -C $(LIB_DIR)/SDL2/build
	cd $(LIB_DIR)/SDL2 && rm -rf build

clean: cleanSDL2
	rm -rf $(BLD_DIR)/*
