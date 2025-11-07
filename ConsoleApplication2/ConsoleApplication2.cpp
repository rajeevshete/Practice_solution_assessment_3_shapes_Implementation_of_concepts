// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

bool compare(shape *a, shape *b)
{
    return (a->area() < b->area());
}

void display(vector<shape *> &vec)
{
    if (vec.empty())
    {
        cout << "No shapes to display!" << endl;
    }
    else
    {
        for (auto &i : vec)
        {
            cout << "Name: " << i->getname() << endl;
            cout << "Area: " << i->area() << endl;
            cout << "Perimeter: " << i->perimeter() << endl;
            cout << "-----------------------------------" << endl;
        }
    }
}

int main()
{
    int choice = 0;
    vector<shape *> vshape;
    stack<shape *> sshape;

    while (choice != 7)
    {
        cout << "---- - Geometry Shape Analyzer---- -" << endl;
        cout << "1. Add Shape" << endl;
        cout << "2. Display Shapes" << endl;
        cout << "3. Sort by Area" << endl;
        cout << "4. Search by Perimeter" << endl;
        cout << "5. Delete Shape" << endl;
        cout << "6. Undo Last Delete" << endl;
        cout << "7. Exit---------------------------------- -" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int choice2;
            cout << "Choose Shape Type :" << endl;
            cout << "1. Circle" << endl;
            cout << "2. Rectangle" << endl;
            cout << "3. Triangle" << endl;
            cout << "Choice :";
            cin >> choice2;

            if (choice2 == 1)
            {
                double r;
                cout << "Enter radius: ";
                cin >> r;
                circle *c1 = new circle(r);
                // sshape.push(c1);
                vshape.push_back(c1);
                cout << "Circle created successfully!" << endl;
            }
            else if (choice2 == 2)
            {
                double l, w;
                cout << "Enter length: " << endl;
                cin >> l;
                cout << "Enter width: " << endl;
                cin >> w;
                rectangle *r1 = new rectangle(l, w);
                // sshape.push(r1);
                vshape.push_back(r1);
                cout << "Rectangle created successfully!" << endl;
            }
            else if (choice2 == 3)
            {
                double a, b, c;
                cout << "Enter side 1: " << endl;
                cin >> a;
                cout << "Enter side 2: " << endl;
                cin >> b;
                cout << "Enter side 3: " << endl;
                cin >> c;
                triangle *t1 = new triangle(a, b, c);
                // sshape.push(t1);
                vshape.push_back(t1);
                cout << "Triangle created successfully!" << endl;
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
            break;
        }
        case 2:
        {
            // stack <shape*> display = sshape;
            // if (vshape.empty())
            // {
            //     cout << "No shapes to display!" << endl;
            // }

            // for (auto& i : vshape)
            // {
            //     cout << "Name: " << i -> getname() << endl;
            //     cout << "Area: " << i -> area() << endl;
            //     cout << "Perimeter: " << i -> perimeter() << endl;
            //     cout << "-----------------------------------" << endl;
            // }
            display(vshape);
            break;
        }
        case 3:
        {
            vector<shape *> vsorted = vshape;
            sort(vsorted.begin(), vsorted.end(), compare);
            cout << "Sorted list of shapes according to area: " << endl;
            display(vsorted);
            break;
        }
        case 4:
        {
            if (vshape.empty())
            {
                cout << "No shapes to search!" << endl;
                break;
            }
            double key_perimeter;
            cout << "Enter perimeter to search shape: ";
            cin >> key_perimeter;
            bool found = false;

            for (auto &i : vshape)
            {
                if (-1e-6 < i->perimeter() - key_perimeter && i->perimeter() - key_perimeter < 1e-6)
                {
                    cout << "Shape found!" << endl;
                    cout << "Name: " << i->getname() << endl;
                    cout << "Area: " << i->area() << endl;
                    cout << "Perimeter: " << i->perimeter() << endl;
                    found = true;
                    cout << "------------------------------" << endl;
                }
            }

            if (found)
            {
                cout << "Shape has been found" << endl;
            }
            else
            {
                cout << "Shape not found!" << endl;
            }
            break;
        }
        case 5:
        {
            int no;
            cout << "Enter the serial number of the shape to delete: ";
            cin >> no;
            if (vshape.empty())
            {
                cout << "No shapes to delete!" << endl;
                break;
            }
            if (no > vshape.size() || no < 1)
            {
                cout << "Invalid serial number!" << endl;
                break;
            }
            sshape.push(vshape[no - 1]);
            for (int i = no - 1; i < vshape.size() - 1; i++)
            {
                vshape[i] = vshape[i + 1];
            }
            vshape.pop_back();
            cout << "Shape deleted successfully!" << endl;
            display(vshape);
            break;
        }
        case 6:
        {
            if (sshape.empty())
            {
                cout << "No deleted shapes to undo!" << endl;
                break;
            }
            vshape.push_back(sshape.top());
            sshape.pop();
            cout << "Undo last delete successful" << endl;
            display(vshape);
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl;
            cout << "Please enter an integer between 1 to 7: " << endl;
            break;
        }
        }
    }
    if (choice == 7)
    {
        cout << endl;
        cout << "Exited successfully!";
    }
    while(!sshape.empty())
    {
        vshape.push_back(sshape.top());
        sshape.pop();
    }
    for(auto s : vshape)
    {
        delete s;
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
