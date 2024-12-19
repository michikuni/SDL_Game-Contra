all:
	g++ -Iinclude/SDL2 -Llib -o main *.cpp -lSDl2main -lSDL2 -lSDL2_ttf -lSDL2_image