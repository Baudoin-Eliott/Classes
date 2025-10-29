#pragma once
#include "Potion.h"
#include"Character.h"
class PoisonPotion : public Potion {


public:
	PoisonPotion(const char* n, const char* desc, int price, int val) : Potion(n, desc, price, val) {};
	void Use(Character* target) { target->Damage(value); };
};