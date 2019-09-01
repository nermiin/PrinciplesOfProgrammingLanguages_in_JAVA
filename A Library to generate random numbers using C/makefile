all: compile run

compile:
	gcc -I ./include/ -o ./lib/Random.o -c ./src/Random.c
	gcc -I ./include/ -o ./lib/RastgeleKarakter.o -c ./src/RastgeleKarakter.c
	gcc -I ./include/ -o ./lib/Mean.o -c ./src/Mean.c
	gcc -I ./include/ -o ./bin/Test ./lib/Random.o ./lib/Mean.o ./lib/RastgeleKarakter.o ./src/Test.c

run:
	./bin/Test
