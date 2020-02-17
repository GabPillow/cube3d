#include "cub3d.h"

static	void putvision(t_mlx *mlx, int map[25][25])
{
	int HEIGHT = 800;
	int	WIDTH = 1000;
	int		x;
	int		y;
	x = 0;
	y = 0;
	while (x <= WIDTH)
	{
		mlx->camerax = 2 * x / (double)WIDTH - 1;
		mlx->ray_posx = mlx->cam_posx;
		mlx->ray_posy = mlx->cam_posy;
		mlx->ray_dirx = mlx->cam_dirx + mlx->planex * mlx->camerax;
		mlx->ray_diry = mlx->cam_diry + mlx->planey * mlx->camerax;
		mlx->mapx = (int)mlx->ray_posx;
		mlx->mapy = (int)mlx->ray_posy;
		mlx->deltadistx = fabs(1 / mlx->ray_dirx);
		mlx->deltadisty = fabs(1 / mlx->ray_diry);
		mlx->hit = 0;
		if (mlx->ray_dirx < 0)
		{
			mlx->stepx = -1;
			mlx->sidedistx = (mlx->ray_posx - mlx->mapx) * mlx->deltadistx;
		}
		else
		{
			mlx->stepx = 1;
			mlx->sidedistx = (mlx->mapx + 1.0 - mlx->ray_posx) * mlx->deltadistx;
		}
		if (mlx->ray_diry < 0)
		{
			mlx->stepy = -1;
			mlx->sidedisty = (mlx->ray_posy - mlx->mapy) * mlx->deltadisty;
		}
		else
		{
			mlx->stepy = 1;
			mlx->sidedisty = (mlx->mapy + 1.0 - mlx->ray_posy) * mlx->deltadisty;
		}
		while (mlx->hit == 0)
		{
			if (mlx->sidedistx < mlx->sidedisty)
			{
				mlx->sidedistx += mlx->deltadistx;
				mlx->mapx += mlx->stepx;
				mlx->side = 0;
			}
			else
			{
				mlx->sidedisty += mlx->deltadisty;
				mlx->mapy += mlx->stepy;
				mlx->side = 1;
			}
			if (map[mlx->mapx][mlx->mapy] > 0)
				mlx->hit = 1;
		}
		if (mlx->side == 0)
			mlx->perpwalldist = (mlx->mapx - mlx->ray_posx + (1 - mlx->stepx) / 2) / mlx->ray_dirx;
		else
			mlx->perpwalldist = (mlx->mapy - mlx->ray_posy + (1 - mlx->stepy) / 2) / mlx->ray_diry;
		mlx->hline = (int)( HEIGHT / mlx->perpwalldist);
		mlx->drawst = -mlx->hline / 2 + HEIGHT / 2;
		mlx->drawend = mlx->hline / 2 + HEIGHT / 2;
		if (mlx->drawst < 0)
			mlx->drawst = 0;
		if (mlx->drawend >= HEIGHT)
			mlx->drawend = HEIGHT - 1;
		y = mlx->drawst;
		while (y < mlx->drawend)
		{
			mlx->color = 8558335;
			if (mlx->side == 1)
				mlx->color = 7247615;
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, mlx->color);
			y++;
		}
		if (mlx->drawend < 0)
			mlx->drawend = HEIGHT;
		y = mlx->drawend;
		while (y < HEIGHT)
		{
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, 16737400);
			mlx_pixel_put(mlx->mlx, mlx->window, x, HEIGHT - y - 1, 16747640);
			y++;
		}
		x++;
	}
}

static int		event(int keycode, t_mlx *mlx)
{
		int map[25][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1},
{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	if (keycode == 13)
		move_forward(map, mlx);
	else if (keycode == 1)
		move_back(map, mlx);
	else if (keycode == 0)
		move_left(map, mlx);
	else if (keycode == 2)
		move_right(map, mlx);
	else if (keycode == 123 || keycode == 124)
		turning_cam(mlx, keycode == 123 ? -0.2 : 0.2);
	else
		return (0);
	putvision(mlx, map);
	return (0);
}

int	main()
{
			int map[25][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1},
{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int HEIGHT = 800;
	int	WIDTH = 1000;
	t_mlx mlx;
	mlx.spw = 0.2;
	//position camera
	mlx.cam_posx = 22;
	mlx.cam_posy = 11.5;
	//regard camera
	mlx.cam_dirx = -1;
	mlx.cam_diry = 0;
	//plan projection
	mlx.planex = 0;
	mlx.planey = 1;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "test");
	putvision(&mlx, map);
	mlx_hook(mlx.window, 2, 0, event, &mlx);
	mlx_loop(mlx.mlx);
}
