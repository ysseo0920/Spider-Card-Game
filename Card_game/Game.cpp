#include "Game.h"


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
	bool isSuccess = false;
	int f1, f2, l1;
	while (!g.isEnd()) {

	//	g.print();
		
		std::cout << "��� ī�带 �����̽ðڽ��ϱ�?  ex 1 2 )  ";

		std::cin >> f1; 
		std::cin >> f2;
		std::cout << "���� �̵���Ű�ڽ��ϱ�?  )  ";
		std::cin >> l1;
		
		isSuccess = g.shift(f1, f2, l1);
		

		if (isSuccess) {
			g.setScore();
		}


	}
	g.~Board();

	


}


Game::~Game()
{
}
