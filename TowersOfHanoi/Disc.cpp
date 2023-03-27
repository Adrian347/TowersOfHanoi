#include "Disc.h"
#include <iostream>

void Disc::DrawDisc() {
	if (GetSize() == 6) {
		std::cout << "      ";
		for (int i = 0; i < GetSize(); i++)
			std::cout << "*";
		std::cout << "      ";
	}
	else if (GetSize() == 12) {
		std::cout << "   ";
		for (int i = 0; i < GetSize(); i++)
			std::cout << "*";
		std::cout << "   ";
	}
	else if (GetSize() == 18) {
		for (int i = 0; i < GetSize(); i++)
			std::cout << "*";
	}
	else {
		std::cout << " ";
	}
}