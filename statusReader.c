#include "cfile.h"
#include <stdio.h>

typedef struct st_pl
{
	char name[21];
	int val1;		//life point
	int val2;		//skills point
	int val3;		//level
	int val4;		//attackersion
}ST_PARAM;


int openFile(void)
{
	FILE *fp;
	char fname[] = "cStatus.txt";
	char chr;
	char temp[256];
	int i = 0, j = 0, wPtr = 0, element = 0;
	int tempA = 0, tempB = 0, tempC = 0;

	fp = fopen(fname "r");
	if(fp == NULL)
	{
		printf("%s file not open! \r\n",fname);
		return -1;
	}
	
	while((chr = fgetc(fp)) != EOF)
	{
		//I thought it is csv file type.
		if(chr == ',')
		{
			char temp2[21];
			//separate each element.
			switch(element)
			{
			case 0:
				for(j = 0; (j < i - 1) || (j < 21); j++)
				{
					temp2[j] = temp[j];
				}
				break;
			case 1:
				tempA = (int)strtol(temp,NULL,10);
				break;
			case 2:
				tempB = (int)strtol(temp,NULL,10);
				break;
			case 3:
				tempC = (int)strtol(temp,NULL,10);
				break;
			}

			//memory temporary clear.
			for( j = 0; j < 256; j++)
			{
				temp[j] = 0x00;
			}

			//count control
			element++;
			i = 0;
		}
		else if(chr == '\n')
		{
			//setting Data.
			ST_PARAM s;

			strcpy(s.name,temp2);
			s.val1 = tempA;
			s.val2 = tempB;
			s.val3 = tempC;
			s.val4 = tempD;
			
			if(wPtr < 10)
			{
				setData(wPtr,&s);
				wPtr++;
			}
			//count control
			i = 0;
			element = 0;
		}
		else
		{
			//copying temporary
			temp[i] = chr;
			i++;
		}
	}
	fclose(fp);
	return 0;
}
