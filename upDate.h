/**
Ellesia Truong 026588859
Program #4: Overloaded Operators
CECS 282-Sec 04
Due Date: November 2, 2021 11:59pm
I certify that this program is my own original work. I did not copy any part of this program from any other source.
I further certify that I typed each and every line of code in this program.
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef upDate_H
#define upDate_H

class upDate{
  private:
    int * dates;
    int Month;
    int Day;
    int Year;
    static int counter;

  public:
    // default constructor
    upDate();

    // Overloaded constructor
    upDate(int M, int D, int Y);
    upDate(int J);

    // destructor
    ~upDate();

    void setDate(int M, int D, int Y);
    int getMonth();
    int getDay();
    int getYear();
    void setMonth(int M);
    void setDay(int D);
    void setYear(int);
    upDate(const upDate &d);
    string getMonthName();
    static int GetDateCount();

    int julian();
    int Greg2Julian (int MONTH, int DAY, int YEAR);
    void Julian2Greg (int jd, int &month, int &day, int &year);


    // Overloaded Operators
    upDate operator=(upDate d);

    // Incrementing Operators
    friend upDate operator+(int n, upDate d);
    upDate operator+(int n);
    upDate operator-(int n);

    // Adding and subtracting days
    upDate operator+=(int n);
    upDate operator-=(int n);

    upDate operator--();
    upDate operator--(int n);
    upDate operator++();
    upDate operator++(int n);


    // Days Between
    int daysBetween(upDate d);
    int operator-(upDate d);

    // Comparing Operators 
    bool operator==(upDate d);
    bool operator<(upDate d);
    bool operator>(upDate d);

    friend ostream& operator<<(ostream &str, const upDate& d);
};

#endif