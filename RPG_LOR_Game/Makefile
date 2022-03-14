# Makefile
CC = g++

ifeq ($(OS),Windows_NT)
LDLIBS=-I C:\SDL2-2.0.18\x86_64-w64-mingw32\include\SDL2\\ -L C:\SDL2-2.0.18\x86_64-w64-mingw32\lib\\ -lmingw32 -lSDL2main -lSDL2 -mwindows -I  C:\SDL2_image-2.0.5\x86_64-w64-mingw32\include\SDL2\\ -L C:\SDL2_image-2.0.5\x86_64-w64-mingw32\lib\\ -lSDL2_image
else 
LDLIBS= -lSDL2main -lSDL2 -lSDL2_image
endif

OBJFILES =   Screen.o MapSreen.o GameOverScreen.o MenuScreen.o Guard.o Hero.o Map.o Item.o TextureManager.o GameObject.o Game.o main.o
TARGET = program.exe

all: $(TARGET)
	
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDLIBS)

Screen.o: Screen.cpp Screen.h
	$(CC) Screen.cpp -c $(LDLIBS)

MapScreen.o: MapScreen.cpp MapScreen.h
	$(CC) MapScreen.cpp -c $(LDLIBS)

GameOverScreen.o: GameOverScreen.cpp GameOverScreen.h
	$(CC) GameOverScreen.cpp -c $(LDLIBS)

MenuScreen.o: MenuScreen.cpp MenuScreen.h
	$(CC) MenuScreen.cpp -c $(LDLIBS)

TextureManager.o: TextureManager.cpp TextureManager.h
	$(CC) TextureManager.cpp -c $(LDLIBS)

Map.o: Map.cpp Map.h
	$(CC) Map.cpp -c $(LDLIBS)

Hero.o: Hero.cpp Hero.h
	$(CC) Hero.cpp -c $(LDLIBS)

Guard.o: Guard.cpp Guard.h
	$(CC) Guard.cpp -c $(LDLIBS)

Item.o: Item.cpp Item.h
	$(CC) Item.cpp -c $(LDLIBS)

GameObject.o: GameObject.cpp GameObject.h
	$(CC) GameObject.cpp -c $(LDLIBS)

Game.o: Game.cpp Game.h
	$(CC) Game.cpp -c $(LDLIBS)

main.o: main.o
	$(CC) main.cpp -c $(LDLIBS) 

clean:
	rm -f $(OBJFILES) $(TARGET) *~


