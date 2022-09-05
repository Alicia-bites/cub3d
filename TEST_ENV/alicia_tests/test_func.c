#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

//# include "mlx.h"
# include "../minilibX/libmlx.h"
# include "libft.h"

# define PI 3.141592653589793238

# define SCREEN_SIZE 1280
# define BACKGROUND_COLOR 0x00898c83
# define PLAYER_COLOR 0x00a44620

# define ESC_KEYCODE 65307
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define CAM_RIGHT 65363
# define CAM_LEFT 65361

# define FILE_ERROR -1
# define MALLOC_ERROR -2
# define EMPTY_LINE -3

# define SPRITE_COUNT 9
# define CHAR_NOT_FOUND	'N'

char	*get_character_in_map(t_list *map, int x, int y)
{
	int	i;

	i = 0;
	while (map)
	{
		if (map->index == y)
		{
			while (map->line)
			{
				if (i == x)
					return (map->line[x]);
				i++;
			}
		}
		map = map->next;
	}
	return (CHAR_NOT_FOUND);
}

int	main(int argc, char **argv)
{
	t_list	*map;
	if (argc == 1)
		return (0);
	map = ft_parse(argv[1]);
	printf("%c\n", get_character_in_map(map, argv[2], argv[3]));
	return (0);
}