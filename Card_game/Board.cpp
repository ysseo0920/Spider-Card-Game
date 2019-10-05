#include "Board.h"
#include <algorithm>
#include <array>
# include <vector>
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

	std::vector<list<Card>> allCard;
	std::stack<Card> store;
	
	
	Board() {

		Board(4, 4);
	}

	Board(int variety, int setNum) {

		_shape = variety;
		_set = setNum;
		score = 500;
		cnt = 0;
		Card* forDist = new Card[setNum];
		int n = 0;

		for (int i = 0; i < setNum / 4; i++) {
			Card c = Card(Spade, i);
			forDist[n++] = c;
			Card c = Card(Heart, i);
			forDist[n++] = c;
			Card c = Card(Diamond, i);
			forDist[n++] = c;
			Card c = Card(Clover, i);
			forDist[n++] = c;

		}
		std::random_shuffle(forDist, forDist + n); // shuffle

		std::deque<Card> dq;
		for (int i = 0; i < forDist->getCardNum; i++) {
			dq.push_back(forDist[i]);
		}

		for (int a = 0; a < 6; a++) {
			std::list<Card> newList;
			for (int i = 0; i < 5; i++) {
				newList.push_back(dq.pop_back);
				dq.pop_back();
			}
			allCard.push_back(newList);
		}
		while (!dq.empty()) {
			Card c = dq.back();
			dq.pop_back();
			store.push(c);
		}




	}


	void isEnd()
	{
		if (cnt < _set) {
			return;
		}
		else {
			Board::~Board();
		}
	}// end  // ������ �������� �ƴ��� üũ�ϰ� ������, deconstror�� �θ���.

	void shift(int fx, int fy, int lx) { // ī�带 �ٸ� ������ �ű��. fx���� lx�� �̵�.
		if (!Board::shiftHelp(fx, fy, lx)) {
			std::cout << "�� ī�带 �ű� �� �����ϴ�" << std::endl;
			return;
		}
		add(lx, remove(fx, fy));


	}

	bool shiftHelp(int fx, int fy, int lx) {// shift �Լ��� ��ȿ���� üũ�Ѵ�.
		if (fx >= 6 || lx >= 6) {
			return false;
		} // ���� �Ѿ����� Ȯ��

		list<Card> list1 = allCard.at(fx); // ??????
		int flag = 0;
		Shape mark;
		for (list<Card>::iterator it = list1.begin(); it != list1.end(); ++it) {

			if (fy == 0) {
				flag = 1;
				Card c = *it;
				mark = c.getCardShape();// fy�� ����

			}
			else if (fy < 0) {
				Card c = *it;
				if (mark != c.getCardShape()) {		// fy���� ���ڵ��� ��������, ���ڰ� ���������� �´��� ����.
					return false;
				}

			}
		}
		fy++;

		if (flag == 1) {
			return true;
		}
		else {
			return false;
		}

		

	}

	void distribute() {
		if (store.empty()) {
			std::cout << "stack�� ī�尡 ��� �ֽ��ϴ�" << std::endl;;
			return;
		}

		for (int i = 0; i < 6; i++) {
			list<Card>* a = &allCard[i];
			Card f = store.top();
			store.pop();
			a->push_back(f);

		}
	}
	// stack�� �ִ� ī�带 �� ���� �й��Ѵ�.

	void add(int num, std::list<Card> num2) {


		list<Card> list1 = allCard.at(num);

		// num list ���� ����.

		for (list<Card>::iterator start = num2.begin(); num2 != num2.end(); ++start) {

			list1.push_back(*start);

		}

		// ������ num2�� �ִ� ���ҵ��� �̸� ���̱�

	} // ���� ī�带 ���Ѵ�.

	std::list<Card> remove(int num, int num2) {
		list<Card> *a = &allCard[num];
		list<Card> toReturn;
		//num list�� ����

		list<Card>::iterator itr = a->begin();
		for (int i = 0; i < num2; i++) { // ������ valid ���� üũ.
			itr++;
		}
	
		list<Card>::iterator itr2 = list<Card>::iterator(itr);

		// list�� num2��° ���ҿ� ����
		while (itr != a->end()) {
			Card c = *itr;
			toReturn.push_back(c);
			++itr;
		}
	 
		a->erase(itr2, a->end());
		return toReturn;

	} // ���� ī�带 ����.

	void print() {
		// �� allCard�� ����Ʈ���� ���Ҹ� ����
		// �� Card�� print�Լ��� �۵��ϸ鼭, iterator �߰�.

	} // print current situlation.	

	~Board()
	{
		std::cout << "ī�� ������ �������ϴ�." << std::endl;
		std::cout << "������ " << score << "�� �Դϴ�" << std::endl;
	}
	// destructor
};







