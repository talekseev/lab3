filter: filter.o bmp_io.o bmp_flip_vertically.o
	gcc -o filter filter.o bmp_io.o bmp_flip_vertically.o

filter.o: filter.c bmp.h
	gcc -c -Wall -Wextra -std=c89 filter.c

bmp_flip_vertically.o: bmp_flip_vertically.c bmp.h
	gcc -c -Wall -Wextra -std=c89 bmp_flip_vertically.c

bmp_io.o: bmp_io.c bmp.h
	gcc -c -Wall -Wextra -std=c89 bmp_io.c

clean:
	rm -rf *.o filter

