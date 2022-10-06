#pragma once
class GameObject
{
private:
	class Game* mGame;

public:
	GameObject(class Game* game);
	virtual ~GameObject();

	class Game* game() { return mGame; }
};

