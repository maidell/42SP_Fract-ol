#include <mlx.h>

int	main(void)
{
	void	*mlx;
	

	mlx = mlx_init();
    mlx_new_window(mlx, 600, 800, "test");
    while (1);
}
    