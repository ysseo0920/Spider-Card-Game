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


	// Generate Card
	for (int i = 0; i < cardNum; i++) {
		Card c = Card(new Shape(i % _shape), i % 14);
		forDist[i] = c;

	}

	// Randomly shuffle
	std::random_shuffle(forDist, forDist + cardNum); 
	

	// For distribute
	std::deque<Card> dq; // 덱 

	for (int i = 0; i < cardNum; i++) {
		dq.push_back(forDist[i]);
	}


	// Add card to each cardfile
	for (int a = 0; a < 6; a++) { // 처음에 card pile이 6개로 되어있지만, 나중에 수정할 때 다른 값으로 변경
		std::list<Card> newList;
		for (int i = 0; i < 5; i++) {
			newList.push_back(dq.back()); // dq.back() : return queue's elecment
			dq.pop_back(); // pop_back return void.
		}
		// Card list ==> Card file
		allCard.push_back(newList);
	}
	// left card ==> put to stack 
	while (!dq.empty()) {
		Card c = dq.back();
		dq.pop_back();
		store.push(c);
	}

	// in the case of first setting ==> already matched. (I have never seen or heard such situlation) 
	for (int i = 0; i < 6; i++) {
		clear(i);
	}


	// delete[] forDist; 
}

bool Board::isEnd()
{
	if (score == 0) {
		std::cout << "카드 게임이 끝났습니다" << std::endl;
		std::cout << "아쉽지만 다시 도전해 보세요" << std::endl;
	}

	// 카드를 전부 맞추었을 때
	if (cnt < _set) {
		return false;
	}
	else {
		std::cout << "카드 게임이 끝났습니다." << std::endl;
		std::cout << "점수는 " << score << "점 입니다" << std::endl;
		return true;
	}
}// end  // 게임이 끝났는지 아닌지 체크하고 끝나면, deconstror를 부른다.


// FX, FX, LX 범위 0 ~ 5
bool Board::shift(int fx, int fy, int lx) { // 카드를 다른 덱으로 옮긴다. fx에서 lx로 이동.
	if (!Board::shiftHelp(fx, fy, lx)) {
		std::cout << "이 카드를 옮길 수 없습니다" << std::endl;
		std::cout << "다시 시도해 보세요" << std::endl;
		return false;
	}
	// 카드를 옮길 수 있을 때, fx번째 리스트에 fy부터 끝까지의 카드를 제거하고, 제거된 배열을 lx번째 리스트에 더한다.
	add(lx, remove(fx, fy));
	return true;


}

int Board::getScore() {

	return Board::score;
}

void Board::setScore() {

	score--;
}



bool Board::shiftHelp(int fx, int fy, int lx) {// shift 함수가 유효한지 체크한다.
	
	if (fx >= 6 || lx >= 6) {
		return false;
	} // inpu이 범위 넘었는지 확인

	list<Card> list1 = allCard.at(fx); // 제거할 list에 access
	int flag = 0;
	Shape* mark = new Shape();

	// fX의 카드 리스트를 훓기

	int num = 0;
	for (list<Card>::iterator it = list1.begin(); it != list1.end(); ++it) {


		if (fy == num) {
			flag = 1;
			
			mark = it->getCardShape();// fy에 접근
			flag = it->getCardNum();

		}
		else if (fy < num) {
			
			// 모양이 같은지 확인, 내림차순이여도, 카드 모양이 다르면 한꺼번에 옮길 수 없음.
			if (mark != it->getCardShape()) {
				return false;
			}


			// 카드 숫자가 내림차순인지 확인.
			if (it->getCardNum() == flag + 1) {
				flag = flag + 1;
			}
			else {
				return false;
			}

			

		}
		num++;
	}
	

	// flag : 옮길 카드 수 
	if (flag != 0) {
		return true;
	}
	else {
		return false;
	}

}

void Board::distribute() { // stack의 카드를 누를 때 각 리스트에 분배하는 역활
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

	// 배열된 카드 set가 있는지 체크
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
		itr++; // 해당하는 숫자까지 iterator를 변경
	}

	//list<Card>::iterator itr2 = list<Card>::iterator(itr);

	// list에 num2번째 원소에 접근
	
	// return할 카드를 만든다.
	while (itr != a->end()) {
		Card c = *itr;
	toReturn.push_back(c);
	++itr;
	}
	toReturn.push_back(*(a->end()));


	a->erase(itr, a->end()); // itr부터 끝까지 제거
	return toReturn;

} // 덱에 카드를 뺀다.

void Board::clear(int a) { // 배열이 되었으면 a번째 열을 제거한다.

	list<Card> p = allCard.at(a);
	list<Card>::iterator itr = p.end();
	itr--;
	Card& k = *itr;
	
	// 마지막 카드가 1이니면, 배열된 경우가 아니니 종료한다.
	if (k.getCardNum() != 1) {
		return;
	}


	for (; p.begin() != itr; itr--) {
		if (itr->getCardNum() != cnt) {
			return;
		}
		cnt++;
	}
	if (itr->getCardNum() != cnt) {
		return;
	}
	else {
		cnt++;
	}

	// 1 ~ K까지 카드수 14, 배열된 카드 수가 14개가 아니면 조건을 충족하지 못한다. 
	if (cnt != 14) {
		return;
	}

	// 맞은 개수 증가
	_set++;
	return;
}