#include "Game.h"
#include <iostream>
#include<array>
#include <random>
#include <cctype>
#include <ctime>
Game::Game()
{
    LoadWords();
    THE_WORD = wordCollection[0];
    
    wrongAttempts = 0;
    usedLetters = "";

}
Game::~Game()
{
    for (int i=0; i<wordCollection.size();i++){
        wordCollection[i].pop_back();
    }
}

void Game::Play()
{
    
    srand(static_cast<unsigned int>(time(0)));

    ShuffleWords();

    std::cout<< "Welcome to Hangman. Good Luck :) " << std::endl;
    SetArrayBlank(7);
    

    while ((wrongAttempts<grantedAttempts) && (wordSoFar != THE_WORD)) {
        std::cout << "\n\nYou have " << (grantedAttempts - wrongAttempts);
        std::cout << " incorrect guesses left.\n" << std::endl;
        std::cout << "You've used the following letters:\n" << usedLetters << std::endl;
        std::cout << "\nSo Far, the word is:\n" << ReturnWord() << std::endl;
        

        std::cout << "\nEnter your Guess: ";
        std::cin >> guess;
        guess = toupper(guess);
        
        while (usedLetters.find(guess)!=std::string::npos) 
        {
            std::cout << "\nYou've already guessed " << guess << std::endl;
            std::cout << "Enter your Guess: " << std::endl;
            std::cin >> guess;
            guess = toupper(guess);

        }
        usedLetters += guess;
        
       if (THE_WORD.find(guess)!=std::string::npos)
       {
            std::cout << "That's correct! " << guess << " is in the word.\n";
            for (int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess)
                {
                    WordArray[i] = guess;
                }
            }
       }
       else
       {
           std::cout << "Sorry, " << guess << " isn't in the word.\n";
           ++wrongAttempts;
       }
       CheckWin();
       

    }
    
}

void Game::SetArrayBlank(int numberOfLetters)
{
    for (size_t i = 0; i < numberOfLetters; i++)
    {
        WordArray[i] = '*';
    }
}


std::string Game::ReturnWord()
{
    std::string str;
    for (char letter : WordArray) {
        str+=letter;
    }
    return str;
}

void Game::ShuffleWords()
{
    int randNum=0;

    for (size_t i = 0; i < wordCollection.size(); i++)
    {
        randNum = rand() % wordCollection.size();
        THE_WORD = wordCollection[randNum];
    }
    

}

void Game::CheckWin()
{
    if (wrongAttempts == grantedAttempts) {
        
        std::cout <<"" << std::endl;
        std::cout << "You have been HANGED :( " << std::endl;
       
    } 
    else {
        std::cout << ""<<std::endl;
        


        
    }

    //std::cout << "The Word was " << THE_WORD << std::endl;
      
}



void Game::LoadWords()
{
    wordCollection.push_back("RISOTTO");
    wordCollection.push_back("SASHIMI");
    wordCollection.push_back("CHURROS");
    wordCollection.push_back("ONIGIRI");
    
}

