#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*arrs;

	arrs = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (arrs->next != NULL)
	{
		arrs = arrs->next;
	}
	arrs->next = new;
}
