#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    file = fopen("numbers.txt", "r");
    
    if (file == NULL) {
        printf("Hiba a fájl megnyitásakor.");
        return 1;
    }
    
    int *numbers = (int*)malloc(100 * sizeof(int));

    if (numbers == NULL) {
        printf("Memóriafoglalási hiba.");
        return 1;
    }

    int count = 0;
    int sum = 0;
    while (fscanf(file, "%d", &numbers[count]) != EOF) {
        sum += numbers[count];
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("A fájl üres.\n");
        free(numbers);
        return 1;
    }

    double average = (double)sum / count;
    printf("A dinamikus tömbben tárolt számok átlaga: %.2f\n", average);

    free(numbers);

    return 0;
}