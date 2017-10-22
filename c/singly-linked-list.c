#include <stdio.h>
#include <stdlib.h>

unsigned int nodeCount;

struct node {
	int num;
	struct node *next;
};
// initialize a node at the end
struct node *InitializeLastNode(struct node *node) {
	// traverse to last node
	while (node->next != NULL)
		node = node->next;
	// point the node to the new last node
	if (!(node->next = malloc(sizeof(struct node))))
		return NULL;
	// set the new node's pointer to NULL
	(node->next)->next = NULL;
	++nodeCount; // maybe could *possibly* be useful
	return node->next;
}
// initialize a node after the argument (maybe first node too, though not necessary)
struct node *InitializeMiddleNode(struct node *node) {
	struct node *next = node->next;
	if (!(node->next = malloc(sizeof(struct node))))
		return NULL;
	(node->next)->next = next;
	++nodeCount;
	return node->next;
}
// remove a given node and return the node before that
struct node *RemoveNode(struct node *head, struct node *node) {
	// traverse to the node
	while (head->next != node)
		head = head->next;
	// point to next node or NULL
	head->next = node->next;
	// free the memory
	free(node);
	return head;
}

struct node *RemoveLastNode(struct node *node) {
	// traverse to last node
	struct node *prev;
	while (node->next != NULL) {
		prev = node;
		node = node-> next;
	}
	prev->next = NULL;
	free(node);
}

int main(void) {
	// pointer to the first node
	struct node *root;
	struct node *currentNode;
	// declaring the root node
	root = malloc(sizeof(struct node));
	root->num = 3291;
	printf("%d\n", root->num);
	currentNode = InitializeLastNode(root);
	currentNode->num = 291;
	printf("%d\n", currentNode->num);
	currentNode = InitializeMiddleNode(root);
	currentNode->num = 2911;
	printf("%d\n", currentNode->num);
}