//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Pointers LIST application example --- TO BE COMPLETED
//

#include "PointersList.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Teste de lista de ponteiros ===\n");

    // Criar lista
    List* l = ListCreate();
    ListTestInvariants(l);

    // Inserir elementos no head
    int a = 10, b = 20, c = 30;
    ListInsertBeforeHead(l, &a);
    ListTestInvariants(l);
    ListInsertBeforeHead(l, &b);
    ListTestInvariants(l);
    ListInsertBeforeHead(l, &c);
    ListTestInvariants(l);

    printf("Lista após inserções no head: tamanho = %d\n", ListGetSize(l));

    // Mover current para head e inserir depois
    ListMoveToHead(l);
    int d = 40;
    ListInsertAfterCurrent(l, &d);
    ListTestInvariants(l);

    // Mover current para tail e inserir antes
    ListMoveToTail(l);
    int e = 50;
    ListInsertBeforeCurrent(l, &e);
    ListTestInvariants(l);

    printf("Lista após inserções antes/depois de current: tamanho = %d\n", ListGetSize(l));

    // Teste de remoção de head
    ListRemoveHead(l);
    ListTestInvariants(l);
    printf("Removido head, tamanho = %d\n", ListGetSize(l));

    // Teste de remoção de tail
    ListRemoveTail(l);
    ListTestInvariants(l);
    printf("Removido tail, tamanho = %d\n", ListGetSize(l));

    // Teste de remoção do current
    ListMoveToHead(l);
    ListMoveToNext(l); // current aponta para segundo nó
    ListRemoveCurrent(l);
    ListTestInvariants(l);
    printf("Removido current, tamanho = %d\n", ListGetSize(l));

    // Teste de remoção do next
    ListMoveToHead(l);
    ListRemoveNext(l);
    ListTestInvariants(l);
    printf("Removido next de current, tamanho = %d\n", ListGetSize(l));

    // Limpar lista
    ListClear(l);
    ListTestInvariants(l);
    printf("Lista limpa, tamanho = %d\n", ListGetSize(l));

    // Destruir lista
    ListDestroy(&l);

    printf("Todos os testes concluídos com sucesso!\n");
    return 0;
}
