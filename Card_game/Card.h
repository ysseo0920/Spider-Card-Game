#pragma once
#include"Place.h"
#include"Deck.h"
class Card
{
private:
	int card_num;
	Shape card_shape;
	Place card_postion;
	bool open;
	//GUI �����ų�� �̹��� + �̹����� ũ�� ���� ���� �ʿ��ϴ�.
public:
	Card();// default�� false
	Card(Shape Card_sha, int card_n); // default�� false
	Card(Shape Card_sha, int card_n, bool is_open);
	int getCardNum();
	Shape getCardShape();
	Place getCardPosition();
	int place(Deck someDeck);
	void printing();
	bool is_open();
	void set_open();
	void set_open(bool opening);
	~Card();
};

enum Shape {
	Spade,
	Diamond,
	Heart,
	Clover
};