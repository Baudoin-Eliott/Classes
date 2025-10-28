#pragma once
#include "Character.h"


class Merchant : public Character {
private:
	std::vector<Item> stock;
public:
	Merchant(std::string n, std::vector<Item> inv) : Character(n, 100), stock(inv) {}
	void ShowInv();
	void BuyItem(Character* customer);
};
