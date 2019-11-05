# include "Board.h"

Board::Board() : Board::Board(4) {

}

Board::Board(int variety) : Board::Board(variety, 48) {


}

Board::Board(int variety, int cardNum) {

	_shape = variety;
	_set = cardNum / variety;
	score = 500;
	cnt = 0;

	Card* forDist = new Card[cardNum];


	for (int i = 0; i < cardNum; i++) {
		Card c = Card(new Shape(cardNum % _shape), cardNum / _shape);
		forDist[i] = c;

	}

	std::random_shuffle(forDist, forDist + cardNum); // shuffle

	std::deque<Card> dq; // 덱 


	for (int i = 0; i < cardNum; i++) {
		dq.push_back(forDist[i]);
	}

	for (int a = 0; a < 6; a++) { // 처음에 card pile이 6개로 되어있지만, 나중에 수정할 때 다른 값으로 변경
		std::list<Card> newList;
		for (int i = 0; i < 5; i++) {
			newList.push_back(dq.back());
			dq.pop_back();
		}
		allCard.push_back(newList);
	}
	while (!dq.empty()) {
		Card c = dq.back();
		dq.pop_back();
		store.push(c);
	}
	for (int i = 0; i < 6; i++) {

		clear(i);
	}


	delete[] forDist;


}

bool Board::isEnd()
{
	if (cnt < _set) {
		return false;
	}
	else {
		std::cout << "카드 게임이 끝났습니다." << std::endl;
		std::cout << "점수는 " << score << "점 입니다" << std::endl;
		return true;
	}
}// end  // 게임이 끝났는지 아닌지 체크하고 끝나면, deconstror를 부른다.

void Board::shift(int fx, int fy, int lx) { // 카드를 다른 덱으로 옮긴다. fx에서 lx로 이동.
	if (!Board::shiftHelp(fx, fy, lx)) {
		std::cout << "이 카드를 옮길 수 없습니다" << std::endl;
		return;
	}
	add(lx, remove(fx, fy));


}

// shape 때문에 수정해야함.
bool Board::shiftHelp(int fx, int fy, int lx) {// shift 함수가 유효한지 체크한다.
	if (fx >= 6 || lx >= 6) {
		return false;
	} // 범위 넘었는지 확인

	list<Card> list1 = allCard.at(fx); // ??????
	int flag = 0;
	Shape* mark = new Shape();

	for (list<Card>::iterator it = list1.begin(); it != list1.end(); ++it) {

		if (fy == 0) {
			flag = 1;
			Card c = *it;
			mark = c.getCardShape();// fy에 접근
			flag = c.getCardNum();

		}
		else if (fy < 0) {
			Card c = *it;
			if (c.getCardNum() == flag + 1) {
				flag = flag + 1;
			}
			else {
				return false;
			}
			if (mark != c.getCardShape()) {		// fy부터 문자들이 동일한지, 순자가 내림차순이 맞는지 점검.
				return false;
			}

		}
	}
	fy++;

	if (flag != 0) {
		return true;
	}
	else {
		return false;
	}

}

void Board::distribute() {
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
	for (int i = 0; i < 6; i++) {

		clear(i);
	}


}
// stack에 있는 카드를 각 덱에 분배한다.


void Board::add(int num, std::list<Card> num2) {


	list<Card>* list1 = &allCard.at(num);
	for (list<Card>::iterator itr = num2.begin(); itr != num2.end(); itr++) {
		list1->push_back(*itr);
	}
	clear(num);
}

std::list<Card> Board::remove(int num, int num2) {
	list<Card>* a = &allCard.at(num);
	list<Card> toReturn;
	//num list에 접근

	list<Card>::iterator itr = a->begin();
	for (int i = 0; i < num2; i++) { // 범위가 valid 한지 체크.
		itr++;
	}

	//list<Card>::iterator itr2 = list<Card>::iterator(itr);

	// list에 num2번째 원소에 접근
//	while (itr != a->end()) {
		//Card c = *itr;
	//	toReturn.push_back(c);
		//++itr;
	//}

	a->erase(itr, a->end());
	return toReturn;

} // 덱에 카드를 뺀다.

void Board::clear(int a) {
	list<Card>* p = &allCard.at(a);
	list<Card>::iterator itr = p->end();
	if (itr->getCardNum() != 1) {
		return;
	}

	for (; p->begin() != itr; itr--) {
		if (itr->getCardNum() != cnt) {
			return;
		}
		cnt++;
	}
	if (cnt != 14) {
		return;
	}

	_set++;
	return;
}