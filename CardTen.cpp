#include "CardTen.h"

int CardTen::Creationcount = -1;
int CardTen::Passcount = 0;
CardTen::CardTen(const CellPosition & pos) : Card(pos)
{
	++Creationcount;
	cardNumber = 10;
}

void CardTen::ReadCardParameters(Grid * pGrid)
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

void CardTen::Apply(Grid * pGrid, Player * pPlayer)
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


void CardTen::Draw(Output * pOut)
{
	pOut->DrawCell(position, cardNumber);
}

bool CardTen::AlreadyCreated()
{
	if (Creationcount != 0)
		return true;
	return false;
}

bool CardTen::FirstPass()
{
	if (Passcount == 0)
		return true;
	return false;
}

void CardTen::SetBought()
{
	bought = true;
}

void CardTen::DestructCard()
{
	Creationcount--;
}




CardTen::~CardTen()
{
}

bool CardTen::IsOverlapping(GameObject * newObj)
{
	return false;
}
