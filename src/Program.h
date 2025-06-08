#pragma once

// I hate warnings
#pragma warning(disable: 6011)
#pragma warning(disable: 6001)
#pragma warning(disable: 4047)
#pragma warning(disable: 4133)
#pragma warning(disable: 4013)
#pragma warning(disable: 4024)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma region Entity

typedef struct Entity {
	int hp;
	bool isDead;
} Entity;

Entity* create_entity(int hp);

void destroy_entity(Entity* entity);

#pragma endregion

#pragma region Enemy

typedef struct Enemy {
	struct Entity* entity;
	char name;
	int armor;
} Enemy;

Enemy* create_enemy(int hp, int armor);

void destroy_enemy(Enemy* enemy);

void check_enemy_death(Enemy* enemy);

void check_enemy_hp(Enemy* enemy);
#pragma endregion

#pragma region Player

typedef struct Player {
	struct Entity* entity;
	char name;
	int dmg;
} Player;

Player* create_player(int hp, char name[10], int dmg);

void destroy_player(Player* player);

void check_player_death(Player* player);

void check_player_hp(Player* player);

void attack_enemy(Player* player, Enemy* enemy);

#pragma endregion