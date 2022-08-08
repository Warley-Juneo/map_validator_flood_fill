#include <stdio.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include <stdlib.h>
#include <time.h>

void	flood_fill(char	***matriz_map, int x, int y, char old_number, char new_number);
int	border_validator(char ***matriz, int x, int y);

void	print_map(char **matriz_map)
{
	int	line;
	int	colun;

	line = 0;
	while (matriz_map[line])
	{
		colun = 0;
		while (matriz_map[line][colun])
		{
			printf("%c", matriz_map[line][colun++]);
		}
		printf("\n");
		line++;
	}
}

int save_lines = 0;

int main()
{
	int	fd = open("./map.txt", O_RDONLY);
	int lines = 0;
	char	**matriz;
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		save_lines++;
	}

	matriz = (char **) malloc(sizeof(char *) * 15);
	close(fd);
	fd = open("map.txt", O_RDONLY);
	while (1)
	{
		buffer = get_next_line(fd);
		buffer = ft_strtrim(buffer, "\n");
		if (!buffer)
			break ;
		matriz[lines] = buffer;
		lines++;
	}
	matriz[lines] == NULL;
	print_map(matriz);
	flood_fill(&matriz, 11, 26, '2', '5');
	// printf("\n");
	// print_map(matriz);
	return (0);
}

void	flood_fill(char	***matriz_map, int x, int y, char old_number, char new_number)
{
	printf("%d %d\n", x, y);
	if (!matriz_map[0][x])
		return ;
	if (matriz_map[0][x][y] == old_number)
	{
		matriz_map[0][x][y] = new_number;
		if (border_validator(matriz_map, x, y))
		{
			printf("Map invalido\n");
			return ;
		}
		if (x > 0 && y > 0 && matriz_map[0][x][y + 1])
			flood_fill(matriz_map, x, y + 1, '0', '5');
		if (x > 0 && y > 0 && matriz_map[0][x][y - 1])
			flood_fill(matriz_map, x, y - 1, '0', '5');
		if (x > 0 && y > 0 && matriz_map[0][x + 1][y])
			flood_fill(matriz_map, x + 1, y, '0', '5');
		if (x > 0 && y > 0 && matriz_map[0][x - 1][y])
			flood_fill(matriz_map, x - 1, y, '0', '5');
	}
	print_map(*matriz_map);
}

int	border_validator(char ***matriz, int x, int y)
{
	if (x == 0 || y == 0 || y == ft_strlen(matriz[0][x]) - 1)
		return (1);
	else if (matriz[0][x][y + 1] != 5 || matriz[0][x][y + 1] != 1 || matriz[0][x][y + 1] != 0)
		return (1);
	else if (matriz[0][x][y - 1] != 5 || matriz[0][x][y - 1] != 1 || matriz[0][x][y + 1] != 0)
		return (1);
	else if (matriz[0][x + 1][y] != 5 || matriz[0][x + 1][y] != 1 || matriz[0][x][y + 1] != 0)
		return (1);
	else if (matriz[0][x - 1][y] != 5 || matriz[0][x - 1][y] != 1 || matriz[0][x][y + 1] != 0)
		return (1);
	return (0);
}
