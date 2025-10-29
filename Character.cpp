#include "Character.h"
#include "Item.h"
#include "Items.h"
#include<iostream>
#include <algorithm>
#include<string>
#include "GameManager.h"
#include <conio.h>


std::vector<std::string> GetItemArt(Item* item) {
	if (dynamic_cast<Weapon*>(item)) {
		return {
			"      .        ",
			"     / \\       ",
			"     | |       ",
			"     | |       ",
			"     |.|       ",
			"     |:|       ",
			"    `--8--'    ",
			"      8        ",
			"Arme "
		};
	}
	if (dynamic_cast<HealPotion*>(item) || dynamic_cast<PoisonPotion*>(item)) {
		return {
			"      _____    ",
			"     `.___,'   ",
			"      (___)    ",
			"      <   >    ",
			"       ) (     ",
			"      /`-.\\    ",
			"     /     \\   ",
			"    / _    _\\  ",
			"Potion"
		};
	}
	if (dynamic_cast<Armor*>(item)) {
		return {
			" \\_              _/ ",
			" ] --__________-- [ ",
			" |       ||       | ",
			" \\       ||       / ",
			"  [      ||      ]  ",
			"  |______||______|  ",
			"  |------..------|  ",
			"  ]      ||      [  ",
			"Armure"
		};
	}
	// Par défaut, pour tout autre objet
	return {
		" [?]  ",
		" ( )  ",
		"  |   ",
		" /\\   ",
		"Objet "
	};
}

void PrintInventoryArt() {

	// Centrage de tout le bloc sur l'écran
	GameManager::GlobalCenterPadding(60);
	std::cout << "+==========================================================+" << std::endl;
	GameManager::GlobalCenterPadding(60);
	std::cout << "|  _____                           _          _            |" << std::endl;
	GameManager::GlobalCenterPadding(60);
	std::cout << "|  \\_   \\ _ __ __   __ ___  _ __  | |_  __ _ (_) _ __  ___ |" << std::endl;
	GameManager::GlobalCenterPadding(60);
	std::cout << "|   / /\\/| '_ \\\\ \\ / // _ \\| '_ \\ | __|/ _` || || '__|/ _ \\|" << std::endl;
	GameManager::GlobalCenterPadding(60);
	std::cout << "|/\\/ /_  | | | |\\ V /|  __/| | | || |_| (_| || || |  |  __/|" << std::endl;
	GameManager::GlobalCenterPadding(60);
	std::cout << "|\\____/  |_| |_| \\_/  \\___||_| |_| \\__|\\___/ |_||_|   \\___||" << std::endl;
	GameManager::GlobalCenterPadding(60);
	std::cout << "+==========================================================+" << std::endl;
	std::cout << "\n"; // Ligne vide pour séparer du reste
}

void PrintCenteredLine(int totalWidth, const std::string& leftBorder, const std::string& rightBorder, const std::string& text) {
	// 1. Centrage du BLOC entier sur l'écran
	GameManager::GlobalCenterPadding(120);

	// 2. Centrage du TEXTE DANS le BLOC (ancien code)
	int textLength = text.length();
	int availableWidth = totalWidth - leftBorder.length() - rightBorder.length();

	// ... (le reste du calcul de paddingLeft/paddingRight reste inchangé) ...
	int padding = availableWidth - textLength;
	int paddingLeft = padding / 2;
	int paddingRight = padding - paddingLeft;

	std::cout << leftBorder;
	for (int i = 0; i < paddingLeft; ++i) {
		std::cout << " ";
	}
	std::cout << text;
	for (int i = 0; i < paddingRight; ++i) {
		std::cout << " ";
	}
	std::cout << rightBorder << std::endl;
}

int Character::AddItem(Item* i)
{
	if (inventory.size() < maxSizeInv)
		inventory.push_back(i);

	else {
		std::cout << "inventaire plein, veillez faire du tri" << std::endl;
		return 1;
	}
	return 0;
}

void Character::SupprItem(Item* item)
{
	for (size_t i = 0; i < inventory.size(); ++i)
	{
		
		if (inventory[i] == item)
		{
			
			delete inventory[i];

			inventory.erase(inventory.begin() + i);
			return;
		}
	}
}

