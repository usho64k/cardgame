#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define	COM_ATK		0
#define	COM_CHR		1
#define	COM_DEF		2
#define COM_PWG		3

typedef struct{
	int hp;			//Hit Points
	int eng;		//Energy
	int cmd;		//Command
	int atk;		//Attack
}target_t;

int decideCommand(int energy);
int display(char *arg);
void displayEndfight(bool r);
char inputCommand(void);
void displayField(void);
void readcsv(void);


target_t player = {500,0,0,48};			//Definition of Player
target_t rival = {500,0,0,50};			//Definition of target

//Game Messages
const char Message[6][256]=
{
	"Your Attack is missed!!(Because of lesser energy)\n",
	"Your Attack has Chritical Damage !!!\n",
	"Your Attack has Guarded...\n",
	"You charged  your eng.\n",
	"You guard yourself.\n",
	"it's bug.\n"
};

int main(void)
{
	unsigned char cont = true;			//End Flag
	int mode = 0;					//Mode<?>
	
	srand(time(NULL));				//Initialize Random

	while(cont)
	{
		displayField();				//Show Field
		
		player.cmd = inputCommand();		//Input Player Command
		rival.cmd = decideCommand(rival.eng);	//Input Computer Command
		
		//player turn
		switch(player.cmd)
		{
		case COM_ATK:
			//Attack
			if(player.eng <= 0)
			{
				printf("%s",Message[0]);
			}
			else 
			{
				if(rival.cmd != COM_DEF)
				{
					printf("%s",Message[1]);
					rival.hp -= (player.atk+(rand() % 65536)/8192);
					
				}
				else
				{
					printf("%s",Message[2]);
					rival.hp -= 0;
				}
				player.eng--;
			}
			
			break;
		case COM_CHR:
			//Charge
			printf("%s",Message[3]);
			player.eng++;
			break;
		case COM_DEF:
			//Guard
			printf("%s",Message[4]);
			break;
		default:
			printf("%s",Message[5]);
			break;
		}

		//COM turn
		switch(rival.cmd)
		{
		case COM_ATK:
			//Attack
			if(rival.eng <= 0)
			{
				
			}
			else
			{
				if(player.cmd != COM_DEF)
				{
					player.hp -= rival.atk + (rand() % 65535) / 7562;
				}
				rival.eng--;
			}
			break;
		case COM_CHR:
			//Charge
			rival.eng++;
			break;
		case COM_DEF:
			//Guard
			break;
		default:
			printf("%s",Message[5]);
			break;
		}
		
		//Fighter left judgement.
		if(player.hp <= 0)
		{
			displayEndfight(false);
			cont = false;
		}
		else if(rival.hp <= 0)
		{
			displayEndfight(true);
			cont =false;
		}
		
	}
	return 0;
}

void displayEndfight(bool r)
{
	if(r)
	{
		printf("You Win!!!\n");
		printf("Your HP:%d  vs Rival HP:%d \n",player.hp,rival.hp);
	}
	else
	{
		printf("Game Over...\n");
		printf("Your HP:%d  vs Rival HP:%d \n",player.hp,rival.hp);
		
	}
}

char inputCommand()
{
	char c,c2 = 0;
	while(c2 < 0x30 || c2 > 0x33)
	{
		printf("\nPress '0(A)' or '1(D)' or '2(M) or other(You must be lose)' ...");
		c2 = getchar();
		while((c = getchar()) != '\n');
	}
	return c2-0x30;
}

void displayField(void)
{
	int i;

	printf("Player Eng:");
	for(i = 0; i < player.eng;i++)
	{
		printf("#");
	}
	printf("\r\n");
	//
	printf("Enemy Eng:");
	for(i = 0; i < rival.eng; i++)
	{
		printf("*");
	}
	printf("\r\n");
	printf("Your HP:%d  vs Rival HP:%d \n",player.hp,rival.hp);
}

//Target Command Desider.
int decideCommand(int energy)
{
	int r = 0;
	if(energy <= 0)
	{
		return COM_CHR;
	}
	else
	{
		r = rand() % 65536;		//r < 65535
		if(r < 45875)
		{
			return COM_ATK;
		}
		else if(r < 63120)
		{
			return COM_CHR;
		}
		else
		{
			return COM_DEF;
		}
	}
}
