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
	
	res =(int *)malloc(sizeof(int) * (a->top) +1);
	i = 0;
	while(i <= a->top)
	{
		j = 0;
		t = 0;
		while(j <= a->top)
		{
			if(a->arr[i] > a->arr[j])
				t++;
			j++;
		}
		res[i] = t;
		i++;
	}
	return (res);
}

void	rrrr(int *list, int top)
{
	int last;
    int i;
    if (top < 1) 
        return;
    last = list[top];
    i = top;
    
    while (i >= 0)
    {
        list[i] = list[i - 1];
        i--;
    }
    list[0] = last;
}

void	rrrra(int *list, int top)
{
    int first;
    int i;
    if (top <= 1) 
        return;
    first = list[0];
    i = 0;
    
	while(i <= top)
	{
		list[i] = list[i + 1];
		i++;
	}
    list[top] = first;
}
int range(int top, int list[], int start, int end)
{
    int k = 0;
    int n = top;

    while (start + k <= top) 
    {
        if (list[start + k] < end)
            break;
        k++;
    }

    if (k == 0) 
        return 1; 

    while (n > start && n < end ) 
    {
        if (list[n] < end)
            break;
        n--;
    }

    if (n > end - k)
        return 2;

    return 0; 
}
void sorting_range(t_stack *a, t_stack *b, int sorted[], int option)
{
    t_range algo;

    algo.start = 0;
    while (a->top > -1)
    {   algo.op = range(a->top, sorted, algo.start, option);
        
        if (algo.op == 1)
        {
            pb(a, b);
            algo.start++;
            option++;
        }
        else if (algo.op == 0)
        {
            ra(a);
        }
        else if (algo.op == 2)
        {
			rra(a); 

        }
    }
 
    push_to_a(a, b);
}

int ft_max(t_stack *b)
{
	int i;
	int max;

	i = 0;
	max = b->top;
	while(i < b->top)
	{
		if(b->arr[max] < b->arr[i])     /// 1 4 5 8 89 7 6 2
			max = i; //  1 
		i++;
	}
	return(max);
}

void push_to_a(t_stack *a, t_stack *b)
{
	int max;

	while(b->top > -1)
	{
		max = ft_max(b);
		if(max)
		{
			if (max <= b->top / 2)
			{
				while (max--)
					rb(b);
			}
			else
			{
				max = b->top - max;
				while (max--)
					rrb(b);
			}
		}
		pa(a, b);
		// printf("b->top %d\n", b->top);
	}
	// exit(0);
}
