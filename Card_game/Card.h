#pragma once
#include"Place.h"
#include"Shape.h"
# include "string"

class Card
{
private:
	int card_num;
	Shape* card_shape;
	Place card_postion;
	bool open;
	//GUI �����ų�� �̹��� + �̹����� ũ�� ���� ���� �ʿ��ϴ�.
	// Card ���� ������, Ȯ�强�� �����ϸ�, 4���� �ƴ� �� �� �ִµ�, �̸� ��� �ٶ� 
	// 1 : Heart, 2 : spade, 3 : clover 4: diamond, 5, 6, 7  .. ���� �ٸ� ������� �����ϰ�,
	// Game�� ����, 1�� �������, 1~4 ���� �����ϴ� �ɷ�...
public:
	Card(Shape* Card_sha, int card_n); // default�� false 
	Card(Shape* Card_sha, int card_n, bool is_open);
	int getCardNum();
	Shape* getCardShape();
	//Place getCardPosition();
	//int place(Deck someDeck);
	void printing();
	bool is_open();
	void set_open();
	void set_open(bool opening);
	~Card();
};