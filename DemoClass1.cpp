//DemoClass1.cpp

//This program illustrates the use of a simple class and member functions

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Savings_Account
{
  private:
    string id_no;
    double balance;
    double rate;

  public:
    Savings_Account(string, double, double);
    double Calc_Interest();
};

Savings_Account::Savings_Account(string id, double bal, double rt)
{
  id_no   = id;
  balance = bal;
  rate    = rt;
}

double Savings_Account::Calc_Interest()
{ 
  return balance * rate; 
}

int main()
{
 
  string id;     //Varaibles to store input data
  double bal;
  double rt;

  //Obtain Account information from the user

  cout << "\nEnter Account ID: ";
  getline(cin, id);

  cout << endl;
  cout << "Enter Balance: ";
  cin >> bal;

  cout << endl;
  cout << "Enter Interest Rate: ";
  cin >> rt;

  Savings_Account acc1(id, bal, rt);    //Initialize the object

  cout << endl;
  cout << fixed << showpoint;
  cout << setprecision(2);

  cout << "The interest on the account is " << acc1.Calc_Interest() << endl;

  return 0;
}

