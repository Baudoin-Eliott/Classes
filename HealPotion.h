#pragma once
#include "Potion.h"
#include "Character.h"

class HealPotion : public Potion {

public:
	HealPotion(const char* n, const char* desc, int val) : Potion(n, desc, val) {};
	void Use(Character* target) { target->Heal(value); };
};