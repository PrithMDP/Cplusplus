//simulate a game of blackjack
#include <iostream>
using namespace std;

struct card
{
	string type;
	char number;
};
//make a deck of cards
int main(int agrc, char ** argv)
{

	card deck[52];
	for(int i=0;i<52;i++)
	{
		if(i<13)
		{
			deck[i].type="hearts";
		}
		else if(i>=13 && i<26)
		{
		 	deck[i].type="diamonds";
		}
		else if(i>=26&&i<39)
		{
		 	deck[i].type="clubs";
		}
		 else
		{
		 	deck[i].type="spades";
		}
	}
	for(int i=0;i<13;i++)
	{
		if(i==0)
		{
			deck[i].number='A';
		}
		else if(i%10==0)
		{
			deck[i].number = 'J';
		}
		else if(i%11 == 0)
		{
			deck[i].number='Q';
		}
		else if(i%12 == 0)
		{
			deck[i].number='K';
		}
		else
		{

		}
	}
	for(int i=0;i<52;i++)
	{
		cout<<deck[i].type<<" "<<deck[i].number<<endl;
	}


}