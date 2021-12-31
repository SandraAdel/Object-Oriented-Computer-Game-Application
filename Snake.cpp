#include "Snake.h"
#include "GameObject.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

}

void Snake::SetBought()
{
}

void Snake::DestructCard()
{
}

bool Snake::IsOverlapping(GameObject * newObj)
{
	return false;
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
