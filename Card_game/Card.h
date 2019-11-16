#pragma once
#include"Place.h"
#include"Shape.h"


class Card
{
private:
	int card_num;
	Shape* card_shape;
	//Place card_postion;
	bool open = false; 
	// Open true : printf the card entirly
	//      false : only print black card 

public:
	Card();
	Card(Shape* Card_sha, int card_n); // default´Â false 
	Card(Shape* Card_sha, int card_n, bool is_open);
	int getCardNum();
	Shape* getCardShape();
	//Place getCardPosition();
	//int place(Deck someDeck);

	bool is_open(); // ==> For print 
	void set_open(); // ==> If user shift card
	void set_open(bool opening);
	//void printing();
	~Card();
};