#pragma once
#include "Item.h"
class Potion : public Item {

protected:
	int value;
public:
	Potion(const char* n, const char* desc, int pri, int val) : Item(n, desc, pri), value(val) {};
	int GetValue() { return value; };
	virtual void Use(Character* target) = 0;
};