/***************************************************************************
Sydney's Rock, Paper, Scissors Game 
Name: Sydney Serrano
Project #: 02
Date Completed: 9/17/18
***************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
  cout << "Welcome to the Rock-Paper-Scissors game!" << endl;
  string redo;
  int scoreP;//score of player
  int scoreC;//score of computer
  scoreP = 0;
  scoreC = 0;

  //Tallies choices of player
  int PR;
  int PP;
  int PS;
  PR = 0;
  PP = 0;
  PS = 0;

  //Tallies choices of computer
  int CR;
  int CP;
  int CS;
  CR = 0;
  CP = 0;
  CS = 0;

  //Tallies losses of player
  int PL;
  PL = 0;

  //Tallies ties of player and computer
  int ties;
  ties = 0;

  //Tallies total matches
  int total;
  total = 0;

  do
  {
  int choice;//Prompts player for choice
  cout << "Enter 1 for rock, 2 for paper, 3 for scissors." << endl;
  cin >> choice;

  srand (time(NULL));//computer chooses a number from 1 to 3
  int randomNumber;
  randomNumber = rand() % 3 + 1;

  switch (choice)//Displays player's choice
  {
    case 1:
      cout << "You chose rock" << endl;
      PR += 1;
      break;
    case 2:
      cout << "You chose paper" << endl;
      PP += 1;
      break;
    case 3:
      cout << "You chose scissors" << endl;
      PS += 1;
      break;
    default:
      cout << choice << " is not a valid choice" << endl;
  }

  switch (randomNumber)//Displays computer's choice
  {
    case 1:
      cout << "The computer chose rock" << endl;
      CR += 1;
      break;
    case 2:
      cout << "The computer chose paper" << endl;
      CP =+ 1;
      break;
    case 3:
      cout << "The computer chose scissors" << endl;
      CS += 1;
      break;
  }
  
  if (randomNumber == choice)//Comp & Player choose the same thing
  {
    cout << "You and the computer tied!" << endl;
    ties += 1;
    total += 1;
  }
  else if (randomNumber == 1 && choice == 3)//Comp Rock v Player Scissor
  {
    cout << "The computer won!" << endl;
    scoreC += 1;
    PL += 1;
    CR += 1;
    PS += 1;
    total += 1;
  }
  else if (randomNumber == 3 && choice == 1)//Comp Scissor v Player Rock
  {
    cout << "You won!" << endl;
    scoreP += 1;
    PR += 1;
    CS += 1;
    total += 1;
  }
  else if (randomNumber == 1 && choice == 2)//Comp Rock v Player Paper
  {
    cout << "You won!" << endl;
    scoreP += 1;
    CR += 1;
    PP += 1;
    total += 1;
  }
  else if (randomNumber == 2 && choice == 1)//Comp Paper v Player Rock
  {
    cout << "The computer won!" << endl;
    scoreC += 1;
    PL += 1;
    CP += 1;
    PR += 1;
    total += 1;
  }
  else if (randomNumber == 2 && choice == 3)//Comp Paper v Player Scissor 
  {
    cout << "You won!" << endl;
    scoreP += 1;
    CP += 1;
    PS += 1;
    total += 1;
  }
  else if (randomNumber == 3 && choice == 2)//Comp Scissor v Player Paper
  {
    cout << "The computer won!" << endl;
    scoreC += 1;
    PL += 1;
    CS += 1;
    PP += 1;
    total += 1;
  }

  redo = "";//Asks player if they want to play again
  cout << "Would you like to play again (Y for yes, N for no)?" << endl;
  cin >> redo;
  if (redo != "Y")//Displays stats when the game ends
  {
    cout << endl << "Thanks for playing!" << endl;
    cout << "The computer's score: " << scoreC << endl;
    cout << "The computer's choices: " << endl;
    cout << "Rock: " << CR << " Paper: " << CP << " Scissors: " << CS << endl;
    cout << endl << "Your score: " << scoreP << endl;
    cout << "Games tied: " << ties << endl;
    cout << "Games lost: " << PL << endl; 
    cout << "Your choices: " << endl;
    cout << "Rock: " << PR << " Paper: " << PP << " Scissors: " << PS << endl << endl;
    if (scoreC > scoreP)
    {
      cout << "The computer won the most rounds!" << endl;
      if (CR > CP && CR > CS)
      {
        cout << "The computer won most of the games choosing rock" << endl;
        cout << "You would have won most of the time if you chose paper" << endl << endl;
      }
      else if (CP > CR && CP > CS)
      {
        cout << "The computer won most of the games choosing paper" << endl;
        cout << "You would have won most of the time if you chose scissors" << endl << endl;
      }
      else if (CS > CP && CS > CR)
      {
        cout << "The computer won most of the games choosing scissors" << endl;
        cout << "You would have won most of the time if you chose rock" << endl << endl;
      }
    }
    else if (scoreC == scoreP)
      cout << "oof y'all tied" << endl << endl;
    else if (scoreP > scoreC) 
    {
      cout << "You won the most rounds!" << endl; 
      if (PR > PP && PR > PS)
        cout << "You won most of the rounds choosing rock" << endl << endl;
      else if (PP > PR && PP > PS)
        cout << "You won most of the rounds choosing paper" << endl << endl;
      else if (PS > PR && PS > PP)
        cout << "You won most of the rounds choosing scissors" << endl << endl;
    }
  }
  } while (redo == "Y");
  return 0;
} 
