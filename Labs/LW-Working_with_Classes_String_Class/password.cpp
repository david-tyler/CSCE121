#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {

    string password;
    
    cout << "Please enter your text input: ";
    cin >> password;
    cout << "input: " << password << endl;

    for(int i = 0; i < static_cast<int>(password.length()); i++)
    {
        if(password.at(i) == 'a')
        {
            password.replace(i, 1,"@");
        }
        else if(password.at(i) == 'e')
        {
            password.replace(i, 1,"3");
        }
        else if(password.at(i) == 'i')
        {
            password.replace(i, 1,"!");
        }
        else if(password.at(i) == 'o')
        {
            password.replace(i, 1,"0");
        }
        else if(password.at(i) == 'u')
        {
            password.replace(i, 1,"^");
        }
    }
    for(int i = password.length()-1; i >= 0; i--)
    {
        password.append(password.substr(i,1));
    }

    cout << "output: " << password;

    return 0;
}
