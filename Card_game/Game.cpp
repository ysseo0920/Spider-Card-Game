#include "Game.h"

#include <iostream>
#include "Board.h"


int main() {

	Game g = Game();
	g.~Game();

	return 0;

}


Game::Game()
{


	std::cout << "Play �� ī�� ���� ���� ī�� ���� �Է��Ͻÿ�  " ;
	
	int variety; 
	int cardNum;
	std::cin >> variety;
	std::cin >> cardNum;
    	
	Board g = Board(variety, cardNum);
	int f1, f2, l1;
	while (g.isEnd()) {

		std::cout << "��� ī�带 �����̽ðڽ��ϱ�?  ex 1 2 )  ";

		std::cin >> f1; 
		std::cin >> f2;
		std::cout << "���� �̵���Ű�ڽ��ϱ�?  )  ";
		std::cin >> l1;

		g.shift(f1, f2, l1);
		


	}
	g.~Board();

	


}


Game::~Game()
{
}
