#include "push_swap.h"

void ra(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
		write(1,"ra\n",3);
}

void rb(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
		write(1,"rb\n",3);
	
}
void rotate_b(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
		write(1,"rr\n",3);
	
}
void rotate_a(t_stack *arr)
{
    int last;
    int i;
    if (arr->size <= 1) 
        return;
    last = arr->arr[arr->size -1];
    i = arr->size -1;
    
    while (i > 0)
    {
        arr->arr[i] = arr->arr[i - 1];
        i--;
    }
    arr->arr[0] = last;
}
void rr(t_stack *stacka , t_stack *stackb)
{
	rotate_a(stacka);
	rotate_b(stackb);
}