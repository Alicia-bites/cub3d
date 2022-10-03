
	// if (game->depart == 'N')
	// 	game->ray.dirx = -1;
	// if (game->depart == 'N')
	// 	game->ray.plany = 0.66;
	if (game->depart == 'S')
		game->ray.dirx = 1;
	if (game->depart == 'S')
		game->ray.plany = -0.66;
	if (game->depart == 'E')
		game->ray.diry = 1;
	if (game->depart == 'E')
		game->ray.planx = 0.66;
	if (game->depart == 'W')
		game->ray.diry = -1;
	if (game->depart == 'W')
		game->ray.planx = -0.66;



	if (game->ray.raydiry == 0)
		game->ray.deltadistx = 0;
	else if (game->ray.raydirx == 0)
		game->ray.deltadistx = 1;
	else
		game->ray.deltadistx = sqrt(1 + (game->ray.raydiry
			* game->ray.raydiry) / (game->ray.raydirx *
			game->ray.raydirx));
	if (game->ray.raydirx == 0)
		game->ray.deltadisty = 0;
	else if (game->ray.raydiry == 0)
		game->ray.deltadisty = 1;
	else
		game->ray.deltadisty = sqrt(1 + (game->ray.raydirx *
			game->ray.raydirx) / (game->ray.raydiry *
			game->ray.raydiry));