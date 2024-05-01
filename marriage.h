#define ATR_NUM 10
#define CHAR_PTR_CAP 128

#include <stdbool.h>

// Nodo
typedef struct Node {
	struct Node *next;
	struct Node *prev;
	int atr[ATR_NUM];
	int relevance;
	char name[CHAR_PTR_CAP];
} node_t;

// Pilha
typedef struct Stack {
	node_t *top;
	int size;
} stack_t;

// Lista duplamente encadeada
typedef struct DL_List {
	node_t *tail;
	node_t *head;
	int size;
} dl_list;

// Cria um novo nodo
node_t *new_node();

// Cria uma nova pilha
stack_t *new_stack();

// Cria uma nova lista DL
dl_list *new_dl_list();

// Retorna o tamanho da lista
int size_list(dl_list *l);

// Retorna 'true' se a lista estiver vazia
bool empty_list(dl_list *l);

// Insere um nodo na lista
void insert_node(dl_list *l, node_t *n);

// Remove um nodo da lista
void remove_node(dl_list *l, int relevance_del);

// Remove a cabeça da lista
void remove_head(dl_list *l);

// Remove a cauda da lista
void remove_tail(dl_list *l);

// Libera todos os nodos da lista e a libera
void free_list(dl_list *l);

// Retorna 'true' se a pilha estiver vazia
bool empty_stack(stack_t *s);

// Insere um nodo na pilha (LIFO)
void push_stack(stack_t *s, node_t *n);

// Remove uma pessoa da pilha (LIFO)
void pop_stack(stack_t *s);

// Libera todos os nodos da pilha e libera a pilha
void free_stack(stack_t *s);

// Rola 'n_dices' 1d20, os soma e retorna a soma
int roll_1d20(short n_dices);

// Duelo candidato x pretendente
void duel(dl_list *conc_l, dl_list *prt_l, node_t *cnd, int *match, int *mismatch);

// Faz os pareamentos
void pairing(stack_t *cnd_s, dl_list *conc_l, dl_list *prt_l, int *match, int *mismatch, int *no_pair);
