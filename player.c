#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"

struct player *new_player(char *n, int h, int hu) {
	struct player *user;
	user = malloc(sizeof(struct player));

	strncpy(user->name, n, sizeof(user->name)-1);
	user->hearts = h;
	user->hunger = hu;

	return user;
}

void display_player(struct player *p) {
	printf("Name:\t%s\nHearts:\t%d\nHunger:\t%d\n", p->name, p->hearts, p->hunger);
}

void take_damage(struct player *p, int damage) {
	p->hearts -= damage;
}

void use_energy(struct player *p, int energy) {
	p->hunger -= energy;
}

void erase_player(struct player *player_name) {
	free(player_name);
}

void print_list(struct player *p) {
	while (p) {
		display_player(p);
		printf("\n");
		p = p->next;
	}
}

struct player *insert_front(struct player *p, char *n, int h, int hu) {
	struct player *play = new_player(n, h, hu);
	play->next = p;
	return play;
}

struct player *free_list(struct player *p) {
	while (p) {
		struct player *next = p->next;
		erase_player(p);
		p = next;
	}
}

struct player *remove_node(struct player *front, char *n) {
	struct player *current = front;

	if (strcmp(current->name, n) == 0) {
		current = front->next;
		erase_player(front);
		return current;
	}

	while (current->next) {
		struct player *next = current->next;

		if (!strcmp(next->name, n)) {
			current->next = next->next;
			erase_player(next);
			return front;
		}

		else {
			current = current->next;
		}
	}

	return front;
}
