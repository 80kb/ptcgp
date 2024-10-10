PROJECT = ptcgp

CC = g++
CFLAGS = -g -Wall -Wextra

BLD_DIR = out
SRC_DIR = src
LIB_DIR = lib

$(PROJECT):
	$(CC) $(CFLAGS)

SDL2:
	cd $(LIB_DIR)/SDL2 &&\
	mkdir build &&\
	cd build &&\
	../configure
	$(MAKE) -C $(LIB_DIR)/SDL2/build
	cd $(LIB_DIR)/SDL2/build &&\
	sudo make install	

clean:
	$(MAKE) clean -C $(LIB_DIR)/SDL2/build
