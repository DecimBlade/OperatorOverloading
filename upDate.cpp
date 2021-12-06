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
#include "upDate.h"
using namespace std;

int upDate::julian(){
  int JD1 = Greg2Julian(dates[0], dates[1], dates[2]);
  return JD1;
}

// Computes the Julian date given the Gregorian Calender Date
int upDate::Greg2Julian (int MONTH, int DAY, int YEAR){                                          
  int I,J,K; 

  I = YEAR;                                                                  
  J = MONTH;                                                                 
  K = DAY;  

  int JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;

  return JD;                              
}

// Computes the Gregorian Calender Date given the Julien Date
void upDate::Julian2Greg (int jd, int &month, int &day, int &year){
  int I,J,K,L,N; 

  L = jd+68569;                                                      
  N = 4*L/146097;                                                    
  L = L-(146097*N+3)/4;                                              
  I = 4000*(L+1)/1461001;                                             
  L = L-1461*I/4+31;                                                 
  J = 80*L/2447;                                                      
  K = L-2447*J/80;                                                   
  L = J/11;                                                        
  J = J+2-12*L;                                                     
  I = 100*(N-49)+I+L;

  year = I;                                                          
  month = J;                                                         
  day = K;
}

int upDate::counter = 0;

// Creating an array of pointers and then setting the date to the default date of May 11th, 1959
upDate::upDate(){
  dates = new int[3];
  
  dates[0] = 5;
  dates[1] = 11;
  dates[2] = 1959;

  counter++;
}

// Overloaded constructor: Allows the main to call the function and let it enter their own date. 
upDate::upDate(int M, int D, int Y){
  dates = new int[3];
  counter++;
  // Condition to check if the date has a valid month and day. 
  // If it doesn't then it will set the date to default, else it will set the date to the one inserted in the parameters.
  if(M < 1 || M > 12 || D < 1 || D > 31){
    dates[0] = 5;
    dates[1] = 11;
    dates[2] = 1959;
  }
  else{
    dates[0] = M;
    dates[1] = D;
    dates[2] = Y;
  }
}

// Overloaded constructor: Converting Julian to Greg and assigning the pointers to them.
upDate::upDate(int J){
  dates = new int[3];
  counter++;

  Julian2Greg(J, Month, Day, Year);

  dates[0] = Month;
  dates[1] = Day;
  dates[2] = Year;
}

// Destructor 
upDate:: ~upDate(){
  delete [] dates;
  counter--;
}

void upDate::setDate(int M, int D, int Y){
  if(M < 1 || M > 12 || D < 1 || D > 31){
    dates[0] = 5;
    dates[1] = 11;
    dates[2] = 1959;
  }
  else{
    dates[0] = M;
    dates[1] = D;
    dates[2] = Y;
  }
}

int upDate::getMonth(){
  return dates[0];
}

int upDate::getDay(){
  return dates[1];
}

int upDate::getYear(){
  return dates[2];
}

void upDate::setMonth(int M){
  dates[0] = M;
}

void upDate::setDay(int D){
  dates[1] = D;
}

void upDate::setYear(int Y){
  dates[2] = Y;
}


// Copy constructor
upDate::upDate(const upDate &d){
  dates = new int[3];
  counter++;

  dates[0] = d.dates[0];
  dates[1] = d.dates[1];
  dates[2] = d.dates[2];
}

