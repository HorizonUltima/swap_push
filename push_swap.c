#define MY_UINT_MAX ((unsigned int)0 - 1)
#define MY_INT_MAX  ((int)(MY_UINT_MAX / 2))
#define MY_INT_MIN  (-MY_INT_MAX - 1)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_operror(void)
{
	write(2, "Error!", 6);
	return (1);
}

int	ft_skip_whitespace(const char *str, long int *k, long int *j, int *sign)
{
	long int	i;

	i = 0;
	while (str[*k + i] == ' ' || (str[*k + i] >= 9 && str[*k + i] <= 13))
		i++;
	if (!str[*k + i])
	{
		if (*k == 0)
		{
			*k = -1;
			*j = -1;
			return (1);	
		}
		return (0);
	}
	if (str[*k + i] == '-' || str[*k + i] == '+')
	{
		if (str[*k + i] == '-')
			*sign -= 2;
		i++;
	}

	if (!(str[*k + i] >= '0' && str[*k + i] <= '9'))
	{
		*k = -1;
		*j = -1;
		return (1);
	}
	*k += i;
	return (0);
}

void	ft_skip_space_l(const char *str, long int *k, long int *j)
{
	while (str[*k] == ' ' || (str[*k] >= 9 && str[*k] <= 13))
		(*k)++;
	if (!str[*k])
	{
		*k = 0;
		(*j) += 1;
	}

}

int	ft_atoi_c(const char *str, long int *k, long int *j)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	if (ft_skip_whitespace(str, k, j, &sign))
		return (0);
	while (str[*k] >= '0' && str[*k] <= '9')
	{
		result = result * 10 + (str[(*k)++] - '0');
		if (((long)sign == 1 && result > (long int)MY_INT_MAX)
			|| ((long)sign == -1 && - result < (long int)MY_INT_MIN))
		{
			*k = -1;
			*j = -1;
			return (0);
		}
	}
	*j = *k;
	if (ft_skip_whitespace(str, k, j, &sign))
		return (0);
	return (1);
}

unsigned int	ft_count_ints(int argc, const char **argv)
{
	int			i;
	long int	j;
	long int	k;
	unsigned int	l;

	i = 0;
	l = 0;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (ft_atoi_c(argv[i + 1], &k, &j))
		{
			l++;
			if (k == j)
				break ;
			j = k;
		}
		if (j == -1)
			return(0);
		i++;
	}
	return (l);
}

int	ft_atoi_l(const char *nptr, long int *j, long int *k)
{
	int			sign;
	int	result;

	sign = 1;
	result = 0;
	ft_skip_whitespace(nptr, k, j, &sign);
	while (nptr[*k] >= '0' && nptr[*k] <= '9')
		result = result * 10 + (nptr[(*k)++] - '0');
	ft_skip_space_l(nptr, k, j);
	return (result * sign);
}

int	ft_is_duplicate(int *list, int curr)
{
	int	i;

	i = 0;
	while (i < curr)
	{
		if (list[i++] == list[curr])
		{
			write(2, "Error!", 6);
			return (1);
		}
	}
	return (0);
}

int	ft_check_order(int argc, const char **argv, int **list_ints)
{
	unsigned int	i;
	long int	j;
	long int	k;
	unsigned int	size;

	size = ft_count_ints(argc, argv);
	if (!size || size == 1)
		return (ft_operror());
	*list_ints = (int *)malloc(size * sizeof(int));
	if (!*list_ints)
		return (ft_operror());
	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		(*list_ints)[i] = ft_atoi_l(argv[j + 1], &j, &k);
		if (ft_is_duplicate(*list_ints, i))
		{
			free(*list_ints);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, const char **argv)
{
	int	*list_ints;
	int i = 0;

	if (ft_check_order(argc - 1, argv, &list_ints))
		return (1);
	//blah blah, useful functions.
	while (i < 10)
		printf("%d\n", list_ints[i++]);
	write(1, "OK!", 3);
	free(list_ints);
	return (0);
}
