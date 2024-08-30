#include<iostream>
#include<iomanip>
using namespace std;

class Digital_Clock
{
    private:
        int min, sec, hours, hour;
    public:
        Digital_Clock(int h, int m, int s): hours(h), min(m), sec(s)
        { /*Empty body*/                                           }
        void Display_Time()
        {
            if(hours>12)
                hour = hours-12;
            else
                hour = hours;

            if(hours<10)
                cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<" ";

            else if(min<10)
                cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<" ";

            else if(sec<10)
                cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<" ";

            else
                 cout<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<" ";    


            if(hours>=12&&hours<24)
                cout<<"pm";
            else if(hours==24)
                cout<<"am";
            else
                cout<<"am";
        }
};

int main()
{
    int hours, min, sec;
    cout<<"\n\t\t***Wellcome to Digital Clock***"<<endl;
    cout<<"Enter the time in 24 hour format: "<<endl;
    cout<<"Enter Hours: ";  cin>>hours;
    cout<<"Enter Minutes: ";  cin>>min;
    cout<<"Enter Seconds: ";  cin>>sec;
    Digital_Clock clock(hours, min, sec);
    clock.Display_Time();

    return 0;
}