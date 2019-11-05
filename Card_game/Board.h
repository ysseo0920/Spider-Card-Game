#pragma once
#include <algorithm>
# include <vector>
# include <iostream> 
# include "Card.h"
# include "Shape.h"
#include <list>
#include <stack>

using namespace std;

class Board {


	int cnt; // ���� ����
	int _shape; // # of card type
	int _set; // setting ����
	int score; // ����

	std::vector<list<Card>> allCard;
	std::stack<Card> store;
public:
	Board();

	Board(int variety);

	Board(int variety, int cardNum);
	bool isEnd();

	void shift(int fx, int fy, int lx);

	// shape ������ �����ؾ���.
	bool shiftHelp(int fx, int fy, int lx);
	void distribute();
	std::list<Card> remove(int num, int num2);
	void add(int num, std::list<Card> num2);
	void clear(int a);
	// destructor
};