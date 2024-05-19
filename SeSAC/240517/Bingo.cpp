#include <iostream>
#include <time.h>

/*
숫자빙고 게임
1 ~ 25 사이의 숫자를 섞어 줌
무한반복을 하며 5 * 5로 출력
사용자는 숫자를 입력함
입력이 0일 경우 게임 종료
입력이 0 미만 25초과일 경우 다시 입력
숫자를 제대로 입력했다면 해당 숫자를 찾아서 *로 출력
기존에 이미 입력하여 *로 된 숫자는 다시 입력받음
가로5줄, 세로5줄, 대각선 2줄 중에 몇줄이 *로 모두 바뀌었는지 확인
5줄 이상일 경우 게임 종료
*/

void PrintGameBoard(const int* const GameBoard, const bool* const Opened)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int CurrentLoc = i * 5 + j;
			if (Opened[GameBoard[CurrentLoc] - 1])
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
	std::cout << std::endl << std::endl;
}

int CheckBingo(const int* const GameBoard, const bool* const Opened)
{
	int Bingo = 0;

	// 가로, 세로 빙고 확인
	for (int i = 0; i < 5; i++)
	{
		bool VFlag = true;
		bool HFlag = true;

		for (int j = 0; j < 5; j++)
		{
			int VLoc = j * 5 + i;
			int HLoc = i * 5 + j;

			if (!Opened[GameBoard[VLoc] - 1])
			{
				VFlag = false;
			}
			if (!Opened[GameBoard[HLoc] - 1])
			{
				HFlag = false;
			}
		}

		if (VFlag)
		{
			Bingo++;
		}
		if (HFlag)
		{
			Bingo++;
		}
	}

	// 대각선 빙고 확인
	bool DFlag1 = true;
	bool DFlag2 = true;
	for (int i = 0; i < 5; i++)
	{
		int DLoc1 = i * 5 + i;
		int DLoc2 = (i + 1) * 4;

		if (!Opened[GameBoard[DLoc1] - 1])
		{
			DFlag1 = false;
		}
		if (!Opened[GameBoard[DLoc2] - 1])
		{
			DFlag2 = false;
		}
	}

	if (DFlag1)
	{
		Bingo++;
	}
	if (DFlag2)
	{
		Bingo++;
	}

	return Bingo;
}

int Evaluate(const int* const PlayerGameBoard, const int* const AIGameBoard, const bool* const Opened)
{
	int PlayerBingo = CheckBingo(PlayerGameBoard, Opened);
	int AIBingo = CheckBingo(AIGameBoard, Opened);

	int Eval = 0;
	if (PlayerBingo >= 5 && AIBingo >= 5)
	{
		Eval = 0;
	}
	else if (PlayerBingo >= 5)
	{
		Eval = -999;
	}
	else if (AIBingo >= 5)
	{
		std::cout << "ho ";
		Eval = 999;
	}
	else
	{
		Eval = AIBingo * AIBingo * 10 - PlayerBingo * PlayerBingo;
	}

	return Eval;
}

