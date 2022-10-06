#include "Game.h"
#include <Novice.h>
#include "Key.h"
#include "Container.h"
#include "Scene.h"
#include "Normal.h"
#include "Screen.h"
#include "Player.h"


Game::Game() {

	mContainer = new Container();

	mScene[kNormal] = new Normal(this);

	mScreen = new Screen(this);

	mPlayer = new Player(this);

}

Game::~Game() {

	delete mPlayer;

	delete mScreen;

	for (int num = 0; num < kSceneIdNum; num++) {
		delete mScene[num];
	}

	delete mContainer;

}


void Game::Run() {

	// ���C�u�����̏�����
	Novice::Initialize(container()->window().kWindowTitle, container()->window().kWindowWidth, container()->window().kWindowHeight);

	mContainer->Load();

	mScene[kNormal]->Create();

	ChangeScene(kNormal);

	mScreen->Create();

	mPlayer->Create();

	// �E�B���h�E�́~�{�^�����������܂Ń��[�v
	while (Novice::ProcessMessage() == 0) {
		// �t���[���̊J�n
		Novice::BeginFrame();

		// �L�[���͂��󂯎��
		Key::Input();

		mScene[mCurrentSceneId]->Proc();
		
		// �t���[���̏I��
		Novice::EndFrame();

		// ESC�L�[�������ꂽ�烋�[�v�𔲂���
		if (Key::IsTrigger(KC_ESCAPE)) {
			break;
		}
	}

	// ���C�u�����̏I��
	Novice::Finalize();

}


void Game::ChangeScene(SceneId next) {
	mCurrentSceneId = next;
	mScene[mCurrentSceneId]->Init();
}
