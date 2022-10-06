#pragma once
class Game
{
// コンテナ
private:
	class Container* mContainer;

public:
	const class Container* container() { return mContainer; }

// シーン
public:
	enum SceneId {
		kNormal,

		kSceneIdNum // シーンの種類
	};

private:
	// 現在のシーン
	SceneId mCurrentSceneId;
	// シーンポインタ
	class Scene* mScene[kSceneIdNum];

public:
	void ChangeScene(SceneId next);

private:
	class Screen* mScreen;

public:
	class Screen* screen() { return mScreen; }

// プレイヤー
private:
	class Player* mPlayer;

public:
	class Player* player() { return mPlayer; }

public:
	Game();
	~Game();

	void Run();

};

