#pragma once

int	ft_strlen(const char *str);

int	ft_strcmp(const char *s1, const char *s2);

int	ft_isprint(int c);

int	detect_int_overflow(const char *input);

int	anti_overflow_atoi(const char *input, int *result);

int	has_dot(const char *input);
