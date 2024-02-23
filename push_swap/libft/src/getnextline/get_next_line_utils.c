/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavier <afavier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:20:39 by afavier           #+#    #+#             */
/*   Updated: 2023/12/07 14:17:36 by afavier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	j;
	size_t	i;
	char	*s;

	i = 0;
	if (!s1)
		return (free(s1), NULL);
	len = ft_strlen(s1, '\0') + ft_strlen(s2, '\n');
	j = 0;
	s = malloc(sizeof(char ) * (len + 1));
	if (!s)
		return (free(s1), NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		s[i++] = s2[j++];
	if (s2[j++] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	free (s1);
	return (s);
}

size_t	ft_strlen(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i +1);
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	y;
	char	*tab;

	i = ft_strlen(s, '\0');
	y = 0;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	while (s[y])
	{
		tab[y] = s[y];
		y++;
	}
	tab[y] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
