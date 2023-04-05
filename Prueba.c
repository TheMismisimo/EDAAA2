#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct m {
	float **data;
	int row_dim;
	int col_dim;
} matrix;


// tamaño máximo de linea en los archivos
#define MAX_LINE_SIZE 1000

int main()
{
    char *filename = "prueba.txt";
	struct m LaMatrix;
    char filas[MAX_LINE_SIZE];
    FILE *fpoint2 = fopen(filename, "w");
    int contadorfilas = 0;

    printf("Escriba el contenido de las filas, para dejar de escribir dar como input el numero 0:\n");
    while ( strcmp( fgets(filas, MAX_LINE_SIZE, stdin), "0\n") != 0){
        fprintf(fpoint2,"%s", filas);
        fflush(stdin);
        contadorfilas++;
    }
    fprintf(fpoint2,"\n");
    fclose(fpoint2);
    
    fpoint2 = fopen(filename, "r");
    char buffer[MAX_LINE_SIZE]; 
    while(fgets(buffer, MAX_LINE_SIZE, fpoint2) != NULL) {

        int largolinea = strlen(buffer);
        if (largolinea > 0 && buffer[largolinea-1] == '\n') {
            buffer[largolinea-1] = '\0';
    }
        float contador = 0;
        char *token;

        token = strtok(buffer, " \n");

        while(token != NULL) {

            contador += 1;
            token = strtok(NULL, " \n");
        }
        if (contador  == 0){
            continue;
        }
        if ( LaMatrix.row_dim == 0){
			LaMatrix.col_dim = contador;
		} else if (LaMatrix.col_dim != contador) {
            printf("El archivo no contiene una matriz válida.\n");
            printf("El archivo no contiene una matriz válida en la línea:\n%s\n", buffer);
            exit(EXIT_FAILURE);
        }
        LaMatrix.row_dim++;
    }

    LaMatrix.data = (float **) malloc(LaMatrix.row_dim * sizeof(float *));
    for (int i = 0; i < LaMatrix.row_dim; i++) {
        LaMatrix.data[i] = (float *) malloc(LaMatrix.col_dim * sizeof(float));
    }
    fclose(fpoint2);

    fpoint2 = fopen(filename, "r");
    int fila = 0;

    while(fgets(buffer, MAX_LINE_SIZE, fpoint2) != NULL) {
        int columna = 0;
        char *token;

        token = strtok(buffer, " \n");

        while(token != NULL) {
            LaMatrix.data[fila][columna] = atof(token);
            columna++;
            token = strtok(NULL, " \n");

        }
        fila++;
    }
    fclose(fpoint2);
    printf("las columnas %d, las filas %d\n", LaMatrix.col_dim, LaMatrix.row_dim);
    printf("valor 2, 2 de la matriz: %f", LaMatrix.data[1][1]);

    fflush(stdout);
    return 0;
}
