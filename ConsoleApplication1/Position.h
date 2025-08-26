#pragma once
class Position
{
private:
	int x;
	int y;
public:
	Position();
	Position(int x, int y);
	~Position();

	void SetX(int x);
	void SetY(int y);

	int GetX(void) const;
	int GetY(void) const;
};