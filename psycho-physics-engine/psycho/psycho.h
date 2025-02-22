#pragma once
#include <cmath>

#define ToRAD(degree) degree * 0.01745329251

namespace psycho2D
{

	///////////////////////////// Math Engine ///////////////////////////////

	struct vec2
	{
		union
		{
			struct { float x, y; };
			float arr[2];
		};

		float operator[](int index)
		{
			return arr[index];
		}

		vec2()
			: x(0.0f), y(0.0f) {
		}

		vec2(float x, float y)
			: x(x), y(y) {
		}

		vec2(float val)
			: x(val), y(val) {
		}

		void add(const vec2& v)
		{
			x += v.x;
			y += v.y;
		}

		void sub(const vec2& v)
		{
			x -= v.x;
			y -= v.y;
		}

		void scale(float val)
		{
			x *= val;
			y *= val;
		}

		float length()
		{
			return sqrtf((x * x) + (y * y));
		}

		float magnitude()
		{
			return length();
		}

		float lengthsqrd()
		{
			return (x * x) + (y * y);
		}

		void normalize()
		{
			float l = length();
			vec2 normalized = { 0.0f, 0.0f };

			if (l > 0)
			{
				normalized.x = x / l;
				normalized.y = y / l;
			}

			x = normalized.x;
			y = normalized.y;
		}

		void rotate(float angle)
		{
			vec2 result(0.0f);

			float rad = ToRAD(angle);
			result.x = x * cosf(rad) - y * sinf(rad);
			result.y = x * sinf(rad) + y * cosf(rad);

			x = result.x;
			y = result.y;
		}
	};

	vec2 add(const vec2& v1, const vec2& v2)
	{
		vec2 result(0.0f);
		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;
		return result;
	}

	vec2 sub(const vec2& v1, const vec2& v2)
	{
		vec2 result(0.0f);
		result.x = v1.x - v2.x;
		result.y = v1.y - v2.y;
		return result;
	}

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

	vec2 rotate(const vec2& v, float angle)
	{
		vec2 result(0.0f);

		float rad = ToRAD(angle);
		result.x = v.x * cosf(rad) - v.y * sinf(rad);
		result.y = v.x * sinf(rad) + v.y * cosf(rad);
		return result;
	}

	float dot(const vec2& v1, const vec2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}


	//////////////////// Manifold ////////////////////
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

	collsion_manifold circle_vs_circle(const circle& c1, const circle& c2)
	{
		float r = c1.r + c2.r;
		float dist = length(c1.c, c2.c);

		collsion_manifold manifold;

		if (dist > r)
			return manifold;

		manifold.collided = true;
		manifold.penterationdepth = r - dist;
		
		// calculate normal
		manifold.normal = sub(c2.c, c1.c);
		manifold.normal.normalize();
		manifold.normal.scale(manifold.penterationdepth);

		return manifold;
	}
}
