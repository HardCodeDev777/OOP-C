#include "Program.h"

#pragma region Entity

Entity* create_entity(int hp) {
	Entity* entity = malloc(sizeof(Entity));
	entity->hp = hp;
	entity->isDead = false;
	return entity;
}

void destroy_entity(Entity* entity) {
	free(entity);
}

#pragma endregion

#pragma region Enemy

Enemy* create_enemy(int hp, int armor) {
	Enemy* enemy = malloc(sizeof(Enemy));
	enemy->entity = create_entity(hp);
	enemy->armor = armor;
	return enemy;
}

void destroy_enemy(Enemy* enemy) {
	free(enemy);
	enemy = NULL;
}

void check_enemy_death(Enemy* enemy) {
	if (enemy->entity->isDead) {
		printf("Enemy is dead!");
		destroy_enemy(enemy);
	}
}

void check_enemy_hp(Enemy* enemy) {
	if (enemy->entity->hp <= 0)
	{
		enemy->entity->isDead = true;
		check_enemy_death(enemy);
	}
}
#pragma endregion

#pragma region Player

Player* create_player(int hp, char name[10], int dmg) {
	Player* player = malloc(sizeof(Player));
	player->entity = create_entity(hp);
	player->name = name;
	player->dmg = dmg;
	return player;
}

void destroy_player(Player* player) {
	free(player);
	player = NULL;
}

void check_player_death(Player* player) {
	if (player->entity->isDead) {
		printf("Player is dead!");
		destroy_player(player);
	}
}

void check_player_hp(Player* player) {
	if (player->entity->hp <= 0)
	{
		player->entity->isDead = true;
		check_player_death(player);
	}
}

void attack_enemy(Player* player, Enemy* enemy) {
	enemy->entity->hp -= (player->dmg - enemy->armor);
	check_enemy_hp(enemy);
	check_player_hp(player);
}

#pragma endregion

int main(void) {
	Player* player = create_player(100, "John Wick", 90);
	Enemy* enemy = create_enemy(100, 25);
	attack_enemy(player, enemy);
	attack_enemy(player, enemy);
	if (enemy != NULL) attack_enemy(player, enemy);
	return 0;
}