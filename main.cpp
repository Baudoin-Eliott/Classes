#include "GameManager.h"
#include "Items.h"


GameManager Game;

#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 


//fonction ininterresante
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
int GenerateRandomNumber(int min, int max) {

	int randNum = rand() % (max - min + 1) + min;
	return randNum;
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
void PrintMonsterArt(const std::string name) {
	if (name == "Goblin") {
		GameManager::GlobalCenterPadding(35);
		std::cout << "   ,      ,\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "            /(.-  -.)\\\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "        |\\  \\/      \\/  /|\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "        | \\ / =.  .= \\ / |\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "        \\( \\   o\\/o   / )/\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "         \\_, '-/  \\-' ,_/\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "           /   \\__/   \\\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "           \\ \\__/\\__/ /\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "         ___\\ \\|--|/ /___\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "       /`    \\      /    `\\\n";
		GameManager::GlobalCenterPadding(35);
		std::cout << "       /       '----'       \\\n";
		std::cout << "\n";
	}
	else if (name == "Wolf") {
		GameManager::GlobalCenterPadding(18);
		std::cout << "       / \\      _-'\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "     _/|  \\-''- _ /\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "__-' { |          \\\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "    /             \\\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "    /       \"o.  |o }\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "|            \\ ;\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "                  ',\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "       \\_         __\\\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "         ''-_    \\.//\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "           / '-____'\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "          /\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "        _'\n";
		GameManager::GlobalCenterPadding(18);
		std::cout << "      _-'\n";
		std::cout << "\n";
	}
	else {
		GameManager::GlobalCenterPadding(30);
		std::cout << "      .-\"\"\"-.\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "    .'       '.\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "   /           \\\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "  |  .--. .--.  |\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "  | (    Y    ) |\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "   \\  '--' '--' /\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "    '.       .'\n";
		GameManager::GlobalCenterPadding(30);
		std::cout << "      '-...-'\n";
		std::cout << "\n";
	}
}
//*fonction ininterresante


//init des monstres et marchants
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
std::vector<std::vector<EnemieCara>> SetEnemy() {

	std::vector<std::vector<EnemieCara>> enemies;

	//foret(Zone1)
	std::vector<EnemieCara> zone1Enemies;
	EnemieCara goblin("Goblin", 3, 1, 15, 5, 20, 5);
	EnemieCara loup("Wolf", 5, 2, 20, 10, 30, 10);
	EnemieCara slime("Slime", 2, 1, 10, 5, 5, 1);

	zone1Enemies.push_back(goblin);
	zone1Enemies.push_back(loup);
	zone1Enemies.push_back(slime);
	//*foret(Zone1)


	//ajout de toute les zones
	enemies.push_back(zone1Enemies);



	return enemies;
}
//*init des monstres et marchants


//menu
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
		menu();
		break;
	case(1):
		Game.player->DisplayInv();
		Game.lastmenuSelection = 1;
		menu();
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
		menu();
		break;
	}

}

void Setup() {
	srand(time(NULL));
	Game.merchants = SetMerchant();
	Game.zoneMonsters = SetEnemy();
	Game.currentZone = 0;
	Game.running = 1;
}
//*menu

//Zones communes
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

