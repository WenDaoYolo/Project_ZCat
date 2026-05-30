#include<stdio.h>
#include<windows.h>
#include<time.h>

#define ROW 3										//定义棋盘参数
#define COL 3
enum GAMESTATUS{CONTINUE,DRAW,PWIN,CWIN};			//定义游戏状态

void PrintMenu();									//打印游戏菜单
void PrintRule();									//打印游戏规则
void Reboard(char board[ROW][COL]);					//初始化棋盘
void PrintBoard(char board[ROW][COL]);			    //打印棋盘
void PlayerMove(char board[ROW][COL]);				//玩家回合
void ComputerMove(char board[ROW][COL]);			//电脑回合
GAMESTATUS GetGameStatus(char board[ROW][COL]);     //获取游戏状态
int JudgmentGameStatus(GAMESTATUS GameStatus);      //判断游戏状态