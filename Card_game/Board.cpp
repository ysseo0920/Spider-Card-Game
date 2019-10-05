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


	int cnt; // 맞춘 개수
	int _shape; // # of card type
	int _set; // setting 개수
	int score; // 점수

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
	}// end  // 게임이 끝났는지 아닌지 체크하고 끝나면, deconstror를 부른다.

	void shift(int fx, int fy, int lx) { // 카드를 다른 덱으로 옮긴다. fx에서 lx로 이동.
		if (!Board::shiftHelp(fx, fy, lx)) {
			std::cout << "이 카드를 옮길 수 없습니다" << std::endl;
			return;
		}
		add(lx, remove(fx, fy));


	}

	bool shiftHelp(int fx, int fy, int lx) {// shift 함수가 유효한지 체크한다.
		if (fx >= 6 || lx >= 6) {
			return false;
		} // 범위 넘었는지 확인

		list<Card> list1 = allCard.at(fx); // ??????
		int flag = 0;
		Shape mark;
		for (list<Card>::iterator it = list1.begin(); it != list1.end(); ++it) {

			if (fy == 0) {
				flag = 1;
				Card c = *it;
				mark = c.getCardShape();// fy에 접근

			}
			else if (fy < 0) {
				Card c = *it;
				if (mark != c.getCardShape()) {		// fy부터 문자들이 동일한지, 순자가 내림차순이 맞는지 점검.
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
			std::cout << "stack에 카드가 비어 있습니다" << std::endl;;
			return;
		}

		for (int i = 0; i < 6; i++) {
			list<Card>* a = &allCard[i];
			Card f = store.top();
			store.pop();
			a->push_back(f);

		}
	}
	// stack에 있는 카드를 각 덱에 분배한다.

	void add(int num, std::list<Card> num2) {


		list<Card> list1 = allCard.at(num);

		// num list 끝에 접근.

		for (list<Card>::iterator start = num2.begin(); num2 != num2.end(); ++start) {

			list1.push_back(*start);

		}

		// 끝부터 num2에 있는 원소들을 이머 붙이기

	} // 덱에 카드를 더한다.

	std::list<Card> remove(int num, int num2) {
		list<Card> *a = &allCard[num];
		list<Card> toReturn;
		//num list에 접근

		list<Card>::iterator itr = a->begin();
		for (int i = 0; i < num2; i++) { // 범위가 valid 한지 체크.
			itr++;
		}
	
		list<Card>::iterator itr2 = list<Card>::iterator(itr);

		// list에 num2번째 원소에 접근
		while (itr != a->end()) {
			Card c = *itr;
			toReturn.push_back(c);
			++itr;
		}
	 
		a->erase(itr2, a->end());
		return toReturn;

	} // 덱에 카드를 뺀다.

	void print() {
		// 각 allCard의 리스트들의 원소를 생성
		// 각 Card의 print함수를 작동하면서, iterator 추가.

	} // print current situlation.	

	~Board()
	{
		std::cout << "카드 게임이 끝났습니다." << std::endl;
		std::cout << "점수는 " << score << "점 입니다" << std::endl;
	}
	// destructor
};







