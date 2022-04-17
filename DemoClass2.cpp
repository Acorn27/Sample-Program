//DemoClass2.cpp

//This program uses an expanded version of the Savings_Account
//class introduced in DemoClass1.cpp.

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
    double Get_Balance();
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
  cout << setprecision(2)
	 << setiosflags(ios::fixed)
	 << setiosflags(ios::showpoint);

  string id;
  double bal;
  double rt;
  double amount;

  cout << endl;
  cout << "Enter Account ID: ";
  getline(cin, id);

  cout << endl;
  cout << "Enter Balance: ";
  cin >> bal;

  cout << endl;
  cout << "Enter Interest Rate: ";
  cin >> rt;

  Savings_Account acc1(id, bal, rt);

  cout << endl;
  cout << "Account ID Number is " << acc1.Get_ID() << endl << endl;

  cout << "The balance in the account is now " << acc1.Get_Balance() << endl << endl;

  cout << "Enter an amount to deposit: ";
  cin >> amount;

  acc1.Deposit(amount);

  cout << endl << endl;
  cout << "A deposit of " << amount << " was made." << endl;
  cout << "The balance in the account is now " << acc1.Get_Balance();

  acc1.Calc_Interest();

  cout << endl << endl;
  cout << "Interest was applied to the account." << endl;
  cout << "The balance in the account is now " << acc1.Get_Balance();

  cout << endl << endl;
  cout << "Enter an amount to withdraw: ";
  cin >> amount;

  if (acc1.Withdraw(amount))
  {
    cout << endl << endl;
	  cout << "A withdrawal of " << amount << " was made.";
  }
  else
  {
    cout << endl << endl;
	  cout << "WITHDRAWAL NOT MADE: Insufficient funds.";
  }

  cout << endl;
  cout << fixed << showpoint;
  cout << setprecision(2);

  cout << "The balance in the account is now " << acc1.Get_Balance() << endl;

  return 0;
}
