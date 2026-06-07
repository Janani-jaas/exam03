#include <stdio.h>

int is_balanced(char *s)
{
    int i = 0;
    int balance = 0;
    while (s[i])
    {
        if (s[i] == '(')
            balance++;
        else if (s[i] == ')')
            balance--;
        if (balance < 0)
            return (0);
        i++;
    }
    return(balance == 0);
}

void solve(char *s, int idx, int removals_left)
{
    if (removals_left == 0)
    {
        if (is_balanced(s))
            puts(s);
        return;
    }
    int i = idx;
    while (s[i])
    {
        if (s[i] == '(' || s[i] == ')')
        {
            char temp = s[i];
            s[i] = ' ';
            solve(s, i + 1, removals_left - 1);
            s[i] =  temp;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    char *s = av[1];
    int i = 0;
    int open = 0;
    int close = 0;
    while (s[i])
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
        {
            if (open > 0)
                open--;
            else 
                close++;
        }
        i++;
    }
    solve(s, 0, open + close);
    return (0);
}
