#include "DXUT.h"
#include "cTitleUI.h"

cTitleUI::cTitleUI()
{
	for (int i = 0; i < 4; ++i)
		m_but.push_back(new cButton(VEC2(WINSIZEX - 250, 150 + 250 * i), VEC2(0.3, 0.3), VEC2(0.8, 0.8)));

	m_but[0]->m_text = IMAGE->FindTexture("TitleStartUI");
	m_but[1]->m_text = IMAGE->FindTexture("TitleHowtoUI");
	m_but[2]->m_text = IMAGE->FindTexture("TitleRankUI");
	m_but[3]->m_text = IMAGE->FindTexture("TitleExitUI");

	m_nowBut = 0;
}

cTitleUI::~cTitleUI()
{
	for (auto iter : m_but)
		SAFE_DELETE(iter);
	m_but.clear();
}

void cTitleUI::Init()
{
	m_but[m_nowBut]->m_isOn = false;
	m_nowBut = 0;
	m_but[m_nowBut]->m_isOn = true;
}

void cTitleUI::Update()
{
	if (KEYDOWN(VK_UP)) {
		m_but[m_nowBut]->m_isOn = false;
		if (m_nowBut != 0) m_nowBut--;
		else m_nowBut = 3;
		m_but[m_nowBut]->m_isOn = true;
	}
	if (KEYDOWN(VK_DOWN)) {
		m_but[m_nowBut]->m_isOn = false;
		if (m_nowBut < 3) m_nowBut++;
		else m_nowBut = 0;
		m_but[m_nowBut]->m_isOn = true;
	}
	if (KEYDOWN(VK_RETURN)) {
		SOUND->Play("SelectSND", false);
		switch (m_nowBut) {
		case 0:
			SCENE->ChangeScene("IntroScene", "WhiteFade", 1.5);
			break;
		case 1:
			SCENE->ChangeScene("HowtoScene", "BlackFade", 3);
			break;
		case 2:
			SCENE->ChangeScene("RankScene", "BlackFade", 5);
			break;
		case 3:
			PostQuitMessage(0);
			break;
		}
	}

	for (auto iter : m_but) 
		iter->Update();
}

void cTitleUI::Render()
{
	for (auto iter : m_but)
		iter->Render();
}

void cTitleUI::Release()
{
}
