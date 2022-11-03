#include "fractol.h"

// ponteiro é uma variável que guarda o endereço de memória de outra variável
// . quando eu quero acessar o valor de uma variavel da struct
// quando eu quero acessa o valor de uma variavel da struct por meio de um ponteiro
//

void	init_mlx(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, TITLE);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->addr = mlx_get_data_addr(m->img, &m->bits_per_pixel, &m->line_length,
			&m->endian);
}

void	init_var(t_fractol *f)
{
	f->min[REAL] = -1.5;
	f->max[REAL] = 1.5;
	f->min[IMAGINARY] = -1.5;
	f->max[IMAGINARY] = 1.5;
}

int	main(void)
{
	t_mlx teste;
	t_fractol mudar;

	init_var(&mudar);
	init_mlx(&teste);
	draw_fractol(&teste, &mudar);
	//my_mlx_pixel_put(&teste, 400, 400, 0xFFF000);
	mlx_put_image_to_window(teste.mlx, teste.win, teste.img, 0, 0);
	mlx_loop(teste.mlx);
}