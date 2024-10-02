srcfiles = main.c draw.c game.c

pacman : $(srcfiles)
	gcc -o pacman $(srcfiles) $(shell sdl2-config --cflags --libs)

