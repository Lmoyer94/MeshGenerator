#include "Mesh.h"

int main()
{
	Mesh plane = create_plane(2, 2);
	save_mesh("plane.obj", plane);

	Mesh rect = create_rect(2,2,2);
	save_mesh("rect.obj", rect);

	return 0;
}