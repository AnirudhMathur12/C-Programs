#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 93

char character[LENGTH];
int indexes[] = {};

void generatePassword()
{	
	int len;
	printf("How long should the password be? ");
	scanf("%d", &len);
	
	for(int i = 0; i < len; i++)
	{
		int index = rand()%LENGTH;
		printf("%c",character[index]);
	}
	printf("\n");
}

void loadChar()
{
	FILE *fptr;
	fptr = fopen("/Users/anuragmathur/Library/RPG/source.txt", "r");
	if(fptr == NULL)
	{
		perror("Error in loading file");
		exit(1);
	}

	for(int i = 0; i < LENGTH; i++)
	{
		fscanf(fptr, "%c", &character[i]);
	}
}

int main()
{
	printf("Version: 1.0.0\n");
	srand(time(0));
	loadChar();
	char choice = 'y';
	while(1)
	{
		generatePassword();
		printf("Continue? (y/n) ");
		scanf(" %c", &choice);
		if(choice != 'y')
		{
			break;
		}
		
	}
	printf("Bye!");
	return 0;
}
