#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 10


	char matriz [TAM][2][20];
	char  aux[1][2][20];
	int i,j;
	int inicio, meio, fim;

int main(int argc, char *argv[]) {

	strcpy(matriz[0][0], "45313126865");
	strcpy(matriz[0][1], "Joao");
	strcpy(matriz[1][0], "55555555555");
	strcpy(matriz[1][1], "Alan");
	strcpy(matriz[2][0], "41483454886");
	strcpy(matriz[2][1], "Maria");
	strcpy(matriz[3][0], "11111111111");
	strcpy(matriz[3][1], "Josefa");
	strcpy(matriz[4][0], "12345678901");
	strcpy(matriz[4][1], "Ricardo");
	strcpy(matriz[5][0], "09876543211");
	strcpy(matriz[5][1], "Roberta");
	strcpy(matriz[6][0], "11122223333");
	strcpy(matriz[6][1], "Marcos");
	strcpy(matriz[7][0], "99988887654");
	strcpy(matriz[7][1], "Daniel");
	strcpy(matriz[8][0], "77777666662");
	strcpy(matriz[8][1], "Tomas");
	strcpy(matriz[9][0], "33333333333");
	strcpy(matriz[9][1], "Naruto");


	printf("Nome:\t\t| CPF:\t\t|\n");
	printf("---------------------------------\n");
	for (i = 0; i < TAM; i++){
		for(j = 0; j < 1; j++){
			printf("%s\t| %s\t\t|\n", matriz[i][j], matriz[i][j++]);
		}
	}

	for (i = 1; i < TAM; i++){
        j = i;

        while(j > 0 && (strcmp(matriz[j - 1], matriz[j]) == 1)){
            strcpy(aux[0][0], matriz[j][0]);
            strcpy(aux[0][1], matriz[j][1]);


            strcpy(matriz[j], matriz[j - 1][0]);
            strcpy(matriz[j][1], matriz[j - 1][1]);

            strcpy(matriz[j - 1], aux[0][0]);
            strcpy(matriz[j - 1][1], aux[0][1]);
           j--;
        }
	}

    printf("\n\n\n\n\n\n\n\Nome:\t\t| CPF:\t\t|\n");
	printf("---------------------------------\n");
	for (i = 0; i < TAM; i++){
		for(j = 0; j < 1; j++){
			printf("%s\t| %s\t\t|\n", matriz[i][j], matriz[i][j++]);
		}
	}

	char busca[20];
	printf("\n\n\n\n\n\Digite o numero a ser buscado:\n");
	scanf("%s", &busca);

    int ini = 0;
    int fim = TAM - 1;
    int meio = 0;
    int indice = -1;
    int comp = -1;
    char matPos[20];

    while (ini < fim){
        if(fim - ini == 1){
            if(fim == meio){
                meio = ini;
            } else {
                meio = fim;
            }
        } else {
            meio = (ini + fim) / 2;
        }

        strcpy(matPos,matriz[meio]);
        comp = strcmp(busca, matPos);

        switch(comp){
            case 0:
                indice = meio;
                ini = fim + 1;
                // igual
                break;
            case 1:
                ini = meio;
                // Primeira string maior
                break;
            case -1:
                fim = meio;
                // Primeira string menor
                break;
            default:
                // Ocorreu um erro
                break;

        }
    }

    if(indice >= 0){
        printf("\n\nEncontrado %s ", matriz[indice][1]);
    } else {
        printf("\n\nNao encontrado");
    }

	return 0;
}
