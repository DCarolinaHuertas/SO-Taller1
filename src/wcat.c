#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Si no hay archivos en el comando, salir sin error
    if (argc < 2) exit(0); 

    // Recorrer cada archivo pasado por el usuario
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        char buffer[1024];
        // Leer el archivo por pedazos (buffers) de 1024 caracteres
        while (fgets(buffer, sizeof(buffer), fp)) {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    return 0;
}