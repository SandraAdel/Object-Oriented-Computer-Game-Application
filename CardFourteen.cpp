#include "CardFourteen.h"



int CardFourteen::Creationcount = -1;
int CardFourteen::Passcount = 0;
CardFourteen::CardFourteen(const CellPosition & pos) : Card(pos)
{
	++Creationcount;
	cardNumber = 10;
}

void CardFourteen::ReadCardParameters(Grid * pGrid)
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

void CardFourteen::Apply(Grid * pGrid, Player * pPlayer)
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
			pGrid->BuyThisCard(this);
			++Passcount;
		}
	}
	else
		pPlayer->SetWallet(pPlayer->GetWallet() - CardFees);
}

void CardFourteen::Draw(Output * pOut)
{
	pOut->DrawCell(position, cardNumber);
}

bool CardFourteen::AlreadyCreated()
{
	if (Creationcount != 0)
		return true;
	return false;
}

void CardFourteen::SetBought()
{
	bought = true;
}

void CardFourteen::DestructCard()
{
	Creationcount--;
}

bool CardFourteen::IsOverlapping(GameObject * newObj)
{
	return false;
}



CardFourteen::~CardFourteen()
{
}

