#pragma once
#include "Screen.h"
class Container
{

private:
	// �E�B���h�E�f�[�^
	struct WindowData {
		const char* kWindowTitle;	// �^�C�g��
		const int kWindowWidth;		// ��
		const int kWindowHeight;	// ����
	};

	// �Q�[���f�[�^
	struct GameData	{
		Screen::Data screen;
	};

private:
	WindowData mWindowData;
	GameData mGameData;

// �Q�b�^�[
public:
	const WindowData& window() const { return mWindowData; }

	const Screen::Data& screen() const { return mGameData.screen; }

public:
	Container();
	~Container();

	void Load();

private:
	void setData();
	void setImages();
};

