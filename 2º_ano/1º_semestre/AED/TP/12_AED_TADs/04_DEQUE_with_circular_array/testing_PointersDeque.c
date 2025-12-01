#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "PointersDeque.h"

int main(void) {
    Deque* d = DequeCreate(100);

    int i = 0;
    int o = 0;

    for (int n = 0; n < 2000000; n++) {
        // Decisão de adicionar ou remover
        if (Deque_size(d) == 0 || 
            (Deque_size(d) < 20 && (rand() & 0x01000000) == 0)) {

            // Adiciona na traseira
            int* aux = malloc(sizeof(int));
            *aux = i;
            Deque_add_at_rear(d, aux);
            i++;
        } else {
            // Remove da frente
            int* aux = (int*)Deque_remove_at_front(d);
            assert(*aux == o);
            o++;
            free(aux);
        }

        // Verifica o primeiro elemento
        if (Deque_size(d) > 0) {
            int* aux = (int*)Deque_peek_at_front(d);
            assert(*aux == o);
        }
    }

    // Esvaziar o deque
    while (!Deque_isEmpty(d)) {
        int* aux = (int*)Deque_remove_at_front(d);
        printf("%d\n", *aux);
        free(aux);
    }

    printf("All is well [i = %d, o = %d]\n", i, o);

    DequeDestroy(&d);

    return 0;
}
