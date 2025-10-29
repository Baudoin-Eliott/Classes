#pragma once
#include "Item.h"

class Weapon : public Item {

protected:
	int damage;
	int durabilite;
public:
	Weapon(const char* n, const char* desc, int val, int dmg, int dur) : Item(n, desc, val), damage(dmg), durabilite(dur) {};
	int GetDamage() { return damage; };
	int GetDurabilite() { return durabilite; };
	bool DecreaseDurability(int amount) { durabilite -= amount; if (durabilite < 0) return true ;return false; };

	void Use() { durabilite--; };
};