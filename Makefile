run: all
	./build/main.exe


all: compile_all
	
compile_all:
	gcc -o ./build/main.exe ./src/main.c ./src/read_writefile.c

clean:
	del /q build\* 
	del /q tmp\*