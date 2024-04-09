#include "Shapes.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    

    Shapes s;

    ifstream in("Text.txt");
    if (!in.is_open()) 
    {
        cout << "File not found!" << endl;
        return -1;
    }

    in >> s;

    in.close();

    Cylinder* c = new Cylinder(22, 3);

    ofstream out("Text1.txt", ios::app);
    if (!out.is_open()) {
        cout << "File not found!" << endl;
        return -1;
    }

    out << s << endl;
    s.add(0, c);
    out << s << endl;
    s.pop(1);
    out << s << endl;
    s.deleteAll();
    out << s << endl;

    out.close();

    return 0;
}
