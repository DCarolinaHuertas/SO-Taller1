# Taller 1: Utilidades de Unix (wcat, wgrep, wzip, wunzip)

DIANA CAROLINA HUERTAS CC. 40944999
diana.huertas@udea.edu.co

##  Documentación de Funciones
* **wcat.c**: Implementa la lectura de archivos mediante `fopen()` y `fgetc()`. Se encarga de imprimir el contenido en la salida estándar y manejar errores de apertura de archivos (exit 1).
* **wgrep.c**: Realiza búsquedas de cadenas de texto usando `getline()` para gestionar líneas de longitud variable de forma dinámica. Permite la entrada desde archivos o desde la entrada estándar (`stdin`).
* **wzip.c**: Aplica el algoritmo de compresión **Run-Length Encoding (RLE)**. Escribe en formato binario con `fwrite()`, utilizando 4 bytes para el contador (`int`) y 1 byte para el carácter (`char`), cumpliendo con el formato de 5 bytes por ráfaga.
* **wunzip.c**: Realiza la descompresión leyendo bloques binarios con `fread()`. Reconstruye el texto original repitiendo el carácter según el contador entero recuperado.

##  Problemas Presentados y Soluciones
1. **Manejo de Memoria Dinámica:** En `wgrep`, el uso de `getline` requería entender la gestión de punteros para evitar desbordamientos. Se solucionó inicializando correctamente el buffer.
2. **Formato Binario en wzip:** El reto principal fue asegurar que el entero ocupara exactamente 4 bytes. Se resolvió usando `sizeof(int)` en `fwrite` en lugar de imprimir texto plano.
3. **Cierre de Estructuras:** Se presentó un error de sintaxis en `wunzip` por una llave faltante al final del código, el cual fue corregido tras revisar la estructura del `main`.

## (d) Pruebas Realizadas
* **Validación de Argumentos:** Se verificó que todos los programas retornen un mensaje de ayuda y Status 1 si no se pasan parámetros.
* **Prueba de Compresión (Punto 2 y 3):** Se comprimieron dos archivos (`uno.txt` y `dos.txt`) con el contenido "AAAAA" y "BBBBB" respectivamente. El resultado fue un único archivo `unido.z` de **10 bytes** (5 por cada letra), validando el formato binario y la unión de flujos.
* **Prueba de Integridad:** Se usó `diff` para comparar un archivo original con uno descomprimido, confirmando que no hay pérdida de datos.

## (e) Video de Sustentación
* **Enlace al video: Anexo

## (f) Manifiesto de Transparencia
Declaramos que para el desarrollo de esta práctica se utilizó la asistencia de IA generativa (Gemini) en los siguientes puntos:
* Explicación de la lógica de lectura/escritura binaria con `fread` y `fwrite`.
* Depuración de errores de compilación y sintaxis en C.
* Estructuración de los casos de prueba para validar los tamaños de los archivos comprimidos.
