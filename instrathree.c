#include "push_swap.h"


void rra(t_stack *arr)
{
    int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;
	}
    arr->arr[arr->size -1] = first;
		write(1,"rra\n",4);

}

void rrb(t_stack *arr)
{
	int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
		write(1,"rrb\n",4);
}

void rrotateb(t_stack *arr)
{
	int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
		write(1,"rrr\n",4);
}
void rrotatea(t_stack *arr)
{
	int first;
    int i;
    if (arr->size <= 1) 
        return;
    first = arr->arr[0];
    i = 0;
    
	while(i < arr->size-1)
	{
		arr->arr[i] = arr->arr[i + 1];
		i++;

	}
    arr->arr[arr->size -1] = first;
}
void rrr(t_stack *stacka , t_stack* stackb)
{
	rrotatea(stacka);
	rrotateb(stackb);
}