#include "../parsing.h"

void check_f_and_last_line(t_tinfo *mapp)
{
	char *first;
	char *last;
	// int i;
	int f;

	first = mapp->dbl_ptr[0];
	last = mapp->dbl_ptr[mapp->hieght - 1];
	// i = 0;
	f = 0;

	while (first[f])
	{
		if (first[f] != '1' && first[f] != '\n')
			ft_error("👾 YOU NEED '1' IN FIRST ROW 👾", first);
		f++;
	}
	f = 0;
	while (last[f])
	{
		if (last[f] != '1' && last[f] != '\n')
			ft_error("👾 YOU NEED '1' IN LAST ROW 👾", last);
		f++;
	}
}