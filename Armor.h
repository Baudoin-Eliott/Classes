#pragma once
#include "Item.h"

class Armor : public Item {
private:
	int armorPoint;
	int durability;

public:

	Armor(const char* name, const char* desc, int value, int armorP, int dura) : Item(name, desc, value), armorPoint(armorP), durability(dura) {};
	~Armor() = default;
	void RemoveDurability(int value) { durability -= value; if (durability < 0) delete(this); };

};