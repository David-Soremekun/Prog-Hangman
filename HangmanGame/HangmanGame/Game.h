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
	
	
	char WordArray[7] = {};
	std::string wordSoFar;
	
	//wordSoFar.assign(10,'e');
	std::string usedLetters;
	
	char guess;
	
	int wrongAttempts;
public:

	Game();
	~Game();
	void Play();
	void SetArrayBlank(int numberOfLetters);
	std::string ReturnWord();
	void ShuffleWords();
	void LoadWords();
	void CheckWin();

};

