
/*
**  main.c
**
**  Utilisation des fonctions du mini SGF.
**
**  04/04/2007
*/

#include <stdio.h>
#include <stdlib.h>

#include "sgf-disk.h"
#include "sgf-fat.h"
#include "sgf-dir.h"
#include "sgf-io.h"

int main() {
	OFILE* file;
	int c;
	int i = 0;
	init_sgf();

	printf("\nListing du disque\n\n");
	list_directory();

	printf("\nOuverture du fichier essai.txt ...\n");
	file = sgf_open("essai.txt", READ_MODE);

	printf("\n-- Lecture du fichier essai.txt --\n\n");
	while ((c = sgf_getc(file)) > 0) {
		printf("%d : ", i++);
		putchar(c);
		printf("\n");
	}

	/*while( (c = sgf_getc(file)) >  0)
		putchar(c);*/

	printf("\n-- Fin de lecture --\n");

	printf("\n-------\n");
	printf("TEST SEEK : \n");

	sgf_seek(file, 5);
	c = sgf_getc(file);
	putchar(c);
	printf("\n");

	sgf_seek(file, 127);
	c = sgf_getc(file);
	putchar(c);
	printf("\n");

	sgf_seek(file, 140);
	c = sgf_getc(file);
	putchar(c);
	printf("\n");

	sgf_close(file);

	return (EXIT_SUCCESS);
	}
