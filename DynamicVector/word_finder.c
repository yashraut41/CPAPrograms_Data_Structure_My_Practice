/*
	Yashwant Raut™️ 11 09 2021
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>

#define SUCCESS 1
#define OUT 1
#define IN 0
#define MAX_LINE_LENGTH 256

char line[MAX_LINE_LENGTH];

typedef int ret_t;
struct new_word
{
	char* word;
	int lineNumber;
	int wordNumber;
};

struct vectorOfWords
{
	struct new_word  **p_words;
	size_t size;
};


void push_back(struct vectorOfWords* p_vec_word, struct new_word *word);
void show(struct vectorOfWords *p_vec_word);
struct vectorOfWords* create_vector_words();
ret_t destroy_vector(struct vectorOfWords *p_vec_word);
void build_vector_of_words(struct vectorOfWords *,const char*);
ret_t find_word_and_print(struct vectorOfWords *p_vec_word, const char* word);


int main(int argc, char const *argv[])
{

	if(argc < 3)
	{
		fprintf(stderr,"Usage Error %s file_name word_to_find", argv[0]);
		exit(EXIT_FAILURE);
	}

	ret_t ret;

	//create vector of struct new_word
	struct vectorOfWords *p_vec_word = NULL;

	p_vec_word = create_vector_words();
	assert(p_vec_word != NULL);

	//build vector of words from input file
	build_vector_of_words(p_vec_word,argv[1]);

	// show(p_vec_word);
	ret = find_word_and_print(p_vec_word,argv[2]);
	assert(ret!= 0);

	ret = destroy_vector(p_vec_word);
	assert(ret == SUCCESS);


	return 0;
}


struct vectorOfWords* create_vector_words()
{
	struct vectorOfWords *p_vec_word = NULL;
	p_vec_word =(struct vectorOfWords *)malloc(sizeof(struct vectorOfWords));
	assert(p_vec_word != NULL);

	p_vec_word->p_words = NULL;
	p_vec_word->size = 0;

	return p_vec_word;
}

void build_vector_of_words(struct vectorOfWords *p_vec_word,const char* path_name)
{	

	int STATE = OUT;
	int start_index = 0;
	int end_index = 0;
	int word_len = 0;
	char* dup_word = NULL;
	struct new_word* p_new_word = NULL;
	int wordNumberCount = 0;
	int lineNumberCount = 0; 

	//File Pointer
	FILE* fp = fopen(path_name,"r");

	//first read line from file
	while(fgets(line,MAX_LINE_LENGTH,fp))
	{
		lineNumberCount = lineNumberCount + 1;
		//REMOVE all special characters from line
		for(int i = 0; i < strlen(line); i++)
		{
			if(!isalnum(line[i]))
			{
				line[i]=' ';
			}
		}

		/*	 Now separate worda from line and build struct word 
			 of that single word and send that struct word to vectorOfWords  */
		wordNumberCount = 0;
		int lineLegth = strlen(line);
		for(int i = 0; i < lineLegth ; i++)
		{
			if(STATE == OUT && (!isspace(line[i])) )
			{
				STATE = IN;
				start_index = i;
				wordNumberCount = wordNumberCount + 1;
			}
			else if(STATE == IN && isspace(line[i]))
			{
				STATE = OUT;
				
				end_index = i;

				line[end_index] = '\0';

				word_len = end_index - start_index;
				dup_word =(char *)malloc(word_len+1);
				
				strncpy(dup_word,&line[start_index],word_len);

				//now create struct word
				p_new_word =(struct new_word*)malloc(sizeof(struct new_word));
				assert(p_new_word != NULL);

				p_new_word->word = (char *)malloc(word_len+1);
				assert(p_new_word->word != NULL);

				p_new_word->word = dup_word;
				p_new_word->wordNumber = wordNumberCount;
				p_new_word->lineNumber = lineNumberCount;

				push_back(p_vec_word,p_new_word);

			}
		}
	}

}

void push_back(struct vectorOfWords* p_vec_word, struct new_word *inWord)
{
	p_vec_word->p_words = (struct new_word**)realloc(p_vec_word->p_words,sizeof(struct new_word*) *(p_vec_word->size + 1));
	assert(p_vec_word->p_words != NULL);

	p_vec_word->size = p_vec_word->size + 1;

	p_vec_word->p_words[p_vec_word->size - 1]=(struct new_word *)malloc(sizeof(struct new_word));
	assert(p_vec_word->p_words[p_vec_word->size - 1]);

	p_vec_word->p_words[p_vec_word->size - 1]->word = inWord->word;
	p_vec_word->p_words[p_vec_word->size - 1]->lineNumber = inWord->lineNumber;
	p_vec_word->p_words[p_vec_word->size - 1]->wordNumber = inWord->wordNumber;

}

void show(struct vectorOfWords *p_vec_word)
{
	for (int i = 0; i < p_vec_word->size; ++i)
	{
		/* code */
		printf("Line -> %s\n",p_vec_word->p_words[i]->word);
		printf("LineNumber -> %d\n",p_vec_word->p_words[i]->lineNumber);
		printf("wordNumber -> %d\n",p_vec_word->p_words[i]->wordNumber);
	printf("\n\n");

	}
}

ret_t destroy_vector(struct vectorOfWords *p_vec_word)
{
	for (int i = 0; i < p_vec_word->size; ++i)
	{
		/* code */
		free(p_vec_word->p_words[i]);
		free(p_vec_word->p_words[i]->word);
	}
	free(p_vec_word->p_words);
	free(p_vec_word);
	return SUCCESS;
}

ret_t find_word_and_print(struct vectorOfWords *p_vec_word, const char* searchedWord)
{	
	int isFind = 0;

	for (int i = 0; i < p_vec_word->size; ++i)
	{
		/* code */
		if(strcmp(searchedWord,p_vec_word->p_words[i]->word) == 0)
		{
					/* code */
			isFind = 1;
			printf("Line -> %s\n",p_vec_word->p_words[i]->word);
			printf("LineNumber -> %d\n",p_vec_word->p_words[i]->lineNumber);
			printf("wordNumber -> %d\n",p_vec_word->p_words[i]->wordNumber);
			printf("\n\n");

		}
	}

	return isFind;
}
