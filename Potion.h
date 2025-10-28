#pragma once
#include "Item.h"
class Potion : public Item {

protected:
	int value;
public:
	Potion(const char* n, const char* desc, int val) : Item(n, desc, val), value(val) {};
	int GetValue() { return value; };
	virtual void Use(Character* target) = 0;
};