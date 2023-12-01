#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Guess the number!\n");

    srand(time(NULL));
    int secret_number = rand() % 100 + 1;

    printf("The secret number is: %d\n", secret_number);

    while (1) {
        printf("Please input your guess.\n");

        char input[100];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            fprintf(stderr, "Failed to read line\n");
            exit(1);
        }

        int guess;
        if (sscanf(input, "%d", &guess) != 1) {
            continue; // Skip this iteration if the input is not a valid number
        }

        if (guess < secret_number) {
            printf("Too small!\n");
        } else if (guess > secret_number) {
            printf("Too big!\n");
        } else {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}
