all:
	echo please specify windows/osx/linux

osx: gc.a
linux: gc.a
windows: gc.lib

gc.lib:
		gcc -o gc.lib -shared src/main/*.c

gc.a:
	gcc -o gc.a -shared src/main/*.c

test: test.exe
	./test.exe

test.exe: gc.lib
	gcc -o test.exe src/test/*.c gc.*