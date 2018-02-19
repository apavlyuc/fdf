
#include <plain.h>
#include <point.h>

void					print_plain(t_plain *plain)
{
	ft_lstiter(plain->points, &print_point_el);
}
