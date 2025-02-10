#include "Mesh.h"

int main()
{
	Mesh plane = create_plane(2, 2);
	save_mesh(plane);

	return 0;
}