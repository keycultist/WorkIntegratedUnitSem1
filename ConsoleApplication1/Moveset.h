#pragma once
#include <string>
#include <iostream>
#include <vector>
class Moveset
{
public:

	struct Move
	{
		std::string MoveName;
		int MoveStrength;
		int Hits;
		std::string MoveType;

		Move(const std::string& N, int P, int H, const std::string& T = "Normal");
	};

private:
	std::vector<Move> Moves;
public:
	void SetMove(const Move& move);
	void ReplaceMove(const Move& move, int index);
	Move GetMove(int index) const;
	int size() const;

	void EnemyInit(const std::string Class);
	void PlayerInit(const std::string Class);
};

