CC = gcc


all :  snake3D


snake3D : snake3D.c
	$(CC) snake3D.c -o snake3D -lglut -lGL  -lGLU -lm

clean :
	rm -f   snake3D
