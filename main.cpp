#include "GameManager.h"
#include "Items.h"
#include<iostream>
#include <conio.h>

GameManager Game;

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 


int AskInt(int min, int max, const char* msg = "", bool isBorned = true) {

	int value;
	do {
		if (msg != "") {
			std::cout << msg << std::endl;
		}
		else {
			if (isBorned) std::cout << "Entrez une valeur entre " << min << " et " << max << "." << std::endl;
			else std::cout << "Veuillez entrer un nombre." << std::endl;
		}
		std::cin >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Merci d'entrer un nombre." << std::endl;
			continue;
		}
	} while (isBorned ? (value < min || value > max) : false);
	return value;
}
void PrintVillageArt() {

	// Centrage de tout le bloc sur l'écran (en utilisant la fonction statique)
	// Assure-toi que GameManager.h est inclus.
	GameManager::GlobalCenterPadding(67);
	std::cout << "+===============================================================+" << std::endl;

	GameManager::GlobalCenterPadding(67);
	std::cout << "|__     __                         _                            |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|\\ \\   / /___   _   _  ___    ___ | |_  ___  ___    __ _  _   _ |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "| \\ \\ / // _ \\ | | | |/ __|  / _ \\| __|/ _ \\/ __|  / _` || | | ||" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|  \\ V /| (_) || |_| |\\__ \\ |  __/| |_|  __/\\__ \\ | (_| || |_| ||" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|   \\_/  \\___/ _\\__,_||___/  \\___| \\__|\\___||___/  \\__,_| \\__,_||" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|__   __(_)| || |  __ _   __ _   ___                            |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|\\ \\ / /| || || | / _` | / _` | / _ \\                           |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "| \\ V / | || || || (_| || (_| ||  __/                           |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|  \\_/  |_||_||_| \\__,_| \\__, | \\___|                           |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|     _  _    _          |___/                _                 |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|  __| |( )  / \\   _   _ | |__    ___  _ __  (_) _ __    ___    |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "| / _` ||/  / _ \\ | | | || '_ \\  / _ \\| '_ \\ | || '_ \\  / _ \\   |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|| (_| |   / ___ \\| |_| || |_) ||  __/| |_) || || | | ||  __/   |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "| \\__,_|  /_/   \\_\\\\__,_||_.__/  \\___|| .__/ |_||_| |_| \\___|   |" << std::endl;
	GameManager::GlobalCenterPadding(67);
	std::cout << "|                                     |_|                       |" << std::endl;

	GameManager::GlobalCenterPadding(67);
	std::cout << "+===============================================================+" << std::endl;
	std::cout << "\n"; // Ligne vide pour séparer du menu
}
void PrintMenuArt() {

	// Centrage de tout le bloc sur l'écran
	GameManager::GlobalCenterPadding(28);
	std::cout << "+============================+" << std::endl;

	GameManager::GlobalCenterPadding(28);
	std::cout << "| __  __                     |" << std::endl;
	GameManager::GlobalCenterPadding(28);
	std::cout << "||  \\/  |  ___  _ __   _   _ |" << std::endl;
	GameManager::GlobalCenterPadding(28);
	std::cout << "|| |/\\| | / _ \\| '_ \\ | | | ||" << std::endl;
	GameManager::GlobalCenterPadding(28);
	std::cout << "|| |  | ||  __/| | | || |_| ||" << std::endl;
	GameManager::GlobalCenterPadding(28);
	std::cout << "||_|  |_| \\___||_| |_| \\___/ |" << std::endl;

	GameManager::GlobalCenterPadding(28);
	std::cout << "+============================+" << std::endl;
	std::cout << "\n"; // Ligne vide pour séparer du menu
}
void PrintMerchantArt() {
	GameManager::GlobalCenterPadding(53);
	std::cout << "+===================================================+\n";
	GameManager::GlobalCenterPadding(53);
	std::cout << "|                          _                    _   |\n";
	GameManager::GlobalCenterPadding(53);
	std::cout << "|  /\\/\\    ___  _ __  ___ | |__    __ _  _ __  | |_ |\n";
	GameManager::GlobalCenterPadding(53);
	std::cout << "| /    \\  / _ \\| '__|/ __|| '_ \\  / _` || '_ \\ | __||\n";
	GameManager::GlobalCenterPadding(53);
	std::cout << "|/ /\\/\\ \\|  __/| |  | (__ | | | || (_| || | | || |_ |\n";
	GameManager::GlobalCenterPadding(53);
	std::cout << "|\\/    \\/ \\___||_|   \\___||_| |_| \\__,_||_| |_| \\__||";
	GameManager::GlobalCenterPadding(53);
	std::cout << "+===================================================+\n";
	std::cout << "\n";
}




std::vector<Merchant> SetMerchant() {
	std::vector<Merchant> merchants;
	std::vector<Item*> inv;

	inv.push_back(new HealPotion("Potion de soins", "Regenere 10 hp !", 5));
	inv.push_back(new Weapon("Epee en fer", "Une meilleure epee que l'epee en bois !", 10, 5, 50));
	inv.push_back(new PoisonPotion("Potion de poison", "Enleve 10 hp !", 5));

	Merchant merchant("blob", inv);
	merchants.push_back(merchant);
	return merchants;
}

