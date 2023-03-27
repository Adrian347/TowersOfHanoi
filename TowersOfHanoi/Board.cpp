#include "Board.h"
#include <iostream>
#include <windows.h>
using namespace std;

Board::Board() {
	m_a = new Tower(3);
	m_b = new Tower(0);
	m_c = new Tower(0);
}

void Board::SetCursor(int _x, int _y) {
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = _x;
	position.Y = _y;
	SetConsoleCursorPosition(screen, position);
}

Tower* Board::GetTower(char _tower) {
	if (_tower == 'a' || _tower == 'A')
		return m_a;
	else if (_tower == 'b' || _tower == 'B')
		return m_b;
	else if (_tower == 'c' || _tower == 'C')
		return m_c;
}

void Board::MoveDisc(Tower* _source, Tower* _destination) {
	_destination->PushDisc(_source->PopDisc());
}

void Board::DrawBoard() {
	system("cls");
	m_a->DrawTower(0, 15);
	SetCursor(6, 18);
	Sleep(500);
	cout << "Tower A";
	m_b->DrawTower(20, 15);
	SetCursor(26, 18);
	Sleep(500);
	cout << "Tower B";
	m_c->DrawTower(40, 15);
	SetCursor(46, 18);
	Sleep(500);
	cout << "Tower C";
	SetCursor(20, 20);
	Sleep(500);
	cout << "Number of Moves: " << GetMoves();
	SetCursor(20, 22);
	cout << "Welcome to Towers of Hanoi\n";
}

bool Board::WinGame() {
	if (m_c->DiscCount() == 3) {
		return true;
	}
	else {
		return false;
	}
}

Tower* Board::ProcessInput(char _input, Board* _board) {
	while (true) {
		if (IsValidInput(_input) == true) {
			if (_input == 'x' || _input == 'X') {
				delete _board;
				exit('0');
			}
			if (_input == 'n' || _input == 'N') {
				delete _board;
				system("cls");
				PlayGame();
			}
			else if (_input == 'a' || _input == 'A' ||
				_input == 'b' || _input == 'B' ||
				_input == 'c' || _input == 'C') {
				return GetTower(_input);
			}
			break;
		}
		else {
			cout << "Not a valid input.";
			cout << "\nChoose again ([X] to Quit, [N] for New): ";
			cin >> _input;
		}
	}
}

bool Board::IsValidInput(char _input) {
	switch (_input) {
	case 'x': case 'X':
	case 'n': case 'N':
	case 'a': case 'A':
	case 'b': case 'B':
	case 'c': case 'C':
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool Board::IsValidMove(Tower* _source, Tower* _destination) {
	if (_source->GetDiscs().empty()) {
		return false;
	}
	else if	(!_destination->GetDiscs().empty() &&
		_destination->GetDisc()->GetSize() < _source->GetDisc()->GetSize()) {
		m_moves++;
		return false;
	}
	else {
		m_moves++;
		return true;
	}
}

void Board::PlayGame() {
	char sourceInput;
	char destinationInput;
	char playInput;
	Board* board;
	board = new Board();
	Tower* source;
	Tower* destination;
	do {
		board->DrawBoard();
		while (true) {
			cout << "\nChoose Source Tower ([X] to Quit, [N] for New): ";
			cin >> sourceInput;
			source = board->ProcessInput(sourceInput, board);

			cout << "Choose Destination Tower ([X] to Quit, [N] for New): ";
			cin >> destinationInput;
			destination = board->ProcessInput(destinationInput, board);

			if (board->IsValidMove(source, destination) == false) {
				if (source->GetDiscs().empty()) {
					cout << "Invalid Move! Source tower has no discs.";
				}
				else if (!destination->GetDiscs().empty() &&
					destination->GetDisc()->GetSize() < source->GetDisc()->GetSize()) {
					cout << "Invalid Move! You cannot stack a disc on top of a smaller disc.";
				}
			}
			else {
				board->MoveDisc(source, destination);
				break;
			}
		}

	} while (board->WinGame() == false);

	board->DrawBoard();
	cout << "\nYou win!";
	cout << "\nPress [Y] to play again; press any other key to quit: ";
	cin >> playInput;
	if (playInput == 'y' || playInput == 'Y') {
		delete board;
		PlayGame();
	}
	else {
		delete board;
		exit('0');
	}
}

