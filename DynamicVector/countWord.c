#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LINE_LENGTH 256
#define OUT 0
#define IN 1

char line[LINE_LENGTH];
void show(const char* , int );
void countWords(void);

int  main(int argc, char const *argv[])
{
	/* code */

	countWords();


	return 0;
}

void countWords()
{

	int numberOfWords = 0;
	int STATE  = OUT;
	puts("Enter string");
	fgets(line,LINE_LENGTH,stdin);


	for(int i = 0; i < strlen(line); i++)
	{
		
		if(STATE == OUT && (!isspace(line[i])) )
		{
			STATE = IN;
			numberOfWords++;
		}else if(STATE == IN && isspace(line[i]))
		{
			STATE = OUT;
		}
	}

	show(line,numberOfWords);

}

void show(const char* string, int totalWords)
{
	printf("%s\n",string );
	printf("Total Words = %d\n",totalWords);
}