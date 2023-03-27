#include <windows.h>
#include "Tower.h"
Tower::Tower() {

}

Tower::Tower(int _discs) {
	for (int i = _discs; i > 0; i--) 
		m_discs.push_back(new Disc(i * 6));
}

void Tower::SetCursor(int _x, int _y) {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = _x;
	position.Y = _y;
	SetConsoleCursorPosition(screen, position);
}

Disc* Tower::GetDisc() {
	Disc* popDisc = m_discs[m_discs.size() - 1];
	return popDisc;
}

Disc* Tower::PopDisc() {
	Disc* popDisc = m_discs[m_discs.size() - 1];
	m_discs.pop_back();
	return popDisc;
}

void Tower::PushDisc(Disc* _disc) {
	m_discs.push_back(_disc);
}

void Tower::DrawTower(int _x, int _y) {
	SetCursor(_x, _y);
	for (int i = m_discs.size() - 1; i >= 0; i--) {
		m_discs[i]->DrawDisc();
		std::cout << endl;
		if (i <= 2) {
			if (i == 1) {
				if (m_discs.size() == 2)
					SetCursor(_x, _y + 1);
				else 
					SetCursor(_x, _y + 2);
			}
			else if (i == 2) {
				SetCursor(_x, _y + 1);
			}	
		}
		Sleep(500);
	}
}

int Tower::DiscCount() {
	return m_discs.size();
}