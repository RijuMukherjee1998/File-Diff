run: all
	./build/main.out


all: clean compile_all
	
compile_all:
	gcc -o ./build/main.out ./src/main.c ./src/read_writefile.c -lm   # also linked the math module (-lm) -- some how math.h was not linked properly

clean:
	rm -f ./build/* 
	rm -f ./tmp/*
