#include "PolygonVertex.h"
#include "Game.h"
#include "Player.h"
#include "OrbitCircle.h"
PolygonVertex::PolygonVertex(Game* game) :
	GameObject(game)
{}

PolygonVertex::~PolygonVertex(){}

void PolygonVertex::Create(int i) {
	mData.mTheta = Math::ToRadians(90.0f + 120.0f * i);
	mData.mPosition = game()->player()->originalVertexPosition();
	mData.mState = kStay;
}

void PolygonVertex::Update() {
	mData.mPosition = game()->player()->originalVertexPosition().Rotated(mData.mTheta) + game()->player()->orbitCircle()->position();
}