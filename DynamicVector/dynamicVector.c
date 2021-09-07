#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1
typedef int ret_t;

struct dynamicVector
{
	int *pa;
	size_t vSize;
};

void show(struct dynamicVector *p_vector, int size);
struct dynamicVector *create_vector(void);
ret_t push_back(struct dynamicVector *p_vec_int,int data);
void destroy_vector(struct dynamicVector *p_vec_int);

int main()
{
	struct dynamicVector *p_vec_int = NULL;
	int size = 5;
	ret_t ret;
	p_vec_int = create_vector();
	assert(p_vec_int != NULL);

	for(int i = 0; i < size; i++)
	{
		ret = push_back(p_vec_int,(i+1)*10);
		if(ret != SUCCESS)
		{
			fprintf(stderr, "Unexpected Error\n");
			exit(EXIT_FAILURE);
		}

	}

	show(p_vec_int, size);
	ret=destroy_vector(p_vec_int);
	assert(ret == SUCCESS);
	p_vec_int = NULL;

	return EXIT_SUCCESS;

}

struct dynamicVector *create_vector()
{
	struct dynamicVector *p_vec_int = NULL;
	p_vec_int = (struct dynamicVector*)malloc(sizeof(struct dynamicVector));
	assert(p_vec_int!= NULL);

	p_vec_int->pa = NULL;
	p_vec_int->vSize = 0;

	return p_vec_int; 
}

ret_t push_back(struct dynamicVector *p_vec_int,int data)
{

	p_vec_int->pa = (int*)realloc(p_vec_int->pa,sizeof(int)*p_vec_int->vSize);
	assert(p_vec_int->pa != NULL);

	p_vec_int->vSize = p_vec_int->vSize + 1;

	p_vec_int->pa[p_vec_int->vSize - 1] = data;


	return SUCCESS; 
}


void show(struct dynamicVector *p_vector, int size)
{

	for(int i = 0; i < size; i++)
		printf("%d =[%d]\n",i ,p_vector->pa[i]);
}

ret_t destroy_vector(struct dynamicVector* p_vec_int)
{
	free(p_vec_int->pa);
	free(p_vec_int);
	return (SUCCESS);
}






























