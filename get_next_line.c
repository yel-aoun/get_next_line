/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:04:27 by yel-aoun          #+#    #+#             */
/*   Updated: 2021/12/13 21:04:32 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_put(char *s_r)
{
	int		i;
	char	*save_line;

	i = 0;
	if (!s_r[i])
		return (NULL);
	while (s_r[i] && s_r[i] != '\n')
		i++;
	save_line = ft_strdup_demo(s_r, (i + 2));
	return (save_line);
}

char	*ft_free(char *save)
{
	free(save);
	return (NULL);
}

char	*ft_static(char *save)
{
	char	*save_line;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	if (!save[i[0]])
		return (ft_free(save));
	while (save[i[1]] && save[i[1]] != '\n')
		i[1]++;
	if (save[i[1]] != '\n')
		return (ft_free(save));
	save_line = malloc(sizeof(char) * (ft_strlen(save) - i[1] + 1));
	if (!save_line)
		return (NULL);
	i[1]++;
	while (save[i[1]] != '\0')
		save_line[i[0]++] = save[i[1]++];
	save_line[i[0]] = '\0';
	free(save);
	return (save_line);
}

char	*ft_save_what_i_did_read(int fd, char *save_read)
{
	char	*buf;
	int		read_b;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(save_read);
		return (NULL);
	}
	read_b = 1;
	while (!ft_strchr(save_read, '\n') && read_b != 0)
	{
		read_b = read(fd, buf, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_b] = '\0';
		save_read = ft_strjoin(save_read, buf);
	}
	free (buf);
	return (save_read);
}

char	*get_next_line(int fd)
{
	static char	*save_read;
	char		*put_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	save_read = ft_save_what_i_did_read(fd, save_read);
	if (!save_read)
		return (NULL);
	put_line = ft_put(save_read);
	save_read = ft_static(save_read);
	return (put_line);
}
