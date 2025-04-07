

#include <iostream>
using namespace std;
void input(double& hour, double& minute, char& colon);
void convert(double& hour);
void outcome(double& hour, double& minute);


int main()
{
    double hour(0.0), minute(0.0);
    char colon, option;
    do {
    cout<< "Enter 24 hour time in the format HH : MM" << endl;
    cin >> hour >> colon>> minute;
    input(hour, minute, colon);
    convert(hour);
    outcome(hour, minute);
    cout << "\nY/y continues, other quits" << endl;
    cin >> option;
    } while (option == 'y' || option == 'Y');
    
}

void input(double& hour, double& minute, char& colon)
{
    hour = hour;
    minute = minute;
}

void convert(double& hour)
{
    if (hour > 12)
    {
        hour = hour - 12.0; // 
    }
    else if (hour < 1)
    {
        hour = 12 + hour;
    }
    else
    {
        hour = hour - 0;
    }
}

void outcome(double& hour, double& minute)
{
    cout << "Time in 12 hour format: " << endl << hour << ":" << minute;
}
