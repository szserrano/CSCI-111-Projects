/****************************************
 * Sydney Serrano - Jurassic Park Section
 ***************************************/
#include<iostream>
using namespace std;

//These are the structures for the Hero and the Car
struct Hero
{
  float hp = 100.0;
  float money = 50.0;
  float dignity = 0.0;
  bool key1 = false;
  bool key2 = false;
  bool key3 = false;
  bool key4 = false;
};

struct Car
{
  int fuel = 10;
};

//These are the functions that are being used within this section
void tRex();
int firstChoice();
int secondChoice(int);
bool thirdChoice(int, int, Car, Hero);
bool carFuel(Car);
bool checkHealth(Hero);
bool keyCheck(bool);
Car fuelTracker(Car);
Car fuelDispenser(Hero, Car, int, int);
Hero lose(bool);
Hero fuelCost(Car, Hero, int, int);
Hero szserrano(Hero);

Hero szserrano(Hero protagonist){//This is the main shell of the jurassic park section
  int C1, C2, C3;
  bool key;
  Car jeep;
  tRex();
  C1 = firstChoice();
  C2 = secondChoice(C1);
  lose(checkHealth);
  jeep = fuelDispenser(protagonist, jeep, C1, C2);
  protagonist = fuelCost(jeep, protagonist, C1, C2);
  key = thirdChoice(C1, C2, jeep, protagonist);
  lose(checkHealth);
  if (key == true)
  {
    cout << "\nYou have escaped the T-rex with the key in posession!\n";
    protagonist.key1 = true;
  }
  else
    cout << "\nYou have died, but you can jump back in to try and snatch the key at the gate!\n";
  return protagonist;
}

void tRex(){//This tells the player that they are within the Jurassic Park movie.
  cout <<"             .-=-==--==--."<<endl;
  cout <<"       ..-=='  ,'o`)      `."<<endl;
  cout <<"     ,'         `""         \\"<<endl;
  cout <<"    :  (                     `.__...._"<<endl;
  cout <<"    |                  )    /         `-=-."<<endl;
  cout <<"    :       ,vv.-._   /    /               `---==-._"<<endl;
  cout <<"     \\/\\/\\/VV ^ d88`;'    /                         `."<<endl;
  cout <<"         ``  ^/d88P!'    /             ,              `._"<<endl;
  cout <<"            ^/    !'   ,.      ,      /                  '-,,__,,--'""""-._.-."<<endl;
  cout <<"           ^/    !'  ,'  \\ . .(      (         _           )  ) ) ) ))_,-.\\"<<endl;
  cout <<"          ^(__ ,!',''   ;:+.:%:a.     \\:.. . ,'          )  )  ) ) ,''    '"<<endl;
  cout <<"          ',,,'','     /o:::':%:%a.    \\:.:.:         .    )  ) _,'"<<endl;
  cout <<"           """"       ;':::'' `+%%%a._  \\%:%|         ;.). _,-'"<<endl;
  cout <<"                  ,-='_.-'      ``:%::)  )%:|        /:._,"<<endl;
  cout <<"                 (/(/'           ,' ,'_,'%%%:       (_,'"<<endl;
  cout <<"                                (  (//(`.___;        \\"<<endl;
  cout << "You're suddenly driving a jeep while a gigantic t-rex is chasing you!\nThe jeep's fuel tank is half empty!(10 gal left)\n\n";
}

int firstChoice(){//This prompts the player with which course of action he chooses to take to avoid the rock.
  int C1, C2;
  Hero protagonist;
  Car jeep;
  cout << "There is a rock in your path, allowing you to only turn right or left. Which do you choose?\n";
  cout << "1. Left\n2. Right\n3. Forward\n(Enter either '1', '2', or '3' for your choice): ";
  cin >> C1;
  return C1;
}

