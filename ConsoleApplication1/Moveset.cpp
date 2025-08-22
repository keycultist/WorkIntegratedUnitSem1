#include "Moveset.h"

Moveset::Move::Move(const std::string& N, int P, int H, const std::string& T) : MoveName(N), MoveStrength(P), Hits(H), MoveType(T)
{
}

void Moveset::SetMove(const Move& Move)
{
    Moves.push_back(Move);
}

void Moveset::ReplaceMove(const Move& newmove, int index)
{
    if (index >= 0 && index < Moves.size()) {
        Moves[index] = newmove; // replace existing move
    }
    else {
        std::cout << "Error!";
    }
}

Moveset::Move Moveset::GetMove(int index) const
{
    if (index >= 0 && index < Moves.size()) {
        return Moves[index];
    }
    return Move("Empty", 0, 0);
}

int Moveset::size() const {
    return Moves.size();
}

void Moveset::EnemyInit(const std::string Class)
{
    Moveset EnemyNameMoveset; //Found out this is not needed, i think.

    //SetMove(Move("MOVE NAME", STRENGTH, HITS, "TYPE"));

    //Add enemy movesets
    if (Class == "Cleaver") {
        EnemyNameMoveset.SetMove(Move("Lesser Cleave, Vertical", 1, 5, "Abyssal"));
		EnemyNameMoveset.SetMove(Move("Lesser Spear", 4, 1, "Abyssal"));
    }
    else if (Class == "Silent") {
        EnemyNameMoveset.SetMove(Move("Alas", 1, 2, "Physical"));
		EnemyNameMoveset.SetMove(Move("Mook", 1, 5, "Physical"));
    }
    else if (Class == "Mani") {
        EnemyNameMoveset.SetMove(Move("Ankle Splitter", 5, 1, "Physical"));
        EnemyNameMoveset.SetMove(Move("Rising Dragon", 1, 3, "Physical"));
    }
    else if (Class == "Resonant") {
        EnemyNameMoveset.SetMove(Move("Trails of Blue", 3, 1, "Physical"));
        EnemyNameMoveset.SetMove(Move("Tempestuous Danza", 5, 1, "Physical"));
    }
    else if (Class == "Grunt") {
        EnemyNameMoveset.SetMove(Move("Slash", 2, 1, "Physical"));
        EnemyNameMoveset.SetMove(Move("Dust", 1, 4, "Physical"));
    }
    else if (Class == "Necromancer") {
		EnemyNameMoveset.SetMove(Move("Avaunt", 1, 3, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Lich's Grasp", 5, 1, "Abyssal"));
    }
    else if (Class == "Rogue") {
        EnemyNameMoveset.SetMove(Move("Shadow Step", 3, 1, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Lethality", 1, 4, "Abyssal"));
    }

    // Special Classes (bosses, etc) Fourth move activates thru conditionals
    else if (Class == "ColorCleaver") {
		EnemyNameMoveset.SetMove(Move("Greater Cleave, Vertical", 2, 4, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Spear", 4, 1, "Physical"));
        EnemyNameMoveset.SetMove(Move("Upstanding Slash", 3, 1, "Physical"));
		EnemyNameMoveset.SetMove(Move("Greater Cleave, Horizontal", 25, 1, "Abyssal"));
    }
    else if (Class == "DarkSilence") {
        EnemyNameMoveset.SetMove(Move("Mook Workshop", 2, 6, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Crystal Atelier", 3, 2, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Atelier Logic", 3, 2, "Physical"));
        EnemyNameMoveset.SetMove(Move("Furioso", 2, 12, "Abyssal"));
    }
    else if (Class == "ManiKatti") {
        EnemyNameMoveset.SetMove(Move("Tatsumaki", 2, 6, "Physical"));
        EnemyNameMoveset.SetMove(Move("Goshoryu", 3, 4, "Physical"));
        EnemyNameMoveset.SetMove(Move("Demon Flip", 1, 5, "Physical"));
        EnemyNameMoveset.SetMove(Move("Shun Goku Satsu", 1, 25, "Abyssal"));
    }
    else if (Class == "AzureResonance") {
        EnemyNameMoveset.SetMove(Move("Trails of Blue", 3, 2, "Physical"));
        EnemyNameMoveset.SetMove(Move("Tempestuous Danza", 5, 2, "Physical"));
        EnemyNameMoveset.SetMove(Move("Final Impromptu", 6, 2, "Magical"));
        EnemyNameMoveset.SetMove(Move("Grand Finale", 1, 25, "Abyssal"));
    }

    // True Boss movesets, Phase Change moves will be commented.
    else if (Class == "OneWingedAngel") {
		EnemyNameMoveset.SetMove(Move("Flare.", 4, 8, "Magical"));
        EnemyNameMoveset.SetMove(Move("Shadow Flare.", 15, 3, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Octaslash.", 3, 8, "Physical"));
        EnemyNameMoveset.SetMove(Move("Scintilla.", 0, 1, "Counter"));

        // Phase Change Only Move, used ONCE per fight.
		EnemyNameMoveset.SetMove(Move("Supernova.", 1, 150, "BossMove"));

		// if HP <= 1% then use this move.
        EnemyNameMoveset.SetMove(Move("I refuse to be just a memory.", 1, 225, "DeathMove"));
    }
    else if (Class == "JovialChaos") {
        EnemyNameMoveset.SetMove(Move("At the ready.", 5, 1, "Buff"));
        EnemyNameMoveset.SetMove(Move("Curse.", 0, 1, "Debuff"));
        EnemyNameMoveset.SetMove(Move("Fire.", 45, 1, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Focus.", 5, 1, "Buff"));

		// Phase Change Only Move, used ONCE per fight.
		EnemyNameMoveset.SetMove(Move("Deus Ex Machina.", 1, 150, "BossMove"));

		// if HP <= 1% then use this move.
        EnemyNameMoveset.SetMove(Move("Door to the Backyard.", 1, 200, "DeathMove"));
    }
    else if (Class == "Bob") {
        EnemyNameMoveset.SetMove(Move("Bob's Biggest Bang", 45, 1, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Bob's Blazar.", 1, 50, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Bob's Bazooka", 45, 1, "Physical"));
		EnemyNameMoveset.SetMove(Move("Bob's Burgers", 5, 1, "Buff"));

		// Phase Change Only Move, used ONCE per fight.
		EnemyNameMoveset.SetMove(Move("Bob's Black Hole", 1, 150, "BossMove"));

		// if HP <= 1% then use this move.
        EnemyNameMoveset.SetMove(Move("Bob's Big Black Broad Bounteous Bountiful Black Breach", 1, 200, "DeathMove"));
    }
    else if (Class == "DevilGene") {
		EnemyNameMoveset.SetMove(Move("Electric Wind God Fist.", 45, 1, "Physical"));
        EnemyNameMoveset.SetMove(Move("Obliteration.", 35, 1, "Physical"));
        EnemyNameMoveset.SetMove(Move("Devil Gene: Unleashed.", 1, 45, "Physical"));
		EnemyNameMoveset.SetMove(Move("Linebreaker.", 40, 1, "Physical"));

		// Phase Change Only Move, used ONCE per fight.
		EnemyNameMoveset.SetMove(Move("Devil Dimension: Twisted Chains.", 1, 150, "BossMove"));

		// if HP <= 1% then use this move.
		EnemyNameMoveset.SetMove(Move("Demonic Valour.", 1, 200, "DeathMove"));
    }
    else if (Class == "Susanoo") {
        EnemyNameMoveset.SetMove(Move("Ouja Zenrouga", 50, 1, "Abyssal"));
		EnemyNameMoveset.SetMove(Move("Garengeki", 1, 50, "Abyssal"));
		EnemyNameMoveset.SetMove(Move("Jabaku Fuueinjin", 10, 3, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Jarin Renshouga", 20, 2, "Abyssal"));

		// Phase Change Only Move, used ONCE per fight.
		EnemyNameMoveset.SetMove(Move("Senkon Meiraku", 1, 150, "BossMove"));

		// if HP <= 1% then use this move.
        EnemyNameMoveset.SetMove(Move("Kamigaeri: Orochizantou Reppuuga", 50, 4, "DeathMove"));
    }
  //  else if (Class == "TheDemonKing") {
  //      EnemyNameMoveset.SetMove(Move("BRO WHERE'S THE BALL???", 45, 1, "Physical"));
  //      EnemyNameMoveset.SetMove(Move("Metavision", 5, 1, "Buff"));
  //      EnemyNameMoveset.SetMove(Move("Two Gun Volley", 20, 2, "Physical"));
  //      EnemyNameMoveset.SetMove(Move("FOOTBALL IS NOT THAT SERIOUS??", 1, 45, "Abyssal"));
  //      
  //      // Phase Change Only Move, used ONCE per fight.
  //      EnemyNameMoveset.SetMove(Move("MOVE IT.", 150, 1, "BossMove"));
		//
  //      // if HP <= 1% then use this move.
		//EnemyNameMoveset.SetMove(Move("I want to win,,, WITH MY OWN GOAL!!!!", 200, 1, "DeathMove"));
  //  }
}


void Moveset::PlayerInit(const std::string Class)
{
    Moves.clear();
    if (Class == "Warrior") {
        SetMove(Move("Slash", 2, 1, "Physical"));
        SetMove(Move("Slam", 4, 1, "Physical"));
    }
    else if (Class == "Mage") {
        SetMove(Move("Ice Barrage", 1, 4, "Magical"));
        SetMove(Move("Staff Slam", 2, 1, "Physical"));
    }
    else if (Class == "Hunter") {
        SetMove(Move("Piercing Arrow", 3, 1, "Physical"));
        SetMove(Move("Remedy", 10, 1, "Heal"));
    }
    else if (Class == "Assassin") {
        SetMove(Move("Backstab", 2, 2, "Physical"));
        SetMove(Move("Knife Throw", 1, 3, "Physical"));
    }
    else if (Class == "Summoner") {
        SetMove(Move("Summon: Fly", 1, 1, "Summon"));
    }
    else if (Class == "Ritualist") {
        SetMove(Move("Fillet", 4, 3, "Physical"));
    }
    else if (Class == "Berserker") {
        SetMove(Move("Ravenge", 0, 1, "Physical"));
    }
    else if (Class == "Conduit") {
        SetMove(Move("Omnislash", 3, 7, "Physical"));
        SetMove(Move("Armiger", 7, 3, "Magical"));
    }
}
