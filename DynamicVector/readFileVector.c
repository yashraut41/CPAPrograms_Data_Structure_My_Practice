#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


                                    

#define SUCCESS 1
#define MAX_LINE_LENGTH 256
typedef int ret_t;

char line[MAX_LINE_LENGTH]; 


struct vectorString
{
	char** pp_lines;
	size_t size;
};

struct vectorString *create_vector();
ret_t push_back(struct vectorString *p_vec_line, char* new_line );
void show(struct vectorString *p_vec_line);
ret_t destroy_vector_lines(struct vectorString *p_vec_line);


int main(int argc, char const *argv[])
{
	struct vectorString *p_vec_line = NULL;
	
    ret_t ret;
    int lineLength = 0;
    char* dup_line = NULL;

    if(argc!= 2)
    {
    	fprintf(stderr, "Usage Error %s file name\n", argv[0]);
    	exit(EXIT_FAILURE);
    }

	
    //create empty vector
    p_vec_line = create_vector();
	assert(p_vec_line != NULL);
	
    //open file
    FILE* fp = fopen(argv[1],"r");
    assert(fp);

    //read line from file

    while(fgets(line,MAX_LINE_LENGTH, fp))
    {

        lineLength = strlen(line);    
        dup_line = (char *)malloc(lineLength + 1);
        assert(dup_line);
        
        strncpy(dup_line,line,lineLength);
        
        ret = push_back(p_vec_line,dup_line);
        assert(ret == SUCCESS);


    }
    
	

    /* code */
   
	show(p_vec_line);

	ret = destroy_vector_lines(p_vec_line);
	assert(ret == SUCCESS);

	p_vec_line = NULL;
    fclose(fp);
	return (EXIT_SUCCESS);
}

struct vectorString *create_vector()
{
	struct vectorString *p_vec_line = NULL;
	p_vec_line = (struct vectorString*)malloc(sizeof(struct vectorString));
	assert(p_vec_line != NULL);
	memset(p_vec_line,0,sizeof(struct vectorString));

	p_vec_line->pp_lines = NULL;
	p_vec_line->size = 0;

	return p_vec_line;
}
ret_t push_back(struct vectorString *p_vec_line, char* new_line)
{
	p_vec_line->pp_lines =(char**)realloc(p_vec_line->pp_lines, (p_vec_line->size+1) * sizeof(char *));
	assert(p_vec_line->pp_lines != NULL);
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
	for(int i = 0; i < p_vec_line->size; ++i)
	{
		free(p_vec_line->pp_lines[i]);
	}
	free(p_vec_line->pp_lines);
	free(p_vec_line);
	return SUCCESS;     

}




