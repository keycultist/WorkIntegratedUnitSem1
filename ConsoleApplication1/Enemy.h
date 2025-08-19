#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
	private:
		std::string EnemyClass;
		int EnemyHP;
		int EnemyPower;
		int EnemyPosX, EnemyPosY;
		int EnemyLvl;
		int EnemyXP;
		std::string EnemyEquippedWeapon;
		std::string EnemyEquippedArmor;

	protected:


	public:
		void SetEnemyClass(std::string Class);
		void SetEnemyHP(int HP);
		void SetEnemyPower(int Power);
		void SetEnemyPos(int X, int Y);
		void SetEnemyLvl(int Lvl);
		void SetEnemyXP(int XP);
		void SetEnemyEquippedWeapon(std::string Weapon);
		void SetEnemyEquippedArmor(std::string Armor);

		std::string GetEnemyClass(void) const;
		int GetEnemyHP(void) const;
		int GetEnemyPower(void) const;
		int GetEnemyPosX(void) const;
		int GetEnemyPosY(void) const;
		int GetEnemyLvl(void) const;
		int GetEnemyXP(void) const;
		std::string GetEnemyEquippedWeapon(void) const;
		std::string GetEnemyEquippedArmor(void) const;

		Enemy();
		Enemy(std::string EnemyClass, int EnemyHP, int EnemyPower, int EnemyPosX, int EnemyPosY, int EnemyLvl, std::string EnemyEquippedWeapon, std::string EnemyEquippedArmor);
		~Enemy();
};

#endif