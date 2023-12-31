#include "Employee.h"
#include <fstream>
#include <ctype.h>
#include <iomanip>

using namespace std;

int main()
{
    string s;
    string sTotal;
    int numEmployees = 0;
    int idIndex;
    
    Employee* employeeArr = new Employee[100];
    Employee* newEmployee; 
    Workday* dummy = new Workday();
    
    string wk1str, wk2str, fileName;
    int wk1datecode, wk2datecode;
    cout << "Enter name of file: (typing out \".txt\" at end of name is optional)" << endl;
    getline(cin, fileName);
    
    if(!(fileName.size() > 4 && fileName.substr(fileName.size() - 4) == ".txt"))
    {
        fileName += ".txt";
    }
    
    //cout << "Enter starting date of week 1: (mm/dd/yyyy OR m/d/yy)" << endl;
    cout << "Enter starting date of week 1: (mm/dd/yyyy OR m/d/yy)" << endl;
    getline(cin, wk1str);
    //wk1str = "5/20/2023";
    wk1datecode = dummy->calcDatecode(wk1str);
    
    cout << "Enter starting date of week 2: (7 days after previous date, same format)" << endl;
    getline(cin, wk2str);
    //wk2str = "5/27/2023";
    wk2datecode = dummy->calcDatecode(wk2str);
    
    //cout << wk1datecode << endl;
    //cout << wk2datecode << endl;
    
    ifstream in;
    in.open(fileName);

    string inputLine;
    getline(in, inputLine);

    while(!in.eof())
    {
        if(isalpha(inputLine.at(0))) {
            
        idIndex = -1;
        int pos2 = inputLine.find(" ");
        string newID = inputLine.substr(0, pos2);
        string newName = inputLine.substr(pos2 + 1);
        
        for(int i = 0; i < numEmployees; i++)
        {
            if(newID == employeeArr[i].getID())
            {
                idIndex = i;
            }
        }
        if(idIndex == -1)
        {
            newEmployee = new Employee(newID, newName);
            employeeArr[numEmployees] = *newEmployee;
            newEmployee = &employeeArr[numEmployees];
            numEmployees++;
        }
        else
        {
            newEmployee = &employeeArr[idIndex];
            newEmployee->split = true;
        }

        getline(in, inputLine);
        while(isdigit(inputLine.at(0)))
        {
            Workday* newWorkday = new Workday(inputLine);
            newEmployee->addWorkday(newWorkday);
            if(in.eof())
            {
                break;
            }
            getline(in, inputLine);
        } 
        }
        else
        {
            getline(in, inputLine);
        }
    }
    
    for(int i = 0; i < numEmployees; i++)
    {
        employeeArr[i].calcTimeWorked(wk2datecode);
        double regular = employeeArr[i].getRegular();
        double overtime = employeeArr[i].getOvertime();
        double total = regular + overtime;
        
        //cout << "\n" << employeeArr[i].getID() << " (" << employeeArr[i].getName() << ")\n";
        cout << "\n";
        cout << employeeArr[i].getID();
        cout << " ";
        cout << employeeArr[i].getName();
        cout << "\n";
        //cout << "hello";
        //cout << "bruh\n";
        //printf("Reg: %.2f, Ovr: %.2f (Tot: %.2f)", regular, overtime, total);
        cout << fixed;
        cout << setprecision(2);
        cout << "Reg: " << regular << ", Ovr: " << overtime << " (Tot: " << total << ")";
        if(!(employeeArr[i].split))
        {
            cout << endl;
        }
        else
        {
            cout << " !!! SPLIT !!!" << endl;
        }
    }
    return 0;
}