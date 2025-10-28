#pragma once

#include<vector>
#include<iostream>
#include"Item.h"
#include"Weapon.h"
#include"Armor.h"

class Character
{
protected:
	
	
	std::string name;
	
	int money;
	int maxHp;
	int hp;

	std::vector<Item*> inventory;
	int maxSizeInv = 16;

	Weapon* equipItem = nullptr;
	Armor* Helmet = nullptr;
	Armor* Chestplate = nullptr;
	Armor* Pants = nullptr;
	Armor* Boots = nullptr;

public:
	Character() : name(""), maxHp(100), hp(100), money(0) {};

	Character(std::string n, int MxHp) : name(n), maxHp(MxHp), hp(MxHp),money(0) {};
	Character(std::string n, int MxHp, int currentHp) : name(n), maxHp(MxHp), hp(currentHp), money(0) {};
	Character(std::string n, int MxHp, int currentHp, int mo) : name(n), maxHp(MxHp), hp(currentHp), money(mo) {};
	virtual ~Character();
	
	void DisplayStats();

	std::string GetName() { return name; };
	int GetMoney() { return money; };
	int GetHp() { return hp; };
	int GetMaxHp() { return maxHp; };
	int AddItem(Item* i);
	void SupprItem(Item* i);
	void EquipItem();
	void EquipThisItem(Weapon* item);
	void DisplayItemActions(Item* selectedItem);
	bool ExecuteItemAction(Item* item, const std::string& action);

	void DisplayInv();
	void AddMoney(int value) { money += value; std::cout << "Votre nouveau solde est de: " << money << std::endl; };

	void Damage(int dmg);
	void Heal(int healValue);


};


