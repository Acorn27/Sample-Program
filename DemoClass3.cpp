//DemoClass3.cpp

//This program uses an expanded version of the Savings_Account
//class introduced in DemoClass1.cpp.

//It illustrates the use of a destructor.

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
    Savings_Account(string, double);
    Savings_Account(string);
    ~Savings_Account();
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

  cout << "Three-arg constuctor for " << id_no << endl;
}

Savings_Account::Savings_Account(string id, double bal)
{
  id_no = id;
  balance = bal;
  rate = 0.02;

  cout << "Two-arg constuctor for " << id_no << endl;

}

Savings_Account::Savings_Account(string id)
{
  id_no = id;
  balance = 0.0;
  rate = 0.02;

  cout << "One-arg constuctor for " << id_no << endl;
}

Savings_Account::~Savings_Account()
{
  cout << "Destructor executed for " << id_no << endl;
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
  Savings_Account acc3("3333", 100.00, 0.06);
  Savings_Account acc2("2222", 200.00);
  Savings_Account acc1("1111");

  cout << endl;
  cout << "*** End of Program ***" << endl;

  return 0;
}
