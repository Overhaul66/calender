#include <iostream>
#include <iomanip>
using namespace std;

class calender {
    int day;
    int month;
    int year;
    
    //first day of year
    
    int frstday;
    
    //number of days in months
    static int days[12]; 
    //name if months
    static string m[12];
    
    public:
   
    //dd mm yy
       calender(int d, int m, int y) : day(d), month(m), year(y) {
       
     //check for leap year
   
   if((year % 4 == 0 && year % 100 != 0) || (year%400 == 0 && year % 100 == 0)) {
        //change days of feb
        days[1] = 29;
   }
   
   //decrease year to work with 1st jan
   year -= 1;

   frstday = ((day + (2 * month)) + (3*(month+1)/5) + year + (year/4) - (year/100) +(year/400) + 2 ) % 7 ;
   
   //  frstday      result
   //   1           sunday
   //   2           monday
   //   3           tuesday
   //   4           wednesday
   //   5            thursday
   //   6             friday
   //   0             saturdat
   // 0 - 6 because of mod 7
   
   //saturday
   if(frstday == 0) frstday = 7;
   
  
    }
    //function to show calender
    void printCalender() ;
            
 };

int calender::days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string calender::m[12] = {
"January", "Febuary", "March", "April", "May","June","July","August","September", "October","November","December"
};

void calender::printCalender()  {
     int i = 0; //iterator for days
     int k = 1; //iterator for spaces
 
     for(int x=0; x<12; x++) {
     cout<<setw(23)<<m[x]<<'\n';
     cout<<"•••••••••••••••••••••••••••••••••••••\n";
     cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n";
 
       //spaces 
     
       for(; k<frstday; k++) {
           cout<<"     ";
       }
       
       for(int y=1; y<=days[i]; y++) {
          cout<<setw(5)<<y;
            
            //print newline when days is 7         
            if(k == 7) {
               cout<<'\n';
               k=0;
            }
            
            ++k;
       }
      
       frstday = k; k=1;
       ++i;
       cout<<'\n'<<'\n';
  }
   
     
  }
    


int main() {
  //13 for jan && 14 for feb

  int year;
  cout<<"Enter year to show calender\n";
  cin >> year;
  
           //dd  mm   yy
  calender c(1, 13, year);
  c.printCalender();
  
  cout<<"\nNotice : if any errors let me know";
  
  return 0;
}    