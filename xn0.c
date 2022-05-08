#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "graphic.h"

#define EX 'X'
#define ZERO '0'
char num[9] ={'1','2','3','4','5','6','7','8','9'};

int full_check(char *dp, char ex, char zero)
{
	int i = 0;
	for (int a = 0;a < 9;a++)
	{
		if (dp[a] == ex || dp[a] == zero)
			i++;
	}
	return i;
}
int position_check(int p, char psym, char oppo)
{	
	if (num[p-1] != psym && num[p -1] != oppo)
	{
		 return 1;
	}
	else{
		printf("there is an error\n");
		return -1;	
	}	
	
}

void replace(int p, char psym){
	num[p-1] = psym;
}

int pattern_check(int p, char psym){
	if(num[0] == psym && num[1] == psym && num[2] == psym)
		return 1;
	else if(num[3] == psym && num[4] == psym && num[5] == psym)
		return 1;
	else if(num[6] == psym && num[7] == psym && num[8] == psym)
		return 1;
	else if(num[0] == psym && num[4] == psym && num[8] == psym)
		return 1;
	else if(num[2] == psym && num[4] == psym && num[6] == psym)
		return 1;
	else if(num[0] == psym && num[3] == psym && num[6] == psym)
		return 1;
	else if(num[1] == psym && num[4] == psym && num[7] == psym)
		return 1;
	else if(num[2] == psym && num[5] == psym && num[8] == psym)
		return 1;
	else
		return 0;
}

int main()
{
	system("clear");
	int p1 = 10, p2 = 10;
	LOAD_SCREEN();
	sleep(1);
while(full_check(num, EX, ZERO) != 9){
/*player 1*/
player1:
	system("clear");
	DISPLAY(num);
	if(full_check(num, EX, ZERO) == 9){
		printf("========ITS A DRAW MATCH PLEASE RESTART==========\n");
		break;
	}
	printf("input for player 1\n");
	scanf("%d", &p1);
	if (p1 <= 9 && p1 > 0)
	{
		if (position_check(p1, ZERO, EX) == 1)
			replace(p1, ZERO);	
		else{
			printf("error\n");
			goto player1;
		}
	}else{
		printf("error 1\n");
		sleep(1);
		goto player1;
	}
	if (pattern_check(p1, ZERO) == 1)
	{
		WINNER_P1();
		break;
	};
/*player 2*/
player2:
	system("clear");
	DISPLAY(num);
	if(full_check(num, EX, ZERO) == 9){
		printf("========ITS A DRAW MATCH PLEASE RESTART==========\n");
		break;
	}
	printf("input for player 2\n");
	scanf("%d", &p2);
	if (p2 <= 9 && p2 > 0)
	{
		if (position_check(p2, EX, ZERO) == 1)
			replace(p2, EX);
		else{
			printf("error\n");
			sleep(1);
			goto player2;
		}
	}
	else{
		printf("error 2\n");
		goto player2;
	}
	if (pattern_check(p2, EX) == 1)
	{
		WINNER_P2();
		break;
	};
}
	return 0;
}
