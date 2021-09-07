#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
                                    

#define SUCCESS 1
typedef int ret_t;


struct vectorString
{
	char** pp_lines;
	size_t size;
};

struct vectorString *create_vector();
ret_t push_back(struct vectorString *p_vec_line, char* new_line );
void show(struct vectorString *p_vec_line);
ret_t destroy_vector_lines(struct vectorString *p_vec_line);

int main()
{
	struct vectorString *p_vec_line = NULL;
	ret_t ret;
	p_vec_line = create_vector();
	assert(p_vec_line != NULL);

	for (int i = 0; i < 10; ++i)
	{
		/* code */
		ret = push_back(p_vec_line,"Hello I am Yashwant ");
		assert(ret == SUCCESS);
	}

	show(p_vec_line);

	ret = destroy_vector_lines(p_vec_line);
	assert(ret == SUCCESS);

	p_vec_line = NULL;

	return (EXIT_SUCCESS);
}

struct vectorString *create_vector()
{
	struct vectorString *p_vec_line = NULL;
	p_vec_line = (struct vectorString*)malloc(sizeof(struct vectorString));
	assert(p_vec_line != NULL);

	p_vec_line->pp_lines = NULL;
	p_vec_line->size = 0;

	return p_vec_line;
}
ret_t push_back(struct vectorString *p_vec_line, char* new_line )
{
	p_vec_line->pp_lines =(char**)realloc(p_vec_line->pp_lines, sizeof(char*) * p_vec_line->size);
	p_vec_line->size = p_vec_line->size + 1;
	p_vec_line->pp_lines[p_vec_line->size - 1] = new_line;

	return SUCCESS;

}
void show(struct vectorString *p_vec_line)
{
	for(int i = 0; i < p_vec_line->size; i++)
	{
		printf("%s\n",p_vec_line->pp_lines[i]);
	}
}
ret_t destroy_vector_lines(struct vectorString *p_vec_line)
{
	for(int i = 0; i < p_vec_line->size; i++)
	{
		free(p_vec_line->pp_lines[i]);
	}
	free(p_vec_line->pp_lines);
	free(p_vec_line);
	return SUCCESS;     

}



/*int main()
{
	
char *string = "heelo this string";
char **ppLine = &string;

// **ppLine = "heelo this string raut";
// int a[10];
printf("%c",*(*ppLine));

// printf("%lu",strlen(string));

for(int i=0; i < strlen(string); i++)
{	
	*(*ppLine+i) = "A";
	printf("%c",*(*ppLine+i));
}

}


void printLastLetter(char **str)
{
    printf("%c\n",*(*str + strlen(*str) - 1));
    printf("%c\n",**(str + strlen(*str) - 1));
}

int main()
{
    char *str = "1234556";
    printLastLetter(&str);
    return 1;
}*/








