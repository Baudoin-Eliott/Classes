#pragma once

class Character;
class Item
{
protected:
	const char* name;
	int price;
	const char* description;

public:
	Item(const char* n, const char* desc, int pri) : name(n), description(desc), price(pri) {};
	virtual ~Item() = default;
	const char* GetName() { return name; };
	const char* GetDesc() { return description; };
	int GetPrice() { return price; };

	virtual void Use(Character* target) {};
};



