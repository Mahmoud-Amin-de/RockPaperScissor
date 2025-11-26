#include<iostream> 
#include<cstdlib>
#include<ctime>
using namespace std;



enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };

enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";
};

struct stGameResults
{
	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice() {
	return (enGameChoice)RandomNumber(1, 3);
}

void SetWinnerScreenColor(enWinner Winner) {

	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;
	default:
		system("color 6F");
		break;
	}
}

string WinnerName(enWinner Winner)
{
	string arrWinnerNames[3] = { "Player", "Computer", "No Winner" };
	return arrWinnerNames[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::Stone:
		return (RoundInfo.ComputerChoice == enGameChoice::Scissor) ? enWinner::Player : enWinner::Computer;
	case enGameChoice::Paper:
		return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Player : enWinner::Computer;
	case enGameChoice::Scissor:
		return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Player : enWinner::Computer;
	}
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes) return enWinner::Player;
	else if (PlayerWinTimes < ComputerWinTimes) return enWinner::Computer;
	else return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.GameRounds = GameRounds;
	GameResults.PlayerWinTimes = PlayerWinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone", "Paper", "Scissor" };
	return arrGameChoices[Choice - 1];
}



enGameChoice ReadPlayerChoice()
{
	short Choice = 1;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);
	return (enGameChoice)Choice;

}

void PrintRoundResults(stRoundInfo RoundInfo) {


	cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
	cout << "Player Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
	cout << "_________________________________________\n" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);
}

short ReadHowManyRounds()
{
	short GameRounds = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds >10);

	return GameRounds;
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; ++GameRound)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player)
			PlayerWinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}
	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}





string Tabs(short NumberOfTabs) {

	string TabsString = "";

	for (short i = 1; i < NumberOfTabs; ++i) {
		TabsString += "\t";
		cout << TabsString;

	}
	return TabsString;
}


void ShowGameOverScreen()
{
	cout << Tabs(2) << "--------------------------------------------------------- \n\n" << endl;
	cout << Tabs(2) << "                 +++ G a m e O v e r +++                    \n";
	cout << Tabs(2) << "----------------------------------------------------------\n\n" << endl;

}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "-----------------------[Game Results] --------------------- \n\n";
	cout << Tabs(2) << "Game Rounds       :" << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player won times  :" << GameResults.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer won times:" << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw times        :" << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner      :" << GameResults.WinnerName << endl;
	cout << Tabs(2) << "----------------------------------------------------------\n\n";
	SetWinnerScreenColor(GameResults.GameWinner);
}







void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResults(GameResults);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N ? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	// Seeds the random number generator
	srand((unsigned)time(NULL));

	StartGame();


	return 0;
}

