#pragma once
class Card
{
private:
	int card_num;
	Shape card_shape;
	//GUI 적용시킬때 이미지 같은 것이 필요하다.
public:
	Card();
	Card(Shape Card_sha, int card_n);
	int getCardNum();
	Shape getCardShape();
	~Card();
};

enum Shape {
	Spade,
	Diamond,
	Heart,
	Clober
};