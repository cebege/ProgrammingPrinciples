#pragma once
#include <Windows.h>

class AudioManager
{
	static AudioManager* s_pInstance;

	bool m_SoundOn;

	AudioManager()
		: m_SoundOn(true)
	{

	}

	//is this a singleton design pattern? one and only one instance?
	// global access, no ownership, lazyinitialisation
	// saves memory - but how?
	// Flexibility

public:
	static AudioManager* GetInstance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new AudioManager();
		}
		return s_pInstance;
	}

	static void destroyInstance()
	{
		delete s_pInstance;
		s_pInstance = nullptr;
	}

	void ToggleSound()
	{
		m_SoundOn = !m_SoundOn;
	}

	bool IsSoundOn()
	{
		return m_SoundOn;
	}

	void playdoorclose()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(500, 75); // frequency and duration
		Beep(500, 75);
	}

	void playerdooropen()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(1397, 97);
	}

	void pickupkey()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(1568, 100);
	}

	void dropKeySound()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(1568, 200);
		Beep(1568, 50);
	}

	void moneySound()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(1568, 50);
	}

	void loseLife()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(200, 100);
	}

	void PlayLoseSound()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(500, 75);
		Beep(500, 75);
		Beep(500, 75);
		Beep(500, 75);
		Beep(500, 75);
		Beep(500, 75);
	}

	void win()
	{
		if (!m_SoundOn)
		{
			return;
		}
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1245, 1000);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1175, 1000);
	}
};