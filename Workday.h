#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

class Workday
{
    private:
        int datecode;
        double timeWorked;
    
    public:
        Workday();
        Workday(string inputLine);
        ~Workday();
        int calcDatecode(string dateString);
        double calcTimeWorked(string timeString);
        int getDatecode();
        double getTimeWorked();
        void printWorkday();
}; 

Workday::Workday()
{
    datecode = 000000;
    timeWorked = 0.00;
}
Workday::Workday(string inputLine)
{
    int pos = inputLine.find(" ");
    string dateString = inputLine.substr(0, pos);
    string timeString = inputLine.substr(pos + 1);
    datecode = calcDatecode(dateString);
    timeWorked = calcTimeWorked(timeString);
}
Workday::~Workday()
{
    return;
}

int Workday::calcDatecode(string dateString)
{
    int m, d, y;
    
    int pos = dateString.find("/");
    m = stoi(dateString.substr(0, pos));
    dateString.erase(0, pos + 1);
    pos = dateString.find("/");
    d = stoi(dateString.substr(0, pos));
    y = stoi(dateString.substr(dateString.size() - 2));
    
    return (y * 10000) + (m * 100) + d;
}
double Workday::calcTimeWorked(string timeString)
{
    int hr, min;
    
    int pos = timeString.find(":");
    hr = stoi(timeString.substr(0, pos - 1));
    min = stoi(timeString.substr(pos + 2));
    
    return (double)(hr) + (double)(min / 60.0);
}

int Workday::getDatecode()
{
    return datecode;
}
double Workday::getTimeWorked()
{
    return timeWorked;
}

void Workday::printWorkday()
{
    cout.precision(3);
    cout << datecode << "                  " << timeWorked  << " hr" << endl;
}