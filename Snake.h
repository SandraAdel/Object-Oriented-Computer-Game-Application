#pragma once

#include "CellPosition.h"
#include "Grid.h"
#include "Cell.h"
class GameOject;
class Snake :public GameObject
{
	CellPosition endCellPos;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snake by moving player to ladder's end cell

	virtual void SetBought();
	virtual void DestructCard();
	virtual bool IsOverlapping(GameObject*newObj);
	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor
};

