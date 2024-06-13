/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:29:56 by brappo            #+#    #+#             */
/*   Updated: 2024/06/13 11:38:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

bool	parse_element(t_game *game, char *element, char **identifier)
{
	char	*information;
	ssize_t	identifier_index;

	information = ft_strchr(element, ' ');
	if (information != element + 1
		&& information != element + 2)
	{
		write(STDOUT_FILENO, "unknown element identifier", 27);
		return (false);
	}
	*information = '\0';
	information++;
	identifier_index = find_str_in_array(identifier, element, 6);
	if (identifier_index == -1)
	{
		write(STDOUT_FILENO, "unknown element identifier", 27);
		return (false);
	}
	game->textures[identifier_index] = ft_strdup(information);
	free(element);
	if (game->textures[identifier_index] == NULL)
		return (false);
	identifier[identifier_index] = "";
	return (true);
}

void	init_identifier(char **identifier)
{
	identifier[0] = "NO";
	identifier[1] = "SO";
	identifier[2] = "WE";
	identifier[3] = "EA";
	identifier[4] = "F";
	identifier[5] = "C";
}

bool	read_elements(t_game *game, int fd)
{
	char			*line;
	unsigned int	elements_read;
	char			*identifier[6];

	elements_read = 0;
	init_identifier(identifier);
	ft_bzero(game->textures, 6 * sizeof(char *));
	while (elements_read < 6)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (false);
		if (line[0] == '\n')
			free(line);
		else
		{
			if (!parse_element(game, line, identifier))
			{
				free_array(game->textures, 6, false);
				return (false);
			}
			elements_read++;
		}
	}
	return (true);
}
