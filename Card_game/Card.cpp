#pragma once
#include "Card.h"
#include "Shape.h"

    Card::Card() : Card::Card(new Shape("diamond"), 1) {
			
	}
	Card::Card(Shape* Card_sha, int card_n) : Card::Card(Card_sha, card_n, false) {
		
	} // default는 false 

	Card::Card(Shape* Card_sha, int card_n, bool is_open)
	{
		card_shape = Card_sha;
		card_num = card_n;
		open = is_open;
	};

	int Card::getCardNum() {
		return card_num;
	};
	Shape* Card::getCardShape() {
		
		return card_shape;
		
	};

	bool Card::is_open() {
		return open;
	};
	void Card::set_open() {
		open = true;
	};
	void Card::set_open(bool opening) {
	
		open = opening;
	};
	Card::~Card() {

	};

/*
Place Card::getCardPosition()
{
	return Place();
}

Place Card::getCardPosition()
{
	//TODO 나중에 GUI 만들때 생각하기
	return Place();
}
int Card::place(Deck someDeck)
{
	//TODO
	return 0;
}

*/