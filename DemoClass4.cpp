//DemoClass4.cpp

//This program uses an expanded version of the Savings_Account
//class introduced in DemoClass1.cpp.

//The program illustrates object assignment

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
	  Savings_Account(string id, double bal = 0.00, double rt = 0.02);
    double Calc_Interest();
    double Get_Balance();
    double Get_Rate();
    string Get_ID();
    void Deposit(double);
    bool Withdraw(double);
};

Savings_Account::Savings_Account(string id, double bal, double rt)
{
  id_no   = id;
  balance = bal;
  rate    = rt;
}

double Savings_Account::Get_Balance()
{
  return balance;
}

string Savings_Account::Get_ID()
{
  return id_no;
}

double Savings_Account::Get_Rate()
{
  return rate;
}

double Savings_Account::Calc_Interest()
{
  double interest;

  interest = balance * rate;
  balance += interest;

  return interest;
}

void Savings_Account::Deposit(double amount)
{
  balance += amount;
}

bool Savings_Account::Withdraw(double amount)
{
  bool result;

  if (amount <= balance)
  {
    balance -= amount;
    result = true;
  }
  else
    result = false;

  return result;
}

int main()
{
  Savings_Account acc1("1111", 100.00, 0.03);
  Savings_Account acc2("2222", 200.00);

  acc2 = acc1;

  cout << fixed << showpoint;
  cout << setprecision(2);

  cout << "The new values for acc2 are: " << endl << endl;
  cout << "ID = " << acc2.Get_ID() << endl;
  cout << "Balance = " << acc2.Get_Balance() << endl;
  cout << "Rate = " << acc2.Get_Rate() << endl;

  return 0;
}
