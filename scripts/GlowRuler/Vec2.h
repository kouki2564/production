#pragma once
#include <cmath>

class Vec2
{
public:
	float x;
	float y;

	Vec2() :
		x(0.0f),
		y(0.0f)
	{
	}

	Vec2(float x, float y) :
		x(x),
		y(y)
	{
	}

	// 演算子
	Vec2 operator +() const
	{
		return *this;
	}

	Vec2 operator -() const
	{
		return Vec2{ -x,-y };
	}

	/// 足し算
	Vec2 operator +(Vec2 vec) const
	{
		return Vec2{ x + vec.x, y + vec.y };
	}
	Vec2 operator +=(Vec2 vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	/// 引き算
	Vec2 operator -(Vec2 vec) const
	{
		return Vec2{ x - vec.x, y - vec.y };
	}
	Vec2 operator -=(Vec2 vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	/// 掛け算
	Vec2 operator *(float scale) const
	{
		return Vec2{ x * scale, y * scale };
	}
	Vec2 operator *=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	/// 割り算
	Vec2 operator /(float scale) const
	{
		return Vec2{ x / scale, y / scale };
	}
	Vec2 operator /=(float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	bool operator !=(Vec2 vec)
	{
		return (static_cast<int>(x) != static_cast<int>(vec.x) || static_cast<int>(y) != (vec.y));
	}

	bool operator ==(Vec2 vec)
	{
		return (static_cast<int>(x) == static_cast<int>(vec.x) && static_cast<int>(y) == (vec.y));
	}

	float WallLength(Vec2 a) const
	{
		return sqrtf(a.x * a.x + a.y * a.y);
	}

	/// <summary>
	/// ベクトルの長さの2乗を求める
	/// </summary>
	/// <returns>長さの2乗</returns>
	float SqLength() const
	{
		return x * x + y * y;
	}

	/// <summary>
	/// ベクトルの長さを求める
	/// </summary>
	/// <returns>長さ</returns>
	float Length() const
	{
		return sqrtf(SqLength());
	}

	/// <summary>
	/// 自身の正規化を行う
	/// </summary>
	void Normalize()
	{
		float len = Length();

		// 長さ0以下なら処理を行わない
		if (len <= 0.0f) return;

		x /= len;
		y /= len;
	}
};