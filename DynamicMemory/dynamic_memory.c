#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct point
{
	double x,y,z;
};

int main()
{

	//array of pointers of user defined data type
	struct point **my_Struct = NULL;
	int a_Size = 5;

	my_Struct = (struct point** )malloc(sizeof(struct point*) * a_Size);
	assert(my_Struct);
	memset(my_Struct,0,a_Size * sizeof(struct point*));
	
	for(int i = 0; i < a_Size; i++)
	{
		my_Struct[i] = (struct point*)malloc(sizeof(struct point));
		my_Struct[i]->x =  10.0f;
		my_Struct[i]->y =  20.0f;
		my_Struct[i]->z =  30.0f;
	}

	for(int i = 0; i < a_Size; i++)
	{
		 printf("my_Struct[%d]-> x = %.2lf\n my_Struct[%d]-> y = %.2lf\n my_Struct[%d]-> z = %.2lf \n",
		 	i, my_Struct[i]->x , i, my_Struct[i]->y,i,my_Struct[i]->z );

	}
}

/* void user_defined_Data_type_Array()
{
	struct point *p_struct;
	int a_size = 5;

	p_struct = (struct point*)malloc(sizeof(struct point) * a_size);

	for(int i = 0; i < a_size; i++)
	{
		p_struct[i].x = (i + 1) * 10.0f;
		p_struct[i].y = (i + 2) * 10.0f;
		p_struct[i].z = (i + 3) * 10.0f;
	}

	for(int i = 0; i < a_size; i++)
	{
		// printf("p_struct[%d]->x = %f\n",i,p_struct[i].x);
		// printf("p_struct[%d]->x = %f\n",i,p_struct[i].y);
		// printf("p_struct[%d]->x = %f\n",i,p_struct[i].z);
		
		printf("p_struct[%d]->x = %.2lf\n p_struct[%d]->y = %.2lf\n p_struct[%d]->z = %.2lf\n",i,p_struct[i].x,
				i,p_struct[i].y, i,p_struct[i].z);
				
	}
}

void user_defined_data_type()
{
	struct point  *my_Struct = (struct point*)malloc(sizeof(struct point));

	my_Struct->x = 12.0;
	my_Struct->y = 13.5;
	my_Struct->z = 14.2;


	printf("%f,%f,%f\n",my_Struct->x,my_Struct->y,my_Struct->z );

}


void array_of_integer_pointers()
{
	//array of integer pointers
	int **pp = NULL;

	int a_size = 5;

	pp =(int**)malloc(sizeof(int*) * a_size);
	
	memset(pp, 0, sizeof(int*) * a_size);

	for(int i = 0; i < a_size; i++ )
	{
		pp[i] = (int*)malloc(sizeof(int*));
		*pp[i] = (i+1) * 10; 
	}

	for(int i = 0; i < a_size; i++)
	{
		printf("%d\n",*pp[i]);
	}
}

// void array_of_builtin_type()
{
	array of inbuilt data type
	
	int *piArray = NULL;
	int a_size = 5;

	for(int i = 0; i < a_size; i++)
	{
		 piArray = (int*)realloc(piArray,sizeof(int));
		 piArray[i] = (i + 1) * 10; 
	} 

	for(int i = 0; i < a_size; i++)
	{
		printf("%d\n",piArray[i]);
	}	
}*/