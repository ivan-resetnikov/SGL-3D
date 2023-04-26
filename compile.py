from os import system
from sys import argv
argv = argv[1::]


DEPENDECIE_FLAGS = '-I./dep/include -L./dep/lib'
SOURCE_FLAGS = '-o bin/main.exe src/main.cpp'
OPENGL_FLAGS = '-lgdi32 -lglfw3dll -lopengl32 -lglew32'
RELEASE_FLAGS = '-static -static-libgcc -static-libstdc++'



specialFlags = ''

if len(argv) > 0:
	if argv[0] == '--release' or argv[0] == '-r' :
		specialFlags += RELEASE_FLAGS

system(f'g++ {DEPENDECIE_FLAGS} {SOURCE_FLAGS} {OPENGL_FLAGS} {specialFlags}')