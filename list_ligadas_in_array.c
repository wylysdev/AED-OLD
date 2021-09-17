#include <stdio.h>

#define NODES_SIZE 5

struct Node {
	int info;
	int next;
};
typedef struct Node node_t;

node_t nodes[NODES_SIZE];

void print_nodes() {
	for (int i = 0; i < NODES_SIZE; i++) {
    	printf("%2d - info: %2d next: %2d\n", i, nodes[i].info, nodes[i].next);
	}
	printf("\n");
}

// 0..NODES_SIZE-1 : ponteiros válidos
// -1          	: ponteiro null
int alloc_node() {
	for (int i = 0; i < NODES_SIZE; i++) {
    	if (nodes[i].next == -2) {
        	return i;
    	}
	}
	return -1;
}

void free_node(int n) {
	nodes[n].info = 0;
	nodes[n].next = -2;
}

void push(int * stk, int info) {
	int aux = alloc_node();
	if (aux != -1) { // !is_null(aux)
    	nodes[aux].info = info; // info(aux) = info
    	nodes[aux].next = *stk; // next(aux) = stk
    	*stk = aux;
	}
}

int pop(int * stk) {
	int aux = *stk;      	// aux = stk
	*stk = nodes[*stk].next; // stk = next(stk)
	int i = nodes[aux].info; // i = info(aux)
	free_node(aux);      	// free_node(aux)
	return i;
}

int main() {
	// criar o balaio de nós disponíveis
	for (int i = 0; i < NODES_SIZE; i++) {
    	nodes[i].info = 0;
    	nodes[i].next = -2;
	}
	// print_nodes();
    
	int stk1 = -1; // list = null
	int stk2 = -1; // list = null
	int stk3 = -1; // list = null
    
	push(&stk1, 10);
	push(&stk2, 20);
	push(&stk3, 30);
	print_nodes();
	printf("stk: %d %d %d\n", stk1, stk2, stk3);
    
	push(&stk2, 40);
	print_nodes();
	printf("stk: %d %d %d\n", stk1, stk2, stk3);
    
	/*
	// remover o primeiro nó da lista
	int i = pop(&list);
	print_nodes();
	printf("list: %d info: %d\n", list, i);
    
	i = pop(&list);
	print_nodes();
	printf("list: %d info: %d\n", list, i);
    
	/*
	aux = alloc_node();
	if (aux != -1) { // !is_null(aux)
    	nodes[aux].info = 30; // info(aux) = 30
    	nodes[aux].next = list; // next(aux) = list
    	list = aux;
	}
	print_nodes();
	printf("list: %d\n", list);
    
	// remover o segundo nó da lista
	aux = nodes[list].next; // aux = next(list)
	nodes[list].next = nodes[aux].next; // next(list) = next(aux)
	nodes[aux].next = -1; // next(aux) = null
	free_node(aux);
	print_nodes();
	printf("list: %d\n", list);
    
	aux = alloc_node();
	if (aux != -1) { // !is_null(aux)
    	nodes[aux].info = 40; // info(aux) = 40
    	nodes[aux].next = list; // next(aux) = list
    	list = aux;
	}
	print_nodes();
	printf("list: %d\n", list);
	*/
	printf("FIM!\n");
	return 0;
}
