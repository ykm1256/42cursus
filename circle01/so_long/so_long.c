/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:14 by kyoon             #+#    #+#             */
/*   Updated: 2022/07/06 18:20:48 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"
#include "stdlib.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

typedef struct	s_param
{
	int	x;
	int	y;
}				t_param;

void	param_init(t_param *param)
{
	param->x = 5;
	param->y = 5;
}


int		key_press(int keycode, t_param *param)
{
	static int a;

	if (keycode == KEY_W)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_S)
		param->y++;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_param	param;

	param_init(&param);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "test");
	mlx_hook(mlx_win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
}
