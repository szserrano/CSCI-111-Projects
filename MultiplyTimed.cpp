/***********************************************************************************
 * Sydney's Timed Multiplication Game
 * Name: Sydney Serrano
 * Side Project #: 02
 * Date Completed: 
 **********************************************************************************/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<time.h>
using namespace std;

int main()
{
  string redo;
  int dif;
  int f1;
  int f2;
  int correct;
  int answer;
  int score = 0;
  timespec ts_beg, ts_end;  
  int timer;
  string flag;
  flag = "green";
  string ready;
  ready = "";

  cout << "Welcome to the Timed Multiplication Game!" << endl;

  do {
    cout << "Please select a difficulty (Enter a number from 1 to 3): \n";
    cout << "'(1)Easy' - Factors range from 1 to 5. Time to answer: 5 seconds.\n"; 
    cout << "'(2)Medium' - Factors range from 5 to 10. Time to answer: 3 seconds.\n";
    cout << "'(3)Hard' - Factors range from 10 to 15. Time to answer: 14 seconds.\n\n";
    cin >> dif;
    switch (dif)
    {
      case 1:
        cout << "Your goal is to get at least 5 correct.\n";
        cout << "You have 5 seconds to answer each question.\n";
        cout << "Are you ready? (Enter 'Y' to begin or any key to exit)\n";
        cin >> ready;

        if (ready == "Y") 
        {
          cout << "Good luck!" << endl;
          do
          {
            timespec ts_beg, ts_end;
            srand (time(NULL));
            f1 = rand() % 5 + 1;
            f2 = rand() % 5 + 1;
            correct = f1 * f2;

            clock_gettime(CLOCK_REALTIME, &ts_beg);
            cout << "What is " << f1 << " * " << f2 << "?" << endl;
            cin >> answer;
            clock_gettime(CLOCK_REALTIME, &ts_end);
            timer = ts_end.tv_sec - ts_beg.tv_sec;
            if (timer == 1)
              cout << "You took 1 second to respond.\n";
            else
              cout << "You took " << timer << " seconds to respond" << endl;

            if (timer > 5)
            {
              cout << "I'm sorry, but you took " << timer << " seconds to respond. You are only allowed 5 seconds to respond." << endl;
              flag = "red";
            }

            if (answer == correct && timer <= 5)
            {
              cout << "Keep Going!" << endl;
              score++;
              flag = "green";
            }
            else if (answer == correct && timer > 5)
            {
              cout << "\nYour answer is correct, but you took too long to answer.\n";
              cout << "You should work on your multiplication skills within the range of 1 - 5. Here's your score: " << score << "\n\n";
            }
            else 
            {
              cout << endl << "I'm sorry, but your answer is not correct. The correct answer is: " << correct << endl;
              if (score > 5)
              {
                cout << "Good Job! Here's your score: " << score << endl << endl;
                break;
              }
              else
              {
                cout << "You should work on your multiplication skills within the range of 1 - 5. Here's your score: " << score << "\n\n";
                break;
              }
            }
          } while (answer == correct && flag == "green");
          break;
        }
        else
          break;

      case 2:
        cout << "Your goal is to get at least 10 correct." << endl;
        cout << "You have 3 seconds to answer each question.\n";
        cout << "Are you ready? (Enter 'Y' to begin or any key to exit)\n";
        cin >> ready;
        if (ready == "Y")
        {
          do
          {
            srand (time(NULL));
            f1 = 5 + (rand() % (10 - 5 + 1));
            f2 = 5 + (rand() % (10 - 5 + 1));
            correct = f1 * f2;

            clock_gettime(CLOCK_REALTIME, &ts_beg);
            cout << "What is " << f1 << " * " << f2 << "?" << endl;
            cin >> answer;
            clock_gettime(CLOCK_REALTIME, &ts_end);
            timer = ts_end.tv_sec - ts_beg.tv_sec;

            if (timer == 1)
              cout << "You took 1 second to respond.\n";
            else
              cout << "You took " << timer << " seconds to respond" << endl;

            if (timer > 3)
            {
              cout << "I'm sorry, but you took " << timer << " seconds to respond. You are only allowed 3 seconds to respond." << endl;
              flag = "red";
            }

            if (answer == correct && timer <= 3)
            {
              cout << "Keep Going!" << endl;
              score++;
              flag = "green";
            }
            else if (answer == correct && timer > 3)
            {
              cout << "\nYour answer is correct, but you took too long to answer.\n";
              cout << "You should work on your multiplication skills within the range of 5 - 10. Here's your score: " << score << "\n\n";
            }
            else 
            {
              cout << endl << "I'm sorry, but your answer is not correct. The correct answer is: " << correct << endl;
              if (score > 10)
              {
                cout << "Good Job! Here's your score: " << score << endl << endl;
                break;
              }
              else
              {
                cout << "You should work on your multiplication skills within the range of 5 - 10. Here's your score: " << score << "\n\n";
                break;
              }
            }
          } while (answer == correct && flag == "green");
          break;
        }
        else
          break;

      case 3:
        cout << "Your goal is to get at least 20 correct. Good luck!" << endl;
        cout << "You have 14 seconds to answer each question.\n";
        cout << "Are you ready? (Enter 'Y' to begin or any key to exit)\n";
        cin >> ready;

        if (ready == "Y") 
        {
          do
          {
            srand (time(NULL));
            f1 = 10 + (rand() % (15 - 10 + 1));
            f2 = 10 + (rand() % (15 - 10 + 1));
            correct = f1 * f2;
            clock_gettime(CLOCK_REALTIME, &ts_beg);
            cout << "What is " << f1 << " * " << f2 << "?" << endl;
            cin >> answer;
            clock_gettime(CLOCK_REALTIME, &ts_end);
            timer = ts_end.tv_sec - ts_beg.tv_sec;

            if (timer == 1)
              cout << "You took 1 second to respond.\n";
            else
              cout << "You took " << timer << " seconds to respond" << endl;

            if (timer > 14)
            {
              cout << "I'm sorry, but you took " << timer << " seconds to respond. You are only allowed 14 seconds to respond." << endl;
              flag = "red";
            }

            if (answer == correct && timer <= 14)
            {
              cout << "Keep Going!" << endl;
              score++;
              flag = "green";
            }
            else if (answer == correct && timer > 14)
            {
              cout << "\nYour answer is correct, but you took too long to answer.\n";
              cout << "You should work on your multiplication skills within the range of 10 - 15. Here's your score: " << score << "\n\n";
            }
            else 
            {
              cout << endl << "I'm sorry, but your answer is not correct. The correct answer is: " << correct << endl;
              if (score > 15)
              {
                cout << "Good Job! Here's your score: " << score << endl << endl;
                break;
              }
              else
              {
                cout << "You should work on your multiplication skills within the range of 10 - 15. Here's your score: " << score << "\n\n";
                break;
              }
            }
          } while (answer == correct && flag == "green");
          break;
        }
        else
          break;
    }

    cout << "Would you like to play again (Please enter 'Yes' or 'No')?" << endl;
    cin >> redo;
  } while (redo == "Yes");
  return 0;
}
