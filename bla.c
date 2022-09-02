int	init_game(t_list *map);
void	draw_no_player(t_mlx *mlx);
void	draw_player(t_mlx *mlx);
void	draw_background(t_mlx *mlx);
int	start_ray_casting_loop(t_list map);
int	perform_dda(t_vector *vec, t_list map);
int	calculate_ray_position_and_direction(t_vector *vec);
int	set_vectors(t_vector *vec);
void	calculate_step(t_vector *vec);

#include "cub.h"