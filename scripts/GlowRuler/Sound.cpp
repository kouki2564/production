#include "Sound.h"
#include "DxLib.h"
#include "Handle.h"

Sound::Sound() :
	m_num(0),
	m_handle(0),
	m_volume(0),
	m_volPow(0)
{
}

Sound::~Sound()
{
	m_handle = 0;
}

// BGM�̃n���h���Z�b�g
void Sound::InitBGM(const int& handle)
{
	m_handle = handle;
	m_num = 0;
}

// SE�̃n���h���Z�b�g
void Sound::InitSE(const int& handle)
{
	m_handle = handle;
	m_num = 1;
}

// BGM���ʐݒ�
void Sound::UpdateBGM(int BGMvol)
{
	m_volPow = BGMvol;
	// ���ʐݒ�
	if (m_num == 0 && m_volPow * 51 != m_volume)
	{
		m_volume = m_volPow * 51;
		if (this->ChackPlaying())
		{
			if (m_volPow == 0)
			{
				this->Stop();
			}
		}
		else
		{
			if(m_volPow != 0)
				this->LoopPlay();
		}
		ChangeVolumeSoundMem(m_volume, m_handle);
	}
}

// SE���ʐݒ�
void Sound::UpdateSE(int SEvol)
{
	m_volPow = SEvol;
	// ���ʐݒ�
	if (m_num == 1 && m_volPow * 51 != m_volume)
	{
		m_volume = m_volPow * 51;
 		ChangeVolumeSoundMem(m_volume, m_handle);
	}
}

// ���̂ݍĐ�
void Sound::OnePlay()
{
	if(m_volPow != 0)
		PlaySoundMem(m_handle, DX_PLAYTYPE_BACK, true);
}

// ���[�v�Đ�
void Sound::LoopPlay()
{
	if (m_volPow != 0)
		PlaySoundMem(m_handle, DX_PLAYTYPE_LOOP, true);
}

// �T�E���h��~
void Sound::Stop()
{
	StopSoundMem(m_handle);
}

// ���݉�������Ă��邩
bool Sound::ChackPlaying() const
{
	return CheckSoundMem(m_handle);
}
