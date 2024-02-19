#include "SoundManager.h"
#include "Sound.h"

SoundManager::SoundManager():
	m_soundNum(0),
	m_soundCount(0)
{
}

SoundManager::~SoundManager()
{
	if (m_soundCount != 0)
	{
		for (int i = 0; i < m_soundCount; i++)
		{
			delete m_pSound[i];
			m_pSound[i] = nullptr;
		}
	}
}

void SoundManager::Init(int no)
{

}

void SoundManager::Update()
{
	// ‰¹—Ê‚âÄ¶ó‹µ“™‚ÌXV
}

void SoundManager::Output(int no)
{
	// Ä¶ŠÖ˜A
}

// Ä¶‚·‚é‚à‚Ì‚Ì’Ç‰Á
void SoundManager::CallSound(int no)
{
	m_soundCount++;
	m_pSound.resize(m_soundCount);
	m_pSound[m_soundCount - 1] = new Sound;
	m_pSound[m_soundCount - 1]->InitBGM(no);
}
