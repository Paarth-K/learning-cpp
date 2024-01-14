#include <iostream>

using namespace std;

class Student
{
public:
    int id;
    string name;
    int grade;
    int age;
    string gender;

    void DisplayInfo()
    {
        cout << "ID: " << id << '\n';
        cout << "Name: " << name << '\n';
        cout << "Grade: " << grade << '\n';
        cout << "Age: " << age << '\n';
        cout << "Gender: " << gender << endl;
    }
};

class Employee
{
private:
    int id;
    string name;
    int age;
    string gender;
    string role;

public:
    Employee(int ID, string NAME, int AGE, string GENDER, string ROLE)
    {
        id = ID;
        name = NAME;
        age = AGE;
        gender = GENDER;
        role = ROLE;
    }

    void DisplayInfo()
    {
        cout << "ID: " << id << '\n';
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
        cout << "Gender: " << gender << endl;
        cout << "Role: " << role << '\n';
    }

    void UpdateName(string newName)
    {
        name = newName;
    }
};

class Rectangle
{
public:
    double width;
    double length;
    Rectangle(double WIDTH, double LENGTH)
    {
        width = WIDTH;
        length = LENGTH;
    }

    double area()
    {
        return width * length;
    }
    double perimeter()
    {
        return (width * 2) + (length * 2);
    }
};

int main()
{

    Rectangle rect1(100, 200);

    cout << "Area: " << rect1.area() << "\n";
    cout << "Perimeter: " << rect1.perimeter() << endl;

    // e1.DisplayInfo();
    // int age;
    // Employee e1(1, "Chad", 23, "Male", "CEO");

    // cout << "Enter your age: ";
    // cin >> age;
    // cout << endl;

    // cout << age << endl;

    return 0;
}