void Character::EquipItem()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << inventory[i]->GetName() << ", a une valeur de: " << inventory[i]->GetValue() << ".\n" << inventory[i]->GetDesc() << "\n pour equiper cette item, ecrire " << i << std::endl;
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	int value;
	std::cin >> value;
	if (value < 0 || value >= inventory.size())
	{
		std::cout << "Mauvais index" << std::endl;
		return;
	}
	int choice;
	std::cout << "Où voulez vous l'equiper ? (1 = Arme, 2 = Armor)" << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		EquipThisItem(dynamic_cast<Weapon*>(inventory[value]));
	}


}

void Character::EquipThisItem(Weapon* item)
{
	equipItem = item;


}

bool Character::ExecuteItemAction(Item* item, const std::string& action) {
	if (action == "Utiliser la potion") {
		if (Potion* p = dynamic_cast<Potion*>(item)) {
			p->Use(this);
			SupprItem(item);
		}
	}
	else if (action == "Equiper l'arme") {
		if (Weapon* w = dynamic_cast<Weapon*>(item)) {
			EquipThisItem(w);
			std::cout << "Vous avez equipe l'arme: " << w->GetName() << std::endl;
		}
	}
	else if (action == "Desequiper l'arme") {
		if (equipItem == item) {
			equipItem = nullptr;
			std::cout << "Vous avez desequipe l'arme: " << item->GetName() << std::endl;
		}
	}
	else if (action == "Equiper l'armure") {
		if (Armor* a = dynamic_cast<Armor*>(item)) {
			// Logique pour equiper l'armure
			std::cout << "Vous avez equipe l'armure: " << a->GetName() << std::endl;
		}
	}
	else if (action == "Jeter l'item") {
		std::cout << "Vous avez jete l'item: " << item->GetName() << std::endl;
		SupprItem(item);
	}
	else if (action == "Retour a l'inventaire") {
		return false;
	}

	return false;
}

void Character::DisplayItemActions(Item* selectedItem) {
	system("cls");
	if (!selectedItem) 
		return;
	std::vector<std::string> actions;

	Weapon* w = dynamic_cast<Weapon*>(selectedItem);
	Armor* a = dynamic_cast<Armor*>(selectedItem);
	Potion* p = dynamic_cast<Potion*>(selectedItem);

	if (p) 
		actions.push_back("Utiliser la potion");
	else if (w) {
		if (selectedItem == equipItem)
			actions.push_back("Desequiper l'arme");
		else
			actions.push_back("Equiper l'arme");
	}
	else if (a) {
		actions.push_back("Equiper l'armure");
	}
	
	actions.push_back("Jeter l'item");
	actions.push_back("Retour a l'inventaire");

	int selectedAction = 0;
	int actionKey = -1;
	bool actionMenuActive = true;

	while (actionMenuActive) {
		system("cls");
		GameManager::GlobalCenterPadding(35);
		std::cout << "ACTIONS pour " << selectedItem->GetName() << ":\n";
		GameManager::ButtonPrint(actions, selectedAction);
		actionKey = _getch();
		switch (actionKey) {
		case('z'):
			selectedAction = (selectedAction > 0) ? selectedAction - 1 : actions.size() - 1;
			break;
		case('s'):
			selectedAction = (selectedAction < actions.size() - 1) ? selectedAction + 1 : 0;
			break;
		case('\r'): case(' '):
			actionMenuActive = ExecuteItemAction(selectedItem, actions[selectedAction]);
			break;
		}
	}


}

