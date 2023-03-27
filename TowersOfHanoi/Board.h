#ifndef BOARD_H
#define BOARD_H
#include "Tower.h"
#include <windows.h>
class Board
{
private:
	Tower* m_a;
	Tower* m_b;
	Tower* m_c;
	int m_moves = 0;
public:
	Board();
	virtual ~Board() { std::cout << "\nBoard destroyed."; }
	void SetCursor(int _x, int _y);
	Tower* GetTower(char _tower);
	int GetMoves() { return m_moves; }
	void MoveDisc(Tower* _source, Tower* _destination);
	void DrawBoard();
	bool WinGame();
	Tower* ProcessInput(char _input, Board* _board);
	bool IsValidInput(char _input);
	bool IsValidMove(Tower* _source, Tower* _destination);
	void PlayGame();
};
#endif

