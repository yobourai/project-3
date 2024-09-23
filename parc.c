// #include "push_swap.h"
// t_stack *parc(int ac, char *av[]) 
// {
// 	t_stack *stack;
// 	stack =malloc(sizeof(t_stack));
//     if(!stack)
//          return 0;
//     int j;
//     int i ;
//     int k ;

//     i = 1;
//     k= 0;
//     j = 0;
//     char ***ptr;
//     ptr = malloc(sizeof(char **) * ac );
//     while(av[i])
//     {  
//         ptr[j] =ft_split(av[i], ' ');
//         i++;
//         j++;
//     }
//     ptr[j] = NULL;
// 	stack->size = len(ptr);
// 	stack->top = stack->size - 1;
// 	k = stack->size -1;
//     int flag ;
//     flag = 0;
//     stack->arr = malloc(sizeof(int) * (stack->size) );
// 	j = 0;
//     while(ptr[j])
//     {
//         i = 0;
//         while(ptr[j][i])    
//         {
//             	stack->arr[k] = ft_atoi(ptr[j][i],&flag);
//                 k--;
//             	i++;
    
//         }
//         j++;
//     }
//     if(flag == 1)
//     {
//         write(2,"Error\n",6);
//         exit(1);
//     }
// 	if(check(stack->arr , len(ptr))== 1)
//     {
//         write(2,"Error\n",6);
//         exit(1);
//     }
//     return stack;
// }

#include "push_swap.h"

t_stack *initialize_stack(int total_size)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    stack->size = total_size;
    stack->top = total_size - 1;
    stack->arr = malloc(sizeof(int) * total_size);
    if (!stack->arr)
    {
        free(stack);
        return NULL;
    }

    return stack;
}

char ***parse_input(int ac, char *av[])
{
    char ***ptr = malloc(sizeof(char **) * ac);
    if (!ptr)
        return NULL;

    int i = 1, j = 0;
    while (av[i])
    {
        ptr[j] = ft_split(av[i], ' ');
        i++;
        j++;
    }
    ptr[j] = NULL;
    return ptr;
}

int fill_stack(t_stack *stack, char ***ptr)
{
    int k = stack->size - 1;
    int flag = 0;
    int j = 0, i;

    while (ptr[j])
    {
        i = 0;
        while (ptr[j][i])
        {
            stack->arr[k] = ft_atoi(ptr[j][i], &flag);
            if (flag == 1)
                return 1;
            k--;
            i++;
        }
        j++;
    }

    return 0;
}

void handle_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int check_for_errors(t_stack *stack)
{
    if (check(stack->arr, stack->size) == 1)
        return 1;
    return 0;
}
t_stack *parc(int ac, char *av[])
{
    char ***ptr = parse_input(ac, av);
    if (!ptr)
        return NULL;

    int total_size = len(ptr);
    t_stack *stack = initialize_stack(total_size);
    if (!stack)
        return NULL;

    if (fill_stack(stack, ptr) == 1)
        handle_error();

    if (check_for_errors(stack))
        handle_error();

    return stack;
}
