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


	int cnt; // ���� ����
	int _shape; // # of card type
	int _set; // setting ����
	int score; // ����

	std::list<Card> allCard;
	std::queue<Card> forDist;
	std::stack<Card> store;
	
	
	void isEnd(); // ������ �������� �ƴ��� üũ�ϰ� ������, deconstror�� �θ���.

	void shift(); // ī�带 �ٸ� ������ �ű��.

	void shiftHelp(); // shift�� ��ȿ���� üũ�Ѵ�.

	void distribute(); // stack�� �ִ� ī�带 �й��Ѵ�.

	void add(); // ���� ī�带 ���Ѵ�.

	void remove(); // ���� ī�带 ����.

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
	std::cout << "ī�� ������ �������ϴ�." << std::endl;
	std::cout << "������ " << score << "�� �Դϴ�" << std::endl;
}
