COMPILE=-lm -lglfw -lGLESv2 -lXrandr -lpthread -lXi -lX11 -lXmu -lglut -lGL -lX11 -lxml2  $(shell pkg-config --cflags freetype2) -lfreetype -g
all:
	g++ mainMenu.cc -fPIC -shared $(COMPILE) -z defs -o ../a.so
