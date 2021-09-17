#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};
typedef struct Node node_t;

void print(node_t *l) {
    if (l == NULL) {
        printf("Lista Vazia!\n");
    } else {
        for (node_t *aux = l; aux != NULL; aux = aux->next) {
            printf("{%d, %p} -> ", aux->info, aux->next);
        }
        printf("X \n");
    }
}
node_t * alloc_node() {
    node_t *aux = malloc(sizeof(node_t));
    if (aux == NULL) {
        aux->info = 0;
        aux->next = NULL;
    }
    return aux;
}

void free_node(node_t * n) {
    free(n);
}
void push(node_t **stk, int info) {
    node_t *aux = alloc_node();
    if (aux != NULL) {
        aux->info = info;
        aux->next = *stk;
        *stk = aux;
    }
}

int pop(int * stk) {
    int aux = *stk;          // aux = stk
    *stk = nodes[*stk].next; // stk = next(stk)
    int i = nodes[aux].info; // i = info(aux)
    free_node(aux);          // free_node(aux)
    return i;
}
int main() {
    
    node_t *list = NULL; // ptr para lista vazia
    print(list);
    
    push(&list, 10);
    print(list);
    
    push(&list, 20);
    print(list);
    
    push(&list, 30);
    print(list);
    
}
