#include "CardEleven.h"



int CardEleven::Creationcount = -1;
int CardEleven::Passcount = 0;
CardEleven::CardEleven(const CellPosition & pos) : Card(pos)
{
	bought = false;
	++Creationcount;
	cardNumber = 10;
}

void CardEleven::ReadCardParameters(Grid * pGrid)
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

void CardEleven::Apply(Grid * pGrid, Player * pPlayer)
{
	Output*POut = pGrid->GetOutput();
	Input*PIn = pGrid->GetInput();
	if (Passcount == 0 || bought == false) //Check if it is the first time passing by the card
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



void CardEleven::Draw(Output * pOut)
{
	pOut->DrawCell(position, cardNumber);
}

bool CardEleven::AlreadyCreated()
{
	if (Creationcount != 0)
		return true;
	return false;
}

bool CardEleven::FirstPass()
{
	if (Passcount == 0)
		return true;
	return false;
}

void CardEleven::SetBought()
{
	bought = true;
}

void CardEleven::DestructCard()
{
	Creationcount--;
}

bool CardEleven::IsOverlapping(GameObject * newObj)
{
	return false;
}


CardEleven::~CardEleven()
{
}
