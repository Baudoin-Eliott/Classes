#pragma once

#include "Character.h"
#include "Player.h"
#include "Merchant.h"
#include "Enemy.h"

struct EnemieCara {
	std::string name;
	int maxLvl;
	int minLvl;
	int maxDHp;
	int minDHp;
	int maxDMoney;
	int minDMoney;

	EnemieCara(std::string n, int maxlvl, int minlvl, int maxdhp, int mindhp, int maxdmo, int mindmo) : name(n), maxLvl(maxlvl), minLvl(minlvl), maxDHp(maxdhp), minDHp(mindhp), maxDMoney(maxdmo), minDMoney(mindmo) {}
};
class GameManager
{
public:
	// Remplacement de 'static Character player' par 'static Player* player'
	// L'objet sera alloué dans main.cpp
	static Player* player;
	static std::vector<Merchant> merchants;
	static std::vector<std::vector<EnemieCara>> zoneMonsters; //2D for zones and their monsters
	static int lastZone;
	static int currentZone;
	static int running;
	static int lastmenuSelection;


	void ChangeZone(int newZone) { lastZone = currentZone; currentZone = newZone; };

	static void GlobalCenterPadding(int blockWidth);
	static void ButtonPrint(const std::vector<std::string>& buttons, int selected);
};