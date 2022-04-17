// Chapter 14, Programming Challenge 3: Day of the Year Modification
#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
   int day;

public:
   static int daysAtEndOfMonth[ ];
   static string monthName[ ];
   void print();
   void printDayNumber( ) { cout << day; }
   void setDay(int day){this->day = day;}
   DayOfYear(string nameOfMonth, int dayOfMonth);
   DayOfYear() { };
   DayOfYear  operator++(int);
   DayOfYear  operator++( );
   DayOfYear  operator--(int);
   DayOfYear  operator--();
};

int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90,
                                      120, 151, 181,
                                      212, 243, 273,
                                      304, 334, 365 };

string DayOfYear::monthName[]= { "January", "February",
                                 "March", "April",
                                 "May", "June",
                                 "July", "August",
                                 "September", "October",
                                 "November", "December" };

// ***************************************
// Constructor                           *
// ***************************************
DayOfYear::DayOfYear(string nameOfMonth, int dayOfMonth)
{
    bool error = false;
    // Find month
    for (int m = 0; m < 12; m++)
    {
      if (nameOfMonth == monthName[m])
      {
        if (m  == 0)
        {
            day = dayOfMonth;
            error = dayOfMonth < 0 || dayOfMonth >= 32 ;
            if (error) break;
        }
        else
        {
           day = dayOfMonth + daysAtEndOfMonth[m-1];
           error = dayOfMonth < 0 ||
                   dayOfMonth  > daysAtEndOfMonth[m]  - daysAtEndOfMonth[m-1];
           if (error) break;
        }
        return;
      }
      // Try another month
    }
    // Not a legit month
    cout << "Incorrect  name or day of month";
    exit(1);
}

// *********************************
//         DayOfYear::print.       *
// Convert and print day of year   *
// *********************************
void DayOfYear::print()
{
    int month = 0;

    while (daysAtEndOfMonth[month] < day)
         month = (month + 1) % 12;

    // DaysAtEndOfMonth >= day
    if (month == 0)
      cout << "\nJanuary " << day << endl <<endl;
    else
    {
       cout << endl << monthName[month] <<  " "
            << day - daysAtEndOfMonth[month-1]
            << endl << endl;
    }
}

// ************************************
//            Postfix ++              *
//  Go forward one day in the year    *
// ************************************
DayOfYear DayOfYear::operator++(int)
{
  DayOfYear temp = *this;
  day ++;
  if (day == 366) day = 1;
  return temp;
}

// ************************************
//          Postfix --                *
//  Back up one day in the year       *
// ************************************
DayOfYear DayOfYear::operator--(int)
{
  DayOfYear temp = *this;
  day --;
  if (day == 0) day = 365;
  return temp;
}

// ************************************
//          Prefix ++                 *
//  Go forward one day in the year    *
// ************************************
DayOfYear DayOfYear::operator++()
{
  day ++;
  if (day == 366) day = 1;
  return *this;
}

// ************************************
//          Prefix --                 *
// Back up one day in the year        *
// ************************************
DayOfYear DayOfYear::operator--()
{
  day --;
  if (day == 0) day = 365;
  return *this;
}

int main()
{
    // Tell user what program does
    cout << "This program converts a Month and day of month into\n"
         << "A day of the year in the range 1..365";
    // Get user input
    cout << "\nEnter month and day (Example: January 3):  ";
    string month;
    int day;
    cin >>  month >> day;

    // Do computation and print result
    DayOfYear dy(month, day);
    dy.printDayNumber();

    --dy;
    cout << "\nThe day before is ";  dy.print();
    dy ++; dy ++;
    cout << "\nThe day after is "; dy.print();

    return 0;
}
