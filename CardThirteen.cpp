#include "CardThirteen.h"



int CardThirteen::Creationcount = -1;
int CardThirteen::Passcount = 0;
CardThirteen::CardThirteen(const CellPosition & pos) : Card(pos)
{
	++Creationcount;
	cardNumber = 10;
}

void CardThirteen::ReadCardParameters(Grid * pGrid)
{
	if (AlreadyCreated() == true)
		return;
	Output*POut = pGrid->GetOutput();
	Input*PIn = pGrid->GetInput();
	POut->PrintMessage("Please enter the card cost:  ");
	CardCost = PIn->GetInteger(POut);
	POut->PrintMessage("Now, please enterthe card fees:  ");
	CardFees = PIn->GetInteger(POut);
	Draw(POut);
	POut->ClearStatusBar();
}

void CardThirteen::Apply(Grid * pGrid, Player * pPlayer)
{
	Output*POut = pGrid->GetOutput();
	Input*PIn = pGrid->GetInput();
	if (Passcount == 0) //Check if it is the first time passing by the card
	{
		POut->PrintMessage("Would you like to buy this cell? (y/n): ");
		string choice = PIn->GetSrting(POut);
		if (choice == "y") //Check if the player wants to buy the card
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - CardCost);
			++Passcount;
		}
	}
	else
		pPlayer->SetWallet(pPlayer->GetWallet() - CardFees);
}

void CardThirteen::Draw(Output * pOut)
{
	pOut->DrawCell(position, cardNumber);
}

bool CardThirteen::AlreadyCreated()
{
	if (Creationcount != 0)
		return true;
	return false;
}

bool CardThirteen::FirstPass()
{
	if (Passcount == 0)
		return true;
	return false;
}

void CardThirteen::SetBought()
{
	bought = true;
}

void CardThirteen::DestructCard()
{
	Creationcount--;
}

CardThirteen::~CardThirteen()
{
}

bool CardThirteen::IsOverlapping(GameObject * newObj)
{
	return false;
}
