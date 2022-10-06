#include "Normal.h"
#include "Game.h"
#include "Player.h"
#include "OrbitCircle.h"

Normal::Normal(Game* game) :
	Scene(game)
{

}
Normal::~Normal(){}

void Normal::Create(){
}

void Normal::Init() {
	game()->player()->Init();
}

void Normal::Update(){
	game()->player()->Update();
}

void Normal::Draw(){
	game()->player()->Draw();
}

void Normal::NextScene(){}