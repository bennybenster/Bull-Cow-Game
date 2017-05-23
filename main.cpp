/* This is the console executable that makes use of the BullCowClass
This acts as the view in a MVC pattern and is responsible for the all 
user interaction for game logic see the FBullCowGame class!
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

int main();

void PrintOutro();
void PlayGame();
Ftext GetValidGuess();
bool AskToPlayAgain();
int32 GetNumberOfLetters();

FBullCowGame BCGame; //instantiate a new game 

//The entry point to our application
int main()
{
	
	bool bWantsToPlayAgain = false;
	do 
	{
		PlayGame();
		std::cout << "The word was: " << BCGame.GetHiddenWord() << "\n\n";
		bWantsToPlayAgain = AskToPlayAgain();
		if (bWantsToPlayAgain) 
		{
			BCGame.Reset();
		}
	} 
	while (bWantsToPlayAgain);
	return 0;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();
	//loop for the number of turns asking for guesses while the game is not won
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <=MaxTries)
	{
		Ftext PlayerGuess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(PlayerGuess); //get number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls << " - ";
		std::cout << "Cows = " << BullCowCount.Cows << "\n";		
		if (!BCGame.IsGameWon()) {      //there is some stuff here to print (if the game isn't won)
			if (MaxTries - BCGame.GetCurrentTry() > 0) //if more than one try
			{
				std::cout << (MaxTries + 1) - BCGame.GetCurrentTry() << " tries left\n\n";
			}
			else { std::cout << "This is your last try!\n\n"; } //if last try
		}
	}
	PrintOutro();
	return;
}
//loop before the game to get a valid setup type


//loop continually until I get a valid guess
Ftext GetValidGuess() 
{
	Ftext PlayerGuess = "";
	EGuessStatus Status = EGuessStatus::Invalid;
	do {//get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Enter your guess: \n";
		std::getline(std::cin, PlayerGuess);
		Status = BCGame.CheckGuessValidity(PlayerGuess);
		switch (Status)
		{
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (letters are all different)\n\n";
			break;
		case EGuessStatus::Not_lower_case:
			std::cout << "Please only type in lower case\n\n";
			break;
		default:
			//assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); //keep looping until no errors
	return PlayerGuess;
}

bool AskToPlayAgain()
{
	Ftext Response = "";
	std::cout << "Do you want to play again? y/n\n";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

//print exit criteria
void PrintOutro() {
	bool bGameWon = BCGame.IsGameWon();
	if (bGameWon) {
		std::cout << "You are a WINNER!!\n\n";
	}
	else {
		std::cout << "You are a LOSER!!\n\n";
	}
	return;
}