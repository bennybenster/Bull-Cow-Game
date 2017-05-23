//Game logic is created here. All the important types that are required by the main consoles are here
#pragma once

#include "FBullCowGame.h"
#include <map>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define TMap std::map  //to make Unreal friendly

FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsThisGameWon; }

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,6}, {4,8}, {5,10}, {6,12}, {7,14}, {8,14} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
};

FBullCowGame::FBullCowGame() // this is the default constructor 
	{ Reset(); } //constructed from Reset()

void FBullCowGame::Reset()
{
	FString HIDDEN_WORD = StartofGamePrintIntroAndReturnAHiddenWord();
	bIsThisGameWon = false;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

FString FBullCowGame::StartofGamePrintIntroAndReturnAHiddenWord()
{
	int32 NumberOfLetters = 0;
	srand(static_cast<unsigned int>(time(NULL)));
	int32 RandIndex = 0;
	//This is the Intro
	std::cout << "  Bulls and Cows:                       /;    ;\\" << std::endl;
	std::cout << "       *A WORD GAME*                __  \\\\____//" << std::endl;
	std::cout << "                                   /{_\\_/   `'\\____" << std::endl;
	std::cout << "  Bulls are in the right place     \\___   (o)  (o  }" << std::endl;
	std::cout << "        _____________________________/          :--'  " << std::endl;
	std::cout << "    ,-,'`@@@@@@@@       @@@@@@         \\_    `__\\" << std::endl;
	std::cout << "   ;:(  @@@@@@@@@        @@@             \\___(o'o)" << std::endl;
	std::cout << "   :: )  @@@@          @@@@@@        ,'@@(  `===='" << std::endl;
	std::cout << "   :: : @@@@@:          @@@@         `@@@:" << std::endl;
	std::cout << "   :: \\  @@@@@:       @@@@@@@)    (  '@@@'" << std::endl;
	std::cout << "   ;; /\\      /`,    @@@@@@@@@\\   :@@@@@)  Cows are a good guess" << std::endl;
	std::cout << "   ::/  )    {_----------------:  :~`,~~;    but in the wrong place" << std::endl;
	std::cout << "  ;;'`; :   )                  :  / `; ;	    " << std::endl;
	std::cout << " ;;;; : :   ;                  :  ;  ; :       " << std::endl;
	std::cout << " `'`' / :  :                   :  :  : :" << std::endl;
	std::cout << "     )_ \\__;                   :_ ;  \\_\\       " << std::endl;
	std::cout << "     :__\\  \\                   \\  \\  :  \\ " << std::endl;
	std::cout << "         `^'                    `^'  `-^-'  " << std::endl;
	std::cout << "Your challenge is to guess an isogram (a word with no duplicate letters)\n\n";
	
	//This is to ask the user for the hidden word length required
	do {
		std::cout << "How many letters would you like to try and guess? 3-8?";
		std::cin >> NumberOfLetters;
		while (std::cin.fail())
		{
			std::cout << "Enter a number between 3 and 8\n";
			std::cin.clear();   //clear istream
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');  //repair istream
			std::cin >> NumberOfLetters; //get user input again
		}
		if ((NumberOfLetters < 3) || (NumberOfLetters > 8))
		{
			std::cout << "Enter a number between 3 and 8\n";
		}
	} while ((NumberOfLetters < 3) || (NumberOfLetters > 8));
	
	std::cin.clear();					//something was still in my 'cin'
	std::cin.ignore(10000, '\n');		//this code clears it (taken from internet)

	//This is to return a  randomly generated hidden word
	switch (NumberOfLetters)
	{
	case 3:
		RandIndex = rand() % 157;
		return ThreeLetterWordList[RandIndex];
		break;
	case 4:
		RandIndex = rand() % 402;
		return FourLetterWordList[RandIndex];
		break;
	case 5:
		RandIndex = rand() % 348;
		return FiveLetterWordList[RandIndex];
		break;
	case 6:
		RandIndex = rand() % 216;
		return SixLetterWordList[RandIndex];
		break;
	case 7:
		RandIndex = rand() % 134;
		return SevenLetterWordList[RandIndex];
		break;
	case 8:
		RandIndex = rand() % 54;
		return EightLetterWordList[RandIndex];
		break;
	}
	std::cout << "Something went wrong, please close the game and restart";
	return "SomethingWentWrong";
}

// Checks for validity and offers error types
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) { return EGuessStatus::Not_Isogram; } //if the guess is not an isogram
	else if (!IsLowerCase(Guess)) { return EGuessStatus::Not_lower_case; } //if the guess isn't all lowercase
	else if (Guess.length() != GetHiddenWordLength()) { return EGuessStatus::Wrong_length; } //if the guess is wrong length
	else { return EGuessStatus::OK; } //otherwise return OK
}

//receives a VALID guess, increments turn and then returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	
	MyCurrentTry++;//increment the turn number
	FBullCowCount ThisBullCowCount;//set up a return variable

	int32 HiddenWordLength = MyHiddenWord.length();
	// First do the loop for Bulls, if the guess character position is the same as the hidden word character position add to the bull count
	for (int32 GuChar = 0; GuChar < HiddenWordLength; GuChar++)
	{
		if (Guess[GuChar] == MyHiddenWord[GuChar])
		{
			ThisBullCowCount.Bulls++;
		}
		// If no bulls are found then do the loop for the cows.
		else {
			for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
			{
				if (Guess[GuChar] == MyHiddenWord[MHWChar])
				{
					ThisBullCowCount.Cows++;
				}
			}
		}
	}
	if (ThisBullCowCount.Bulls == HiddenWordLength)
	{
		bIsThisGameWon = true;
	}
	else {
		bIsThisGameWon = false;
	}
	// If no bulls or cows have been found nothing will be added
	return ThisBullCowCount;
}


//This will check to see if the string is an isogram
bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) return true; //treat 0 and 1 letter strings as isograms
	TMap<char,bool> LetterSeen;
	for (auto Letter : Word) 
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) { return false; }//check LetterSeen, if true, return false (duplicate)
		else  { LetterSeen[Letter] = true; } // otherwise make LetterSeen for that letter true
	}
	return true;  //for example if \0 is entered
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	if (Word.length() <= 0) return true; //treat 0 letter strings as lower case
	for (auto Letter : Word) 
	{
		if (!islower(Letter)) { return false; } //if not a lower case letter return false
	}
	return true; //anything other than an uppercase letter
}

