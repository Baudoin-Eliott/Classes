#pragma once
#include "Character.h"
class Enemy : public Character
{
private:

public:
	Enemy(std::string n) : Character(n, 100, 1) {}
	Enemy(std::string n, int MaxHp) : Character(n, MaxHp, 1){}
	Enemy(std::string n, int MaxHp, int hp) : Character(n, MaxHp, hp, 1){}
	Enemy(std::string n, int MaxHp, int hp, int money) : Character(n, MaxHp, hp, money, 1){}
	Enemy(std::string n, int MaxHp, int hp, int money, int lvl) : Character(n, MaxHp, hp, money, lvl) {}
};