int secondChoice(int C1){//Depending on the previous choice, the player must choose between a few other options.
  int C2;
  Hero protagonist;
  Car jeep;
  switch(C1){
    case 1:
      jeep.fuel -= 1;
      cout << "\n\nYou turn left and end up a gas station. You have " << jeep.fuel << " gallons left.\n";
      cout << "You can either \n1. Refill your gas tank\n2. Keep driving ahead.\n";
      cout << "(Enter either '1' or '2' for your choice): ";
      cin >> C2;
      return C2;
    case 2:
      jeep.fuel -= 1;
      cout <<"\n\nYou turn right and go around the rock and you catch a glimpse of the gate on the other side of a thick grove of trees. You have " << jeep.fuel << " gallons left.\n";
      cout <<"What do you do?\n";
      cout <<"1. Drive through the grove of trees(requires 15 gallons of fuel)\n2. Keep following the road.\n";
      cout <<"(Enter either '1' or '2' for your choice): ";
      cin >> C2;
      if (C2 == 1)
      {
        bool b, key;
        cout << "\n\nYou cut throught the grove of trees, but you find that you slow to a stop midway. You find out that you have run out of fuel.\n";
        cout << "A tree blocks the T-rex's vision of the jeep and the T-rex ends up crushing you under it's giant foot.\n";
        protagonist.hp = 0;
        b = checkHealth(protagonist);
        key = keyCheck(b);
        return key;
      }
      else if (C2 == 2)
      {
        bool b, key;
        cout << "\n\nYou follow the road and slowly see the fuel needle drop to 'Empty'. You are just 50 yards from the gate and try to run to it.\n";
        cout << "You get out and run towards the gate until you are a few steps away from freedom when the T-rex completely devours you.\n";
        protagonist.hp = 0;
        b = checkHealth(protagonist);
        key = keyCheck(b);
        return key;
      }
    case 3:
      cout<<"\nYou decided to try to brute force your way THROUGH the rock and end up totalling the jeep and getting eaten by the T-rex.\n";
      protagonist.hp = 0;
      checkHealth(protagonist);
  }
}

bool thirdChoice(int C1, int C2, Car jeep, Hero protagonist){//Depending on the previous two choices, the player must choose a third choice.
  int C3;
  if (C1 == 1)
  {
    switch(C2){
      case 1:
        cout << "\n\nYou now have " << jeep.fuel << " gallons of fuel. You decide to drive back onto the road and catch a glimpse of the gate on the other side of a thick grove of \ntrees.\n";
        cout <<"What do you do?\n";
        cout <<"1. Drive through the grove of trees(requires 15 gallons of fuel)\n2. Keep following the road.\n";
        cout <<"(Enter either '1' or '2' for your choice): ";
        cin >> C3;
        if (C3 == 1 && jeep.fuel >=15)
        {
          bool b, key;
          cout << "\n\nYou cut through the grove of trees and make it through the gate, escaping the T-rex.\n";
          b = checkHealth(protagonist);
          key = keyCheck(b);
          return key;
        }
        else if (C3 == 2 && jeep.fuel >= 20)
        {
          bool b, key;
          cout << "\n\nYou follow the road all the way to the gate. The T-rex is a few steps away, but you manage to narrowly escape and acquire the key.\n";
          b = checkHealth(protagonist);
          key = keyCheck(b);
          return key;
        }
        else if (C3 == 1 && jeep.fuel <15)
        {
          bool b, key;
          cout << "\n\nYou cut throught the grove of trees, but you find that you slow to a stop midway. You find out that you have run out of fuel.\n";
          cout << "A tree blocks the T-rex's vision of the jeep and the T-rex ends up crushing you under it's giant foot.\n";
          protagonist.hp = 0;
          b = checkHealth(protagonist);
          key = keyCheck(b);
          return key;
        }
        else
        {
          bool b, key;
          cout << "\n\nYou follow the road and slowly see the fuel needle drop to 'Empty'. You are just 50 yards from the gate and try to run to it.\n";
          cout << "You get out and run towards the gate until you are a few steps away from freedom when the T-rex completely devours you.\n";
          protagonist.hp = 0;
          b = checkHealth(protagonist);
          key = keyCheck(b);
          return key;
        }
      case 2:
        jeep.fuel = 8;
        cout << "\n\nYou decide to drive back onto the road and you catch a glimpse of the gate on the other side of a thick grove of trees.\nYou have " << jeep.fuel << " gallons left.\n";
        cout <<"What do you do?\n";
        cout <<"1. Drive through the grove of trees(requires 15 gallons of fuel)\n2. Keep following the road.\n";
        cout <<"(Enter either '1' or '2' for your choice): ";
        cin >> C3;
        if (C3 ==1)
        {
          bool b, key;
          jeep.fuel = 0;
          cout << "\n\nYou try to cut through the grove of trees, but end up running out of fuel midway. The T-rex catches up and snatches you out from the driver\nseat and into his mouth.\n";
          protagonist.hp = 0;
          b = checkHealth(protagonist);
          key = keyCheck(b);
          return key;
        }
        else
        {
          bool b, key;
          jeep.fuel = 0;
          cout << "\n\nYou follow the road and slowly see the fuel needle drop to 'Empty'. You are just 50 yards from the gate and try to run to it.\n";
          cout << "You get out and run towards the gate until you are a few steps away from freedom when the T-rex completely devours you.\n";
          protagonist.hp = 0;
          b = checkHealth(protagonist);
          key = keyCheck(b);
          return key;
        }
    }
  }
}

