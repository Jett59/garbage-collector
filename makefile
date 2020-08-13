all: gc.lib

gc.lib:
	gcc -o gc.lib -shared src/main/*.c

test: test.exe
	./test.exe

test.exe: gc.lib
	gcc -o test.exe src/test/*.c gc.lib