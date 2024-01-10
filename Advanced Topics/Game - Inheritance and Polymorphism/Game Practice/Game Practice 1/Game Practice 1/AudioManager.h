#pragma once
#include <Windows.h>

using namespace std;

class AudioManager
{
	static AudioManager* _instance;

	AudioManager()
	{};

public:

	static AudioManager* getInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new AudioManager();
		}
		return _instance;
	}

	static void destroyInstance()
	{
		_instance = nullptr;
		delete _instance;
	}



};