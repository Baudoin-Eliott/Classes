#pragma once
#include "Item.h"

class Weapon : public Item {

protected:
	int damage;
	int durabilite;
public:
	int GetDamage() { return damage; };
	int GetDurabilite() { return durabilite; };

	void Use() { durabilite--; };
};