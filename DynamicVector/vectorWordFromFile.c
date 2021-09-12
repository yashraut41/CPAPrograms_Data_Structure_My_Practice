#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

#define SUCCESS 1
#define MAX_LINE_LENGTH 256
typedef int ret_t;
char line[MAX_LINE_LENGTH];

#define OUT 1
#define IN  2

struct vectorWords
{
	char **p_words;
	size_t size;
};

struct vectorWords* create_Vector_words();
void show(struct vectorWords *p_vec_word);
ret_t push_back(struct vectorWords *p_vec_word, char *new_word);
ret_t destroy_vector(struct vectorWords *p_vec_word);
void removeSpecialCharacters(FILE*);
void separateWords(struct vectorWords* p_vec_word,char* new_line);
ret_t searchWord(const char*);

char *dup_line = NULL;
int length = 0;
ret_t ret;
struct vectorWords* p_vec_word = NULL;


int main(int argc, char const *argv[])
{
	/* code */

	if(argc!=3)
	{
		fprintf(stderr, "Usage Error %s  file_name word_to_find \n",argv[0]);
		exit(EXIT_FAILURE);
	}

	
	//OPEN file 
	FILE* fp =fopen(argv[1],"r");
	assert(fp);


	//create empty vector of words
	p_vec_word = create_Vector_words();
	assert(p_vec_word != NULL);
	

 	//get string from file and remove special character from string
	removeSpecialCharacters(fp);

	

	//print vector of words
	show(p_vec_word);

	//search word 
	ret = searchWord(argv[2]);
	if(ret == 0)
	{
		printf("%s -> not found in file\n",argv[2]);
	}else
	{
		printf("%s -> found in file.\n Total wordCount = %d\n",argv[2],ret);
	}

	ret = destroy_vector(p_vec_word);
	assert(ret == SUCCESS);

	p_vec_word = NULL;



	return 0;
}

void removeSpecialCharacters(FILE* filePointer)
{	
	
	while(fgets(line,MAX_LINE_LENGTH,filePointer))
	{
		length = strlen(line);

		dup_line =(char*)malloc(length);
		strncpy(dup_line,line,length);


		for (int i = 0; i < length; ++i)
		{
			if(!isalnum(dup_line[i]))
			{
				dup_line[i]=' ';
			}
		}

	//now from that string seprate words and create vector of those words 
	separateWords(p_vec_word,dup_line);
	}

	

}
void separateWords(struct vectorWords* p_vec_word,char * dup_line)
{
    char *dup_word = NULL;
 	int end_index = 0;
	int start_index = 0;
	int word_len = 0;
	int STATE = OUT;



	for (int i = 0; i < length; ++i)
	{
		/* code */
		if(STATE == OUT && (!isspace(dup_line[i])) )
		{
			STATE = IN;
			start_index = i;

		}else if(STATE == IN && isspace(dup_line[i]))
		{
			STATE = OUT;
			
			end_index = i;
			
			dup_line[end_index] = '\0';
			
			word_len = end_index - start_index;
			
			dup_word = (char *)malloc(word_len + 1);
			strncpy(dup_word,&dup_line[start_index], word_len);
			
			ret = push_back(p_vec_word,dup_word);
			assert(ret == SUCCESS);

		}

	}
}


struct vectorWords* create_Vector_words()
{
	struct vectorWords *p_vec_word = NULL;

	p_vec_word = (struct vectorWords *)malloc(sizeof(struct vectorWords));
	assert(p_vec_word != NULL);

	memset(p_vec_word,0,sizeof(struct vectorWords));

	p_vec_word->p_words = NULL;
	p_vec_word->size = 0;

	return p_vec_word;
}

ret_t push_back(struct vectorWords *p_vec_word,char *new_word)
{
	p_vec_word->p_words =(char**)realloc(p_vec_word->p_words, sizeof(char *)*(p_vec_word->size+1));
	assert(p_vec_word->p_words != NULL);

	p_vec_word->size = p_vec_word->size + 1;
	p_vec_word->p_words[p_vec_word->size - 1] = new_word;

	return SUCCESS;
}

void show(struct vectorWords *p_vec_word)
{
	for (int i = 0; i < p_vec_word->size; ++i)
	{
		printf("%s\n",p_vec_word->p_words[i]);
	}
}

ret_t destroy_vector(struct vectorWords *p_vec_word)
{
	for (int i = 0; i < p_vec_word->size; ++i)
	{
		free(p_vec_word->p_words[i]);
		/* code */
	}
	free(p_vec_word->p_words);
	free(p_vec_word);

	return SUCCESS;
}

ret_t searchWord(const char* findWord)
{
	int wordCount = 0;

	for(int i = 0; i < p_vec_word->size;i++)
	{
		if(strcmp(findWord, p_vec_word->p_words[i]) == 0)
		{
			wordCount  = wordCount + 1;
		}
	}

	return wordCount;
}






