#include "Mesh.h"

using std::to_string;
using std::string;

using std::pow;

void create_plane(Mesh& mesh, float width, float height)
{
	Vertex v1, v2, v3, v4;

	//create vertices
	v1 = Vertex(width, height, 0, 1);
	v2 = Vertex(0, height, 0, 2);
	v3 = Vertex(0, 0, 0, 3);
	v4 = Vertex(width, 0, 0, 4);

	Face face1;
	face1.v1 = v1;
	face1.v2 = v2;
	face1.v3 = v3;

	Face face2;
	face2.v1 = v1;
	face2.v2 = v3;
	face2.v3 = v4;

	mesh.vertices.push_back(v1);
	mesh.vertices.push_back(v2);
	mesh.vertices.push_back(v3);
	mesh.vertices.push_back(v4);

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);
}

void create_rect(Mesh& mesh, float width, float height, float depth)
{
	//create vertices
	Vertex v1, v2, v3, v4, v5, v6, v7, v8;


	v1 = Vertex(width/2, height/2, depth/2, 1);
	v2 = Vertex(-width/2, height/2, depth/2, 2);
	v3 = Vertex(-width/2, -height/2, depth/2, 3);
	v4 = Vertex(width/2, -height/2, depth/2, 4);

	v5 = Vertex(-width/2, height/2, -depth/2, 5);
	v6 = Vertex(width/2, height/2, -depth/2, 6);
	v7 = Vertex(width/2, -height/2, -depth/2, 7);
	v8 = Vertex(-width/2, -height/2, -depth/2, 8);

	mesh.vertices.push_back(v1);
	mesh.vertices.push_back(v2);
	mesh.vertices.push_back(v3);
	mesh.vertices.push_back(v4);

	mesh.vertices.push_back(v5);
	mesh.vertices.push_back(v6);
	mesh.vertices.push_back(v7);
	mesh.vertices.push_back(v8);

	//CUBE FACE 1
	Face face1;
	face1.v1 = v1;
	face1.v2 = v2;
	face1.v3 = v3;

	Face face2;
	face2.v1 = v1;
	face2.v2 = v3;
	face2.v3 = v4;

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);

	//CUBE FACE 2
	face1.v1 = v6;
	face1.v2 = v1;
	face1.v3 = v4;

	face2.v2 = v6;
	face2.v1 = v4;
	face2.v3 = v7;

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);

	//CUBE FACE 3
	face1.v1 = v5;
	face1.v2 = v6;
	face1.v3 = v7;

	face2.v2 = v5;
	face2.v1 = v7;
	face2.v3 = v8;

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);

	//CUBE FACE 4
	face1.v1 = v2;
	face1.v2 = v5;
	face1.v3 = v8;

	face2.v2 = v2;
	face2.v1 = v8;
	face2.v3 = v3;

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);


	//CUBE FACE 5
	face1.v1 = v6;
	face1.v2 = v5;
	face1.v3 = v2;

	face2.v2 = v6;
	face2.v1 = v2;
	face2.v3 = v1;

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);

	//CUBE FACE 6
	face1.v1 = v4;
	face1.v2 = v3;
	face1.v3 = v8;

	face2.v2 = v4;
	face2.v1 = v8;
	face2.v3 = v7;

	mesh.faces.push_back(face1);
	mesh.faces.push_back(face2);
}

