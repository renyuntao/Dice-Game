#include<iostream>
#include<random>
#define WIN_POINTS 100
using std::cout;
using std::cin;
using std::endl;


/*
 * Flag depend show Player1's information
 * or Player2's information
 */
void showInfo(int flag,int score1,int score2,int throwValueSum)
{
	cout<<"\n\n###################### Dice Game ######################\n\n";
	
	cout<<"Player1's Score: "<<score1<<"\n";
	cout<<"Player2's Score: "<<score2<<"\n\n";
	
	// Player1 is in the game
	if(!(flag & 1))
	{
		cout<<"        Now Player1 is in the game\n\n";
	}

	// Player2 is in the game
	else
	{
		cout<<"        Now Player2 is in the game\n\n";
	}

	cout<<"The sum of throw value is: "<<throwValueSum<<"\n";
	cout<<"*********** Select ************\n";
	cout<<"   1. Throw\n";
	cout<<"   2. Stop \n";
	cout<<"*******************************\n";
	cout<<"Input your select [1-2]: ";
}

/*
 * Show win information
 *
 */
void showWinInfo(int flag,int score)
{
	cout<<"\n################## Dice Game Over ####################\n\n";
	// Flag is even number,then Player1 is win
	if(!(flag & 1))
	{
		cout<<"Player1 is Win!\n";
		cout<<"Score: "<<score<<"\n";
	}

	// Flag is odd number,then Player2 is win
	else
	{
		cout<<"Player2 is Win!\n";
		cout<<"Score: "<<score<<"\n";
	}
	cout<<"\n";
	cout<<"######################################################\n";
}

/*
 * Get random value(1-6)
 *
 */
int getRand()
{
	static std::uniform_int_distribution<unsigned> u(1,6);
	static std::default_random_engine e;
	return u(e);
}

void DiceGame()
{
	// Flag depend is Player1 throw or Player2 throw
	int flag = 0;
	int score1 = 0, score2 = 0;

	// Begin Game
	while(true)
	{
		int sum = 0;
		bool gameOver = false;

		showInfo(flag,score1,score2,sum);

		int select;
		cin>>select;

		// Check input
		while(select < 1 || select > 2)
		{
			cout<<"Invalid input,please select again [1-2]:";
			cin>>select;
		}

		bool meetOne = false;

		// Throw
		while(select == 1)
		{
			int throwValue = getRand();

			cout<<"\n--------------------------";
			cout<<"\n\nYour throw number is "<<throwValue<<"\n\n";
			cout<<"--------------------------\n";

			// Should stop
			if(throwValue == 1)
			{
				meetOne = true;
				break;
			}
			
			sum += throwValue;

			// Check whether the game should over
			if(!(flag & 1))
			{
				if(score1 + sum >= WIN_POINTS)
				{
					score1 += sum;
					gameOver = true;
					break;
				}
			}
			else
			{
				if(score2 + sum >= WIN_POINTS)
				{
					score2 += sum;
					gameOver = true;
					break;
				}
			}

			showInfo(flag,score1,score2,sum);

			cin>>select;

			// Check input
			while(select < 1 || select > 2)
			{
				cout<<"Invalid input,please select again [1-2]:";
				cin>>select;
			}
		}

		if(gameOver)
			break;

		// Stop not beacause of meet 1
		if(!meetOne)
		{
			// Player1
			if(!(flag & 1))
				score1 += sum;
			else
				score2 += sum;
		}

		++flag;
	}

	// Show Win Information
	showWinInfo(flag,score1>score2?score1:score2);
}

int main()
{
	// Begin game
	DiceGame();

	return 0;
}
