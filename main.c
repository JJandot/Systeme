
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

	printf("\nOuverture en lecture du fichier essai.txt ...\n");
	file = sgf_open("essai.txt", READ_MODE);

	printf("\n-- Lecture du fichier essai.txt --\n\n");
	/*
	// Permet de débug la fonction SEEK
	while ((c = sgf_getc(file)) > 0) {
		printf("%d : ", i++);
		putchar(c);
		printf("\n");
	}
	*/

	while( (c = sgf_getc(file)) >  0)
		putchar(c);

	printf("\n-- Fin de lecture --\n");

	printf("\n-------\n");
	printf("TEST SEEK : \n");

	sgf_seek(file, 126);
	c = sgf_getc(file);
	putchar(c);
	printf("\n");

	sgf_seek(file, 127);
	c = sgf_getc(file);
	putchar(c);
	printf("\n");

	sgf_seek(file, 142);
	c = sgf_getc(file);
	putchar(c);
	printf("\nFIN TEST\n");

	return (EXIT_SUCCESS);
}
