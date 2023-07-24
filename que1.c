#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &x);

    FILE *input_file, *output_file;
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL) {
        printf("Error opening input file.");
        exit(1);
    }

    if (output_file == NULL) {
        printf("Error opening output file.");
        exit(1);
    }

    int numbers[x];
    for (int i = 0; i < x; i++) {
        fscanf(input_file, "%d", &numbers[i]);
    }

    fclose(input_file);

    // Sort the array in ascending order
    for (int i = 0; i < x-1; i++) {
        for (int j = i+1; j < x; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Write the sorted array to file
    fprintf(output_file, "Sorted array:\n");
    for (int i = 0; i < x; i++) {
        fprintf(output_file, "%d ", numbers[i]);
    }
    fclose(output_file);

    printf("Sorted array written to file.\n");
    return 0;
}
