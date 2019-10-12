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


	int cnt; // ���� ����
	int _shape; // # of card type
	int _set; // setting ����
	int score; // ����

	std::vector<list<Card>> allCard;
	std::stack<Card> store;
	
	
	Board() {

		Board(4, 4);
	}

	Board(int variety, int cardNum) {

		_shape = variety;
		_set = cardNum;
		
		score = 500;
		cnt = 0;


		Card* forDist = new Card[cardNum];
		
	
		for (int i = 0; i < cardNum; i++) {
			Card c = Card(cardNum % _shape, cardNum / _shape);
			forDist[i] = c;

		}
		std::random_shuffle(forDist, forDist + cardNum); // shuffle

		std::deque<Card> dq; // �� 


		for (int i = 0; i < cardNum; i++) {
			dq.push_back(forDist[i]);
		}

		for (int a = 0; a < 6; a++) { // ó���� card pile�� 6���� �Ǿ�������, ���߿� ������ �� �ٸ� ������ ����
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


	bool isEnd()
	{
		if (cnt < _set) {
			return false;
		}
		else {
			std::cout << "ī�� ������ �������ϴ�." << std::endl;
			std::cout << "������ " << score << "�� �Դϴ�" << std::endl;
			return true;
		}
	}// end  // ������ �������� �ƴ��� üũ�ϰ� ������, deconstror�� �θ���.

	void shift(int fx, int fy, int lx) { // ī�带 �ٸ� ������ �ű��. fx���� lx�� �̵�.
		if (!Board::shiftHelp(fx, fy, lx)) {
			std::cout << "�� ī�带 �ű� �� �����ϴ�" << std::endl;
			return;
		}
		add(lx, remove(fx, fy));


	}

	// shape ������ �����ؾ���.
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


		list<Card> list1 = allCard[num];

		// num list ���� ����.

		for (list<Card>::iterator start = num2.begin(); start != num2.end(); ++start) {

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
	//	while (itr != a->end()) {
			//Card c = *itr;
		//	toReturn.push_back(c);
			//++itr;
		//}
	 
		a->erase(itr, a->end());
		return toReturn;

	} // ���� ī�带 ����.

	// Print ���� �߰� �ٶ�.
	void print() {

		bool s = store.empty;
		const char* status = ( s ) ? "empty" : "full";
		std::vector<list<Card>::iterator> itr;
		itr.at(0) = allCard[0].begin();
		itr.at(1) = allCard[1].begin();
		itr.at(2) = allCard[2].begin();
		itr.at(3) = allCard[3].begin();
		itr.at(4) = allCard[4].begin();
		itr.at(5) = allCard[5].begin();

		std::cout << "                    " <<" Console â "<< "                    " << std::endl;
		std::cout <<  std::endl;
		std::cout << "    " << "score " << score << std::endl;
	    std::cout << "stack : "  << status << std::endl; 
		
		int numList[6] = { allCard[0].size,  allCard[1].size,  allCard[2].size,  allCard[3].size,  allCard[4].size,  allCard[5].size };
		bool possible[6] = { true, true, true, true, true, true };
		bool k = true;
		int p = 1;
		while (k) {

			for (int i = 0; i < 6; i++) {

				if ( possible[i] == true) {
					
					Card o = *itr.at(i);
					o.printing();
				    itr.at(i)++;
					if (itr.at(i) > allCard[i].end )
						possible[i] = false;
				}
				else {
  
					std::cout << "   "<< std::endl;
				}
			}
			k = possible[0] || possible[1] || possible[2] || possible[3] || possible[4] || possible[5];
		}



		// �� allCard�� ����Ʈ���� ���Ҹ� ����
		// �� Card�� print�Լ��� �۵��ϸ鼭, iterator �߰�.

	} // print current situlation.	

	~Board() // if ( setNum == count ) 
	{   
		
	}
	// destructor
};







