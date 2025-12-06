#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "DequeList.h"


void test_deque_operations() {
    printf("==========================================\n");
    printf("         INICIANDO TESTES DO DEQUE\n");
    printf("==========================================\n");

    // 1. CRIAÇÃO
    printf("\n--- Teste 1: Criação e Estado Inicial ---\n");
    Deque* d = DequeCreate();
    
    if (d == NULL) {
        printf("ERRO: Falha ao criar o Deque.\n");
        return;
    }
   	Deque_display(d); 

    // 2. ADICIONAR E REMOVER NA FRENTE
    printf("\n--- Teste 2: Add/Remove Front ---\n");
  	
	for(int i = 0; i<10; i++){
        void* val = malloc(sizeof(int));
        int num = i * 10;
        *(int*)val = num;
        Deque_add_at_front(d, val); 
        printf("Add Front %d:\n", *(int*)val ); 
        Deque_display(d);
        
    }
    void* peek_f = Deque_peek_at_front(d);
    assert(peek_f != NULL && *(int*)peek_f == 90);
    printf("Peek Front: %d\n", *(int*)peek_f);

    void* removed_f = Deque_remove_at_front(d); // Remove 90. Head:10
    assert(removed_f != NULL && *(int*)removed_f == 90);
    assert(Deque_size(d) == 9);
    printf("Remove Front: "); Deque_display(d);
    free(removed_f);
    // 3. ADICIONAR E REMOVER NA CAUDA
    printf("\n--- Teste 3: Add/Remove Rear ---\n");
    void* val = malloc(sizeof(int));
	*(int*) val = 35;
    Deque_add_at_rear(d, val); // Head:10->30
    printf("Add Rear (35): "); Deque_display(d);
	//*(int*)val = 40;
    //printf("Add Rear (40): "); Deque_display(d);
    void* peek_r = Deque_peek_at_rear(d);
    printf("Peek Rear: %d\n", *(int*)peek_r);
    
    void* removed_r = Deque_remove_at_rear(d); // Remove 40. Head:10->30
    printf("Remove Rear: %d\n", *(int*)removed_r); Deque_display(d);
    free(removed_r);
    // 4. TESTE DE LIMITE (FULL)
   /* printf("\n--- Teste 4: Limite de Capacidade ---\n");
    Deque_add_at_front(d, create_int(50)); // Head:50->10->30
    Deque_add_at_rear(d, create_int(60));  // Head:50->10->30 (Não deve adicionar, já está full)
    printf("Add Front (50): "); //Deque_display(d); // 50->10->30
    printf("Tentativa Add Rear (60) [FULL]: Deve manter tamanho %d\n", Deque_size(d));
*/
    // 5. LIMPEZA

    printf("\n--- Teste 5: Clear e Empty ---\n");
    Deque_clear(d);
    printf("Deque apos Clear: ");Deque_display(d);

    
    printf("\n--- Teste 7: Destruição ---\n");
    DequeDestroy(&d);
    //free(val);
    assert(d == NULL);
    printf("Deque destruido com sucesso. Ponteiro setado para %p.\n", d);
    
    printf("\n==========================================\n");
    printf("        TODOS OS TESTES PASSARAM!\n");
    printf("==========================================\n");
}

int main() {
    test_deque_operations();
    return 0;
}
