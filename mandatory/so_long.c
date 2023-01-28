#include"../so_long.h"

int	closewin(t_list *so_long) // the purpose of this function is to close the window when i click x button
{
	ft_printf("OH MAN YOU JUST RUINING IT :(\n"); // this message just for fun of course, it will display every time the user close the window with x button.
	mlx_clear_window(so_long->mlx, so_long->win);
/*
	mlx_clear_window is a function provided by the minilibX library,
	which is a simplified library for creating graphical programs on
	the X Window System (the underlying system used to manage windows
	and graphical interface in Unix-like operating systems, including
	Linux and macOS). The function is used to clear a window, typically
	by filling it with a solid color. It takes as parameters the address
	of the window to clear and the color to use.
*/
	exit(0); // The exit(1) function is used to terminate a program and return a status code of 1 to the operating system
}

int	main(int ac, char **av)
{
	t_list	so_long; 

	so_long.i = 0; // index of the so_long.map array.
	so_long.j = 0; // index of the so_long.map array.
	so_long.p = 0; // the number of 'P' character in map.
	so_long.e = 0; // the number of 'C' character in map.
	so_long.c = 0; // the number of collectibles.
	so_long.move = 0; // the number of the moves of our player we gonna use it to display it in terminal in mandatory part,
			  // but in bonus i diplay it in the window
	so_long.height = 0; // the height of our map.
	if (ac != 2) // to check the number of arguments that the user typed (THIS IS JUST A PROTECTION TO OUR PROGRAM)
		exit (1);
	map_valid(av[1], &so_long); // the parsing of map and check if the map valid or not
	so_long.mlx = mlx_init(); //  The mlx_init function initializes the connection to the X server and returns a pointer to the created MLX structure...
	so_long.win = mlx_new_window(so_long.mlx, so_long.width * 64,
			so_long.height * 64, "Farm"); // create a window and point to it with so_long.win
	if (!so_long.mlx || !so_long.win) //PROTECTION
		exit(1);
	print_map(&so_long); // use it to print map
	mlx_hook (so_long.win, 2, 1L << 0, move, &so_long); // Use keystrokes to move
	mlx_hook (so_long.win, 17, 1L << 0, closewin, &so_long); // closing the window
	mlx_loop(so_long.mlx); //  This event loop is responsible for handling input
			       //events from the X server, such as mouse movements or
			       //key presses, and updating the program's window accordingly.
	return (0);
}
