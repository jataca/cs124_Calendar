/***********************************************************************
* Program:
*    Project 2, Calendar
*    Brother Helfrich, CS124
* Author:
*    Jacob Casperson
* Summary: 
*    This is the most awesome c++ program I've ever created!!! It creates
*    any month calendar from 1753 to any date in the future! wow! 
*
*    Estimated:  8.0 hrs   
*    Actual:     8.0 hrs
*      ugh, where to start. The offset and spacing was a headache. I had
*      to rewrite the isLeapYear logic because I didn't understand the 
*      way Professor Helfrich did it. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prompts user for a month, must be a valid number
 ***********************************************************************/
int getMonth()
{
   int month;
   
   do
   {
      cout << "Enter a month number: ";
      cin  >> month;
      
      if (month < 1 || month > 12)
         cout << "Month must be between 1 and 12.\n";
   }
   while (month < 1 || month > 12);
      
   return month;
}

/**********************************************************************
 * Prompts user for a year. Must be 1753 or later
 ***********************************************************************/
int getYear()
{
   int year;
   
   do
   {
      cout << "Enter year: ";
      cin  >> year;
       
      if (year < 1753)
         cout << "Year must be 1753 or later.\n";
   }
   while (year < 1753);
      
   return year;
}

/**********************************************************************
 * Determines if it is a leap year or not
 ***********************************************************************/
bool isLeapYear(int year)
{
   // return a leap year if year / 4 has no remainder and year / 100
   // does have a remainder. Or return leap year if year / 400 = 0
   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
      return true;
   else
      return false; 
}

/**********************************************************************
 * Adds days to the total day count
 ***********************************************************************/
int monthCount(int month, int year)
{
   int monthDays = 0;

   // adds 31, 30, 29, or 28 to the number of days
   for (int previousMonth = 1; previousMonth < month; previousMonth++)
   {
      if (previousMonth == 1 || previousMonth == 3 || previousMonth == 5
          || previousMonth == 7 || previousMonth == 8
          || previousMonth == 10 || previousMonth == 12)
         monthDays = monthDays + 31;

      else if (previousMonth == 4 || previousMonth == 6 ||
               previousMonth == 9 || previousMonth == 11)
         monthDays = monthDays + 30;

      else if (previousMonth == 2 && isLeapYear(year) == false)
         monthDays = monthDays + 28;

      else
         monthDays = monthDays + 29; 

   }
   
   return monthDays;
}

/**********************************************************************
 * adds days to the total day count
 ***********************************************************************/
int yearCount(int year)
{
   int yearDays = 0;

   // adds 365 or 366 days
   for (int previousYear = 1753; previousYear < year; previousYear++)
   {
      if (isLeapYear(previousYear) == false)
         yearDays = yearDays + 365;

      if (isLeapYear(previousYear) == true)
         yearDays = yearDays + 366; 
   }
   
   return yearDays;
}

/**********************************************************************
 * Calculates the offset, which day to start the month
 ***********************************************************************/
int getOffset(int month, int year)
{
   int yearDays = yearCount(year);

   int monthDays = monthCount(month, year);

   int offset = (yearDays + monthDays) % 7;

   return offset;
}


/**********************************************************************
 * This is used for the displayTable, returns the number of days in the
 * month that the user selected
 ***********************************************************************/
int getDaysInMonth(int month, int year)
{
   int daysInMonth;

   // Give the number of days in the month that's displayed
   if (month == 1 || month == 3 || month == 5
          || month == 7 || month == 8
          || month == 10 || month == 12)
      daysInMonth = 31;
       
   else if (month == 4 || month == 6 ||
            month == 9 || month == 11)
      daysInMonth = 30;

   else if (month == 2 && isLeapYear(year) == false)
      daysInMonth = 28;

   else
      daysInMonth = 29;

   return daysInMonth;
}


/**********************************************************************
 * displays a header and the calender
 ***********************************************************************/
void displayTable(int offset, int numDays)
{
   // Here's where the real program starts
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n   ";

   // what day of the week it is
   int dayOfWeek = (offset + 1) % 7; 

   // get the correct offset to display
   for (int i = 0; i < dayOfWeek; i++)
      cout <<  "    "; 

   // get those numbers down with the correct spacing
   for (int dayOfMonth = 1; dayOfMonth <= numDays; dayOfMonth++)
   {

      if (dayOfMonth > 1 && dayOfMonth < 10)
         cout << "   " << dayOfMonth;

      else if (dayOfMonth >= 10)
         cout << "  " << dayOfMonth;

      else
         cout << dayOfMonth;
       
      dayOfWeek++;

      if (dayOfWeek % 7 == 0)
         cout << endl;
   }

   if (dayOfWeek % 7 != 0)
      cout << endl;


}

/**********************************************************************
 * yay! what month is it?
 ***********************************************************************/
void getMonthName(int month)
{
   if (month == 1)
      cout << "January";

   else if (month == 2)
      cout << "February";

   else if (month == 3)
      cout << "March";

   else if (month == 4)
      cout << "April";

   else if (month == 5)
      cout << "May";

   else if (month == 6)
      cout << "June";

   else if (month == 7)
      cout << "July";

   else if (month == 8)
      cout << "August";

   else if (month == 9)
      cout << "September";

   else if (month == 10)
      cout << "October";

   else if (month == 11)
      cout << "November";

   else if (month == 12)
      cout << "December";
}

/**********************************************************************
 * Main, as always main gets stuck calling all the other functions.
 * It does put out a few couts that I'd prefer to see in display but
 * oh well. IT WORKS!!!! :D 
 ***********************************************************************/
int main()
{
   int month = getMonth();

   int year = getYear();

   isLeapYear(year);

   int daysInMonth = getDaysInMonth(month, year);

   int offset = getOffset(month, year);

   cout << endl;
   
   getMonthName(month);

   cout << ", " << year << endl;
   
   displayTable(getOffset(month, year), daysInMonth);

   return 0;
   
}
