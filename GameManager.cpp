

#include "GameManager.h"
#include "Player.h"
#include <iostream>
#include <algorithm> 


Player* GameManager::player = nullptr;
std::vector<Merchant> GameManager::merchants;
std::vector<std::vector<EnemieCara>> GameManager::zoneMonsters;
int GameManager::lastZone = 0;
int GameManager::currentZone = 0;
int GameManager::running = 1;
int GameManager::lastmenuSelection = -1;
const int SCREEN_WIDTH = 120;


void GameManager::GlobalCenterPadding(int blockWidth) {
	if (blockWidth >= SCREEN_WIDTH) return;
	int padding = (SCREEN_WIDTH - blockWidth) / 2;
	for (int i = 0; i < padding; ++i) {
		std::cout << " ";
	}
}

void GameManager::ButtonPrint(const std::vector<std::string>& buttons, int selected) {


	size_t maxWidth = 0;
	for (const auto& button : buttons) {
		if (button.length() > maxWidth) {
			maxWidth = button.length();
		}
	}

	int buttonWidth = maxWidth + 4;
	std::string horizontalLine(buttonWidth - 2, '=');


	GlobalCenterPadding(buttonWidth);
	std::cout << " +" << horizontalLine << "+" << std::endl;

	for (size_t i = 0; i < buttons.size(); i++) {

		int paddingRight = maxWidth - buttons[i].length();


		GlobalCenterPadding(buttonWidth);


		if (i == selected) {
			std::cout << " |\033[33;40m";
			std::cout << ">";
		}
		else {
			std::cout << "\033[0m";
			std::cout << " | ";
		}


		std::cout << buttons[i];


		for (int j = 0; j < paddingRight; j++) {
			std::cout << " ";
		}


		if (i == selected) {
			std::cout << "<\033[0m|";
		}
		else {
			std::cout << " |";

			std::cout << "\033[0m\n";

		}
		if (i == selected)GlobalCenterPadding(buttonWidth + 1);
		if (i < buttons.size()-1) {
			
			GlobalCenterPadding(buttonWidth);

			std::cout << " |" << std::string(buttonWidth - 2, '-') << "|" << std::endl;
		}

	}

	GlobalCenterPadding(buttonWidth);
	std::cout << " +" << horizontalLine << "+" << std::endl;
}