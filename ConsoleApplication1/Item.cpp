#include "Item.h"
#include <string>
#include <iostream>

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
		"Titanic Chestplate Of The Colossal (LEGENDARY)"

	};


	WarriorWeaponList[0] = "Splintered Wooden Sword (Common)";
	WarriorWeaponList[1] = "Rusty Iron Sword (Common)";
	WarriorWeaponList[2] = "Steel Longsword (Uncommon)";
	WarriorWeaponList[3] = "Adamantite Heavyblade (Rare)";
	WarriorWeaponList[4] = "Enchanted Greatsword (Epic)";
	WarriorWeaponList[5] = "Blessed Blade Of The Holy (LEGENDARY)";
	WarriorWeaponList[6] = "Derelictus (SECRET)";

	MageWeaponList[0] = "Splintered Wooden Staff (Common)";
	MageWeaponList[1] = "Rusty Iron Staff (Common)";
	MageWeaponList[2] = "Steel Staff (Uncommon)";
	MageWeaponList[3] = "Mithril Staff (Rare)";
	MageWeaponList[4] = "Enchanted Staff (Epic)";
	MageWeaponList[5] = "Arcanic Staff Of The Realms (LEGENDARY)";
	MageWeaponList[6] = "Celestial (MYTHIC)";

	HunterWeaponList[0] = "Splintered Wooden Bow (Common)";
	HunterWeaponList[1] = "Rusty Iron Bow (Common)";
	HunterWeaponList[2] = "Steel Shortbow (Uncommon)";
	HunterWeaponList[3] = "Platinum Longbow (Rare)";
	HunterWeaponList[4] = "Enchanted Longbow (Epic)";
	HunterWeaponList[5] = "Empyreal Longbow Of The Vale (LEGENDARY)";
	HunterWeaponList[6] = "Gaia (MYTHIC)";

	AssassinWeaponList[0] = "Splintered Wooden Dagger (Common)";
	AssassinWeaponList[1] = "Rusty Iron Dagger (Common)";
	AssassinWeaponList[2] = "Steel Dagger (Uncommon)";
	AssassinWeaponList[3] = "Titanium Dagger (Rare)";
	AssassinWeaponList[4] = "Enchanted Dagger (Epic)";
	AssassinWeaponList[5] = "Zephyrous Dagger Of The Acrobat (LEGENDARY)";
	AssassinWeaponList[6] = "Archangel (MYTHIC)";

	BerserkerWeaponList[0] = "Splintered Wooden Battleaxe (Common)";
	BerserkerWeaponList[1] = "Rusty Iron Battleaxe (Common)";
	BerserkerWeaponList[2] = "Steel Battleaxe (Uncommon)";
	BerserkerWeaponList[3] = "Tungsten Battleaxe (Rare)";
	BerserkerWeaponList[4] = "Enchanted Battleaxe (Epic)";
	BerserkerWeaponList[5] = "Draconic Battleaxe Of The Molten (LEGENDARY)";
	BerserkerWeaponList[6] = "Annihilation (MYTHIC)";

	SummonerWeaponList[0] = "Torn Grimoire (Common)";
	SummonerWeaponList[1] = "Faded Grimoire (Common)";
	SummonerWeaponList[2] = "Emberleaf Grimoire (Uncommon)";
	SummonerWeaponList[3] = "Moonstone Grimoire (Rare)";
	SummonerWeaponList[4] = "Mystic Grimoire (Epic)";
	SummonerWeaponList[5] = "Celestial Grimoire Of The Enigmatic (LEGENDARY)";
	SummonerWeaponList[6] = "Providence (MYTHIC)";

	RitualistWeaponList[0] = "Broken Ritualist Knife (Common)";
	RitualistWeaponList[1] = "Rusty Ritualist Knife (Common)";
	RitualistWeaponList[2] = "Imbued Ritualist Knife (Uncommon)";
	RitualistWeaponList[3] = "Bloodstone Totem (Rare)";
	RitualistWeaponList[4] = "Infernal Flare Totem (Epic)";
	RitualistWeaponList[5] = "Sanguine Totem Of The Acolyte (LEGENDARY)";
	RitualistWeaponList[6] = "Resonance (MYTHIC)";



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

	if (ItemPlayerClass == "Assassin") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = AssassinWeaponList[i + 1];
		}
		ItemList[22] = AssassinWeaponList[6];
	}

	if (ItemPlayerClass == "Berserker") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = BerserkerWeaponList[i + 1];
		}
		ItemList[22] = BerserkerWeaponList[6];
	}

	if (ItemPlayerClass == "Summoner") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = SummonerWeaponList[i + 1];
		}
		ItemList[22] = SummonerWeaponList[6];
	}

	if (ItemPlayerClass == "Ritualist") {
		for (int i = 0; i < 5; i++) {
			ItemList[i * 5] = RitualistWeaponList[i + 1];
		}
		ItemList[22] = RitualistWeaponList[6];
	}

	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 4; j++) { // 4 classless items per rarity
			ItemList[j + 1 + 5 * i] = ClasslessItemList[4 * i + j];
		}
	}

	ItemList[21] = ClasslessItemList[16]; // 5th rarity, 1 legendary classless item



}



