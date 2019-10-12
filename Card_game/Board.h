#pragma once
#include <algorithm>
#include <array>
# include <vector>
# include <iostream> 
# include <list>
# include <queue>
# include <stack>
# include "Card.h"

class Board
{
public:
	Board();
	Board(int variety, int setNum);

	bool isEnd();
	void shift(int fx, int fy, int lx);
	bool shiftHelp(int fx, int fy, int lx);
	void distribute();
	void add(int num, std::list<Card> num2);
	std::list<Card> remove(int num, int num2);
	void print();


	~Board();
};

