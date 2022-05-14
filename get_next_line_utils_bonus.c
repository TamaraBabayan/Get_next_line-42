/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:37:43 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/28 14:42:10 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;

	i = 0;
	if (!s2)
		return (NULL);
	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstring)
		return (NULL);
	if (s1)
		while (*s1)
			newstring[i++] = *s1++;
	while (*s2)
	{
		newstring[i++] = *s2;
		s2++;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;

	i = 0;
	c1 = c;
	if (!s)
		return (0);
	while (s[i] && s[i] != c1)
		i++;
	if (s[i] == c1)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c] != '\0')
		c++;
	return (c);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (0);
	len = 0;
	while (s1[len] != '\0')
	{
		s2[len] = s1[len];
		len++;
	}
	s2[len] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
