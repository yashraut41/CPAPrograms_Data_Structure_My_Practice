#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SUCCESS 1

typedef int ret_t;

struct vector
{
	int *p_array;
	size_t size;
};

struct vector *create_Vector(void);
ret_t push_back(struct vector *p_vec_int,int element);
void show(struct vector *p_vec_int);
ret_t destroy(struct vector *p_vec_int);

int main()
{
	struct vector *p_vec_int = NULL;
	ret_t ret;

	p_vec_int = create_Vector();

	for(int i =0; i < 10; i++)
	{
		ret =push_back(p_vec_int,(i+1)*10);
		assert(ret == SUCCESS);
	}

	show(p_vec_int);
	
	ret = destroy(p_vec_int);
	assert(ret == SUCCESS);

	p_vec_int = NULL;

	return(EXIT_SUCCESS);
}

struct vector *create_Vector()
{
	struct vector *p_vec_int = NULL;
	p_vec_int = (struct vector*)malloc(sizeof(struct vector));

	p_vec_int->p_array = NULL;
	p_vec_int->size = 0;

	return p_vec_int;
}

ret_t push_back(struct vector *p_vec_int,int element)
{
	p_vec_int->p_array = (int*)realloc(p_vec_int->p_array,p_vec_int->size * sizeof(int));

	p_vec_int->size = p_vec_int->size + 1;
	p_vec_int->p_array[p_vec_int->size - 1] = element;

	return SUCCESS;
}

void show(struct vector *p_vec_int)
{
	for(int i = 0; i < p_vec_int->size; i++)
	{
		printf("p_vec_int->p_array[%d]:%d \n",i,p_vec_int->p_array[i] );
	}
}

ret_t destroy(struct vector *p_vec_int)
{
	free(p_vec_int->p_array);
	free(p_vec_int);

	return SUCCESS;
}





