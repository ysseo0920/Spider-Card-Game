#pragma once
class Card
{
private:
	int card_num;
	Shape card_shape;
	//GUI �����ų�� �̹��� ���� ���� �ʿ��ϴ�.
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