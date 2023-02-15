#pragma once
#include<vector>
#include<cstdlib>
#include<string>
#include <array>
#include<algorithm>
class Game
{
private:
	
	std::vector<std::string> wordCollection;
	
	 
	std::string THE_WORD;
	int grantedAttempts = 8;
	int lengthOfWord=THE_WORD.length();
	
	std::string wordSoFar;
	std::string usedLetters;
	
	char guess;
	
	int wrongAttempts;
public:

	Game();
	~Game();
	void Play();
	void ShuffleWords();
	void LoadWords();
	void CheckWin();

};

