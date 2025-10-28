#pragma once
#include "Potion.h"
#include"Character.h"
class PoisonPotion : public Potion {
public:
	PoisonPotion(const char* n, const char* desc, int val) : Potion(n, desc, val) {};
	void Use(Character* target) { target->Damage(value); };
};