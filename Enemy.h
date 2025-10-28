#pragma once
#include "Character.h"
class Enemy : public Character
{
private:
	int ex;



public:
	Enemy(std::string n) : Character(n, 100), ex(0) {}
	Enemy(std::string n, int MaxHp) : Character(n, MaxHp), ex(0) {}
	Enemy(std::string n, int MaxHp, int hp) : Character(n, MaxHp, hp), ex(0) {}
	Enemy(std::string n, int MaxHp, int hp, int money) : Character(n, MaxHp, hp, money), ex(0) {}
};

