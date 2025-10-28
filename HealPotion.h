#pragma once
#include "Potion.h"
#include "Character.h"

class HealPotion : public Potion {

public:
	void Use(Character* target) { target->Heal(value); };
};