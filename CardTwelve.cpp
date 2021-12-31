#include "CardTwelve.h"

int CardTwelve::Creationcount = -1;
int CardTwelve::Passcount = 0;
CardTwelve::CardTwelve(const CellPosition & pos) : Card(pos)
{
	++Creationcount;
	cardNumber = 10;
}

void CardTwelve::ReadCardParameters(Grid * pGrid)
{
	if (AlreadyCreated() == true)
		return;
	Output*POut = pGrid->GetOutput();
	Input*PIn = pGrid->GetInput();
	POut->PrintMessage("Please enter the card cost:  ");
	CardCost = PIn->GetInteger(POut);
	POut->PrintMessage("Now, please enterthe card fees:  ");
	CardFees = PIn->GetInteger(POut);
	POut->ClearStatusBar();
}

void CardTwelve::Apply(Grid * pGrid, Player * pPlayer)
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

void CardTwelve::Draw(Output * pOut)
{
	pOut->DrawCell(position, cardNumber);
}

bool CardTwelve::AlreadyCreated()
{
	if (Creationcount != 0)
		return true;
	return false;
}

bool CardTwelve::FirstPass()
{
	if (Passcount == 0)
		return true;
	return false;
}

void CardTwelve::SetBought()
{
	bought = true;
}

void CardTwelve::DestructCard()
{
	Creationcount--;
}

CardTwelve::~CardTwelve()
{
}

bool CardTwelve::IsOverlapping(GameObject * newObj)
{
	return false;
}

