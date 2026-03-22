#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Punto 1: Si no hay archivos, error y exit(1)
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    // Punto 3: Puede procesar varios archivos .z seguidos
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        int count;
        char c;
        
        // Punto 2: Lee el bloque de 5 bytes (4 del int + 1 del char)
        // fread devuelve 1 si logra leer el elemento completo
        while (fread(&count, sizeof(int), 1, fp) == 1) {
            if (fread(&c, sizeof(char), 1, fp) == 1) {
                // Reconstruye el texto original
                for (int j = 0; j < count; j++) {
                    printf("%c", c);
                }
            }
        }
        fclose(fp);
    }

    return 0; //Punto 7 todo salio bien
    
}

