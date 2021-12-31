#pragma once
#include "Card.h"
class CardFourteen : public Card
{
private:
	bool bought;
	static int Creationcount; //Number of how many times the card was created
	static int Passcount; //Count how many times the card has been pass upon by players
	int CardCost; //Cost the first player pays if bought
	int CardFees; //Fees paid by the player passing by the owned card
public:
	CardFourteen(const CellPosition & pos);

	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void Draw(Output* pOut);

	static bool AlreadyCreated();

	virtual void SetBought();

	virtual void DestructCard();

	virtual bool IsOverlapping(GameObject*newObj);

	virtual ~CardFourteen();
};

