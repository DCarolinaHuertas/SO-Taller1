#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // El usuario debe proveer al menos el término de búsqueda
    if (argc < 2) {
        printf("wgrep: searchterm [file...]\n");
        exit(1);
    }

    char *term = argv[1];
    char *line = NULL;
    size_t len = 0;

    // Si no hay archivos, leer de lo que el usuario escriba en el teclado (stdin)
    if (argc == 2) {
        while (getline(&line, &len, stdin) != -1) {
            if (strstr(line, term)) printf("%s", line);
        }
    } else {
        // Buscar en cada archivo proporcionado
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            // getline reserva memoria automáticamente para líneas largas
            while (getline(&line, &len, fp) != -1) {
                if (strstr(line, term)) printf("%s", line);
            }
            fclose(fp);
        }
    }
    free(line); // Liberar la memoria usada por getline
    return 0;
}