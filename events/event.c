#include "../cub3d.h"

int		event(int keycode, t_data *data)
{
	if (keycode == K_Z)
		move_forward(data);
	else if (keycode == K_S)
		move_back(data);
	else if (keycode == K_Q)
		move_left(data);
	else if (keycode == K_D)
		move_right(data);
	else if (keycode == K_ARRL || keycode == K_ARRR)
		turning_cam(data, keycode == K_ARRL ? SPT : -SPT);
	else if (keycode == K_ESC)
		ft_close_window(data);
	else
		return (0);
	ft_put_image(data);
	return (0);
}