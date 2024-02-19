#pragma once
class Uti
{
public:
	Uti();
	~Uti();

	void Init();
	void Update();

	int GetLight() const { return m_light; }
	int GetBGM() const { return m_BGM; }
	int GetSE() const { return m_SE; }

	void SetUti(int BGM, int SE, int light);

private:
	// int�F�ݒ��ʂł����鐔�l�@float�Fint�ɉ����āA���ۂ�BGM���̐��l��������{��
	
	// ����
	int m_lightSet;
	int m_light;
	// BGM����
	int m_BGMSet;
	int m_BGM;
	// SE����
	int m_SESet;
	int m_SE;

};