string upDate::getMonthName(){
  string months[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  return months[Month - 1] + " " + to_string(Day) + ", " + to_string(Year);
}

int upDate::GetDateCount(){
  return counter;
}

// Operators 
upDate upDate::operator=(upDate d){
  dates[0] = d.dates[0];
  dates[1] = d.dates[1];
  dates[2] = d.dates[2];

  return *this;
}

upDate upDate::operator+(int n){
  int JD = Greg2Julian(dates[0], dates[1], dates[2]);
  JD = JD + n;

  int m1 = this->getMonth();
  int d1 = this->getDay();
  int y1 = this->getYear();
  Julian2Greg(JD, m1, d1, y1);


  upDate temp = upDate(m1, d1, y1);

  return temp;
}

upDate upDate::operator-(int n){

  int JD = Greg2Julian(dates[0], dates[1], dates[2]);
  JD = JD - n;

  int m1 = this->getMonth();
  int d1 = this->getDay();
  int y1 = this->getYear();
  Julian2Greg(JD, m1, d1, y1);

  upDate temp = upDate(m1, d1, y1);

  return temp;
}

upDate operator+(int n, upDate d){
  int JD, sumJD;
  upDate finalDate;

  JD = d.Greg2Julian(d.dates[0], d.dates[1], d.dates[2]);
  sumJD = JD + n;

  finalDate.Julian2Greg(sumJD, finalDate.dates[0], finalDate.dates[1], finalDate.dates[2]);
  return finalDate;
}

// Finding Days between - Operator
int upDate::daysBetween(upDate d){
  int JD1, JD2;
  JD1 = Greg2Julian(dates[0], dates[1], dates[2]);
  JD2 = Greg2Julian(d.dates[0], d.dates[1], d.dates[2]);

  return JD1 - JD2;
}

int upDate::operator-(upDate d){
  return daysBetween(d);
}

// INCREMENT OPERATORS
upDate upDate::operator+=(int n){
  int JD, finalDate;

  JD = Greg2Julian(dates[0], dates[1], dates[2]);
  finalDate = JD + n;

  Julian2Greg(finalDate, dates[0], dates[1], dates[2]);
  return *this;
}

upDate upDate::operator-=(int n){
  int JD, finalDate;

  JD = Greg2Julian(dates[0], dates[1], dates[2]);
  finalDate = JD - n;

  Julian2Greg(finalDate, dates[0], dates[1], dates[2]);
  return *this;
}

upDate upDate::operator++(){
  int JD;

  JD = Greg2Julian(dates[0], dates[1], dates[2]);
  JD = JD + 1;

  Julian2Greg(JD, dates[0], dates[1], dates[2]);
  return *this;
}

upDate upDate::operator++(int n){
  int JD;
  upDate temp(*this);

  JD = Greg2Julian(dates[0], dates[1], dates[2]);
  JD = JD + 1;

  Julian2Greg(JD, dates[0], dates[1], dates[2]);
  return temp;
}

upDate upDate::operator--(){
  int JD;

  JD = Greg2Julian(dates[0], dates[1], dates[2]);
  JD = JD - 1;

  Julian2Greg(JD, dates[0], dates[1], dates[2]);
  return *this;
}

upDate upDate::operator--(int n){
  int JD;
  upDate temp(*this);

  JD = Greg2Julian(dates[0], dates[1], dates[2]);
  JD = JD - 1;

  Julian2Greg(JD, dates[0], dates[1], dates[2]);
  return temp;
}


// COMPARING OPERATORS
bool upDate::operator==(upDate d){
  int JD1, JD2;
  JD1 = Greg2Julian(dates[0], dates[1], dates[2]);
  JD2 = d.Greg2Julian(d.dates[0], d.dates[1], d.dates[2]);

  if(JD1 == JD2){
    return true;
  }
  else{
    return false;
  }
}

bool upDate::operator<(upDate d){
  int JD1, JD2;
  JD1 = Greg2Julian(dates[0], dates[1], dates[2]);
  JD2 = d.Greg2Julian(d.dates[0], d.dates[1], d.dates[2]);

  if(JD1 < JD2){
    return true;
  }
  else{
    return false;
  }
}

bool upDate::operator>(upDate d){
  int JD1, JD2; 
  JD1 = Greg2Julian(dates[0], dates[1], dates[2]);
  JD2 = d.Greg2Julian(d.dates[0], d.dates[1], d.dates[2]);

  if(JD1 > JD2){
    return true;
  }
  else{
    return false;
  }
}

ostream& operator<<(ostream &str, const upDate& d){
  str << d.dates[0] << "/" << d.dates[1] << "/"<< d.dates[2];
  return str;
}