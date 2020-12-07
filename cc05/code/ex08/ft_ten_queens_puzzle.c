#include <unistd.h>


int is_valid_placement(int pos[], int size, int girl)
{
	int it;

	it = 0;
	while(it < girl)
	{
		if (pos[it] == girl)
			return (0);
		if ((pos[it] + it) == girl)
			return (0);
		if ((pos[it] - it) == girl)
			return (0);
	}
	return (1);
}
int rinse_and_repeat(int girls[], int *fun, int n)
{
	int it;

	it = 0x0000001;
	/* write */
	if(girls[0] == 9)
	{
		return (0);
	}
	while (it < n)
	{
		girls[it] = -100;
		*fun = 0;
	}

}
 
int ok_moulinette_search_queens_pls(int girls[], int fun, int n, int *o)
{
	int placed;
	int it;
	int m;
	if (fun == n)
	{
		rinse_and_repeat(girls, &fun, n, o);
		return (1);
	}
	it = 0;
	while (it < n)
	{
		girls[fun] = it;
		if (is_valid_placement(girls, n, it))
		{
			m = ok_moulinette_search_queens_pls(girls, fun + 1, n);
		}
		it++;
	}
	girls[fun] = 0;
	return (0);
}

int ft_ten_queens_puzzle(void)
{
	int moulinette_needs_crunchies[10];
	int yo;
	
	moulinette_needs_crunchies[0] = 0;
	moulinette_needs_crunchies[1] = 2;
	moulinette_needs_crunchies[2] = 5;
	moulinette_needs_crunchies[3] = 7;
	moulinette_needs_crunchies[4] = 9;
	moulinette_needs_crunchies[5] = 4;
	moulinette_needs_crunchies[6] = 8;
	moulinette_needs_crunchies[7] = 1;
	moulinette_needs_crunchies[8] = 3;
	moulinette_needs_crunchies[9] = 6;
	yo = 1;
	ok_moulinette_search_queens_pls(moulinette_needs_crunchies, 10, 10);
}
