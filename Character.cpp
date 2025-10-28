#include "Character.h"
#include "Item.h"
#include<iostream>

int Character::AddItem(Item* i)
{
	if (inventory.size() < maxSizeInv)
		inventory.push_back(i);

	else {
		std::cout << "inventaire plein, veillez faire du tri" << std::endl;
		return 1;
	}
	return 0;
}

void Character::SupprItem(Item* item)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->GetName() == item->GetName())
		{
			inventory.erase(inventory[i]);
			return;
		}
	}
}

void Character::EquipItem()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << inventory[i]->GetName() << ", a une valeur de: " << inventory[i]->GetValue() << ".\n" << inventory[i]->GetDesc() << "\n pour equiper cette item, ecrire " << i << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	int value;
	std::cin >> value;
	if (value < 0 || value >= inventory.size())
	{
		std::cout << "Mauvais index" << std::endl;
		return;
	}
	int choice;
	std::cout << "Où voulez vous l'equiper ? (1 = Arme, 2 = Armor)" << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		EquipThisItem(inventory[value]);
	}
	

}

void Character::EquipThisItem(Weapon* item)
{
	equipItem = item;


}

void Character::DisplayInv()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (Item* item : inventory) {
		std::cout << item->GetName() << ", a une valeur de: " << item->GetValue() << ".\n" << item->GetDesc() << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

}

void Character::DisplayStats()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "joueur: " << name << "-Pv: " << hp << "/" << maxHp << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Character::Damage(int dmg)
{
	hp -= dmg;
	std::cout << "Le personnage " << name << " a subit " << dmg << " damage, il est maitenant a " << (hp > 0 ? hp : 0) << "Hp !" << std::endl;
	if (hp <= 0)
		std::cout << "Vous etes mort !" << std::endl;

}

void Character::Heal(int healValue)
{
	hp += healValue;
	if (hp > maxHp) hp = maxHp;
	std::cout << "Le personnage " << name << " a ete heal de " << healValue << ", il est maitenant a " << hp << std::endl;

}
