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
    Moveset EnemyNameMoveset;

    //Add enemy movesets
    if (Class == "Cleaver") {
        EnemyNameMoveset.SetMove(Move("Lesser Cleave, Vertical", 1, 4, "Abyssal"));
		EnemyNameMoveset.SetMove(Move("Lesser Cleave, Horizontal", 6, 1, "Abyssal"));
    }
    else if (Class == "Silent") {
        EnemyNameMoveset.SetMove(Move("Alas", 1, 2, "Physical"));
		EnemyNameMoveset.SetMove(Move("Mook", 1, 6, "Physical"));
    }
    else if (Class == "Asdasda") {

    }

    // Special Classes (bosses, etc)
    else if (Class == "ColorCleaver") {
		EnemyNameMoveset.SetMove(Move("Greater Cleave, Vertical", 2, 4, "Abyssal"));
		EnemyNameMoveset.SetMove(Move("Greater Cleave, Horizontal", 10, 1, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Spear", 4, 1, "Physical"));
    }
    else if (Class == "DarkSilence") {
        EnemyNameMoveset.SetMove(Move("Mook Workshop", 2, 6, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Crystal Atelier", 3, 2, "Abyssal"));
        EnemyNameMoveset.SetMove(Move("Furioso", 1, 12, "Abyssal"));
    }
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
        SetMove(Move("Remedy", -10, 1, "Heal"));
    }
}
