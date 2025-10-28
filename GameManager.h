#pragma once

#include "Character.h"
#include "Player.h"
#include "Merchant.h"

class GameManager
{
public:
	// Remplacement de 'static Character player' par 'static Player* player'
	// L'objet sera alloué dans main.cpp
	static Player* player;
	static std::vector<Merchant> merchants;
	static int lastZone;
	static int currentZone;
	static int running;
	static int lastmenuSelection;


	void ChangeZone(int newZone) { lastZone = currentZone; currentZone = newZone; };

	static void GlobalCenterPadding(int blockWidth);
	static void ButtonPrint(const std::vector<std::string>& buttons, int selected);
};