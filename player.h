#ifndef PLAYER_H
#define PLAYER_H

struct player {
	char *name[256];
	int hearts;
	int hunger;

	struct player *next;
};

struct player *new_player(char *n, int h, int hu);
void display_player(struct player *p);
void take_damage(struct player *p, int damage);
void use_energy(struct player *p, int energy);
void erase_player(struct player *player_name);

void print_list(struct player *p);
struct player *insert_front(struct player *p, char *n, int h, int hu);
struct player *free_list(struct player *p);
struct player *remove_node(struct player *front, char *name);

#endif