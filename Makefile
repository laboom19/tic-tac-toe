all: tictactoe

tictactoe: xn0.c graphic.c graphic.h
	gcc xn0.c graphic.c -o tictactoe

clear:
	rm tictavtoe
