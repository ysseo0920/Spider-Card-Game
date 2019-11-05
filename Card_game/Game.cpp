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


	std::cout << "Play 할 카드 종류 수와 카드 수를 입력하시요  " ;
	
	int variety; 
	int cardNum;
	std::cin >> variety;
	std::cin >> cardNum;
    	
	Board g = Board(variety, cardNum);
	int f1, f2, l1;
	while (g.isEnd()) {

		std::cout << "어느 카드를 움직이시겠습니까?  ex 1 2 )  ";

		std::cin >> f1; 
		std::cin >> f2;
		std::cout << "어디로 이동시키겠습니까?  )  ";
		std::cin >> l1;

		g.shift(f1, f2, l1);
		


	}
	g.~Board();

	


}


Game::~Game()
{
}
