balls.o: balls.cpp balls.h
game.o: game.cpp game.h balls.h
machine.o: machine.cpp machine.h balls.h game.h
main.o: main.cpp balls.h game.h machine.h
