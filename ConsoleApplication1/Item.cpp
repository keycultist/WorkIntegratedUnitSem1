#include "Item.h"
#include <string>


Item::Item() {

}



void Item::SetItemList() {

	static const std::string ClasslessItemList[17] = {
		// commons
		"Tough Leather Tunic (Common)",
		"Minor Healing Flask (Common)",
		"Minor Flask Of Strength (Common)",
		"Minor Flask Of Dexterity (Common)",

		// uncommons
		"Chainmail Chestplate (Uncommon)",
		"Medium Healing Flask (Uncommon)",
		"Medium Flask Of Courage (Uncommon)",
		"Medium Flask Of Dexterity (Uncommon)",

		// rares
		"Knight's Chestplate (Rare)",
		"Large Healing Flask (Rare)",
		"Large Flask Of Determination (Rare)",
		"Large Flask Of Dexterity (Rare)",

		// epics
		"Royal Guard's Chestplate (Epic)",
		"Invigorating Healing Flask (Epic)",
		"Empowering Flask Of Resolve (Epic)",
		"Prowessed Flask Of Dexterity (Epic)",

		// legendary
		"Titanic Chestplate Of The Collosal (LEGENDARY)"

	};


	WarriorWeaponList[0] = "Splintered Wooden Sword (Common)";
	WarriorWeaponList[1] = "Rusty Iron Sword (Common)";
	WarriorWeaponList[2] = "Steel Longsword (Uncommon)";
	WarriorWeaponList[3] = "Titanium Heavyblade (Rare)";
	WarriorWeaponList[4] = "Enchanted Greatsword (Epic)";
	WarriorWeaponList[5] = "Blessed Blade Of The Holy (LEGENDARY)";
	WarriorWeaponList[6] = "Derelictus (SECRET)";

	MageWeaponList[0] = "Splintered Wooden Staff (Common)";
	MageWeaponList[1] = "Rusty Iron Staff (Common)";
	MageWeaponList[2] = "Steel Staff (Uncommon)";
	MageWeaponList[3] = "Adamantite Staff (Rare)";
	MageWeaponList[4] = "Enchanted Staff (Epic)";
	MageWeaponList[5] = "Arcanic Staff Of The Realms (LEGENDARY)";
	MageWeaponList[6] = "Celestial (SECRET)";

	HunterWeaponList[0] = "Splintered Wooden Bow (Common)";
	HunterWeaponList[1] = "Rusty Iron Bow (Common)";
	HunterWeaponList[2] = "Steel Shortbow (Uncommon)";
	HunterWeaponList[3] = "Platinum Longbow (Rare)";
	HunterWeaponList[4] = "Enchanted Longbow (Epic)";
	HunterWeaponList[5] = "Empyreal Longbow Of The Vale (LEGENDARY)";
	HunterWeaponList[6] = "Tailwind (SECRET)";





	if (ItemPlayerClass == "Warrior") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = WarriorWeaponList[i + 1];
		}
		ItemList[22] = WarriorWeaponList[6];
	}

	if (ItemPlayerClass == "Mage") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = MageWeaponList[i + 1];
		}
		ItemList[22] = MageWeaponList[6];
	}

	if (ItemPlayerClass == "Hunter") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = HunterWeaponList[i + 1];
		}
		ItemList[22] = HunterWeaponList[6];
	}

	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 4; j++) { // 4 classless items per rarity
			ItemList[j + 1 + 5 * i] = ClasslessItemList[4 * i + j];
		}
	}

	ItemList[21] = ClasslessItemList[16]; // 5th rarity, 1 legendary classless item



}