void Character::DisplayInv()
{
	const int LIST_WIDTH = 30;
	const int DETAIL_WIDTH = 43;
	const int TOTAL_WIDTH = LIST_WIDTH + 5 + DETAIL_WIDTH;

	
	const int DETAIL_ART_HEIGHT = 13;
	const int LINE_NAME = DETAIL_ART_HEIGHT + 0;
	const int LINE_VALUE = DETAIL_ART_HEIGHT + 1;
	const int LINE_STATS = DETAIL_ART_HEIGHT + 2;
	const int LINE_DESCRIPTION = DETAIL_ART_HEIGHT + 3;
	const int MAX_TOTAL_HEIGHT = DETAIL_ART_HEIGHT + 4;

	int selectedIndex = 0;
	bool inventoryActive = true;

	while (inventoryActive) {
		system("cls");
		PrintInventoryArt();

		std::vector<std::string> itemNames;
		for (Item* item : inventory) {
			itemNames.push_back(item->GetName());
		}
		itemNames.push_back("Fermer l'inventaire");

		Item* selectedItem = nullptr;
		std::vector<std::string> itemArt;
		std::string selectedStatus = "";

		if (selectedIndex < inventory.size()) {
			selectedItem = inventory[selectedIndex];
			itemArt = GetItemArt(selectedItem);
			if (selectedItem == equipItem) selectedStatus = " (EQUIPE)";
		}

		
		GameManager::GlobalCenterPadding(TOTAL_WIDTH);
		std::cout << "+============================+     +========================================+\n";

		
		size_t currentHeight = std::max(itemNames.size(), (size_t)MAX_TOTAL_HEIGHT);
		for (size_t i = 0; i < currentHeight; ++i) {

			GameManager::GlobalCenterPadding(TOTAL_WIDTH);

			
			if (i < itemNames.size()) {

				int paddingCount = 24 - itemNames[i].length() - selectedStatus.length();

				if (i == selectedIndex) {
					std::cout << "\033[33;40m";
					std::cout << "| > " << itemNames[i] << selectedStatus;
				}
				else {
					std::cout << "\033[0m";
					std::cout << "|   " << itemNames[i];
					if (i != itemNames.size()-1) {
						for (int i = 0; i < selectedStatus.length(); ++i) {
							std::cout << " ";
						}
					}
					else if (selectedStatus != "")std::wcout << "     ";

				}

				for (int j = 0; j < paddingCount; j++) {
					std::cout << " ";
				}
				std::cout << "\033[0m |";

			}
			else {
				std::cout << "|                            |";
			}

			std::cout << "     ";

			
			if (selectedItem) {
				std::cout << "|";

				
				if (i < DETAIL_ART_HEIGHT && i < itemArt.size()) {
					std::string line = itemArt[i];
					int centerPad = (DETAIL_WIDTH - 2 - line.length()) / 2;
					for (int p = 0; p < centerPad; ++p) std::cout << " ";
					std::cout << line;
					for (int p = 0; p < (DETAIL_WIDTH - 2 - line.length() - centerPad); ++p) std::cout << " ";
				}
				
				else if (i == LINE_NAME) {
					std::string detail = std::string("Nom: ") + selectedItem->GetName() + selectedStatus;
					std::cout << " " << detail;
					for (int p = 0; p < DETAIL_WIDTH - 3 - detail.length(); ++p) std::cout << " ";
				}
				
				else if (i == LINE_VALUE) {
					std::string detail = "Valeur: " + std::to_string(selectedItem->GetValue()) + " Or";
					std::cout << " " << detail;
					for (int p = 0; p < DETAIL_WIDTH - 3 - detail.length(); ++p) std::cout << " ";
				}
				
				else if (i == LINE_STATS) {
					std::string detail = "";
					if (Weapon* w = dynamic_cast<Weapon*>(selectedItem)) {
						
						detail = "Degats: " + std::to_string(w->GetDamage()) + std::string(" | Durabilite: ") + std::to_string(w->GetDurabilite());
					}
					else if (Armor* a = dynamic_cast<Armor*>(selectedItem)) {
					
						detail = "Armure: " + std::to_string(a->GetArmorPoint()) + std::string(" | Durabilite: ") + std::to_string(a->GetDurability()); // (utilise le membre public/protege)
					}
					else if (Potion* p = dynamic_cast<Potion*>(selectedItem)) {
						detail = std::string("Effet: ") + (dynamic_cast<HealPotion*>(p) ? "Soins" : "Poison") + " " + std::to_string(p->GetValue());
					}

					if (!detail.empty()) {
						std::cout << " " << detail;
						for (int p = 0; p < DETAIL_WIDTH - 3 - detail.length(); ++p) std::cout << " ";
					}
					else {
						std::cout << "                                         ";
					}
				}
				else if (i == LINE_DESCRIPTION) {
					std::string detail = std::string("Description: ") + selectedItem->GetDesc();
					std::cout << " " << detail;
					for (int p = 0; p < DETAIL_WIDTH - 3 - detail.length(); ++p) std::cout << " ";
				}
				else {
					std::cout << "                                         ";
				}
				std::cout << "|";
			}
			else {
				std::cout << "|                                         |";
			}

			std::cout << "\n";
		}

		
		GameManager::GlobalCenterPadding(TOTAL_WIDTH);
		std::cout << "+============================+     +========================================+\n";

		
		int key = _getch();

		switch (key) {
		case 'z':
			selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : itemNames.size() - 1;
			break;

		case 's':
			selectedIndex = (selectedIndex < itemNames.size() - 1) ? selectedIndex + 1 : 0;
			break;

		case '\n': case ' ':
			if (selectedIndex == itemNames.size() - 1) {
				inventoryActive = false; 
			}
			else {
				
				DisplayItemActions(inventory[selectedIndex]);
			}
			break;

		default:
			break;
		}
	}
}

