#include "Card.h"




Card::Card(Shape* Card_sha, int card_n)
{
	card_shape = Card_sha;
	card_num = card_n;
	open = false;
}

Card::Card(Shape* Card_sha, int card_n, bool is_open)
{
	card_shape = Card_sha;
	card_num = card_n;
	open = is_open;
}

int Card::getCardNum()
{
	return card_num;
}

Shape* Card::getCardShape()
{
	return card_shape;
}

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

void Card::printing()
{
	std::cout << "Card_num" << card_num << std::endl << "Card_shape : ";
	getCardShape()->print_shape;
	std::cout << "(" << getCardShape()->get_name << std::endl;
	std::cout << std::endl << "Card_open? : ";
	if (open)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl;
}

bool Card::is_open()
{
	return open;
}

void Card::set_open()
{
	open = true;
}

void Card::set_open(bool opening)
{
	open = opening;
}


Card::~Card()
{
}
