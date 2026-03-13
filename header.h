#ifndef _HEADER_H_
#define _HEADER_H_

#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

int	close_window(t_data *f);
int	key_hook(int key, t_data *f);
void	draw(t_data *d);

#endif