int GreedyAlg(int* GameBoard, bool* Opened, const int* const EvalTable)
{
	int Greedy[25] = {};
	for (int i = 0; i < 25; i++)
	{
		Greedy[i] = 10;
	}

	// 가로, 세로 빙고 확인
	for (int i = 0; i < 5; i++)
	{
		int VFlag = 0;
		int HFlag = 0;

		for (int j = 0; j < 5; j++)
		{
			int VLoc = j * 5 + i;
			int HLoc = i * 5 + j;

			if (!Opened[GameBoard[VLoc] - 1])
			{
				VFlag++;
			}
			if (!Opened[GameBoard[HLoc] - 1])
			{
				HFlag++;
			}
		}

		for (int j = 0; j < 5; j++)
		{
			int VLoc = j * 5 + i;
			int HLoc = i * 5 + j;

			Greedy[GameBoard[VLoc] - 1] = std::min(Greedy[GameBoard[VLoc] - 1], VFlag);
			Greedy[GameBoard[HLoc] - 1] = std::min(Greedy[GameBoard[HLoc] - 1], HFlag);
		}
	}

	// 대각선 빙고 확인
	int DFlag1 = 0;
	int DFlag2 = 0;
	for (int i = 0; i < 5; i++)
	{
		int DLoc1 = i * 5 + i;
		int DLoc2 = (i + 1) * 4;

		if (!Opened[GameBoard[DLoc1] - 1])
		{
			DFlag1++;
		}
		if (!Opened[GameBoard[DLoc2] - 1])
		{
			DFlag2++;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		int DLoc1 = i * 5 + i;
		int DLoc2 = (i + 1) * 4;

		Greedy[GameBoard[DLoc1] - 1] = std::min(Greedy[GameBoard[DLoc1] - 1], DFlag1);
		Greedy[GameBoard[DLoc2] - 1] = std::min(Greedy[GameBoard[DLoc2] - 1], DFlag2);
	}

	int result = -1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int loc = i * 5 + j;
			if (!Opened[GameBoard[loc] - 1])
			{
				if (result == -1)
				{
					result = loc;
					continue;
				}
				if (Greedy[GameBoard[loc] - 1] < Greedy[GameBoard[result] - 1])
				{
					result = loc;
				}
				else if (Greedy[GameBoard[loc] - 1] == Greedy[GameBoard[result] - 1] && EvalTable[loc] > EvalTable[result])
				{
					result = loc;
				}
			}
		}
	}

	return (GameBoard[result] - 1);
}

int MinMax(int* PlayerGameBoard, int* AIGameBoard, bool* Opened, int depth, const int MaxDepth, const int* const EvalTable)
{
	if (depth == MaxDepth)
	{
		return Evaluate(PlayerGameBoard, AIGameBoard, Opened);
	}

	int result = Evaluate(PlayerGameBoard, AIGameBoard, Opened);
	//if (depth % 2)
	//{
	//	result = 9999;
	//}
	//else
	//{
	//	result = -9999;
	//}

	int SearchNode = 0;
	for (int i = 0; i < 25; i++)
	{
		if (!Opened[i])
		{
			if (depth % 2)
			{
				Opened[i] = true;
				result = std::min(result, MinMax(PlayerGameBoard, AIGameBoard, Opened, depth + 1, MaxDepth, EvalTable));
				Opened[i] = false;

				if (result == -999)
				{
					return -999;
				}
			}
			else
			{
				if (depth == 0)
				{
					Opened[i] = true;
					int MinMaxResult = MinMax(PlayerGameBoard, AIGameBoard, Opened, depth + 1, MaxDepth, EvalTable) + EvalTable[i];
					Opened[i] = false;

					std::cout << MinMaxResult << " ";

					if (result < MinMaxResult)
					{
						result = MinMaxResult;
						SearchNode = i;
					}
				}
				else
				{
					Opened[i] = true;
					result = std::max(result, MinMax(PlayerGameBoard, AIGameBoard, Opened, depth + 1, MaxDepth, EvalTable) + EvalTable[i]);
					Opened[i] = false;

					if (result == 999)
					{
						return 999;
					}
				}
			}
		}
	}

	if (depth != 0)
	{
		return result;
	}
	std::cout << std::endl;
	return SearchNode;
}

