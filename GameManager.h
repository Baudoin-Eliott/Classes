#pragma once

#include "Character.h"
#include "Player.h"
#include "Merchant.h"

class GameManager
{
public:
	static Character player;
	static std::vector<Merchant> merchants;
	static int lastZone;
	static int currentZone;
	static int running;


	void ChangeZone(int newZone) { lastZone = currentZone; currentZone = newZone; };



};

