#include <stdio.h>
#include <stdbool.h>

void sub_slice(const int *vector, size_t vector_size, const int *sub_vector, size_t sub_vector_size) {
    size_t slices_number = vector_size - sub_vector_size;
    size_t slice_size = sub_vector_size;
    bool found = false;

    for (size_t i = 0; i <= slices_number; ++i) {
        const int *slice_start = vector + i;
        const int *slice_end = slice_start + slice_size;

        // Stampa il sotto-vettore corrente
        printf("[");

        for (const int *p = slice_start; p < slice_end; ++p) {
            printf("%d", *p);

            if (p < slice_end - 1) {
                printf(", ");
            }
        }

        printf("]\n");

        // Verifica se il sotto-vettore corrente è uguale al sotto-vettore cercato
        if (memcmp(slice_start, sub_vector, slice_size * sizeof(int)) == 0) {
            printf("Found\n");
            found = true;
            break;
        }
    }

    // Stampa un messaggio se il sotto-vettore non è stato trovato
    if (!found) {
        printf("Not found\n");
    }
}

int main() {
    int vector[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int sub_vector[] = {30, 40, 50};

    size_t vector_size = sizeof(vector) / sizeof(vector[0]);
    size_t sub_vector_size = sizeof(sub_vector) / sizeof(sub_vector[0]);

    sub_slice(vector, vector_size, sub_vector, sub_vector_size);

    return 0;
}
