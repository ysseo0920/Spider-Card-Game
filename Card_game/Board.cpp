#include "Board.h"

# include <iostream> 
# include <list>
# include <queue>
# include <stack>
# include "Card.h"

using namespace std;

class Board {
	Board(); // default constructor
	Board(int variety, int setNum); // const


	int cnt; // 맞춘 개수
	int _shape; // # of card type
	int _set; // setting 개수
	int score; // 점수

	std::list<Card> allCard;
	std::queue<Card> forDist;
	std::stack<Card> store;
	
	
	void isEnd(); // 게임이 끝났는지 아닌지 체크하고 끝나면, deconstror를 부른다.

	void shift(); // 카드를 다른 덱으로 옮긴다.

	void shiftHelp(); // shift가 유효한지 체크한다.

	void distribute(); // stack에 있는 카드를 분배한다.

	void add(); // 덱에 카드를 더한다.

	void remove(); // 덱에 카드를 뺀다.

	void print(); // print current situlation.

	~Board(); // destructor
};

Board::Board() {

	Board(4, 4);
}

Board::Board(int variety, int setNum) {

	_shape = variety;
	_set = setNum;
	score = 500;
	cnt = 0;
	for (int i = 0; i < setNum / 4; i++) {
		for (int j = 0; j < _shape; j++) {
			Card c = Card(j, i);
			Board::forDist.push(c);
		}
	}


}

void Board::isEnd()
{ 
	if (cnt < _set) {
		return;
	}
	else {
		Board::~Board();
	}
}


Board::~Board()
{
	std::cout << "카드 게임이 끝났습니다." << std::endl;
	std::cout << "점수는 " << score << "점 입니다" << std::endl;
}
