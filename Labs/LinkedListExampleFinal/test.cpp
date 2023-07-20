#include <iostream>
#include <iomanip>
#include "LL.h"

using std::string, std::cout, std::endl;

int main() {
    LL ll;
    cout << "ll: ";
    ll.print();
    ll.insertTail('a');
    ll.print();
    ll.insertTail('b');
    ll.print();
    ll.insertTail('c');
    ll.print();
    string s = "Hello World";
    LL lla(s);
    cout << "lla: ";
    lla.print();
    cout << "o: " << std::boolalpha << lla.hasChar('o') << endl;
    cout << "z: " << std::boolalpha << lla.hasChar('z') << endl;
    lla.insertAfter('X','W');
    lla.print();
    lla.insertAfter('Y', 'H');
    lla.print();
    lla.insertAfter('Z','d');
    lla.print();
    lla.insertTail('k');
    lla.print();
    lla.deleteChar('X');
    lla.print();
    lla.deleteChar('H');
    lla.print();
    lla.deleteChar('k');
    lla.print();
    LL llc(lla);
    cout << "llc: ";
    llc.print();
    ll = llc;
    cout << "ll: ";
    ll.print();
    LL llb;
    llb.insertTail('g');
    cout << "llb: ";
    llb.print();
    llb.deleteChar('g');
    llb.print();
    ll.clear();
    ll.print();
    lla.clear();
    lla.print();


}