void Item::SetWeaponList() {
	if (ItemPlayerClass == "Warrior") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = WarriorWeaponList[i];
		}
	}
	if (ItemPlayerClass == "Mage") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = MageWeaponList[i];
		}
	}
	if (ItemPlayerClass == "Hunter") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = HunterWeaponList[i];
		}
	}
	if (ItemPlayerClass == "Assassin") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = AssassinWeaponList[i];
		}
	}
	if (ItemPlayerClass == "Summoner") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = SummonerWeaponList[i];
		}
	}
	if (ItemPlayerClass == "Ritualist") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = RitualistWeaponList[i];
		}
	}
	if (ItemPlayerClass == "Berserker") {
		for (int i = 0; i < 7; i++) {
			WeaponList[i] = BerserkerWeaponList[i];
		}
	}
}

void Item::SetEquipmentStatsList() {
	WeaponPowerList[0] = 1;
	WeaponPowerList[1] = 2;
	WeaponPowerList[2] = 4;
	WeaponPowerList[3] = 7;
	WeaponPowerList[4] = 13;
	WeaponPowerList[5] = 20;
	WeaponPowerList[6] = 35;
	
	ArmorHPList[0] = 25;
	ArmorHPList[1] = 50;
	ArmorHPList[2] = 90;
	ArmorHPList[3] = 175;
	ArmorHPList[4] = 250;
	
	ArmorDefList[0] = 5;
	ArmorDefList[1] = 12;
	ArmorDefList[2] = 22;
	ArmorDefList[3] = 35;
	ArmorDefList[4] = 50;
}

int Item::GetWeaponPowerListIndex(int index) {
	return WeaponPowerList[index];
}

int Item::GetArmorHPListIndex(int index) {
	return ArmorHPList[index];
}

