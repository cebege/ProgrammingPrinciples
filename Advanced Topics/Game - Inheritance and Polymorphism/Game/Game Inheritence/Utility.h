#pragma once

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

class Utility
{
public:
	static set<int> WriteHighScore(int score)
	{
		// see if file exists and read values

		string fileName = "highscores.txt";
		ifstream highScoreFile(fileName);
		istream_iterator<int> start(highScoreFile), end;
		set<int> highscores(start, end);
		highScoreFile.close();

		// if its empty, populate and save it.

		if (highscores.size() == 0)
		{
			highscores.insert(100);
			highscores.insert(50);
			highscores.insert(20);
			highscores.insert(10);
			highscores.insert(5);

			ofstream outFile(fileName);
			ostream_iterator<int> output_iterator(outFile, "\n");
			copy(highscores.begin(), highscores.end(), output_iterator);
			outFile.close();
		}

		// write score

		highscores.insert(score);

		// remove lowest score

		highscores.erase(highscores.begin());

		// write the highscores.
		ofstream outFile(fileName);
		ostream_iterator<int> output_iterator(outFile, "\n");
		copy(highscores.begin(), highscores.end(), output_iterator);
		outFile.close();

		return highscores;
	}


};