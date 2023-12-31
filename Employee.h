#include "Workday.h"

using namespace std;

class Employee
{
    private:
    Workday* arrWork = new Workday[14];
    string id;
    double overtime, regular = 0.00;
    int numWorkdays = 0;
    string name;
    
    public:
    bool split = false;
    Employee();
    Employee(string newID, string newName);
    ~Employee();
    void addWorkday(Workday* day);
    void calcTimeWorked(int wk2datecode);
    string getID();
    string getName();
    double getOvertime();
    double getRegular();
    Workday* getArrWork();
    void printEmployee();
};

Employee::Employee()
{
    id = -1;
    name = "!!!!!!!!!";
}
Employee::Employee(string newID, string newName)
{
    id = newID;
    name = newName;
    int namePos = name.find(" ");
    name.insert(namePos, ",");
}
Employee::~Employee()
{
    return;
}

void Employee::addWorkday(Workday* day)
{
    arrWork[numWorkdays] = *day;
    numWorkdays++;
}

void Employee::calcTimeWorked(int wk2datecode)
{
    double tempRegular = 0.00;
    for(int i = 0; i < numWorkdays; i++)
    {
        if(arrWork[i].getDatecode() < wk2datecode)
        {
            if(tempRegular + arrWork[i].getTimeWorked() > 40.00)
            {
                overtime += tempRegular + arrWork[i].getTimeWorked() - 40.00;
                tempRegular = 40.00;
            }
            else
            {
                tempRegular += arrWork[i].getTimeWorked();
            }
        }
    }

    for(int i = 0; i < numWorkdays; i++)
    {
        if(arrWork[i].getDatecode() >= wk2datecode)
        {
            if(regular + arrWork[i].getTimeWorked() > 40.00)
            {
                overtime += regular + arrWork[i].getTimeWorked() - 40.00;
                regular = 40.00;
            }
            else
            {
                regular += arrWork[i].getTimeWorked();
            }
        }
    }
    regular += tempRegular;
}

string Employee::getID()
{
    return id;
}
string Employee::getName()
{
    return name;
}
double Employee::getOvertime()
{
    return overtime;
}
double Employee::getRegular()
{
    return regular;
}
Workday* Employee::getArrWork()
{
    return arrWork;
}

void Employee::printEmployee()
{
    cout << "\nID: " << id << endl;
    for(int i = 0; i < numWorkdays; i++)
    {
        arrWork[i].printWorkday();
    }
}