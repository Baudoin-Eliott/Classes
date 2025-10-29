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

	int level;
	int NextLevelExp = 50;
	int exp = 0;


	std::vector<Item*> inventory;
	int maxSizeInv = 16;

	Weapon* equipItem = nullptr;
	Armor* Helmet = nullptr;
	Armor* Chestplate = nullptr;
	Armor* Pants = nullptr;
	Armor* Boots = nullptr;

public:

	Character() : name(""), maxHp(100), hp(100), money(0), level(1) {};
	Character(std::string n, int MxHp, int lvl) : name(n), maxHp(MxHp), hp(MxHp),money(0),level(lvl) {};
	Character(std::string n, int MxHp, int lvl, std::vector<Item*> inv) : name(n), maxHp(MxHp), hp(MxHp),money(0),level(lvl), inventory(inv) {};
	Character(std::string n, int MxHp, int currentHp, int lvl) : name(n), maxHp(MxHp), hp(currentHp), money(0), level(lvl) {};
	Character(std::string n, int MxHp, int currentHp, int mo, int lvl) : name(n), maxHp(MxHp), hp(currentHp), money(mo), level(lvl) {};
	Character(std::string n, int MxHp, int currentHp, int mo, int lvl,Weapon* weapon, Armor* hel, Armor* che, Armor* pan, Armor* boo) : name(n), maxHp(MxHp), hp(currentHp), level(lvl),equipItem(weapon), Helmet(hel), Chestplate(che), Pants(pan), Boots(boo), money(mo) {};
	virtual ~Character();
	
	void DisplayStats();

	std::string GetName() { return name; };
	int GetMoney() { return money; };
	int GetHp() { return hp; };
	int GetMaxHp() { return maxHp; };
	int GetArmor();

	int AddItem(Item* i);
	void SupprItem(Item* i);
	void EquipItem();
	void EquipThisItem(Weapon* item);
	void DisplayItemActions(Item* selectedItem);
	bool ExecuteItemAction(Item* item, const std::string& action);

	Weapon* GetEquippedWeapon() { return equipItem; };

	void GainXp(int xp);
	void LevelUp();

	int GetLevel() { return level; };

	void DisplayInv();
	void AddMoney(int value) { money += value; std::cout << "Votre nouveau solde est de: " << money << std::endl; };

	void Attack(Character& target);
	void Damage(int dmg);
	void Heal(int healValue);


};


