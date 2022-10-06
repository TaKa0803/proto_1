#pragma once
#include "GameObject.h"
#include "MyMath.h"

enum ShapeFillMode {
	kSolid,
	kFrame
};

class Screen :
	public GameObject
{
public:
	struct Data {
		Vector2D mScroll;
		Vector2D mCameraShake;

		Matrix33 mMatrix;

		unsigned int mColor;
		bool isCameraShake;
	};

private:
	Data mData;

public:
	Screen(class Game* game);
	~Screen();

	void Create();
	void Init();
	void Update();
	void CalcMatrix();

	Vector2D& scroll() { return mData.mScroll; }
	Vector2D& cameraShake() { return mData.mCameraShake; }

	Vector2D Conversion(const Vector2D& vec) const {
		return mData.mMatrix * vec;
	}

	void DrawBox() const;
	void DrawTriangle(const Vector2D& vec1, const Vector2D& vec2, const Vector2D& vec3, unsigned int color, ShapeFillMode fillmode) const;
	void DrawCircle(const Vector2D& vec, float rad, unsigned int color, ShapeFillMode fillmode) const;
	void DrawLine(const Vector2D& vec1, const Vector2D& vec2, unsigned int color) const;
	void DrawSprite() const;
	void DrawSpriteRect() const;
	void DrawQuad() const;
};