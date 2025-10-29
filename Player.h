#pragma once
#include "Character.h"

class Player : public Character {
private:


public:

	Player(std::string n) : Character(n, 100, 1) {}
	Player(std::string n, int MaxHp ) : Character(n, MaxHp, 1)  {}
	Player(std::string n, int MaxHp, int hp) : Character(n, MaxHp, hp, 1)  {}
	Player(std::string n, int MaxHp, int hp, int money, int lvl) : Character(n, MaxHp, hp, money, lvl){}

};