/******************************************************************************************
Sydney's Random Number Guessing Game
Name: Sydney Serrano
Project #: 01
Date Completed: 9/9/2018
******************************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//Main function
int main()
{
  // initialize random seed.
  srand (time(NULL) );

  //This holds the random number
  int randomNumber;

  //This prompts the user to choose a difficulty, and holds the difficulty in the int
  int dif;
  cout << "Choose a difficulty (Enter a number from 1-3. 1 being easy, 2 being medium, and 3 being hard)" << endl; 
  cin >> dif; 

  //These specify that guess and lives are integers
  int guess;
  int lives;

  //This if statement runs cetain code when the user chooses the easy difficulty 
  if (dif == 1)
  {
    //This generates a random number from 1 to 10 and sets the amount of guess attempts to 3
    randomNumber = rand() % 10 + 1;
    lives = 3;
    //This while loop runs the code telling the user the guessing range and the amount of 
    //attempts the user has. It also prompts the user to guess a number.
    while (lives > 0)
    {
      cout << "Guess the computer's number. (Range: 1-10)" << endl;
      cout << "Lives: " << lives << endl;
      cin >> guess;
      //These if, else if, and else statements are responsible for telling the user if the 
      //guess was higher, lower, or equal to the random number, decreases the amount of
      //lives by one and says how many more attempts the user has left.
      if (guess > randomNumber)
      {
        lives = lives - 1;
        if (lives == 0)
          cout << "I'm sorry, that is not correct. You lose." << endl;
        else
        cout << "Incorrect. The computer's number is lower than your last guess." << endl;
      }
      else if (guess < randomNumber)
      {
        lives = lives - 1;
        if (lives == 0)
          cout << "I'm sorry, that is not correct. You lose." << endl;
        else
          cout << "Incorrect. The computer's number is higher than your last guess." << endl;
      }
      else
      {
        cout << "You guessed correctly! You win!" << endl;
        break;
      }
    }
  }

  //This if statement runs prety much the same code as the last if statement, however only runs
  //when the user selects the medium difficulty. The block generates a random number from 1 to 
  //50 and sets the amount of attempts to 4.
  if (dif == 2)
  {
    randomNumber = rand() % 50 + 1;
    lives = 4;
    while (lives > 0)
    {
      cout << "Guess the computer's number. (Range: 1-50)" << endl;
      cout << "Lives: " << lives << endl;
      cin >> guess;
      if (guess > randomNumber)
      {
        lives = lives - 1;
        if (lives == 0)
          cout << "I'm sorry, that is not correct. You lose." << endl;
        else
          cout << "Incorrect. The computer's number is lower than your last guess." << endl;
      }
      else if (guess < randomNumber)
      {
        lives = lives - 1;
        if (lives == 0)
          cout << "I'm sorry, that is not correct. You lose." << endl;
        else
          cout << "Incorrect. The computer's number is higher than your last guess." << endl;
      }
      else
      {
        cout << "You guess correctly! You win!" << endl;
        break;
      }
    }
  }

  //This if statement runs the similar code as the previous if statement as well, but it runs 
  //when the user selects the hard difficulty. It generates a random number from 1 to 100
  //and gives the user 5 attempts to guess.
  if (dif == 3)
  {
    randomNumber = rand() % 100 + 1;
    lives = 5; 
    while (lives > 0)
    {
      cout << "Guess the computer's number. (Range: 1-100)" << endl;
      cout << "Lives: " <<  lives << endl;
      cin >> guess;
      if (guess > randomNumber)
      {
        lives = lives - 1;
        if (lives == 0)
          cout << "I'm sorry, that is not correct. You lose." << endl;
        else
        cout << "Incorrect. The computer's number is lower than your last guess." << endl;
      }
      else if (guess < randomNumber)
      {
        lives = lives - 1;
        if (lives == 0)
          cout << "I'm sorry, that is not correct. You lose." << endl;
        else
        cout << "Incorrect. The computer's number is higher than your last guess." << endl;
      }
      else
      {
        cout << "You guessed correctly! You win!" << endl;
        break; 
      }
    }
  }
  return 0;
}