void Character::DisplayStats()
{

	int nameLength = std::strlen(name.c_str()); 

	
	int totalWidth = 20 + nameLength;
	if (totalWidth < 30) {
		totalWidth = 30;
	}

	GameManager::GlobalCenterPadding(totalWidth);
	std::cout << "+";
	for (int i = 0; i < totalWidth - 2; i++) {
		std::cout << "=";
	}
	std::cout << "+" << std::endl;

	GameManager::GlobalCenterPadding(totalWidth);
	PrintCenteredLine(totalWidth, "| ", "|", "STATISTIQUES DE " + name);
	GameManager::GlobalCenterPadding(totalWidth);
	std::string levelText = "NIVEAU: " + std::to_string(level) + " | EXP: " + std::to_string(exp) + "/" + std::to_string(NextLevelExp);
	PrintCenteredLine(totalWidth, "| ", "|", levelText);

	
	int barInnerWidth = totalWidth - 6; 
	float healthRatio = (float)hp / maxHp;
	int filledBlocks = (int)(healthRatio * barInnerWidth);

	std::string healthBar = "[";
	for (int i = 0; i < barInnerWidth; ++i) {
		if (i < filledBlocks) {
			
			healthBar += "\033[32m#\033[0m";
		}
		else {
			healthBar += "\033[30m-\033[0m"; 
		}
	}
	healthBar += "]";

	GameManager::GlobalCenterPadding(totalWidth);
	PrintCenteredLine(totalWidth, "| ", " |", healthBar);


	GameManager::GlobalCenterPadding(totalWidth);
	std::string hpText = " (" + std::to_string(hp) + "/" + std::to_string(maxHp) + ") ";
	PrintCenteredLine(totalWidth, "|", "|", hpText);


	GameManager::GlobalCenterPadding(totalWidth);
	std::string moneyText = "OR: " + std::to_string(money);
	PrintCenteredLine(totalWidth, "|", "|", moneyText);


	GameManager::GlobalCenterPadding(totalWidth);
	std::cout << "+";
	for (int i = 0; i < totalWidth - 2; i++) {
		std::cout << "=";
	}
	std::cout << "+" << std::endl;
}

int Character::GetArmor() {
	return (Helmet ? Helmet->GetArmorPoint() : 0) +
		(Chestplate ? Chestplate->GetArmorPoint() : 0) +
		(Pants ? Pants->GetArmorPoint() : 0) +
		(Boots ? Boots->GetArmorPoint() : 0);
}

void Character::Attack(Character& target)
{
	if (equipItem) {
		target.Damage(equipItem->GetDamage());
		bool dead = equipItem->DecreaseDurability(target.GetArmor() / 10);
		if (dead) {
			std::cout << "Votre arme " << equipItem->GetName() << " s'est brisee !" << std::endl;
			SupprItem(equipItem);
			equipItem = nullptr;
		}
	}
	else 
		target.Damage(1);
}

void Character::Damage(int dmg)
{
	int armor = GetArmor();
	dmg -= armor;
	hp -= dmg;
}

void Character::Heal(int healValue)
{
	hp += healValue;
	if (hp > maxHp) hp = maxHp;
	std::cout << "Le personnage " << name << " a ete heal de " << healValue << ", il est maitenant a " << hp << std::endl;

}

void Character::GainXp(int xp)
{
	exp += xp;
	if (exp >= NextLevelExp) {
		LevelUp();
	}
}

void Character::LevelUp()
{
	level++;
	exp -= NextLevelExp;
	NextLevelExp = static_cast<int>(NextLevelExp * 1.5);
	maxHp += 20;
	hp = maxHp;
	std::cout << "Felicitation " << name << ", vous avez atteint le niveau " << level << " ! Votre vie maximale est desormais de " << maxHp << "." << std::endl;
}

Character::~Character()
{
	for (Item* item : inventory) {
		delete item;
	}
}