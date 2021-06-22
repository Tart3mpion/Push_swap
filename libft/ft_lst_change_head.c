#include "libft.h"
void    ft_lst_change_head(t_list **alst, t_list **blst)
{
    t_list *tmp;
    if (blst)
    {
        while (*blst)
        {
            tmp = (*blst)->next;
            ft_lstaddfront(alst, blst);
            (*blst) = tmp;
        }
    }
}