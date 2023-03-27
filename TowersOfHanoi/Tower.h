#ifndef TOWER_H
#define TOWER_H
#include <iostream>
#include <vector>
#include "Disc.h"
using namespace std;
class Tower
{
private:
	vector<Disc*> m_discs;
public:
	Tower();
	Tower(int _discs);
	~Tower() { cout << "\nTower destroyed."; }
	void SetCursor(int _x, int _y);
	vector<Disc*> GetDiscs() { return m_discs; }
	Disc* GetDisc();
	Disc* PopDisc();
	void PushDisc(Disc* _disc);
	void DrawTower(int _x, int _y);
	int DiscCount();
};
#endif

