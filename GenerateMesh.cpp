#include <fstream>
#include <sstream>

#include "Mesh.h"

using std::to_string;
using std::string;

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

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			output.indices.push_back(x + y * width);
			output.indices.push_back((x + 1) + y * width);
			output.indices.push_back(x + (y + 1) * width);

			output.indices.push_back((x + 1) + y * width);
			output.indices.push_back((x + 1) + (y + 1) * width);
			output.indices.push_back(x + (y + 1) * width);
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
		file.write("v ", sizeof(char)*2);
		str = to_string(mesh.vertices[i].x);
		file.write(str.c_str(), sizeof(str.c_str()));
		file.write(" ", 1);
		str = to_string(mesh.vertices[i].y);
		file.write(str.c_str(), sizeof(str.c_str()));
		file.write(" ", 1);
		str = to_string(mesh.vertices[i].z);
		file.write(str.c_str(), sizeof(str.c_str()));
		file.write("\n", 1);
	}

	for (int i = 0; i < mesh.indices.size(); i += 3)
	{
		file.write("f v", sizeof(char) * 3);
		str = to_string(mesh.indices[i]);
		file.write(str.c_str(), sizeof(str.c_str()));
		file.write(" v", 2);
		str = to_string(mesh.indices[i+1]);
		file.write(str.c_str(), sizeof(str.c_str()));
		file.write(" v", 2);
		str = to_string(mesh.indices[i+2]);
		file.write(str.c_str(), sizeof(str.c_str()));
		file.write("\n", 1);
	}

	file.close();
	
	return;
}