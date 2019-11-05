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
	//GUI 적용시킬때 이미지 + 이미지의 크기 같은 것이 필요하다.
	// Card 종류 개수도, 확장성을 생각하면, 4개가 아닐 수 도 있는데, 이를 고려 바람 
	// 1 : Heart, 2 : spade, 3 : clover 4: diamond, 5, 6, 7  .. 등은 다른 모양으로 설정하고,
	// Game에 따라, 1만 사용할지, 1~4 까지 결정하는 걸로...
public:
	Card(Shape* Card_sha, int card_n); // default는 false 
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