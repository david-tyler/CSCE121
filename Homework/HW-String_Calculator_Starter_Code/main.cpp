#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    // TODO(student): implement the UI
    bool running = true;
    
   
    while(running)
    {
        

        cout << ">> " << endl;
        string number1;
        string sign;
        string number2;
        cin >> number1;
        if(cin.eof())
        {
            running = false;
            break;
        }
        if(number1 == "q" || number1 == "quit")
        {
            running = false;
            break;
        }
        cin >> sign >> number2;


        if(sign == "+")
        {
            cout << "ans =" << endl <<  endl;
            cout << "    " << add(number1, number2) << endl <<  endl;
        }
        if(sign == "*")
        {
            cout << "ans =" << endl <<  endl;
            cout << "    " << multiply(number1, number2) << endl << endl;
        }
    }
    
    cout <<  "farvel!";

    return 0;

}

