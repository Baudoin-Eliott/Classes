#include "Merchant.h"
#include "Item.h"
#include<iostream>

void Merchant::ShowInv()
{
	std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i < stock.size(); i++) {
		std::cout << stock[i].GetName() << ", elle vaux: " << stock[i].GetValue() << "\n" << stock[i].GetDesc() << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

}

void Merchant::BuyItem(Character* customer)
{
	std::cout << "Vous avez actuelement: " << customer->GetMoney() << " piece sur vous !" << std::endl;


	std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i < stock.size(); i++) {
		std::cout << stock[i].GetName() << ", elle vaux: " << stock[i].GetValue() << "\n" << stock[i].GetDesc() << "\nPour l'acheter, entre " << i << std::endl;
		std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;
	}
	
	int value;
	std::cin >> value;
	if (value < 0 || value >= stock.size()) {
		std::cout << "valeur incorrect." << std::endl;
		return;
	}
	else {
		if (customer->GetMoney() >= stock[value].GetValue()) {
			if (customer->AddItem(stock[value]) == 0) {
				customer->AddMoney(-stock[value].GetValue());
				this->SupprItem(&stock[value]);
			}
		}
		else
			std::cout << "Vous n'avez pas un asser gros solde pour acheter cette item !" << std::endl;
	}
}
