#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

int main() {
	srand(time(NULL));

	// print empty list
	printf("--------------\n");
	struct player *begin = NULL;
	printf("Print empty list:\n");
	print_list(begin);
	printf("\n--------------\n");

	// add steve to list
	begin = insert_front(begin, "Steve", 10, 8);
	printf("Added Steve to list:\n");
	print_list(begin);
	printf("--------------\n");

	// add alex, villager, zombie, and creeper to list
	begin = insert_front(begin, "Alex", 8, 10);
	begin = insert_front(begin, "Villager", 5, 5);
	begin = insert_front(begin, "Zombie", 5, 0);
	begin = insert_front(begin, "Creeper", 3, 0);
	printf("Added Alex, Villager, Zombie, and Creeper to list:\n");
	print_list(begin);
	printf("--------------\n");

	// remove zombie from list
	begin = remove_node(begin, "Zombie");
	printf("Removed Zombie from list:\n");
	print_list(begin);
	printf("--------------\n");

	// free rest of list
	begin = free_list(begin);
	printf("Print freed list:\n");
	print_list(begin);
	printf("\n--------------\n");

	return 0;
}