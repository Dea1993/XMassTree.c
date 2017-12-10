#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_CYAN "\x1b[36m"

// funzione che riceve in input un valore e lo assegna dentro la matrice
char monta_albero (char val) {
	int n=19; // numero righe matrice
	int m=18; // numero colonne matrice
	int i, j;
	int matrice [n][m];  // matrice
			     
	// riempo la matrice
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			// ritorna il valore (0 o spazio)
			return matrice [i][j] = val;
		}
	}
	
}

int main() {
	int usleep(useconds_t usec);
	int i, j, z, loop;
	int spazi=9, zeri=1;
	int rnd; // variabile che rappresente la pallina colorata appesa all'albero
	int montata=0; // variabile che indica se ho gia messo una pallina così evito di metterne 2 di fila

	// inizializzo un seme (basato sull'ora) per un numero pseudo-casuale
	srand (time(NULL));

	// stampa la matrice
	// invio i vari caratteri per formare l'albero
	/* il for del loop serve per reiterare il ciclo 4 volte
	* ad ogni iterazione disegno un triangolo (partendo dall'alto)
	* sempre più grande, fino ad arrivare alla base	*/
	for (loop=0;loop<4;loop++) {
		for (i=4;i>0;i--) {
			for(j=spazi;j>0;j--) {
				printf ("%c",monta_albero(' '));
			}
			for(z=0;z<zeri;z++){
				// estraggo un numero casuale da 0 a 4
				rnd=rand()%5;
				// aspetto
				usleep(5000);

				// disegna la stella (X) nella punta dell'albero
				if (zeri==1)
					printf (ANSI_COLOR_YELLOW "X");
				else
					// se rnd e' 1 allora metto la pallina rossa altrimenti no
					if ((rnd==1)&&(montata==0)) {
						printf (ANSI_COLOR_RED "%c",monta_albero('0'));
						montata=1;
					} else if ((rnd==3)&&(montata==0)){
						printf (ANSI_COLOR_CYAN "%c",monta_albero('0'));
						montata=1;
					} else {
						printf (ANSI_COLOR_GREEN "%c",monta_albero('0'));
						montata=0;
					}
			}
			printf("\n");
			// al termine di ogni riga diminuisco uno spazio e aggiungo 2 zeri per allargare l'albero
			spazi--;
			zeri+=2;
		}
		// al termine di ogni "triangolo" aggiungo nuovamente 2 spazi e tolgo 4 zeri, per restringere un po l'albero
		spazi+=2;
		zeri-=4;
	}

	// costruisco il tronco
	for (loop=0;loop<2;loop++) {
		for (i=0;i<8;i++)
			printf(" ");
		for (i=0;i<3;i++)
			printf(ANSI_COLOR_WHITE "0");
		printf("\n");
	}
	return 0;

}     		