void ZoneFight() {
	//ici on vien boucler le fight avec les monstre de la zone Game.MonsterZone(Game.currentZone)
	int fight = true;
	std::vector<EnemieCara> monsters = Game.zoneMonsters[Game.currentZone];

	while (fight) {
		//on tire des chara au hazard
		int randIndex = GenerateRandomNumber(0, monsters.size());
		EnemieCara enemyCara = monsters[randIndex];

		//on vien generer le monstre "unique"
		int lvl = GenerateRandomNumber(enemyCara.minLvl, enemyCara.maxLvl);
		int dhp = GenerateRandomNumber(enemyCara.minDHp, enemyCara.maxDHp);
		int dmoney = GenerateRandomNumber(enemyCara.minDMoney, enemyCara.maxDMoney);

		//##TODO
		//ajouter une arme au monstre -> nouveaux constructeur, liste d'arme par zone, rnd de l'arme, on passe en paramettre l'arme

		//on cree le monstre
		Enemy enemy(enemyCara.name, lvl * 10 + dhp, lvl * 10 + dhp, dmoney, lvl);
		int isAlive = true;
		std::vector<std::string> monsterAction;
		while (isAlive) {
			std::vector < std::string > buttons = { "Attaquer", "Ouvrire le menu", "Fuir" };
			int action = -1;
			int choice = 0;

			//action du joueur
			while (action != '\r' && action != ' ') {
				system("cls");
				PrintMonsterArt(enemy.GetName());
				enemy.DisplayStats();
				for (const std::string& act : monsterAction) {
					GameManager::GlobalCenterPadding(act.length());
					std::cout << act << std::endl;
				}
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
				Game.player->Attack(enemy);
				if (enemy.GetHp() <= 0) {
					std::cout << "Vous avez vaincu le " << enemy.GetName() << "!" << std::endl;
					Game.player->GainXp(enemy.GetLevel() * 20);
					Game.player->AddMoney(enemy.GetMoney());
					isAlive = false;
				}
				break;
			case(1):
				menu();
				break;
			case(2):
				isAlive = false;
				break;
			}
			//action du monstre
			if (enemy.GetHp() > 0 && isAlive) {
				enemy.Attack(*Game.player);
				monsterAction.clear();
				monsterAction.push_back("Le " + enemy.GetName() + " vous a attaque !");
				monsterAction.push_back("Vous subissez " + std::to_string(enemy.GetEquippedWeapon() ? enemy.GetEquippedWeapon()->GetDamage() : 1) + " degats !");
				if (Game.player->GetHp() <= 0) {
					std::cout << "Vous avez ete vaincu par le " << enemy.GetName() << "!" << std::endl;
					fight = false;
					isAlive = false;
					break;
				}
			}


		}
		std::vector<std::string> fightButtons = { "Continuer a combattre", "Retourner au village" };
		int fightAction = -1;
		int fightChoice = 0;
		while (fightAction != '\r' && fightAction != ' ') {
			system("cls");
			Game.ButtonPrint(fightButtons, fightChoice);
			fightAction = _getch();
			switch (fightAction)
			{
			case('z'):
				fightChoice--;
				if (fightChoice < 0) fightChoice = fightButtons.size() - 1;
				break;

			case('s'):
				fightChoice++;
				if (fightChoice >= fightButtons.size()) fightChoice = 0;
				break;
			}
			
		}
		switch (fightChoice)
		{
		case(0):
			break;
		case(1):
			fight = false;
			break;
		}

	}

}
//*Zones communes

//Zones
void history() {
	std::cout << "Tu vis dans un petit village isole, Val d Aubepine, cache au creux des collines brumeuses du royaume d Eldara.\nC’est un lieu paisible, entoure de champs d orge doree, de rivieres claires et d une foret ancienne que les anciens appellent la Sylve - Grise.\nLes habitants vivent simplement : chasseurs, forgerons, herboristes… tout le monde se connait.\nMais depuis quelques semaines, une etrange lueur verte apparait chaque nuit au bord de la foret.\nLe betail tombe malade, et des murmures parlent de creatures rodant sous la lune." << std::endl;
	std::string name;
	std::cout << "Quel est ton nom aventurier ?" << std::endl;
	std::cin >> name;

	// Allocation dynamique du joueur. Le pointeur est stocké dans GameManager.
	Game.player = new Player(name, 100, 100, 5000, 1);

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
		menu();
		break;
	case(1):
		Merchants();
		break;
	case(2):
		ZoneFight();
		break;
	case(3):
		Game.ChangeZone(-2);
		break;
	}


}
//*Zone



int main() {

	Setup();

	history();


	while (Game.running == 1) {
		switch (Game.currentZone) {
		case(-2):
			quit();
			break;
		case(0):
			village();
			break;
		}
	}


	delete Game.player;
	std::cout << "Merci d'avoir jouer a MEDIEVAL SHOPING ADVENTURE par Baudoin Eliott" << std::endl;
	return 0;
}