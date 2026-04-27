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

void	sort(char *s)
{
	int i, j;
	for (i = 0; s[i]; i++)
		for (j = i + 1; s[j]; j++)
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
}

void	permute(char *s, int l, int r)
{
	int i;

	if (l == r)
	{
		print(s);
		return;
	}
	i = l;
	while (i <= r)
	{
		swap(&s[l], &s[i]);
		permute(s, l + 1, r);
		swap(&s[l], &s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int len = 0;

	if (ac != 2)
		return (1);
	while (av[1][len])
		len++;
	sort(av[1]);
	permute(av[1], 0, len - 1);
	return (0);
}