# Makefile

LDLIBS=-I C:\SDL2-2.0.18\x86_64-w64-mingw32\include\SDL2\\ -L C:\SDL2-2.0.18\x86_64-w64-mingw32\lib\\ -lmingw32 -lSDL2main -lSDL2 -I  C:\SDL2_image-2.0.5\x86_64-w64-mingw32\include\SDL2\\ -L C:\SDL2_image-2.0.5\x86_64-w64-mingw32\lib\\ -lSDL2_image


TextureManager.o: TextureManager.cpp TextureManager.h
	g++ TextureManager.cpp -c $(LDLIBS)

Map.o: Map.cpp Map.h
	g++ Map.cpp -c $(LDLIBS)

Hero.o: Hero.cpp Hero.h
	g++ Hero.cpp -c $(LDLIBS)

Guard.o: Guard.cpp Guard.h
	g++ Guard.cpp -c $(LDLIBS)

GameObject.o: GameObject.cpp GameObject.h
	g++ GameObject.cpp -c $(LDLIBS)

Game.o: Game.cpp Game.h
	g++ Game.cpp -c $(LDLIBS)

all: Game.o GameObject.o Guard.o Hero.o Map.o TextureManager.o
	g++ Game.o GameObject.o Guard.o Hero.o Map.o TextureManager.o  $(LDLIBS) -o program.exe

clean:
	rm -f Game.o

dump:
	g++ main.cpp -S
