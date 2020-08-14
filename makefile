all:
	echo please specify windows/osx/linux

osx: gc_osx.dylib
linux: gc_linux.so
windows: gc_windows.dll

gc_windows.dll:
		gcc -o gc_windows.dll -shared src/main/*.c

gc_osx.dylib:
	gcc -o gc_osx.dylib -shared src/main/*.c

gc_linux.so:
	gcc -o gc_linux.so -shared src/main/*.c
