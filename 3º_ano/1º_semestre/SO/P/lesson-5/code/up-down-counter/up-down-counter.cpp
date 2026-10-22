#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int *var;
} ThreadArgs;

void *child_thread(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    int *var = args->var;
    int n2 = 0;

    do {
        printf("Introduza o valor N2 (entre 10 e 20): ");
        if (scanf("%d", &n2) != 1) {
            while (getchar() != '\n'); 
            n2 = 0;
        }
    } while (n2 < 10 || n2 > 20);

    while (*var < n2) {
        (*var)++;
        printf("Filho -> Valor: %d\n", *var);
    }

    return NULL;
}

int main(void) {
    pthread_t tid;
    int n1 = 0;

    do {
        printf("Introduza o valor N1 (entre 1 e 9): ");
        if (scanf("%d", &n1) != 1) {
            while (getchar() != '\n');
            n1 = 0;
        }
    } while (n1 < 1 || n1 > 9);

    int shared_var = n1;

    ThreadArgs args = { &shared_var };

    if (pthread_create(&tid, NULL, child_thread, &args) != 0) {
        perror("Erro ao criar a thread filha");
        return EXIT_FAILURE;
    }

    pthread_join(tid, NULL);

    while (shared_var > 1) {
        printf("Pai (Main) -> Valor: %d\n", shared_var);
        shared_var--;
    }
    printf("Pai (Main) -> Valor final: %d\n", shared_var);

    return 0;
}
