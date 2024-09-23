#include "push_swap.h"


void sa(t_stack *arr)
{
	int k = 0;
	if(arr->size <= 1)
			return ;
		k =arr->arr[arr->size-1]; 
		arr->arr[arr->size-1] = arr->arr[arr->size-2];
		arr->arr[arr->size -2] = k ;
		write(1,"sa\n",3);

}
void sb(t_stack *arr)
{
	if(arr->size <= 1)
			return ;
		int k = 0;
		k =arr->arr[arr->size-1]; 
		arr->arr[arr->size-1] = arr->arr[arr->size-2];
		arr->arr[arr->size -2] = k ;
		write(1,"sb\n",3);

}
void ss(t_stack *a, t_stack *b )
{
	if(a->size <= 1 || b->size <= 1)
		return ;
	int k = 0;
	int n = 0;
	k =a->arr[a->size-1]; 
	a->arr[a->size-1] = a->arr[a->size-2];
	a->arr[a->size -2] = k ;

	n =b->arr[b->size-1]; 
	b->arr[b->size-1] = b->arr[b->size-2];
	b->arr[b->size -2] = n ;
		write(1,"ss\n",3);
}
