/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:07:03 by yel-aoun          #+#    #+#             */
/*   Updated: 2021/12/13 21:07:09 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_demo(char *s1, int d)
{
	char	*cup;
	int		i;

	i = 0;
	cup = malloc(sizeof(char) * d);
	if (!cup)
		return (NULL);
	while (s1[i] && s1[i] != '\n')
	{
		cup[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		cup[i] = s1[i];
		i++;
	}
	cup[i] = '\0';
	return (cup);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	s;

	i = 0;
	s = (char)c;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == s)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	tmp = ft_strjoin_ft(s1, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	free(s1);
	return (tmp);
}

char	*ft_strjoin_ft(char *s1, char *s2, int s)
{
	char	*cup;
	int		i;
	int		l;

	i = 0;
	cup = malloc(sizeof(char) * s);
	if (!cup)
		return (NULL);
	l = 0;
	if (s1)
	{
		while (s1[i])
		{
			cup[i] = s1[i];
			i++;
		}
	}
	while (s2[l])
	{
		cup[i] = s2[l];
		i++;
		l++;
	}
	cup[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (cup);
}
