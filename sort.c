#include "push_swap.h"




void sort_fc(t_stack *arr)
{
	if(arr->size <= 1)
		return ;
	if(arr->arr[arr->top] > arr->arr[arr->top - 1])
				sa(arr);

}

void sort_three(t_stack *stack)
{
	if(stack->size <= 2)
		{
			sort_fc(stack);
			return ;
		}
		if(stack->arr[stack->top] < stack->arr[stack->top -1] && stack->arr[stack->top -2] < stack->arr[stack->top -1] && stack->arr[stack->top - 2] > stack->arr[stack->top])
		{		
					sa(stack);
					ra(stack);
		}
		else if(stack->arr[stack->top] > stack->arr[stack->top -1] && stack->arr[stack->top -2] > stack->arr[stack->top -1] && stack->arr[stack->top -2] > stack->arr[stack->top])
				 sa(stack);
		else if(stack->arr[stack->top] < stack->arr[stack->top -1] && stack->arr[stack->top -2] < stack->arr[stack->top] && stack->arr[stack->top -2] < stack->arr[stack->top - 1])
				rra(stack);
		else if(stack->arr[stack->top] > stack->arr[stack->top -1] && stack->arr[stack->top -2] > stack->arr[stack->top - 1] && stack->arr[stack->top - 2] < stack->arr[stack->top])
				ra(stack);
		else if(stack->arr[stack->top] > stack->arr[stack->top -1] && stack->arr[stack->top -2] < stack->arr[stack->top] && stack->arr[stack->top -2] < stack->arr[stack->top - 1])
		{
			sa(stack);
			rra(stack);
			ra(stack);
			ra(stack);
			ra(stack);
		}
}

int ft_min(t_stack *a)
{
	int i;
	int min;
	int k;

	i = 0;
	min = 2147483647;
	while(i <= a->top)
	{
		if(a->arr[i] < min)
		{
			min = a->arr[i];
			k = i;
		}
		i++;
	}
	return (k);
}

void sort_five(t_stack *a, t_stack *b)
{
	int min_index;

	while(a->top > 2)
	{
		min_index = ft_min(a);
		if(min_index == a->top)
			pb(a, b);
		else if(min_index > a->top - min_index)
			ra(a);
		else if(min_index <= a->top - min_index)
			rra(a);
	}
	sort_three(a);
	while(b->top >= 0)
		pa(a, b);
}


int sorted(t_stack *a)
{
	int i;
	if(a->top <= 0)
		return(1);
	i = 0;
	while(i < a->top)
	{
		if(a->arr[i] < a->arr[i + 1])
			return(0);
		i++;
	}
	return(1);
}

int *bubble_sort(t_stack *a)
{
	int *res;
	int i;
	int j;
	int t;

	res =(int *)malloc(sizeof(int) * (a->top + 1));
	i = 0;
	j = 0;
	while(i < a->top)
	{
		res[i] = a->arr[i];
		i++;
	}
	res[i] = a->arr[i];
	i = 0;
	while(i < a->top -1 )
	{
		j = 0;
		while(j < a->top - i)
		{
			if(res[j] > res[j + 1])
			{
				t  = res[j];
				res[j] = res[j + 1];
				res[j + 1] = t;
			}
			j++;
		}
		i++;
	}
	return (res);

}

int range(int a, int *list, t_range *algo , int size)
{
	int k = 0;
	while(k < size)
	{
		if(a ==list[k])
			break;	
		k++;
	}
	if(k >= algo->start  && k <= algo->end)
		return 1;
	else if(k < algo->start)
		return 2;
	return 0;
}

void sorting_range(t_stack *a, t_stack *b, int sorted[], int option)
{
    t_range *algo;
	algo = malloc(sizeof(t_range));
	int size ;
	size = a->size ;
    algo->start = 0;
	algo->end = option;
    while (a->top > -1)
    {   algo->op = range(a->arr[a->top], sorted, algo , size);
        
        if (algo->op == 1)
        {
            pb(a, b);
            algo->start++;
            algo->end++;
        }
        else if (algo->op == 0)
        {
            ra(a);
        }
        else if (algo->op == 2)
        {
			// rra(a);
				pb(a,b);
				rb(b);
			algo->start++;
            algo->end++;
        }
    }

    push_to_a(a, b);
	// printstack(a,b);
}

int ft_max(t_stack *b)
{
	int i;
	int max;
	i = 0;
	max = b->top;
	while(i < b->top)
	{
		if(b->arr[max] < b->arr[i])
			max = i; 
		i++;
	}
	return(b->arr[max]);
}
int ft_mx(t_stack *b)
{
	int i;
	int max;
	i = 0;
	max = b->top;
	while(i < b->top)
	{
		if(b->arr[max] < b->arr[i])     /// 1 4 5 8 89 7 6 2
			max = i; //  
		i++;
	}
	return(max);
}
void push_to_a(t_stack *a, t_stack *b)
{
	int max;
	int mx ;
	max = ft_max(b);

	while(b->top > 0)
	{
		max = ft_max(b);
		if(max == b->arr[b->top])
			pa(a,b);
		else
		{
			mx = ft_mx(b);
			if (mx <= b->size / 2)
				rrb(b);
			else
				rb(b);
		}
	}
	pa(a,b);	
}
