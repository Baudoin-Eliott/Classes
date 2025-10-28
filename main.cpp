#include "GameManager.h"
#include<iostream>


GameManager Game;

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

std::vector<Merchant> SetMerchant() {
	std::vector<Merchant> merchants;
	std::vector<Item> inv;
	inv.push_back(Item("Potion de soins", "Regenere 10 hp !", 5));
	inv.push_back(Item("Epee en fer", "Une meilleure epee que l'epee en bois !", 10));
	inv.push_back(Item("Potion de poison", "Enleve 10 hp !", 5));
	Merchant merchant("blob", inv);
	merchants.push_back(merchant);
	return merchants;

}

void history() {
	std::cout << "Tu vis dans un petit village isolé, Val d’Aubépine, caché au creux des collines brumeuses du royaume d’Eldara.\nC’est un lieu paisible, entouré de champs d’orge dorée, de rivières claires et d’une forêt ancienne que les anciens appellent la Sylve - Grise.\nLes habitants vivent simplement : chasseurs, forgerons, herboristes… tout le monde se connaît.\nMais depuis quelques semaines, une étrange lueur verte apparaît chaque nuit au bord de la forêt.\nLe bétail tombe malade, et des murmures parlent de créatures rôdant sous la lune." << std::endl;
	std::string name;
	std::cout << "Quel est ton nom aventurier ?" << std::endl;
	std::cin >> name;
	Player player(name, 100, 100, 5000);
	Game.player = player;
	std::cout << "bienvenue dans ces terres " << player.GetName() << "!" << std::endl;
}

void village() {
	int action = AskInt(1, 4, "que voulez vous faire ? (1 = ouvrire le menu, 2 = aller voir le marchant, 3 = aller a la foret, 4 = quitter)");
	switch (action) {
	case(1):
		Game.ChangeZone(-1);
		break;
	case(2):
		Game.merchants[Game.currentZone].BuyItem(&Game.player);
		break;
	case(3):
		Game.ChangeZone(1);
		break;
	case(4):
		Game.running = 0;
	}


}

void menu() {
	int action = AskInt(1, 4, "Que voulez vous faire ? (1 = afficher vos stats, 2 = afficher votre inventaire, 3 = equiper un item de votre inventaire, 4 = fermer le menu)");
	switch (action) {
	case(1):
		Game.player.DisplayStats();
		break;
	case(2):
		Game.player.DisplayInv();
		break;
	case(3):
		Game.player.EquipItem();
		break;
	default:
		Game.ChangeZone(Game.lastZone);
	}


}

void forest() {

}
int main() {

	Game.merchants = SetMerchant();
	Game.currentZone = 0;
	Game.running = 1;
	while (Game.running == 1) {
		switch (Game.currentZone) {
		case(-1):
			//menu
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

	std::cout << "Merci d'avoir jouer a MEDIEVAL SHOPING ADVENTURE par Baudoin Eliott" << std::endl;





	return 0;
}