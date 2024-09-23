#include "push_swap.h"

t_stack *init(t_stack *stack , int size)
{
	stack = malloc(sizeof(t_stack));
	stack->arr = malloc(sizeof(int) * size);
	stack->top = -1;
	stack->size = 0;
	return stack;
}

void printstack(t_stack *a , t_stack *b)
{
	int i ;
	i = a->size - 1;
	while(0 <= i)
	{
		printf("stack A = 			%d\n",a->arr[i]);
		i--;
	}
	int k = b->size -1;
		printf("***************\n");

	while(k >= 0 )
	{
		printf("stack B		%d\n", b->arr[k]);
		k--;
	}
}



int main(int ac, char *av[]) 
{
	t_stack *a;
	t_stack *b;
      b = 0;
	if(ac != 1)
	{
	    a = parc(ac, av);
		b = init(b, a->size);
		// printstack(a ,b);

	       
		if(a->size <= 5)
			sort_five(a, b);
		else if(a->size <= 100)
		{
			int *list = bubble_sort(a);
			sorting_range(a, b, list, 15);
		}
		else if(a->size > 100)
		{
			int *list = bubble_sort(a);
			sorting_range(a, b, list, 30);
		}
	
		printstack(a ,b);
	
	}
    return 0;

}
