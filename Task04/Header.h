#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#define M 8
#define N 8
#define P 8

int board[N][M];
int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

int SearchSolution(int n);
void Solution8Ferzei();
int CheckBoard();
int CheckQueen(int x, int y);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);
void SearchSequence();
void lcs();
void print(int i, int j);
void HomeTask();
