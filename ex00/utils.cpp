// File: utils.cpp
// Created by: Valentin Lepiller
// Created on: 7/10/2023

#include "utils.hpp"
#include <climits>
#include <cstdlib>

int	ft_strlen(const char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i = 0;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// INT_MAX = 2147483647
// INT_MIN = -2147483648
int	anti_overflow_atoi(const char *input, int *result)
{
	int	sign = 0;

	if (input[0] == '+' || input[0] == '-')
		sign++;
	if (ft_strlen(input) > 10 + sign)
		return (1);
	if (ft_strlen(input) == 10 + sign)
	{
		if (input[sign] > '2')
			return (1);
		else if (input[sign] == '2')
		{
			*result = atoi(input + sign + 1);
			if (*result > 147483647 + (input[0] == '-'))
				return (1);
			*result = (*result + 2000000000) * (input[0] == '-' ? -1 : 1);
			return (0);
		}
	}
	*result = atoi(input);
	return (0);
}
