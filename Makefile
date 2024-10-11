TARGET 	:= ptcgp

CC 	:= g++
CFLAGS 	:= -g -Wall -Wextra
LDFLAGS := -lSDL2

BLD_DIR := ./out
SRC_DIR := ./src
LIB_DIR := ./lib

SRC_FILES := $(SRC_DIR)/main.cpp\
	     $(SRC_DIR)/engine/game_state.cpp\
	     $(SRC_DIR)/engine/sdl/sdl_boiler.cpp

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

run:
	$(BLD_DIR)/$(TARGET)

clean:
	rm -rf $(BLD_DIR)/*
	$(MAKE) clean -C $(LIB_DIR)/SDL2/build
	cd $(LIB_DIR)/SDL2 && rm -rf build
