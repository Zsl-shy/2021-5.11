#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void menu(){
	printf("*********************************************\n");
	printf("**********1.��ʼ��Ϸ     0.�˳���Ϸ**********\n");
	printf("*********************************************\n");
}

void game(){
	int ret=0;
	//����-���������Ϣ 
	char arr[ROW][COL]={0};//ȫ���ո� 
	//��ʼ������ 
	InitArr(arr, ROW, COL); 
	//��ӡ����
	DisplayArr(arr, ROW, COL); 
	
	//���� 
	printf("�������,");
	while(1){
		//������� 
		PlayerMove(arr, ROW, COL);
		DisplayArr(arr, ROW, COL); 
		
		//������
		ComMove(arr, ROW, COL);
		DisplayArr(arr, ROW, COL);
		
		//����һ��Ϊ����--�ж�Ӯ�� 
		ret=Winer(arr, ROW, COL);
		 
		if(ret=='*'){
			printf("��һ�ʤ����Ϸ����\n");
			break;
		}
		if(ret=='O'){
			printf("����ʤ����Ϸ����\n");
			break;
		}
		if(ret=='q'){
			printf("ƽ��\n");
			break;
		}
	}
}

int main() {
	int input=0;
	srand((unsigned int)time(NULL));//ʱ��� 
	do{
		menu();
		printf("��ѡ��>:");
		scanf("%d",&input);
		switch(input){
			case 1:
				printf("������\n");
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			defaulf:
				printf("ѡ�����\n");
				break;
		}
		printf("\n");
	}while(input);
	return 0;
}

