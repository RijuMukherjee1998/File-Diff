run: all
	./build/main.out


all: compile_all
	
compile_all:
	gcc -o ./build/main.out ./src/main.c ./src/read_writefile.c

clean:
	rm -f ./build/* 
	rm -f ./tmp/*