void subdivide_mesh(Mesh& mesh, int times = 1)
{
	Mesh temp;

	/*********************************************
	*************** SUBDIVIDE MESH ***************
	*********************************************/
	cout << "Subdividing mesh. This may take some time." << "\n";
	for (int i = 0; i < times; i++)
	{
		cout << "Subdivision Pass #" << i + 1 << "\n";

		int size = mesh.faces.size();
		for (int j = 0; j < size; j++)
		{
			Face f1, f2, f3, f4;
			Vertex v1, v2, v3, v4, v5, v6;

			v1 = mesh.faces[0].v1;
			v3 = mesh.faces[0].v2;
			v5 = mesh.faces[0].v3;

			mesh.faces.erase(mesh.faces.begin());

			v1 = Vertex(v1.x, v1.y, v1.z);
			v2 = Vertex((v1.x + v3.x) / 2.0f, (v1.y + v3.y) / 2.0f, (v1.z + v3.z) / 2.0f);
			v3 = Vertex(v3.x, v3.y, v3.z);
			v4 = Vertex((v3.x + v5.x) / 2.0f, (v3.y + v5.y) / 2.0f, (v3.z + v5.z) / 2.0f);
			v5 = Vertex(v5.x, v5.y, v5.z);
			v6 = Vertex((v1.x + v5.x) / 2.0f, (v1.y + v5.y) / 2.0f, (v1.z + v5.z) / 2.0f);

			mesh.vertices.push_back(v1);
			mesh.vertices.push_back(v2);
			mesh.vertices.push_back(v3);
			mesh.vertices.push_back(v4);
			mesh.vertices.push_back(v5);
			mesh.vertices.push_back(v6);

			f1.v1 = v1;
			f1.v2 = v2;	//top left
			f1.v3 = v6;

			f2.v1 = v2;
			f2.v2 = v3;	//top right
			f2.v3 = v4;

			f3.v1 = v2;
			f3.v2 = v4;	//bottom left
			f3.v3 = v6;

			f4.v1 = v4;
			f4.v2 = v5;	//bottom right
			f4.v3 = v6;

			mesh.faces.push_back(f1);
			mesh.faces.push_back(f2);
			mesh.faces.push_back(f3);
			mesh.faces.push_back(f4);
		}
	}

	/******************************************************
	******************** OPTIMIZE MESH ********************
	******************************************************/
	//remove duplicate vertices
	cout << "Removing duplicate vertices. This may take some time." << "\n";

	for (int i = 0; i < mesh.vertices.size(); i++)
	{
		for (int j = i+1; j < mesh.vertices.size(); j++)
		{
			if (mesh.vertices[j] == mesh.vertices[i])
			{
				mesh.vertices.erase(mesh.vertices.begin() + j);
			}
		}
	}

	cout << "Vertices : " << mesh.vertices.size() << "\n";

	//assign vertices a number based on position in final mesh
	cout << "Assigning each vertex a specific ID." << "\n";
	int vertex_iterator = 1;
	for (int i = 0; i < mesh.vertices.size(); i++)
	{
		mesh.vertices[i].id = vertex_iterator++;
	}

	cout << "Indexing vertices of each face. This may take some time." << "\n";
	//index face vertices
	for (int i = 0; i < mesh.faces.size(); i++)
	{
		for (int j = 0; j < mesh.vertices.size(); j++)
		{
			if (mesh.faces[i].v1 == mesh.vertices[j])
			{
				mesh.faces[i].v1.id = mesh.vertices[j].id;
				continue;
			}

			if (mesh.faces[i].v2 == mesh.vertices[j])
			{
				mesh.faces[i].v2.id = mesh.vertices[j].id;
				continue;
			}

			if (mesh.faces[i].v3 == mesh.vertices[j])
			{
				mesh.faces[i].v3.id = mesh.vertices[j].id;
				continue;
			}
		}
	}

	cout << "Faces : " << mesh.faces.size() << "\n";
}

float calculate_distance(Vertex v1, Vertex v2)
{
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.x, 2) + pow(v2.z - v1.z, 2));
}

void save_mesh(string filepath, Mesh& mesh)
{
	std::ofstream file(filepath);

	cout << "Writing vertices to file. This may take some time. There will be no progress bar to optimize time." << "\n";
	for (int i = 0; i < mesh.vertices.size(); i++)
	{
		file << "v " << mesh.vertices[i].x << " " << mesh.vertices[i].y << " " << mesh.vertices[i].z << "\n";
	}

	cout << "Writing triangles to file. This may take some time. There will be no progress bar to optimize time." << "\n";
	for (int i = 0; i < mesh.faces.size(); i++)
	{
		file << "f " << mesh.faces[i].v1.id << " " << mesh.faces[i].v2.id << " " << mesh.faces[i].v3.id <<  "\n";
	}

	file.close();
	
	return;
}

void load_mesh(string filepath, Mesh& mesh)
{
	std::ifstream file(filepath);
	char c;
	float xf, yf, zf;
	int xi, yi, zi;

	bool notDone = true;
	while (notDone)
	{
		file >> c;
		if (c == 'v')
		{
			file >> xf >> yf >> zf;
			Vertex v(xf, yf, zf);
			mesh.vertices.push_back(v);
		}
		else if (c == 'f')
		{
			file >> xi >> yi >> zi;
			Face f;
			f.v1 = mesh.vertices[xi - 1];
			f.v1.id = xi;
			f.v2 = mesh.vertices[yi - 1];
			f.v2.id = yi;
			f.v3 = mesh.vertices[zi - 1];
			f.v3.id = zi;
			mesh.faces.push_back(f);
		}

		if (file.eof())
			break;
	}
}

void apply_heightmap(SimplexNoise noise, Mesh& mesh, int width, int height)
{
	std::vector<float> texture = noise.GetTexture();
	float magnitude = 100.0f;

	cout << "Applying heightmap to mesh." << "\n";

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			for (int i = 0; i < mesh.vertices.size(); i++)
			{
				if ((mesh.vertices[i].x == x) and (mesh.vertices[i].y == y))
				{
					mesh.vertices[i].z = texture[(y * width) + x] * magnitude;
					break;
				}
			}
		}
	}
}