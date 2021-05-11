#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void menu(){
	printf("*********************************************\n");
	printf("**********1.开始游戏     0.退出游戏**********\n");
	printf("*********************************************\n");
}

void game(){
	int ret=0;
	//数组-存放棋盘信息 
	char arr[ROW][COL]={0};//全部空格 
	//初始化棋盘 
	InitArr(arr, ROW, COL); 
	//打印棋盘
	DisplayArr(arr, ROW, COL); 
	
	//下棋 
	printf("玩家先走,");
	while(1){
		//玩家先走 
		PlayerMove(arr, ROW, COL);
		DisplayArr(arr, ROW, COL); 
		
		//电脑走
		ComMove(arr, ROW, COL);
		DisplayArr(arr, ROW, COL);
		
		//三子一线为生者--判断赢家 
		ret=Winer(arr, ROW, COL);
		 
		if(ret=='*'){
			printf("玩家获胜，游戏结束\n");
			break;
		}
		if(ret=='O'){
			printf("电脑胜，游戏结束\n");
			break;
		}
		if(ret=='q'){
			printf("平局\n");
			break;
		}
	}
}

int main() {
	int input=0;
	srand((unsigned int)time(NULL));//时间戳 
	do{
		menu();
		printf("请选择>:");
		scanf("%d",&input);
		switch(input){
			case 1:
				printf("三子棋\n");
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			defaulf:
				printf("选择错误\n");
				break;
		}
		printf("\n");
	}while(input);
	return 0;
}