int Item::GetArmorDefListIndex(int index) {
	return ArmorDefList[index];
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
		"+10 Power | A flask of power incarnate, drinking it empowers you with Colossal power.",
		"+50% Crit Chance | A flask of embodied prowess. Actually, it's just lemonade.",

		// legendary
		"250 HP | A legendary chestplate forged from deep within The Colossus - The Embodiment of Tenacity. Legend has it that this chestplate could withstand even the wrath of the gods."
	};





	if (ItemPlayerClass == "Warrior") {
		static const std::string WarriorWeaponDescriptionList[7] = {
			"1 Power | Seems roughly forged out of a wooden plank...",
			"2 Power | An old iron sword, rusted throughout. Seems brittle.",
			"4 Power | A knight's longsword, forged cleanly from steel.",
			"7 Power | A large heavyblade crafted with strong titanium.",
			"13 Power | A greatsword enchanted with arcanic magic. It radiates warmly in your hands.",
			"20 Power | A blade blessed by the heavens. It emanates holy power, strong enough to challenge even the colossal titans.",
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



	if (ItemPlayerClass == "Assassin") {
		static const std::string AssassinWeaponDescriptionList[7] = {
			"1 Power | Carved from a broken branch. Sharp enough to scratch, better than bare hands.",
			"2 Power | A small iron dagger, worn out and rusted. It's fragile and dull.",
			"4 Power | A finely forged steel dagger. Good ol' reliable.",
			"7 Power | An agile blade forged of titanium. It glints with an edge that pierces armor.",
			"13 Power | It hums with latent energy. The blade glows faintly, with ethereal power.",
			"20 Power | Infused with the essence of the wind. Fast, deadly, silent. Agility incarnate.",
			"35 Power | Celestial forces, Radiant and Pure."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = AssassinWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = AssassinWeaponDescriptionList[6];
	}

	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 4; j++) { // 4 classless items per rarity
			ItemDescriptionList[j + 1 + 5 * i] = ClasslessItemDescriptionList[4 * i + j];
		}
	}



	if (ItemPlayerClass == "Berserker") {
		static const std::string BerserkerWeaponDescriptionList[7] = {
			"1 Power | Made from the limb of a broken tree, it's heavy and blunt.",
			"2 Power | A dusty, rusted battleaxe made of iron. Its edges are rough, but still viable for cleaving.",
			"4 Power | A sturdy steel battleaxe made for battle, capable of dealing relentless strikes.",
			"7 Power | A heavy tungsten battleaxe, strong enough to shatter defenses.",
			"13 Power | A battleaxe imbued with magical power. Flames flicker along its blade, fueling rage.",
			"20 Power |	Forged in the molten height's dragonfire, the battleaxe burns with infernal fury. It's unmatched power scorches the Earth and rends souls.",
			"35 Power | The Fury Of A Thousand Suns."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = BerserkerWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = BerserkerWeaponDescriptionList[6];
	}

	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 4; j++) { // 4 classless items per rarity
			ItemDescriptionList[j + 1 + 5 * i] = ClasslessItemDescriptionList[4 * i + j];
		}
	}



	if (ItemPlayerClass == "Summoner") {
		static const std::string SummonerWeaponDescriptionList[7] = {
			"1 Power | A tattered book, barely holding its pages together. The spells, faded, but its knowledge lingers.",
			"2 Power | An old grimoire with faded ink and brittle pages. Faint magic still capable of sparking minor incantations.",
			"4 Power | Enchanted Emberleaf vines twine around, a grimoire pulsing with arcanic power.",
			"7 Power | A tome inlaid with celestial moonstone, channeling lunar energy.",
			"13 Power | The grimoire emanates the wisdom of ancient sorcerers. Its pages filled with spells that challenge reality.",
			"20 Power | Gifted by the stars, hiding the secrets of the cosmos. Its celestial incantations strong enough to bend fate itself.",
			"35 Power | Divine Radiance, Holy Flames."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = SummonerWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = SummonerWeaponDescriptionList[6];
	}

	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 4; j++) { // 4 classless items per rarity
			ItemDescriptionList[j + 1 + 5 * i] = ClasslessItemDescriptionList[4 * i + j];
		}
	}



	if (ItemPlayerClass == "Ritualist") {
		static const std::string RitualistWeaponDescriptionList[7] = {
			"1 Power | A cracked knife used for sacred rites. Its power drained, yet it echoes of old ceremonies.",
			"2 Power | A small blade tarnished by time and blood. It whispers faintly of forgotten rituals and sacrifices.",
			"4 Power | A knife still pulsing with ritualist magic, imbued by ancient rites. Capable of cutting through flesh and spirit.",
			"7 Power | A totem made with a core of bloodstone, imbued with ancestral power. It channels power from the sacrificed.",
			"13 Power | Wreathed in infernal flames, its power scorches enemies with the spirits of the sacrificed.",
			"20 Power | The totem bleeds with otherworldly powers, forged of the bones and spirit of those sacrificed. It channels forbidden magic from ancient rites.",
			"35 Power | Bounded Souls Of The Fallen."
		};

		for (int i = 0; i < 5; i++) {
			ItemDescriptionList[i * 5] = RitualistWeaponDescriptionList[i + 1];
		}
		ItemDescriptionList[22] = RitualistWeaponDescriptionList[6];
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

std::string Item::GetItemPlayerClass() {
	return ItemPlayerClass;
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














std::string Item::GetWeaponListIndex(int index) {
	return WeaponList[index];
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

std::string Item::GetAssassinWeaponListIndex(int index)
{
	return AssassinWeaponList[index];
}

std::string Item::GetBerserkerWeaponListIndex(int index)
{
	return BerserkerWeaponList[index];
}

std::string Item::GetSummonerWeaponListIndex(int index)
{
	return SummonerWeaponList[index];
}

std::string Item::GetRitualistWeaponListIndex(int index)
{
	return RitualistWeaponList[index];
}
