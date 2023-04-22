from os import system
from sys import argv
argv = argv[1::]


specialFlags = ''

if len(argv) > 0 and (argv[0] == '--release' or argv[0] == '-r') : specialFlags += ' -static -static-libgcc -static-libstdc++'


system("g++ -I./dep/include -L./dep/lib -o bin/main.exe src/game.cpp -lgdi32 -lglfw3dll -lopengl32 -lglew32" + specialFlags)