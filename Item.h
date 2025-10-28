#pragma once

class Character;
class Item
{
protected:
	const char* name;
	int value;
	const char* description;

public:
	Item(const char* n, const char* desc, int val) : name(n), description(desc), value(val) {};
	~Item() = default;
	const char* GetName() { return name; };
	const char* GetDesc() { return description; };
	int GetValue() { return value; };

	virtual void Use(Character* target);
};



