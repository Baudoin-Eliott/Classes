#include "Merchant.h"

void Merchant::ShowInv()
{
	std::cout << "--------------" << std::endl;
	if (inventory.size() != 0) {
		std::cout << inventory.size() << std::endl;
		for (int i = 0; i < inventory.size(); i++) {
			std::cout << inventory[i]->GetName() << std::endl;
		}
	}
	else
		std::cout << "no item" << std::endl;
	std::cout << "--------------" << std::endl;
}


void Merchant::BuyItem(Character* customer, Item* item)
{
	if (customer->GetMoney() >= item->GetPrice()) {
		customer->AddMoney(-item->GetPrice());
		customer->AddItem(item);
	}

}

Merchant::~Merchant()
{
	for (auto item : inventory) {
		delete item;
	}
}
