#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int info;
	struct Node *left;
	struct Node *right;
};
typedef struct Node node_t;

node_t * alloc_node() {
	node_t *aux = malloc(sizeof(node_t));
	if (aux != NULL) {
    	aux->info = 0;
    	aux->left = NULL;
    	aux->right = NULL;
	}
	return aux;
}

void free_node(node_t * n) {
	free(n);
}

bool is_empty(node_t *lst) {
	return lst == NULL;
}

void print(node_t *lst) {
	if (lst == NULL) {
    	printf("Lista Vazia!\n");
	} else {
    	for (node_t *aux = lst; aux != NULL; aux = aux->right) {
        	printf("[%p]{%p %d %p} -> \n", aux, aux->left, aux->info, aux->right);
    	}
    	printf("X \n");
	}
}

void push(node_t **stk, int info) {
	node_t *aux = alloc_node();
	if (aux != NULL) {
    	aux->info = info;
    	aux->left = NULL;
    	aux->right = *stk;
    	if (!is_empty(*stk)) {
        	(*stk)->left = aux;
    	}
    	*stk = aux;
	}
}

int pop(node_t **stk) {
	node_t *aux = (*stk)->right;
	if (aux != NULL) {
    	aux->left = NULL;
	}
	int i = (*stk)->info;
	free_node(*stk);
	*stk = aux;
	return i;
}

struct Queue {
	node_t *front;
	node_t *rear;
};
typedef struct Queue queue_t;

void queue_insert(queue_t *queue, int info) {
	node_t *aux = alloc_node();
	if (aux != NULL) {
    	aux->info = info;
    	aux->right = NULL;
    	aux->left = queue->rear;
    	if (queue->front == NULL && queue->rear == NULL) { // fila vazia
        	queue->front = aux;
    	} else {
        	(queue->rear)->right = aux;
    	}
    	queue->rear = aux;
	}
}

int queue_remove(queue_t *queue) {
	int i = (queue->front)->info;
	node_t *aux = queue->front;
	queue->front = (queue->front)->right;
	if (queue->front != NULL) {
    	(queue->front)->left = NULL;
	} else {
    	queue->rear = NULL;
	}
	free_node(aux);
	return i;
}

int main() {
	node_t *stk = NULL;
	//print(stk);
    
	push(&stk, 10); //print(stk);
	push(&stk, 20); //print(stk);
	push(&stk, 30); //print(stk);
    
	pop(&stk);  //print(stk);
	pop(&stk);  //print(stk);
	pop(&stk);  //print(stk);
    
	queue_t queue;
	// inicializa a fila vazia
	queue.front = NULL;
	queue.rear = NULL;
	//print(queue.front);
    
	queue_insert(&queue, 10);
	//printf("%p %p\n", queue.front, queue.rear);
	//print(queue.front);
    
	queue_insert(&queue, 20);
	//printf("%p %p\n", queue.front, queue.rear);
	//print(queue.front);
    
	queue_insert(&queue, 30);
	//printf("%p %p\n", queue.front, queue.rear);
	//print(queue.front);
    
	queue_remove(&queue);
	//printf("%p %p\n", queue.front, queue.rear);
	//print(queue.front);
    
	queue_remove(&queue);
	//print(queue.front);
	//printf("%p %p\n", queue.front, queue.rear);
    
	queue_remove(&queue);
	printf("%p %p\n", queue.front, queue.rear);
	print(queue.front);
    
	printf("FIM!");
	return 0;
}
