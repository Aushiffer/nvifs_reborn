#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "marriage.h"

int main() {
	srand(time(NULL));
	stack_t *st = new_stack();
	dl_list *prt_l = new_dl_list();
	dl_list *conc_l = new_dl_list();
	int cnd_num, prt_num, match = 0, mismatch = 0, no_pair = 0;
	char rename_nodes;
	printf("Enter the size of both the candidates stack and the pretenders list, respectively: ");
	scanf("%d", &cnd_num);
	scanf("%d", &prt_num);
	printf("Do you wish to name every single person on the program? (y/n)\n");
	scanf(" %c", &rename_nodes);
	getchar();
	printf("\n");

	if (rename_nodes == 'y' || rename_nodes == 'Y') {
		printf("Candidates stack:\n\n");

		for (int i = 0; i < cnd_num; i++) {
			node_t *n = new_node();
			printf("Candidate %d name: ", i + 1);
			fgets(n->name, sizeof(n->name), stdin);
			n->name[strcspn(n->name, "\n")] = '\0';
			printf("Attributes: ");

			for (int j = 0; j < ATR_NUM; j++)
				printf("%d ", n->atr[j]);

			printf("\n\n");
			push_stack(st, n);
		}

		printf("\nPretenders list:\n\n");

		for (int j = 0; j < prt_num; j++) {
			node_t *n = new_node();
			printf("Pretender %d name: ", j + 1);
			fgets(n->name, sizeof(n->name), stdin);
			n->name[strcspn(n->name, "\n")] = '\0';
			printf("Attributes: ");

			for (int k = 0; k < ATR_NUM; k++)
				printf("%d ", n->atr[k]);

			printf("\n\n");
			insert_node(prt_l, n);
		}
	} else if (rename_nodes == 'n' || rename_nodes == 'N') {
		printf("Candidates stack:\n\n");
		
		for (int i = 0; i < cnd_num; i++) {
			node_t *n = new_node();
			printf("%s %d atributes: ", n->name, i + 1);

			for (int j = 0; j < ATR_NUM; j++)
				printf("%d ", n->atr[j]);

			printf("\n\n");
			push_stack(st, n);
		}

		printf("\nPretenders list:\n\n");

		for (int j = 0; j < prt_num; j++) {
			node_t *n = new_node();
			printf("%s %d atributes: ", n->name, j + 1);

			for (int k = 0; k < ATR_NUM; k++)
				printf("%d ", n->atr[k]);
			
			printf("\n\n");
			insert_node(prt_l, n);
		}
	} else {
		fprintf(stderr, "[-] Invalid input.\n\n");
		free_list(prt_l);
		free_list(conc_l);
		free_stack(st);
		
		return 0;
	}

	pairing(st, conc_l, prt_l, &match, &mismatch, &no_pair);
	printf("\nMatches: %d; Mismatches: %d; People without a pair: %d\n", match, mismatch, no_pair);
	free_list(prt_l);
	free_list(conc_l);
	free_stack(st);

	return 0;
}
