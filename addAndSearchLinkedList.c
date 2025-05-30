#include <stdio.h>
#include <stdlib.h>

// Add and search numbers in a linked list

struct node {

	int value;

	struct node* next;
};

// Function to add a number to a list

struct node* add_number_to_list(struct node* list, int n) {

	struct node* new_node;

	new_node = malloc(sizeof(struct node));

	if (new_node == NULL) {

		printf("Error: malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	new_node->value = n;

	new_node->next = list;

	return new_node;

}



// Function that searches a list and returns a pointer to the node containing n

struct node* search_list(struct node* list, int n) {

	struct node* p;

	for (p = list; p != NULL; p = p->next) {

		if (p->value == n) {
			return p;
		}
	}

	return NULL;		// Returns a null pointer if not found
}

int main(void) {

	struct node *list = NULL;

	list = add_number_to_list(list, 65);
	list = add_number_to_list(list, 23);
	list = add_number_to_list(list, 39);
	

	// Printing numbers in the linked list
	struct node* current = list;

	while (current != NULL) {

		printf("%d ", current->value);
		current = current->next;

	}
	printf("\n");


	// Searching numbers in the linked list
    
    int n;
    printf("Enter a number to search: ");
    scanf("%d", &n);

	struct node* result = search_list(list, n);

	if (result != NULL) {

		printf("Number found: %d\n", result->value);
	}

	else {

		printf("%d not found", n);
	}
    
    
	return 0;
}
