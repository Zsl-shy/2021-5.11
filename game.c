#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
 
 void InitArr(char arr[ROW][COL], int row, int col){
 	int i=0;
 	int j=0;
 	for(i=0; i<row; i++){
 		for(j=0; j<col; j++){
 			arr[i][j]=' ';
		 }
	 }
 }
 
 void DisplayArr(char arr[ROW][COL], int row, int col){
 	int i=0;
 	int j=0;
 	for(i=0; i<row; i++){
 		 //打印一行的数据 
 		for(j=0; j<col; j++){
 			if(j<col-1){
 				printf(" %c |",arr[i][j]);
			}
			else{
				printf(" %c \n",arr[i][j]);
			}
		}
		//打印分割行 
		if(i<row-1){
			for(j=0; j<col; j++){
 				if(j<col-1){
 					printf("---|",arr[i][j]);
				}
				else{
					printf("---\n",arr[i][j]);
				}
			}
		}
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col){
	int x=0;
	int y=0;
	
	while(1){
		printf("输入坐标：>");//1,1
		scanf("%d,%d", &x, &y);
		if((x>=1 && x<=row) && (y>=1 && y<=col)){
			if(arr[x-1][y-1]==' '){
				arr[x-1][y-1]='*';
				break;
			}
			else{
				printf("坐标已被占用，重新输入\n");
				continue;
			}
		}
		else{
			printf("坐标非法，请重新输入\n");
			continue;
		}
	}
}

void ComMove(char arr[ROW][COL], int row, int col){
	int x=0;
	int y=0;
	//获取随机数 
	x=rand()%row;
	y=rand()%col;
	
	if(arr[x][y]==' '){
		printf("电脑走：>\n");
		arr[x][y]='O';
	}
	else{
		ComMove(arr, ROW, COL);
	}
}

//IsFull
int IsFull(char arr[ROW][COL], int row, int col){
	int i=0;
	int j=0;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			if(i==(row-1) && arr[i][j]==' '){
				return 0;
			}
		}
	}
	return 1;
}

char Winer(char arr[ROW][COL], int row, int col){
	int i;
	int j;
	//行 
	for(i=0; i<row; i++){
		if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] && arr[i][0]!=' '){
			return arr[i][0];	
		}	
	}
	//列 
	for(i=0; i<col; i++){
		if(arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i] && arr[0][i]!=' '){	
			return arr[0][i];	
		}
	}
	//斜
	for(i=0; i<row; i++){
		if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[0][0]!=' '){
			return arr[0][0];
		}
		if(arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0] && arr[0][2]!=' '){
			return arr[0][2];
		}
	}
	//平局
		if(1==IsFull(arr, ROW, COL)){
			return 'q';
		}

}
