#pragma once
#include "Character.h"
#include "Item.h" 

class Merchant : public Character {
private:

public:

	Merchant(std::string n, std::vector<Item*> inv) : Character(n, 100, 1, inv) {}
	const std::vector<Item*>& GetStock() const { return inventory; };
	void ShowInv();
	void BuyItem(Character* customer, Item* item);
	virtual ~Merchant();
};