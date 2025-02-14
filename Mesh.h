#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <numbers>
#include <string>
#include <sstream>
#include <vector>

#include <Simplex.h>

using std::cout;
using std::vector;
using std::string;


struct Vertex
{
	float x, y, z;
	int id;

	Vertex(float x = 0.0f, float y = 0.0f, float z = 0.0f, int id = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->id = id;
	};

	bool operator==(Vertex rhs)
	{
		if (this->x == rhs.x and this->y == rhs.y and this->z == rhs.z)
		{
			return true;
		}
		else
			return false;
	}
};



struct Face
{
	Vertex v1, v2, v3;

	bool operator==(Face rhs)
	{
		if ((this->v1 == rhs.v1) or (this->v1 == rhs.v2) or (this->v1 == rhs.v3))
			if ((this->v2 == rhs.v1) or (this->v2 == rhs.v2) or (this->v2 == rhs.v3))
				if ((this->v3 == rhs.v1) or (this->v3 == rhs.v2) or (this->v3 == rhs.v3))
					return true;

		return false;
	}
};

struct Mesh
{
	vector<Vertex> vertices;
	vector<Face> faces;
};



const float TWOPI = 2.0f * std::numbers::pi;
const float TWOOVERPI = 2.0f / std::numbers::pi;

void create_plane(Mesh& mesh, float width, float height);
void create_rect(Mesh& mesh, float width, float height, float depth);

void subdivide_mesh(Mesh& mesh, int times);
float calculate_distance(Vertex v1, Vertex v2);

void save_mesh(string filepath, Mesh& mesh);
void load_mesh(string filepath, Mesh& mesh);

void apply_heightmap(SimplexNoise noise, Mesh& mesh, int width, int height);