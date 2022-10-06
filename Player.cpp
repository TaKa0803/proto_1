#include "Player.h"
#include "Game.h"
#include "Key.h"
#include "DeltaTime.h"
#include "Screen.h"
#include "OrbitCircle.h"

Player::Player(Game* game) :
	GameObject(game)
{}
Player::~Player(){
	delete[] mData.mVertexs;
	delete mData.mOrbitCircle;
}

void Player::Create() {
	mData.mTotalVertexNum = 4;
	mData.mVertexs = new PolygonVertex[mData.mTotalVertexNum]();
	mData.mOrbitCircle = new OrbitCircle(game());
	mData.mOrbitCircle->Create();
	mData.mOriginalVertexPosition = { mData.mOrbitCircle->radius(), 0};

	for (int i = 0; i < mData.mTotalVertexNum; i++) {
		mData.mVertexs[i].mTheta = Math::ToRadians(90.0f + 360.0f / mData.mTotalVertexNum * i);
		mData.mVertexs[i].mPosition = mData.mOriginalVertexPosition;
		mData.mVertexs[i].mState = PolygonVertex::kStay;
	}
	mData.mMoveVertexNum = 0;
	mData.isReverse = 1;
	mData.mVertexThetaSpeed = Math::ToRadians(0.5f);
}

void Player::Init() {

}

void Player::Update(){
	Input();
	mData.mVertexs[mData.mMoveVertexNum].mTheta += mData.mVertexThetaSpeed * mData.isReverse;
	
	for (int i = 0; i < mData.mTotalVertexNum; i++) {
		mData.mVertexs[i].mPosition = mData.mOriginalVertexPosition.Rotated(mData.mVertexs[i].mTheta) + mData.mOrbitCircle->position();
	}

}

void Player::Draw(){
	mData.mOrbitCircle->Draw();
	
	for (int i = 0; i < mData.mTotalVertexNum; i++) {
		int j = (i + 1) % mData.mTotalVertexNum;
		int k = (i + 2) % mData.mTotalVertexNum;
		game()->screen()->DrawTriangle(mData.mVertexs[i].mPosition, mData.mVertexs[j].mPosition, mData.mVertexs[k].mPosition, 0xFFFFFFFF, kSolid);
	}
	for (int i = 0; i < mData.mTotalVertexNum; i++) {
		game()->screen()->DrawCircle(mData.mVertexs[i].mPosition, 10, 0x000000FF, kSolid);
	}


}

void Player::Input(){
	if (Key::IsRelease(KC_SPACE)) {
		mData.mMoveVertexNum++;
		if (mData.mMoveVertexNum >= mData.mTotalVertexNum) {
			mData.mMoveVertexNum = 0;
		}
	}
	//if (Key::IsPressed(KC_SPACE)) {
	//	mData.isReverse = -1;
	//}
	//else {
	//	mData.isReverse = 1;
	//}
}