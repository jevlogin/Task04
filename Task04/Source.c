#include "Header.h"

void Solution8Ferzei()
{
	Zero(M, N, board);
	SearchSolution(1);
	printf("\n\n");
	Print(N, M, board);
}

int SearchSolution(int n)
{
	if (CheckBoard() == 0)
	{
		return 0;
	}
	if (n == 9)
	{
		return 1;
	}
	int row;
	int col;
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < M; col++)
		{
			if (board[row][col] == 0)
			{
				board[row][col] = n;
				if (SearchSolution(n + 1))
				{
					return 1;
				}
				board[row][col] = 0;
			}
		}
	}
	return 0;
}

//	проверка всей доски
int CheckBoard()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (board[i][j] != 0)
			{
				if (CheckQueen(i, j) == 0)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//	Проверка определенного ферзя
int CheckQueen(int x, int y)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (board[i][j] != 0)
			{
				if (!(i == x && j == y))
				{
					if (i - x == 0 || j - y == 0)
					{
						return 0;
					}
					if (abs(i - x) == abs(j - y))
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

//	Выводим доску на экран
void Print(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

//	Очищаем доску
void Zero(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = 0;
		}
	}
}

// Sequence
void SearchSequence()
{
	printf("Enter 1st sequence:");
	scanf("%s", x);
	printf("Enter 2nd sequence:");
	scanf("%s", y);
	printf("\nThe Longest Common Subsequence is ");
	lcs();
	print(m, n);
}

//	Домашнее задание
void HomeTask()
{
	//	srand для получения разных значений random
	srand(time(NULL));

	//	наш массив
	int A[N][M];
	//	массив с препятствиями
	int Map[N][M];
	//	Счетчик препятствий
	int countMap = 0;

	//	Заполнение дополнительного массива 0 и единицами 0 - препятствие обозначается константой #define P 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (countMap < P)
			{
				Map[i][j] = rand() % 2;	//	Вроде как случайное число от 0 до 1 включительно
			}
			else
			{
				Map[i][j] = 1;
			}
			if (Map[i][j] == 0)
			{
				countMap++;
			}
		}
	}
	//Print(N, M, Map);	//	вывод таблицы с рандомными значениями

	int i, j;	//TODO	У меня вопрос, зачем вот таким образом выделять память для i, j?? 
				//	Разве не лучше выделить для них место в цикле, чтобы по завершению работы, даные очищались?
	for (j = 0; j < M; j++)
	{
		if (Map[0][j] == 0)
		{
			A[0][j] = 0;	//	Первая строка
		}
		else
		{
			A[0][j] = 1;
		}
		//A[0][j] = 1;	//	Первая строка
	}
	for (i = 1; i < N; i++)
	{
		if (Map[i][0] == 0)
		{
			A[i][0] = 0;
		}
		else
		{
			A[i][0] = 1;
		}

		for (j = 1; j < M; j++)
		{
			if (Map[i][j] == 1)
			{
				A[i][j] = A[i][j - 1] + A[i - 1][j];
			}
			else
			{
				A[i][j] = 0;
			}
		}
	}

	Print(N, M, A);
}

void print(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 'c')
	{
		print(i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (b[i][j] == 'u')
		print(i - 1, j);
	else
		print(i, j - 1);
}


void lcs()
{
	m = strlen(x);
	n = strlen(y);

	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;


	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 'c';
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 'u';
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 'l';
			}
		}
}

