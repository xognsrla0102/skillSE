#pragma once
class cScroolMap
{
private:
	cImage* m_img1, *m_img2;
	vector<cImage*> m_gas;
	cTimer* m_createGas;
public:
	double m_mapSpd;
	double m_gasSpd;
public:
	cScroolMap(cTexture* text);
	~cScroolMap();

	void Init();
	void Update();
	void Render();
	void Release();
};