void Merchants() {

	Merchant& currentMerchant = Game.merchants[Game.currentZone];
	currentMerchant.ShowInv();
	/*
	std::vector<std::string> desc;
	for (Item* it : currentMerchant.GetStock()) {
		if (it == nullptr) continue;
		desc.push_back(std::string(it->GetName()) + " - " + std::to_string(it->GetValue()) + " pieces");
	}
	

	desc.push_back("Quitter le marchand");
	int action = -1;
	int choice = 0;


	while (action != '\r' && action != ' ') {
		system("cls");
		PrintMerchantArt();
		GameManager::ButtonPrint(desc, choice);
		action = _getch();
		switch (action) {
		case('z'):
			choice--;
			if (choice < 0) choice = desc.size() - 1;
			break;
		case('s'):
			choice++;
			if (choice >= desc.size()) choice = 0;
			break;

		case('\r'): case(' '):
			currentMerchant.BuyItem(Game.player);
			break;
		}
	}
	if (choice == desc.size() - 1) {
		Game.ChangeZone(Game.lastZone);
	}
	*/
}

void history() {
	std::cout << "Tu vis dans un petit village isole, Val d Aubepine, cache au creux des collines brumeuses du royaume d Eldara.\nC’est un lieu paisible, entoure de champs d orge doree, de rivieres claires et d une foret ancienne que les anciens appellent la Sylve - Grise.\nLes habitants vivent simplement : chasseurs, forgerons, herboristes… tout le monde se connait.\nMais depuis quelques semaines, une etrange lueur verte apparait chaque nuit au bord de la foret.\nLe betail tombe malade, et des murmures parlent de creatures rodant sous la lune." << std::endl;
	std::string name;
	std::cout << "Quel est ton nom aventurier ?" << std::endl;
	std::cin >> name;

	// Allocation dynamique du joueur. Le pointeur est stocké dans GameManager.
	Game.player = new Player(name, 100, 100, 5000);

	std::cout << "bienvenue sur ces terres " << Game.player->GetName() << "!" << std::endl;
}

void village() {
	std::vector<std::string> buttons = { "ouvrir le menu", "aller voir le marchant", "aller dans la foret", "quitter le jeu" };
	int action = -1;
	int choice = 0;
	while (action != '\r' && action != ' ') {
		system("cls");
		PrintVillageArt();
		GameManager::ButtonPrint(buttons, choice);
		action = _getch();
		switch (action) {
		case('z'):
			choice--;
			if (choice < 0) choice = buttons.size() - 1;
			break;

		case('s'):
			choice++;
			if (choice >= buttons.size()) choice = 0;
			break;
		}
	}
	switch (choice) {
	case(0):
		Game.ChangeZone(-1);
		break;
	case(1):
		Merchants();
		break;
	case(2):
		//foret
		break;
	case(3):
		Game.ChangeZone(-2);
		break;
	}


}

void menu() {
	std::vector<std::string> buttons = { "afficher vos stats", "afficher votre inventaire", "fermer le menu" };
	int action = -1;
	int choice = 0;
	while (action != '\r' && action != ' ') {
		system("cls");
		PrintMenuArt();
		if (Game.lastmenuSelection == 0)
			Game.player->DisplayStats();
		GameManager::ButtonPrint(buttons, choice);
		action = _getch();
		switch (action) {
		case('z'):
			choice--;
			if (choice < 0) choice = buttons.size() - 1;
			break;

		case('s'):
			choice++;
			if (choice >= buttons.size()) choice = 0;
			break;
		}
	}
	switch (choice) {
	case(0):
		Game.player->DisplayStats();
		Game.lastmenuSelection = 0;
		break;
	case(1):
		Game.player->DisplayInv();
		Game.lastmenuSelection = 1;
		break;
	case(2):
		Game.ChangeZone(Game.lastZone);
		Game.lastmenuSelection = -1;
	}
}

void quit() {
	std::vector<std::string> buttons = { "Je suis sur de vouloir quitter", "My bad.." };
	int action = -1;
	int choice = 0;
	while (action != '\r' && action != ' ') {
		system("cls");
		GameManager::ButtonPrint(buttons, choice);
		action = _getch();
		switch (action) {
		case('z'):
			choice--;
			if (choice < 0) choice = buttons.size() - 1;
			break;

		case('s'):
			choice++;
			if (choice >= buttons.size()) choice = 0;
			break;
		}
	}
	switch (choice) {
	case(0):
		Game.running = 0;
		break;
	case(1):
		Game.ChangeZone(Game.lastZone);
		break;
	}

}

void forest() {

}
int main() {

	Game.merchants = SetMerchant();
	Game.merchants[0].ShowInv();
	Game.currentZone = 0;
	Game.running = 1;

	history();
	Game.player->AddItem(new Weapon("epee en bois", "une epee basique en bois", 1, 2, 10));
	Game.player->AddItem(new Weapon("epee en bois", "une epee basique en bois", 1, 2, 10));
	Game.player->AddItem(new Weapon("epee en bois", "une epee basique en bois", 1, 2, 10));
	while (Game.running == 1) {
		switch (Game.currentZone) {
		case(-2):
			quit();
			break;
		case(-1):
			menu();
			break;
		case(0):
			village();
			break;
		case(1):
			//foret
			break;
		default:
			break;

		}
	}

	delete Game.player;

	std::cout << "Merci d'avoir jouer a MEDIEVAL SHOPING ADVENTURE par Baudoin Eliott" << std::endl;





	return 0;
}