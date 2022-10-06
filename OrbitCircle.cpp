#include "OrbitCircle.h"
#include "Game.h"
#include "Screen.h" 

OrbitCircle::OrbitCircle(class Game* game) :
	GameObject(game)
{}
OrbitCircle::~OrbitCircle(){}

void OrbitCircle::Create(){
	mData.mPosition = { 640,300 };
	mData.mRadius = 200;
}

void OrbitCircle::Init(){
	
}

void OrbitCircle::Draw(){
	game()->screen()->DrawCircle(mData.mPosition, mData.mRadius, 0xFFFFFFFF, kFrame);
}