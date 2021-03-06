#pragma once
#include "cSingleton.hpp"

class cScene;
class cImage;
class cSceneManager : public cSingleton<cSceneManager>
{
private:
	map<string, cScene*> m_scenes;
	cScene* m_now = nullptr, *m_next = nullptr;

	bool m_isFadeChange = false;
	bool m_isFadeOut = false;
	double m_changeSpeed;
public:
	string  m_changeName;
	cImage* m_white = nullptr;
	cImage* m_black = nullptr;
	bool	m_isSceneChange = false;
public:
	cSceneManager();
	virtual ~cSceneManager();

	void AddScene(const string& key, cScene* scenePtr);
	void ChangeScene(const string& key, string changeName, double changeSpeed);

	void Update();
	void Render();

	void FadeSceneChange();

	string GetNowSceneKey();
};

#define SCENE cSceneManager::GetInst()