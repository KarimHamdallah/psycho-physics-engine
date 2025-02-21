#pragma once
#include <cmath>

namespace psycho
{
	struct vec2
	{
		float x, y = 0.0f;

		void Add(const vec2& v)
		{
			x += v.x;
			y += v.y;
		}
	};

	float length(const vec2& v)
	{
		return sqrtf((v.x * v.x) + (v.y * v.y));
	}

	float length(const vec2& p1, const vec2& p2)
	{
		float x = p1.x - p2.x;
		float y = p1.y - p2.y;
		return sqrtf((x * x) + (y * y));
	}

	vec2 normalize(const vec2& v)
	{
		float l = length(v);
		vec2 normalized = { 0.0f, 0.0f };
		
		if (l > 0)
		{
			normalized.x = v.x / l;
			normalized.y = v.y / l;
		}
		return normalized;
	}






	//////////////////// Mainfold ////////////////////
	struct collsion_manifold
	{
		bool collided = false;
		float penterationdepth = 0.0f;
		vec2 normal;
	};

	//////////////////// Shapes ///////////////////////

	struct circle
	{
		vec2 c;
		float r;
	};

	collsion_manifold circlevscircle(const circle& c1, const circle& c2)
	{
		float r = c1.r + c2.r;
		float dist = length(c1.c, c2.c);

		collsion_manifold manifold;

		if (dist > r)
			return manifold;

		manifold.collided = true;
		manifold.penterationdepth = r - dist;
		
		// calculate
		vec2 collsion_normal = { c2.c.x - c1.c.x, c2.c.y - c1.c.y };
		// normalize
		collsion_normal = normalize(collsion_normal);
		// scale
		collsion_normal.x *= manifold.penterationdepth;
		collsion_normal.y *= manifold.penterationdepth;

		manifold.normal = collsion_normal;

		return manifold;
	}
}
