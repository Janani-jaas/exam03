#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void solve(int *set, int *sub, int size, int sub_sz, int i, int sum, int target)
{
    if (i == size)
    {
        if (sum == target)
        {
            int j = 0;
            while (j < sub_sz)
            {
                printf("%d", sub[j]);
                if (j < sub_sz - 1)
                    printf(" ");
                j++;
            }
            printf("\n");
        }
        return ;
    }
    sub[sub_sz] = set[i];
    solve(set, sub, size, sub_sz + 1, i + 1, sum + set[i], target);
    solve(set, sub, size, sub_sz, i + 1, sum, target);
}

int main(int ac, char **av)
{
    if (ac < 3)
        return (1);
    int target = atoi(av[1]);
    int size = ac - 2;
    if (size <= 0)
    {
        if (target == 0)
            printf("\n");
        return (0);
    }
    int *set = malloc(size * sizeof(int));
    int *sub = malloc(size * sizeof(int));
    if (!set || !sub)
        return (1);
    int i = 0;
    while (i < size)
    {
        set[i] = atoi(av[i + 2]);
        i++;
    }
    solve(set, sub, size, 0, 0, 0, target);
    free(set);
    free(sub);
    return (0);
}