//This function checks whether the car still has fuel.
bool carFuel(Car jeep)
{
  int a = jeep.fuel;
  if (a <= 0)
    return false;
  else
    return true;
}

//This function checks if the player has the key or not 
bool keyCheck(bool b)
{
  bool key;
  if (b == true)
    key = false;
  else if (b == false)
    key = true;
  return key;
}

//This function checks whether the protagonist still has health.
bool checkHealth(Hero protagonist)
{
  float a = protagonist.hp;
  bool b;
  if (a <= 0)
  {
    cout << "\nYou have died as your health has dropped to zero. You lose.\n";
    b = true;
    return b;
  }
  else if (a > 0)
  {
    b = false;
    return b;
  }
}

//This checks whether the player has lost.
Hero lose(bool b)
{
  Hero protagonist;
  bool lose = b;
  if (lose == true)
    return protagonist;
}

//This asks the player how many gallons of fuel they want to load into the jeep
Car fuelDispenser(Hero protagonist, Car jeep, int C1, int C2)
{
  if (C1 == 1 && C2 == 1)
  {
    jeep.fuel = 9;
    int gallons, amount;
    float a = jeep.fuel;
    float money = protagonist.money; 
    string YN;
    do {
      while (YN != "Y")
      {
        cout << "\nHow many gallons would you like to purchase? You have " << protagonist.money << " dollars and " << jeep.fuel << " gallons of fuel. Fuel costs $4 per gallon.";
        cout << "\n(If you wish to not purchase any fuel, enter 0 into this prompt and Y into the next prompt)\n";
        cin >> gallons;
        amount = gallons * 4;
        cout << "\nYour total is " << amount << " dollars.\nAre you sure you wish to purchase this much? (Y for Yes, N for No)\n";
        cin >> YN;

        if (money < amount)
        {
          cout << "You do not have enough funds to buy this many gallons of fuel.\n";
          YN = "N";
        }
        else
        {
          jeep.fuel = a + gallons;
          break;
        }
      }
    }while (money <= amount);
    return jeep;
  }
  else
    return jeep;
}

//This deducts the player's money if they bought fuel
Hero fuelCost(Car jeep, Hero protagonist, int C1, int C2)
{
  if (C1 == 1 && C2 == 1)
  {
    int f;
    float money = protagonist.money;
    int gallons, amount;
    f = jeep.fuel;
    gallons = f - 9;
    amount = gallons * 4;
    protagonist.money = money - amount;
    return protagonist;
  }
  else
    return protagonist;
}

int main()
{
  Hero protagonist;
  protagonist = szserrano(protagonist);

  cout << "\nYour health: " << protagonist.hp << endl;
  cout << "Your money: $" << protagonist.money << endl;
  cout << "Your dignity: " << protagonist.dignity << endl;
  cout << "Key or no key?: " << protagonist.key1 << endl;
  return 0;
}
