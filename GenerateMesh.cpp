#include "Mesh.h"

using std::to_string;
using std::string;

using std::pow;

Mesh create_plane(int width, int height)
{
	Mesh output;
	vec3 point;


	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			point = vec3(x, y, 0);
			output.vertices.push_back(point);
		}
	}

	for (int i = 0; i < output.vertices.size() - 1; i += 2)
	{
		float x1 = output.vertices[i].x;
		float y1 = output.vertices[i].y;
		float z1 = output.vertices[i].z;

		for (int j = 1; j < output.vertices.size(); j += 2)
		{
			float x2 = output.vertices[j].x;
			float y2 = output.vertices[j].y;
			float z2 = output.vertices[j].z;

			float distance1 = pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2);

			if (distance1 < 0)
				distance1 *= -1;

			if (distance1 <= 1 and distance1 > 0 and distance1 != 0)
			{
				output.indices.push_back(i+1);
			}
			else if (distance1 > 1 and distance1 > 0 and distance1 != 0)
			{
				output.indices.push_back(i+2);
			}
		}

	}

	return output;
}


void save_mesh(Mesh mesh)
{
	std::ofstream file("mesh.obj");
	std::string str;

	for (int i = 0; i < mesh.vertices.size(); i++)
	{
		file << "v " << mesh.vertices[i].x << " " << mesh.vertices[i].y << " " << mesh.vertices[i].z << "\n";
	}

	for (int i = 0; i < mesh.indices.size()-3; i += 3)
	{
		file << "f " << mesh.indices[i] << " " << mesh.indices[i + 1] << " " << mesh.indices[i + 2] << " " << mesh.indices[i + 3] << "\n";
	}

	file.close();
	
	return;
}