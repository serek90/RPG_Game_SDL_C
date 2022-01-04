# Makefile
CC = g++
LDLIBS=-I C:\SDL2-2.0.18\x86_64-w64-mingw32\include\SDL2\\ -L C:\SDL2-2.0.18\x86_64-w64-mingw32\lib\\ -lmingw32 -lSDL2main -lSDL2 -I  C:\SDL2_image-2.0.5\x86_64-w64-mingw32\include\SDL2\\ -L C:\SDL2_image-2.0.5\x86_64-w64-mingw32\lib\\ -lSDL2_image

OBJFILES =   Guard.o Hero.o Map.o TextureManager.o GameObject.o Game.o main.o
TARGET = program.exe

all: $(TARGET)
	
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)  -L C:\SDL2-2.0.18\x86_64-w64-mingw32\lib\\ -lmingw32 -lSDL2main -lSDL2  -mwindows -L C:\SDL2_image-2.0.5\x86_64-w64-mingw32\lib\\ -lSDL2_image

TextureManager.o: TextureManager.cpp TextureManager.h
	$(CC) TextureManager.cpp -c $(LDLIBS)

Map.o: Map.cpp Map.h
	$(CC) Map.cpp -c $(LDLIBS)

Hero.o: Hero.cpp Hero.h
	$(CC) Hero.cpp -c $(LDLIBS)

Guard.o: Guard.cpp Guard.h
	$(CC) Guard.cpp -c $(LDLIBS)

GameObject.o: GameObject.cpp GameObject.h
	$(CC) GameObject.cpp -c $(LDLIBS)

Game.o: Game.cpp Game.h
	$(CC) Game.cpp -c $(LDLIBS)

main.o: main.o
	$(CC) main.cpp -c $(LDLIBS) 

clean:
	rm -f $(OBJFILES) $(TARGET) *~

dump:
	g++ main.cpp -S