int main()
{
	int PlayerGameBoard[25] = {};
	int AIGameBoard[25] = {};
	bool Opened[25] = {};
	int PlayerBingo = 0;
	int AIBingo = 0;
	enum Turn
	{
		Player,
		AI
	};
	int CurrentTurn = Player;

	// 초기화
	for (int i = 0; i < 25; i++)
	{
		PlayerGameBoard[i] = i + 1;
		AIGameBoard[i] = i + 1;
	}

	// shuffle
	srand(time(NULL));
	rand();

	for (int i = 25; i > 0; i--)
	{
		// player shuffle
		int RandNum1 = rand() % i;
		int temp1 = PlayerGameBoard[i - 1];
		PlayerGameBoard[i - 1] = PlayerGameBoard[RandNum1];
		PlayerGameBoard[RandNum1] = temp1;

		// ai shuffle
		int RandNum2 = rand() % i;
		int temp2 = AIGameBoard[i - 1];
		AIGameBoard[i - 1] = AIGameBoard[RandNum2];
		AIGameBoard[RandNum2] = temp2;
	}

	// set AI Mode
	enum AIMode
	{
		Random,
		Greedy,
		MiniMax
	};
	int AIMode = Greedy;
	std::cout << "AI Mode 선택" << std::endl;
	std::cout << "1. Random" << std::endl;
	std::cout << "2. Greedy" << std::endl;
	std::cout << "3. MiniMax" << std::endl;
	std::cout << "> ";
	std::cin >> AIMode;
	AIMode--;


	// set Eval Table
	int EvalTable[25] = {};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int Pos = i * 5 + j;
			EvalTable[Pos] = 2;

			if (i == j)
			{
				EvalTable[Pos]++;
			}
			if (4 - i == j)
			{
				EvalTable[Pos]++;
			}
		}
	}
	
	
	while (true)
	{
		system("cls");

		// 플레이어 게임 보드 출력
		std::cout << "[Player] " << PlayerBingo << "Bingo" << std::endl;
		PrintGameBoard(PlayerGameBoard, Opened);

		// AI 게임 보드 출력
		std::cout << "[AI - ";
		if (AIMode == AIMode::Random)
		{
			std::cout << "Random";
		}
		else if (AIMode == AIMode::Greedy)
		{
			std::cout << "Greedy";
		}
		else
		{
			std::cout << "MiniMax";
		}
		std::cout << "] " << AIBingo << "Bingo" << std::endl;
		PrintGameBoard(AIGameBoard, Opened);

		// 게임 종료 조건 확인
		if (PlayerBingo >= 5 && AIBingo >= 5)
		{
			std::cout << "무승부입니다." << std::endl << std::endl;
			break;
		}
		else if (PlayerBingo >= 5)
		{
			std::cout << "축하합니다! 승리했습니다!" << std::endl << std::endl;
			break;
		}
		else if (AIBingo >= 5)
		{
			std::cout << "패배하였습니다." << std::endl << std::endl;
			break;
		}

		// 게임 진행
		if (CurrentTurn == Turn::Player)
		{
			// 플레이어 턴
			
			// 유저 입력
			int input;
			std::cout << "빙고 숫자를 입력해주세요 (0 종료) : ";
			std::cin >> input;

			// 종료
			if (input == 0)
			{
				std::cout << "프로그램을 종료합니다." << std::endl;
				break;
			}

			// 범위 예외처리
			if (input < 0 || input > 25)
			{
				std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
				system("pause");
				continue;
			}

			// 중복 확인
			if (Opened[input - 1])
			{
				std::cout << "이미 입력된 번호입니다. 다시 입력해주세요." << std::endl;
				system("pause");
				continue;
			}

			// 플레이어 입력 처리
			Opened[input - 1] = true;

			// 턴 종료
			CurrentTurn = Turn::AI;
		}
		else
		{
			// AI 턴

			// 남은 노드 계산
			int ClosedCount = 0;
			int ClosedNode[25] = {};

			for (int i = 0; i < 25; i++)
			{
				if (!Opened[i])
				{
					ClosedNode[ClosedCount] = i;
					ClosedCount++;
				}
			}

			if (AIMode == AIMode::Random)
			{
				int random = rand() % ClosedCount;
				Opened[random] = true;
			}
			else if (AIMode == AIMode::Greedy)
			{
				std::cout << "AI 계산중..." << std::endl;
				int result = GreedyAlg(AIGameBoard, Opened, EvalTable);
				Opened[result] = true;
			}
			else
			{
				std::cout << "AI 계산중..." << std::endl;
				int result = MinMax(PlayerGameBoard, AIGameBoard, Opened, 0, 5, EvalTable);
				Opened[result] = true;
			}

			// 턴 종료
			CurrentTurn = Turn::Player;
		}

		// 빙고 확인
		PlayerBingo = CheckBingo(PlayerGameBoard, Opened);
		AIBingo = CheckBingo(AIGameBoard, Opened);		
	}
	

	return 0;
}