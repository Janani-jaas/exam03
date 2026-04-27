#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t	ft_strlen(char *s)
{
	size_t i = 0;
	while (s && s[i])
		i++;
	return i;
}

char	*ft_strchr(char *s, int c)
{
	int i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return s + i;
		i++;
	}
	return NULL;
}

void	*ft_memcpy(void *d, void *s, size_t n)
{
	size_t i = 0;
	while (i < n)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
	}
	return d;
}

char	*join(char *s1, char *s2, int n)
{
	char *r = malloc(ft_strlen(s1) + n + 1);
	int i = 0, j = 0;

	if (!r) {
		free(s1);
		return NULL;
	}
	while (s1 && s1[i])
		r[j++] = s1[i++];
	i = 0;
	while (i < n)
		r[j++] = s2[i++];
	r[j] = 0;
	free(s1);
	return r;
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *line = NULL;
	char *nl;
	int r;

	while (1)
	{
		if ((nl = ft_strchr(buf, '\n')))
		{
			line = join(line, buf, nl - buf + 1);
			ft_memcpy(buf, nl + 1, ft_strlen(nl + 1) + 1);
			return line;
		}
		line = join(line, buf, ft_strlen(buf));
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
		{
			buf[0] = 0;
			if (line && *line)
				return line;
			free(line);
			return NULL;
		}
		buf[r] = 0;
	}
}
