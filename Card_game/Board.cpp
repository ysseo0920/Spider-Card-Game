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
	std::deque<Card> dq; // �� 

	for (int i = 0; i < cardNum; i++) {
		dq.push_back(forDist[i]);
	}


	// Add card to each cardfile
	for (int a = 0; a < 6; a++) { // ó���� card pile�� 6���� �Ǿ�������, ���߿� ������ �� �ٸ� ������ ����
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
		std::cout << "ī�� ������ �������ϴ�" << std::endl;
		std::cout << "�ƽ����� �ٽ� ������ ������" << std::endl;
	}

	// ī�带 ���� ���߾��� ��
	if (cnt < _set) {
		return false;
	}
	else {
		std::cout << "ī�� ������ �������ϴ�." << std::endl;
		std::cout << "������ " << score << "�� �Դϴ�" << std::endl;
		return true;
	}
}// end  // ������ �������� �ƴ��� üũ�ϰ� ������, deconstror�� �θ���.


// FX, FX, LX ���� 0 ~ 5
bool Board::shift(int fx, int fy, int lx) { // ī�带 �ٸ� ������ �ű��. fx���� lx�� �̵�.
	if (!Board::shiftHelp(fx, fy, lx)) {
		std::cout << "�� ī�带 �ű� �� �����ϴ�" << std::endl;
		std::cout << "�ٽ� �õ��� ������" << std::endl;
		return false;
	}
	// ī�带 �ű� �� ���� ��, fx��° ����Ʈ�� fy���� �������� ī�带 �����ϰ�, ���ŵ� �迭�� lx��° ����Ʈ�� ���Ѵ�.
	add(lx, remove(fx, fy));
	return true;


}

int Board::getScore() {

	return Board::score;
}

void Board::setScore() {

	score--;
}



bool Board::shiftHelp(int fx, int fy, int lx) {// shift �Լ��� ��ȿ���� üũ�Ѵ�.
	
	if (fx >= 6 || lx >= 6) {
		return false;
	} // inpu�� ���� �Ѿ����� Ȯ��

	list<Card> list1 = allCard.at(fx); // ������ list�� access
	int flag = 0;
	Shape* mark = new Shape();

	// fX�� ī�� ����Ʈ�� �f��

	int num = 0;
	for (list<Card>::iterator it = list1.begin(); it != list1.end(); ++it) {


		if (fy == num) {
			flag = 1;
			
			mark = it->getCardShape();// fy�� ����
			flag = it->getCardNum();

		}
		else if (fy < num) {
			
			// ����� ������ Ȯ��, ���������̿���, ī�� ����� �ٸ��� �Ѳ����� �ű� �� ����.
			if (mark != it->getCardShape()) {
				return false;
			}


			// ī�� ���ڰ� ������������ Ȯ��.
			if (it->getCardNum() == flag + 1) {
				flag = flag + 1;
			}
			else {
				return false;
			}

			

		}
		num++;
	}
	

	// flag : �ű� ī�� �� 
	if (flag != 0) {
		return true;
	}
	else {
		return false;
	}

}

void Board::distribute() { // stack�� ī�带 ���� �� �� ����Ʈ�� �й��ϴ� ��Ȱ
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

	// �迭�� ī�� set�� �ִ��� üũ
	for (int i = 0; i < 6; i++) {
      	clear(i);
	}


}
// stack�� �ִ� ī�带 �� ���� �й��Ѵ�.


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
	//num list�� ����

	list<Card>::iterator itr = a->begin();
	for (int i = 0; i < num2; i++) { // ������ valid ���� üũ.
		itr++; // �ش��ϴ� ���ڱ��� iterator�� ����
	}

	//list<Card>::iterator itr2 = list<Card>::iterator(itr);

	// list�� num2��° ���ҿ� ����
	
	// return�� ī�带 �����.
	while (itr != a->end()) {
		Card c = *itr;
	toReturn.push_back(c);
	++itr;
	}
	toReturn.push_back(*(a->end()));


	a->erase(itr, a->end()); // itr���� ������ ����
	return toReturn;

} // ���� ī�带 ����.

void Board::clear(int a) { // �迭�� �Ǿ����� a��° ���� �����Ѵ�.

	list<Card> p = allCard.at(a);
	list<Card>::iterator itr = p.end();
	itr--;
	Card& k = *itr;
	
	// ������ ī�尡 1�̴ϸ�, �迭�� ��찡 �ƴϴ� �����Ѵ�.
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

	// 1 ~ K���� ī��� 14, �迭�� ī�� ���� 14���� �ƴϸ� ������ �������� ���Ѵ�. 
	if (cnt != 14) {
		return;
	}

	// ���� ���� ����
	_set++;
	return;
}