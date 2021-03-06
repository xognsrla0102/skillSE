#include "DXUT.h"
#include "cScroolMap.h"

cScroolMap::cScroolMap(cTexture* text)
{
	m_img1 = new cImage;
	m_img2 = new cImage;
	m_gas = new cImage;
	m_createGas = new cTimer(0);

	this->text = text;
	Init();
}

cScroolMap::~cScroolMap()
{
	Release();

	SAFE_DELETE(m_img1);
	SAFE_DELETE(m_img2);
	SAFE_DELETE(m_gas);
	SAFE_DELETE(m_createGas);
}

void cScroolMap::Init()
{
	m_img1->m_text = m_img2->m_text = text;

	m_gas->m_text = IMAGE->FindTexture("IngameSmokeIMG", rand() % 4);
	m_gas->m_pos = GXY(-500, -(double)m_gas->m_text->m_info.Height - 1000);

	m_img1->m_pos = VEC2(WINSIZEX / 2, WINSIZEY / 2 - (double)m_img2->m_text->m_info.Height);
	m_img2->m_pos = VEC2(WINSIZEX / 2, WINSIZEY / 2);

	if (GAME->m_isBehind) {
		m_mapSpd = 100;
		m_gasSpd = 1000;
	}
	else {
		m_mapSpd = 300;
		m_gasSpd = 1000;
	}
}

void cScroolMap::Update()
{
	if (m_createGas->Update()) {
		m_createGas->m_delay = 3.f + rand() % 2;
		m_gas->m_text = IMAGE->FindTexture("IngameSmokeIMG", rand() % 4);
		m_gas->m_pos = GXY(-500, -(double)m_gas->m_text->m_info.Height - 1000);
	}

	m_img1->m_pos.y += m_mapSpd * D_TIME;
	m_img2->m_pos.y += m_mapSpd * D_TIME;
	m_gas->m_pos.y += m_gasSpd * D_TIME;

	if (m_img2->m_pos.y >= WINSIZEY / 2 + (double)m_img2->m_text->m_info.Height) {
		m_img1->m_pos = VEC2(WINSIZEX / 2, WINSIZEY / 2 -(double)m_img2->m_text->m_info.Height);
		m_img2->m_pos = VEC2(WINSIZEX / 2, WINSIZEY / 2);
	}

}

void cScroolMap::Render()
{
	IMAGE->Render(m_img1->m_text, m_img1->m_pos, VEC2(1, 1), 0.f, true);
	IMAGE->Render(m_img2->m_text, m_img2->m_pos, VEC2(1, 1), 0.f, true);
	IMAGE->Render(m_gas->m_text, m_gas->m_pos, VEC2(2, 2));
}

void cScroolMap::Release()
{
}
