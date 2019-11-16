#pragma once
#include <algorithm>
# include <vector>
# include <iostream> 
# include "Card.h"
# include "Shape.h"
#include <list>
#include <stack>

using namespace std;

class Board { // 현제 카드수가 48개에 맞추어 세팅이 되어있음

     
	int cnt; // 맞춘 개수
	int _shape; // # of card type
	int _set; // setting 개수
	int score; // 점수

	std::vector<list<Card>> allCard;
	std::stack<Card> store; // store.empty()일 때 아닐 때 출력되는 그림을 다르게 해야함.
public:
	Board();

	Board(int variety);

	Board(int variety, int cardNum);
	bool isEnd();

	// 현제 점수값을 반환한다.
	int getScore();

	// score을 1감소 시킨다.
	void setScore();

	bool shift(int fx, int fy, int lx);

	// shape 때문에 수정해야함.
	bool shiftHelp(int fx, int fy, int lx);
	void distribute();
	std::list<Card> remove(int num, int num2);
	void add(int num, std::list<Card> num2);
	void clear(int a);
	// void print();
	// destructor
};