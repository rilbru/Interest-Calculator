/*****************************************************************************
# Author:           Devri Anderson 
# Lab:              Assignment #2
# Date:             January 22, 2022
# Description:      This program will calculate simple and compound interest
# Input:            int choice, double principal, double rate, double time, double comPeriod
# Output:           double totalAccrued, double interest
# Sources:          Zybooks
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//setting constants
const int SIMPLE = 1, COMPOUND = 2, QUIT = 3;

//function prototypes
void welcome();
void MenuFunction(); 
int readOption(int choice);
double readDouble(string prompt);
double getPrincipal();
double getRate();
double getTime();
double getComPeriod();
void executeOption(int choice);

int main() {
  //declaring variables
  int choice = 0;
  double interest = 0, totalAccrued = 0.0;

  //welcome function
  welcome();

  //set precision to 2 decimal places
  cout << fixed << setprecision(2);

  //do while loop to continue showing menu and calculate cost until user enters 3
  do
  {
    MenuFunction();
    choice = readOption(choice);
    executeOption(choice);

  }while (choice != QUIT);

  //display exit message
  cout << "\nThank you for using my program!" << endl;
} 

//welcome function
void welcome()
{
  cout << "Welcome to my Interest Calculation Program!" << endl;
}

//main menu function
void MenuFunction()
{
  cout << "\nWhat would you like to do today?" << endl;
  cout << "\nPick an option from below: " << endl;
  cout << "1. Simple interest \n2. Compound interest \n3. Quit" << endl;
}


//read option from user
int readOption(int choice)
{
  cin >> choice;
  // data validation
  while (!cin || choice < 1 || choice > 3)
  {
    cout << "Invalid Option! Please choose 1-3: ";
    cin.clear();
    cin.ignore(100, '\n');
    cin >> choice;
  }
  //return users choice 
  return choice;
}

//read option for doubles
double readDouble(string prompt)
{
  double temp = 0;
  //display the string from other functions
  cout << prompt;
  cin >> temp;
  //data validation
  while (!cin)
  {
    cin.clear();
      cin.ignore(100, '\n');
      cout << "\nInvalid input! Try again." << endl;
      cout << prompt;
      cin >> temp;
  }
  //returns the users entry to other functions
  return temp;
}


//calculate interest and total accrued
void executeOption(int choice)
{
  double principal, rate, time, comPeriod, totalAccrued, interest;

  // if statement to get principal, rate and time from user if they select 1 or 2
  if (choice == SIMPLE || choice == COMPOUND)
  {
  principal = getPrincipal();
  rate = getRate();
  time = getTime();
  }
  //if statement to calculate simple interest
  if (choice == SIMPLE)
  {
    interest = (principal * rate * time) / 100.0;
    totalAccrued = principal + interest;
  }
  //if statement to calculate compound interest
  if (choice == COMPOUND)
  {
    //calling compound period function
    comPeriod = getComPeriod();
    rate = (rate / 100.0);
    totalAccrued = principal * pow((1.0 + rate / comPeriod), (comPeriod * time));
    interest = totalAccrued - principal;
  }
  //if statement to display interest and total amount to the user
  if (choice == SIMPLE || choice == COMPOUND)
  {
    cout << "\nInterest accrued: $" << interest << endl;
    cout << "Total accrued amount (principal + interest): $" << totalAccrued << endl;
  }
}

//get principal amount function
double getPrincipal()
{
  double principal = 0.0;
  //sends the prinicipal amount entered to the readDouble function to validate data
  principal = readDouble("Enter the principal amount: ");
  //data validation
  while (principal < 1)
  {
    cout << "\nInvalid amount. Please enter again. ";
    principal = readDouble("\nEnter the principal amount: ");
  }
  //returns principal amount to other functions
  return principal;
}

//interest rate function
double getRate()
{
  double rate = 0.0;
  //sends the rate entered to the readDouble function to validate data
  rate = readDouble("\nEnter the interest rate: ");
  //data validation
  while (rate < 1)
  {
    cout << "\nInvalid amount. Please enter again. ";
    rate = readDouble("\nEnter the interest rate: ");
  }
  //returns the rate to other functions
  return rate;
}

//time function
double getTime()
{
  double time = 0.0;
  //sends the time entered to the readDouble function to validate data
  time = readDouble("\nEnter the time in years: ");
  //data validation
  while (time < 1)
  {
    cout << "\nInvalid time. Please enter again. ";
    time = readDouble("Enter the time in years: ");
  }
  //sends the time entered to other functions
  return time;
}

//compounding period function
double getComPeriod()
{
  double comPeriod = 0;
  //sends the compounding period entered to the readDouble function to validate data
  comPeriod = readDouble("\nEnter the number of compounding period: ");
  //data validation
  while (comPeriod < 1)
  {
    cout << "\nInvalid entry. Please enter again. ";
    comPeriod = readDouble("Enter the number of compounding period: ");
  }
  //returns the compounding period to other functions
  return comPeriod;
}
