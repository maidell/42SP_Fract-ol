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

void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_var(t_fractol *f)
{
	f->min[REAL] = -1.5;
	f->max[REAL] = 1.5;
	f->min[IMAGINARY] = -1.5;
	f->max[IMAGINARY] = 1.5;
}

void	draw_fractol(t_mlx *m, t_fractol *f)
{
    t_fractol teste2;
	f->x = 0;
    teste2.x =0;
    while (f->x < WIDTH)
    {
        f->y = 0;
    }
}

int	main(void)
{
	t_mlx teste;
	t_fractol mudar;

	init_var(&mudar);
	init_mlx(&teste);
	mlx_loop(teste.mlx);
}