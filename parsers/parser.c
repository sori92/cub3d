#include "../cub3d.h"

char	*errase_newline(char *str)
{
	size_t	len;
	size_t	i;
	char	*clean;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (len == ft_strlen(str))
		return (str);
	clean = malloc(sizeof(char) * (len + 1));
	while(str[i] && str[i] != '\n')
	{
		clean[i] = str[i];
		i++;
	}
	clean[i] = '\0';
	free(str);
	return (clean);
}

void	clean_paths_and_colors(t_cub *game)
{
	game->map.paths.no = errase_newline(game->map.paths.no);	
	game->map.paths.so = errase_newline(game->map.paths.so);	
	game->map.paths.ea = errase_newline(game->map.paths.ea);	
	game->map.paths.we = errase_newline(game->map.paths.we);	
	game->map.color.f = errase_newline(game->map.color.f);	
	game->map.color.c = errase_newline(game->map.color.c);	
}
void	parser(t_cub *game)
{
	clean_paths_and_colors(game);
	check_texture_routes_and_colors(game);
	check_chars_and_empty_lines(game);
}