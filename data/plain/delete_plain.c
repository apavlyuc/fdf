
#include <plain.h>
#include <point.h>

void					delete_plain(t_plain **pp, char need_reverse)
{
	if (pp && *pp)
	{
		if (need_reverse)
			ft_lstrev(&((*pp)->points));
		ft_lstdel(&(*pp)->points, delete_point_el);
		ft_memdel((void**)pp);
	}
}
