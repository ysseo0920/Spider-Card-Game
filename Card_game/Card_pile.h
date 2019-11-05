#pragma once
#include<list>
#include"Card.h"
#include"Rule.h"

class Card_pile
{
	std::list<Card> Cards;
public:
	bool add(Card new_card);
	bool add(Card new_card,Rule checking_Rule);
	void printing();

	Card_pile();
	~Card_pile();
};

