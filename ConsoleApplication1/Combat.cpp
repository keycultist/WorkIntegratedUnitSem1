#include "Combat.h"

void Combat::PlayerAttack(Player& MC, Enemy& target, std::string MoveName)
{
	std::cout << MC.getPlayerClass() << " used " << MoveName << std::endl;
	target.setEnemyHP(target.getEnemyHP() -= MC.getPlayerPower());
	std::cout << target.getEnemyClass() << " has " << target.getEnemyHP() << " HP left." << std::endl;
}

void Combat::EnemyAttack(Player& MC, Enemy& target, std::string MoveName)
{
	std::cout << target.getEnemyClass() << " used " << MoveName << std::endl;
	MC.setPlayerHP(MC.getPlayerHP() -= target.getEnemyPower());
	std::cout << MC.getPlayerClass() << " has " << MC.getPlayerHP() << " HP left." << std::endl;
}
