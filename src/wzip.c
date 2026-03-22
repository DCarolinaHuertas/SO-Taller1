#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Punto 5: Si no hay archivos, imprimir mensaje y exit(1)
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0;
    int current_char, last_char = -1;

    // Recorrer todos los archivos pasados por argumento
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((current_char = fgetc(fp)) != EOF) {
            if (last_char == -1) {
                // Primer carácter del primer archivo
                last_char = current_char;
                count = 1;
            } else if (current_char == last_char) {
                // Si el carácter es igual al anterior, sumamos
                count++;
            } else {
                // Si cambia el carácter, escribimos el "paquete" binario
                // 1. Escribimos el número (4 bytes)
                fwrite(&count, sizeof(int), 1, stdout);
                // 2. Escribimos el carácter (1 byte)
                fputc(last_char, stdout);
                
                // Reiniciamos para el nuevo carácter
                last_char = current_char;
                count = 1;
            }
        }
        fclose(fp);
    }

    // Al final de todos los archivos, escribir el último grupo acumulado
    if (last_char != -1) {
        fwrite(&count, sizeof(int), 1, stdout);
        fputc(last_char, stdout);
    }

    return 0; // Status 0: Éxito
}