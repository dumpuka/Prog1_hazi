#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    file = fopen("numbers.txt", "w");
    
    if (file == NULL) {
        printf("Hiba a fájl létrehozásakor.");
        return 1;
    }
    
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        int randomNumber = rand() % 90 + 10;
        fprintf(file, "%d ", randomNumber);
    }

    fclose(file);
    printf("A numbers.txt fájl sikeresen létrehozva és feltöltve.\n");

    return 0;
}