/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

// Delete the first occurrence of a given key
void deleteNode(struct Node **head_ref, int key) {
	struct Node *temp = *head_ref, *prev = NULL;

	// Case 1: Head node itself holds the key
	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next; // move head
		free(temp);				// free old head
		return;
	}

	// Case 2: Search for the key to delete
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If key not found
	if (temp == NULL)
		return;

	// Unlink the node
	prev->next = temp->next;
	free(temp);
}

void printList(struct Node *node) {
	while (node != NULL) {
		printf("%d -> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
}



int main() {
	struct Node *head = malloc(sizeof(struct Node));
	head->data = 10;
	head->next = malloc(sizeof(struct Node));
	head->next->data = 20;
	head->next->next = malloc(sizeof(struct Node));
	head->next->next->data = 30;
	head->next->next->next = NULL;

	printf("Before deletion: ");
	printList(head);

	deleteNode(&head, 20);

	printf("After deletion: ");
	printList(head);
	return 0;
}