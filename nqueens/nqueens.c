#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	safe(int *b, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (b[i] == row)
			return (0);
		if ((b[i] - row == col - i) || (b[i] - row == i - col))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *b, int col, int size)
{
	int	i;
	int	row;

	if (col == size)
	{
		i = 0;
		while (i < size)
		{
			fprintf(stdout, "%d", b[i]);
			if (i < size - 1)
				fprintf(stdout, " ");
			i++;
		}
		fprintf(stdout, "\n");
		return;
	}
	row = 0;
	while (row < size)
	{
		if (safe(b, col, row))
		{
			b[col] = row;
			solve(b, col + 1, size);
		}
		row++;
	}
}

int main(int ac, char **av)
{
	int *b;
	int size;

	if (ac != 2)
		return (1);
	size = atoi(av[1]);
	if (size <= 0)
		return (1);
	b = calloc(size, sizeof(int));
	if (!b)
		return (1);
	solve(b, 0, size);
	free(b);
	return (0);
}