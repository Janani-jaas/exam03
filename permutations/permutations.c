#include <unistd.h>
void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print(char *s)
{
	int i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

void	sort_str(char *s, int len)
{
	int i, j;

	for (i = 0; i < len - 1; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
		}
	}
}

void	permute(char *s, int l, int r)
{
	int i, j;

	if (l == r)
	{
		print(s);
		return;
	}
	for (i = l; i <= r; i++)
	{
		for (j = i; j > l; j--)
			swap(&s[j], &s[j - 1]);
		permute(s, l + 1, r);
		for (j = l; j < i; j++)
			swap(&s[j], &s[j + 1]);
	}
}

int	main(int ac, char **av)
{
	int len = 0;

	if (ac != 2)
		return (1);
	while (av[1][len])
		len++;
	if (len == 0)
		return (0);
	sort_str(av[1], len);
	permute(av[1], 0, len - 1);
	return (0);
}
