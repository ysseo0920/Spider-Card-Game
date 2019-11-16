#pragma once
#include <algorithm>
# include <vector>
# include <iostream> 
# include "Card.h"
# include "Shape.h"
#include <list>
#include <stack>

using namespace std;

class Board { // ���� ī����� 48���� ���߾� ������ �Ǿ�����

     
	int cnt; // ���� ����
	int _shape; // # of card type
	int _set; // setting ����
	int score; // ����

	std::vector<list<Card>> allCard;
	std::stack<Card> store; // store.empty()�� �� �ƴ� �� ��µǴ� �׸��� �ٸ��� �ؾ���.
public:
	Board();

	Board(int variety);

	Board(int variety, int cardNum);
	bool isEnd();

	// ���� �������� ��ȯ�Ѵ�.
	int getScore();

	// score�� 1���� ��Ų��.
	void setScore();

	bool shift(int fx, int fy, int lx);

	// shape ������ �����ؾ���.
	bool shiftHelp(int fx, int fy, int lx);
	void distribute();
	std::list<Card> remove(int num, int num2);
	void add(int num, std::list<Card> num2);
	void clear(int a);
	// void print();
	// destructor
};