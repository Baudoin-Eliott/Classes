#pragma once
#include "Potion.h"
#include"Character.h"
class PoisonPotion : public Potion {
public:
	void Use(Character* target) { target->Damage(value); };
};