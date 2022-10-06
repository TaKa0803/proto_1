#pragma once
#include "GameObject.h"
#include "MyMath.h"

class Player : 
	public GameObject {

public:
	struct PolygonVertex {
		enum State {
			kMove,
			kStay,

			kStateNum
		};

		Vector2D mPosition;
		float mTheta;
		State mState;
	};

	struct Data {
		int mTotalVertexNum;
		PolygonVertex* mVertexs;
		Vector2D mOriginalVertexPosition;
		int mMoveVertexNum;
		float mVertexThetaSpeed;
		int isReverse;
		class OrbitCircle* mOrbitCircle;

	};


private:
	Data mData;


public:
	Player(class Game* game);
	~Player();

	void Create();
	void Init();
	void Update();
	void Draw();

	const Vector2D& originalVertexPosition() const { return mData.mOriginalVertexPosition; }
	const class OrbitCircle* orbitCircle() const { return mData.mOrbitCircle; }

private:
	void Input();

};