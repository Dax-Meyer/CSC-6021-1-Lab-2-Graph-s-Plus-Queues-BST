#include<iostream>
#include<limits>
#include "Graph.h"
#include "Path.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

void showWelcome ();
void showMenu ();
int validate (int choice);
bool process (int choice);
void function1 ();
void function2 ();
void function3 ();

/////////////////////////////////////////////////////////////////////////////

Graph<int> g_int(4);

int main ()
{
    bool AGAIN = true;
    int choice = 0;

    showWelcome ();

    do
    {
        showMenu ();
        cout << endl << "Make your choice: ";
        cin >> choice;
        choice = validate (choice);
        AGAIN = process (choice);

    }
    while (AGAIN);
}

/////////////////////////////////////////////////////////////////////////////
// showMenu function
/////////////////////////////////////////////////////////////////////////////

void showMenu ()
{
    cout << "1. Add Nodes" << endl;
    cout << "2. Display Matrix" << endl;
    cout << "3. Find Shortest Path" << endl;
    cout << "4. Exit" << endl;
}

/////////////////////////////////////////////////////////////////////////////
// validate function
/////////////////////////////////////////////////////////////////////////////

int validate (int choice)
{
    while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }

    return choice;
}

/////////////////////////////////////////////////////////////////////////////
// showWelcome Function
/////////////////////////////////////////////////////////////////////////////

void showWelcome ()
{
    cout << "///////////////////////////////" << endl;
    cout << "Welcome to the Graph-Based Robot Path Planning " << endl;
    cout << "///////////////////////////////" << endl;
}

/////////////////////////////////////////////////////////////////////////////
// process function
/////////////////////////////////////////////////////////////////////////////

bool process (int choice)
{
    bool AGAIN = true;

    enum Options
    { 
        ADD_NODE = 1, 
        DISPLAY_MATRIX, 
        SHORTEST_PATH, 
        EXIT 
    };

    switch (choice)
    {
        case ADD_NODE:
            cout << "Enter function 1." << endl;
            function1 ();
            break;

        case DISPLAY_MATRIX:
            cout << "Enter function 2." << endl;
            function2 ();
            break;

        case SHORTEST_PATH:
            cout << "Enter function 3." << endl;
            function3 ();
            break;


        case EXIT:
            cout << "Exiting... Thank you for using the program!" << endl << endl;
            AGAIN = false;
    }

    return AGAIN;
}

/////////////////////////////////////////////////////////////////////////////
// function1 function
/////////////////////////////////////////////////////////////////////////////

void function1 ()
{
    int number_of_edges;

    cout << "\n========== ADD EDGES ==========" << endl;

    cout << "How many edges would you like to add? ";
    cin >> number_of_edges;

    for (int i = 0; i < number_of_edges; i++)
    {
        int start, end;

        cout << "\nEnter starting node: ";
        cin >> start;

        cout << "Enter ending node: ";
        cin >> end;

        g_int.add_edge(start, end);
    }
}

/////////////////////////////////////////////////////////////////////////////
// function2 function
/////////////////////////////////////////////////////////////////////////////

void function2 ()
{
    cout << "\n========== GRAPH MATRIX ==========" << endl;

    g_int.print_matrix();
}

/////////////////////////////////////////////////////////////////////////////
// function3 function
/////////////////////////////////////////////////////////////////////////////

void function3 ()
{
    int start, goal;

    cout << "\n=== Robot Path Planning ===" << endl;

    cout << "Enter starting node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    vector<int> path = g_int.bfs_shortest_path(start, goal);

    cout << "Shortest Path: ";
    print_path(path);
}

/////////////////////////////////////////////////////////////////////////////
