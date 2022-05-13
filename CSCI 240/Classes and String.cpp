/***************************************************************
CSCI 240         Program 9     Fall 2021

Programmer: Milo Zak, Sebastian Lesny

Section: CSCI 240

Date Due: Dec. 3, 2021

Purpose: This program creates a card class for a game.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

//This class creates a card object to show a singular card in text form

class Card
{
	private:
		int cvalue;
		char s[];
   public:
       void setCard( int faceVal, char suitVals);
       char suit;			 //get suit value
       int faceValue();		//getface value
       void displaycard();
};

/***************************************************************************/


//This creates the entire deck object of 52 cards with fuit suit arrays.

class DeckOfCards
{
public:
DeckOfCards();

Card draw();
void shuffle();
bool isEmpty();

private:
static const int MAX_CARDS = 52; //Maximum number of cards in a deck
static const int NUM_SUITS = 4; //Number of card suits
static const int CARDS_PER_SUIT = 13; //Number of cards of each suit

Card deck[MAX_CARDS]; //The deck of cards
int topCard; //The subscript of the card on the top of the deck

};

int main()
{
	//seeding rand num genorator
	srand(11);
	
	//using methods built
	Card card1;
	DeckOfCards doc1;
	
	//variable
	int sumofCards,
		drawingCards,
		drawCount = 0,
		cast;
	
	//getting cast
	cout<<"How many times do you want to cast?";
	cin>>cast;
	
	//looping for the amount of times player has cast, as long as there are cards
	while(!doc1.isEmpty() && drawCount < cast)
	{
		//showing how many draws
	   drawCount++;
	   cout<<"Draw "<<drawCount<<endl;
	   
		//drawing card
		card1 = doc1.draw();
		
		//if statements for what to do on certain cards
       if(card1.faceValue() == 1)
       {
       		sumofCards = sumofCards + 20;
		   	cout<<"You drew a "<<card1.faceValue()<<" of "<<card1.suit<< " and caught a big fish. 20 points\n";
	   }
	   if(card1.faceValue() == 11)
	   {
	   		sumofCards = sumofCards - 11;
	   		cout<<"You drew a "<<card1.faceValue()<<" of "<<card1.suit<<" and caught an old shoe. -11 points\n";
	   }
	   if(card1.faceValue() == 12)
	   {
	   		sumofCards = sumofCards + 10;
	   		cout<<"you drew a "<<card1.faceValue()<<" of "<<card1.suit<<" and caught a fish. 10 points\n";
	   }
	   if(card1.faceValue() == 13)
	   {
	   		sumofCards = sumofCards + 40;
		   	cout<<"You drew a "<<card1.faceValue()<<" of "<<card1.suit<< " and caught a shark. 40 points\n";
	   }
	   if(card1.faceValue() >= 2 && card1.faceValue() <= 6)
	   {
	   		sumofCards = sumofCards + 5;
		   	cout<<"You drew a "<<card1.faceValue()<<" of "<<card1.suit<< " and caught a goldfish. 5 points\n";
	   }
	   	   if(card1.faceValue() >= 7 && card1.faceValue() <= 10)
	   {
	   		sumofCards = sumofCards -20;
		   	cout<<"You drew a "<<card1.faceValue()<<" of "<<card1.suit<< " and caught a toliet. -20 points\n";
	   }
	}	
	//final total
	cout<<"Your final point total is "<<sumofCards<<" points."<<endl;
	return 0;
}

/***************************************************************
Method: setcard

Use: This method displays the card

Arguments: none

Returns: none
***************************************************************/
void Card::setCard(int faceVal, char suitVals)
{
    //setting the face value since its wrong
   if(faceVal > 13 || faceVal < 1)
   {
       cvalue = 1;
   }
   else
   {
       cvalue = faceVal;
   }
  
   //Setting the Suit value since its probably wrong
   if (suitVals != 'C' && suitVals != 'D' && suitVals != 'H' && suitVals != 'S')
   {
       suit = 'H';
   }
   else
   {
       suit = suitVals;
   }
   
  
}

/***************************************************************
Method: facevalue

Use: This method displays the card value woowwwwwwwwwwww

Arguments: none

Returns: cvalue (card value)
***************************************************************/
int Card::faceValue()
{
     return cvalue;
}

/***************************************************************
Method: displaycard()

Use: This method displays the card woowwwwwwwwwwww

Arguments: none

Returns: ahahaha you thought it would return something
***************************************************************/
void Card::displaycard()
{
	if(cvalue == 1)
	{
		cout<<"Ace of ";
	}
    else if (cvalue == 11)
    {
        cout << "Jack of ";
    }
    else if (cvalue == 12)
    {
        cout << "Queen of ";
    }
    else if (cvalue == 13)
    {
        cout << "King of ";
    }
    else
    {
        cout << "" << cvalue << " of ";
    }

		
	if (suit == 'C')
    cout << "Clubs";

    else if (suit == 'D')
    cout << "Diamonds";

    else if (suit == 'H')
    cout << "Hearts";
    
    else if (suit == 'S')
    cout << "Spades";

}
/***************************************************************
Constructor

Use: This creates a DeckOfCards object and then shuffles the
cards

Arguments: none

Note: -1 is used to signal that no cards have been removed from
the deck
***************************************************************/

DeckOfCards::DeckOfCards()
{
//An array of the 4 possible values for the card suit
char suitVals[NUM_SUITS] = { 'C', 'D', 'H', 'S' };

int cardSub = 0; //subscript to process the deck of cards

//Go through all 52 spots in the array of Cards and put a card
//at the location

for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
{
//For each of the suits, put in all of the cards for the suit
for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
{
//Put the card into the deck
deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );

//Move to the next card in the deck
cardSub++;
}
}

//shuffle the playing cards
shuffle();

//Set the top card location to -1 to indicate the deck is brand new
topCard = -1;
}

/***************************************************************
Method: Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
//Increment to get the subscript of the current top card
topCard++;

//return the card that is currently on the top of the deck
return deck[topCard];
}

/***************************************************************
Method: void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
//Shuffle all 52 cards that are in the deck

random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method: bool isEmpty()

Use: This method determines if the deck of cards is empty( have
all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
return topCard + 1 >= MAX_CARDS;
}
