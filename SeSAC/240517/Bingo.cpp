#include <iostream>
#include <time.h>

void InitGameBoard(int* GameBoard)
{
	// initialize
	for (int i = 0; i < 25; i++)
	{
		GameBoard[i] = i + 1;
	}

	// shuffle
	for (int i = 25; i > 0; i--)
	{
		int RandNum = rand() % i;
		int temp = GameBoard[i - 1];
		GameBoard[i - 1] = GameBoard[RandNum];
		GameBoard[RandNum] = temp;
	}
}

void PrintGameBoard(int* GameBoard, bool* Open)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int CurrentLoc = i * 5 + j;
			if (Open[CurrentLoc])
			{
				std::cout << "*" << "\t";
			}
			else
			{
				std::cout << GameBoard[CurrentLoc] << "\t";
			}
		}
		std::cout << std::endl;
	}
}

int FindPos(int* GameBoard, int input)
{
	int Pos = -1;

	for (int i = 0; i < 25; i++)
	{
		if (GameBoard[i] == input)
		{
			Pos = i;
			break;
		}
	}
	
	return Pos;
}

void Input(int* GameBoard, bool* Open, int input)
{
	int Pos = FindPos(GameBoard, input);
	Open[Pos] = true;
}

int CheckBingo(bool* Open)
{
	int Bingo = 0;

	for (int i = 0; i < 5; i++)
	{
		bool HFlag = true;
		for (int j = 0; j < 5; j++)
		{
			int CurrentLoc = i * 5 + j;

			if (!Open[CurrentLoc])
			{
				HFlag = false;
				break;
			}
		}

		if (HFlag)
		{
			Bingo++;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		bool VFlag = true;
		for (int j = 0; j < 5; j++)
		{
			int CurrentLoc = j * 5 + i;

			if (!Open[CurrentLoc])
			{
				VFlag = false;
				break;
			}
		}

		if (VFlag)
		{
			Bingo++;
		}
	}

	bool DFlag1 = true;
	for (int i = 0; i < 5; i++)
	{
		int CurrentLoc = i * 5 + i;
		if (!Open[CurrentLoc])
		{
			DFlag1 = false;
			break;
		}
	}
	if (DFlag1)
	{
		Bingo++;
	}

	bool DFlag2 = true;
	for (int i = 0; i < 5; i++)
	{
		int CurrentLoc = (i + 1) * 5 - i;
		if (!Open[CurrentLoc])
		{
			DFlag2 = false;
			break;
		}
	}
	if (DFlag2)
	{
		Bingo++;
	}

	return Bingo;
}

int MinMax(bool* Open)
{

}

int Evaluate(bool* Open)
{
	MinMax(Open);

	return 0;
}

int main()
{
	// initialize
	int PlayerGameBoard[25] = {};
	int AIGameBoard[25] = {};
	bool PlayerOpen[25] = {};
	bool AIOpen[25] = {};
	int PlayerBingo = 0;
	int AIBingo = 0;

	// shuffle
	srand(time(NULL));
	rand();
	InitGameBoard(PlayerGameBoard);
	InitGameBoard(AIGameBoard);
	
	while (true)
	{
		system("cls");

		// print player gameboard
		std::cout << "[Player] " << PlayerBingo << "Bingo" << std::endl;
		PrintGameBoard(PlayerGameBoard, PlayerOpen);
		std::cout << std::endl << std::endl;

		// print ai gameboard
		std::cout << "[AI] " << AIBingo << "Bingo" << std::endl;
		PrintGameBoard(AIGameBoard, AIOpen);
		std::cout << std::endl << std::endl;

		// check win condition;
		if (PlayerBingo == 5)
		{
			std::cout << "축하합니다! 승리했습니다!" << std::endl << std::endl;
			break;
		}

		if (AIBingo == 1)
		{
			std::cout << "패배하였습니다." << std::endl << std::endl;
			break;
		}

		// user input
		int input;
		std::cout << "빙고 숫자를 입력해주세요 (0 종료) : ";
		std::cin >> input;

		if (input == 0)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;
			break;
		}
		else if (input < 0 || input > 25)
		{
			std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
			system("pause");
			continue;
		}
		else if (PlayerOpen[FindPos(PlayerGameBoard, input)])
		{
			std::cout << "이미 입력된 번호입니다. 다시 입력해주세요." << std::endl;
			system("pause");
			continue;
		}

		Input(PlayerGameBoard, PlayerOpen, input);
		PlayerBingo = CheckBingo(PlayerOpen);

		if (PlayerBingo == 5)
		{
			continue;
		}

		int AIInput = Evaluate(AIOpen);
		Input(AIGameBoard, AIOpen, AIGameBoard[AIInput]);
		AIBingo = CheckBingo(AIOpen);
	}
	

	return 0;
}