void Item::SetItemDescriptionList() {
	static const std::string ClasslessItemDescriptionList[17] = {
		// commons
		"25 HP | A ragged tunic made from rather old, tattered leather. Well, better than nothing.",
		"+15 HP | A small flask with a few drops of some rejuvenating brew, though it smells quite repulsive.",
		"+2 Power | A small flask with a few drops of some dark concoction. It seems empowering.",
		"+10% Crit Chance | A small flask with a few drops of smooth light liquid. Is it lemonade?",

		// uncommons
		"40 HP | An old chestplate made with chainmail. Seems durable enough to withstand a few slashes.",
		"+30 HP | A decently sized flask with some rejuvenating brew. Tastes... bearable enough.",
		"+4 Power | A decently sized flask with a blood red concoction. It seems like it would fuel you with power.",
		"+20% Crit Chance | A decently sized flask with a light yellow brew. It really resembles lemonade.",

		// rares
		"70 HP | A solid metal chestplate worn by knights. It's very durable and will probably protect you from quite a lot.",
		"+50 HP | A large flask of a rejuvenating brew. It's smell and taste is rather pleasant.",
		"+6 Power | A large flask with a blazing orange concoction. Strong potion, for strong warriors.",
		"+35% Crit Chance | A large flask of a clear light yellow brew. Are we sure it isn't just lemonade?",

		// epics
		"150 HP | A gilded chestplate donned by the royal guards, strong enough to withstand blows from the strongest foes.",
		"+130 HP | A flask of invigorating brew. The essence of life - it recovers your life forced substantially.",
		"+10 Power | A flask of power incarnate, drinking it empowers you with collosal power.",
		"+50% Crit Chance | A flask of embodied prowess. Actually, it's just lemonade.",

		// legendary
		"250 HP | A legendary chestplate forged from deep within The Collosus - The Embodiment of Tenacity. Legend has it that this chestplate could withstand even the wrath of the gods."
	};





	if (ItemPlayerClass == "Warrior") {
		static const std::string WarriorWeaponDescriptionList[7] = {
			"1 Power | Seems roughly forged out of a wooden plank...",
			"2 Power | An old iron sword, rusted throughout. Seems brittle.",
			"4 Power | A knight's longsword, forged cleanly from steel.",
			"7 Power | A large heavyblade crafted with strong titanium.",
			"13 Power | A greatsword enchanted with arcanic magic. It radiates warmly in your hands.",
			"20 Power | A blade blessed by the heavens. It emanates holy power, strong enough to challenge even the collosal titans.",
			"35 Power | Forsaken by the world."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = WarriorWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = WarriorWeaponDescriptionList[6];
	}

	if (ItemPlayerClass == "Mage") {
		static const std::string MageWeaponDescriptionList[7] = {
			"1 Power | A shabby stick. It's possible to imbue some magic into this, probably.",
			"2 Power | A stave made of iron, rusted throughout.",
			"4 Power | A steel staff, decent for casting spells.",
			"7 Power | An adamantite staff. It has a decent magic capacity, suitable for novice mages.",
			"13 Power | A magic staff enchanted by great mages. You can sense the magic imbued emanating strongly from it.",
			"20 Power | A legendary stave that wields worldly arcanic power, even the greatest order of mages struggle to wield this.",
			"35 Power | The Sun, The Moon, The Stars."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = MageWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = MageWeaponDescriptionList[6];
	}

	if (ItemPlayerClass == "Hunter") {
		static const std::string HunterWeaponDescriptionList[7] = {
			"1 Power | Roughly shaped from a old piece of wood. Atleast it can shoot arrows.",
			"2 Power | An iron bow, worn out to time, covered in rust.",
			"4 Power | A shortbow forged of steel. In the right hands, it could be decently powerful.",
			"7 Power | A longbow made of platinum. Used by archers across the land, great at precision and power.",
			"13 Power | A longbow imbued with magic. It wields great power, transferring arcanic magic to arrows shot.",
			"20 Power | A legendary bow from the Empyreal Valleys. Imbued with the essence of winds, it unleashes immense power with every shot.",
			"35 Power | Clouds over the moon, wind over the flowers."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = HunterWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = HunterWeaponDescriptionList[6];
	}

	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 4; j++) { // 4 classless items per rarity
			ItemDescriptionList[j + 1 + 5 * i] = ClasslessItemDescriptionList[4 * i + j];
		}
	}

	ItemDescriptionList[21] = ClasslessItemDescriptionList[16]; // 5th rarity, 1 legendary classless item
}





void Item::SetItemCostList() {
	// common cost 3
	for (int i = 0; i < 5; i++) {
		ItemCostList[i] = 3;
	}

	// uncommon cost 8
	for (int i = 0; i < 5; i++) {
		ItemCostList[i + 5] = 8;
	}

	// rare cost 15
	for (int i = 0; i < 5; i++) {
		ItemCostList[i + 10] = 15;
	}

	// epic cost 25
	for (int i = 0; i < 5; i++) {
		ItemCostList[i + 15] = 25;
	}

	// legendary 40
	for (int i = 0; i < 2; i++) {
		ItemCostList[i + 20] = 40;
	}

	// secret 1
	ItemCostList[22] = 1;
}



void Item::SetItemTypeList() {
	for (int i = 0; i < 4; i++) {
		ItemTypeList[5 * i] = "Weapon";
		ItemTypeList[5 * i + 1] = "Armor";
		ItemTypeList[5 * i + 2] = "Consumable";
		ItemTypeList[5 * i + 3] = "Consumable";
		ItemTypeList[5 * i + 4] = "Consumable";
	}
	ItemTypeList[20] = "Weapon";
	ItemTypeList[21] = "Armor";

	ItemTypeList[22] = "Weapon";

}



void Item::SetItemPlayerClass(std::string c) {
	ItemPlayerClass = c;
}




std::string Item::GetItemListIndex(int index) {
	return ItemList[index];
}




std::string Item::GetItemDescriptionListIndex(int index) {
	return ItemDescriptionList[index];
}




int Item::GetItemCostListIndex(int index) {
	return ItemCostList[index];
}



std::string Item::GetItemTypeListIndex(int index) {
	return ItemTypeList[index];
}






std::string Item::GetWarriorWeaponListIndex(int index) {
	return WarriorWeaponList[index];
}




std::string Item::GetMageWeaponListIndex(int index) {
	return MageWeaponList[index];
}




std::string Item::GetHunterWeaponListIndex(int index) {
	return HunterWeaponList[index];
}