#pragma once
#include "Potion.h"
#include "Character.h"

class HealPotion : public Potion {

public:
	HealPotion(const char* n, const char* desc, int pri,int val) : Potion(n, desc, pri,val) {};
	void Use(Character* target) { target->Heal(value); };
};