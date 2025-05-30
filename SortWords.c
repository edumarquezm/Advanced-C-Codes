#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// To use strcmp

// Write a program that sorts a series of words entered by the user

struct node {

	char str[20];

	struct node* next;
};


// Function to add strings to the list

struct node* add_string_to_list(struct node* list, char str[]) {
	
	struct node* new_node;

	new_node = malloc(sizeof(struct node));

	if (new_node == NULL) {

		printf("Error: malloc failed!\n");
		exit(EXIT_FAILURE);
	}

	strcpy(new_node->str, str);
	
	new_node->next = list;

	return new_node;

}

int read_linee(char str[], int n) {

	int ch, i = 0;

	while ((ch = getchar()) != '\n')  {

		if (i < n) {
			str[i++] = ch;
		}
	}

	str[i] = '\0';

	return i;
}


// Function to sort strings in ascending order

struct node* sort_strings(struct node* list) {

	struct node* curr = list;
	struct node* prev = NULL;
	struct node* sorted_list = NULL;

	while (curr != NULL) {

		struct node* next = curr->next;

		// If the sorted list is empty or the current string is smaller than the first string in the sorted list

		if (sorted_list == NULL || strcmp(curr->str, sorted_list->str) < 0) {
			curr->next = sorted_list;
			sorted_list = curr;
		}
		else {
			struct node* temp = sorted_list;

			// Find the correct position to insert the current string in the sorted list
			while (temp->next != NULL && strcmp(curr->str, temp->next->str) >= 0) {
				temp = temp->next;
			}

			curr->next = temp->next;
			temp->next = curr;
		}

		curr = next;
	}

	return sorted_list;
}



int main(void) {

	struct node* list = NULL;

	char str[20];

	while (1) {		// Infinite loop

		printf("Enter word: ");
		int result = read_linee(str, sizeof(str));

		if (result == '\0') {								// If user enters an empty string, loop ends
			break;
		}

		list = add_string_to_list(list, str);				// If user does not enter an empty string, add it to the list

	}

	printf("\nAll strings entered: ");

	// Print all the strings in the linked list

	struct node* current = list;

	while (current != NULL) {

		printf("%s ", current->str);

		current = current->next;
	}
	
	// Print all the strings in the linked list in sorted order

	printf("\nIn sorted order: ");

	struct node* walker = sort_strings(list);
	
	while (walker != NULL) {

		printf("%s ", walker->str);

		walker = walker->next;

	}

	return 0;
}
