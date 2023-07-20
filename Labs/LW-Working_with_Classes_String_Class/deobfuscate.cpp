#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {

    string obfuscated;
    string numbers;
    cout << "Please enter obfuscated sentence: ";
    cin >> obfuscated;
    cout << "Please enter deobfuscation details: ";
    cin >> numbers;

    int ascii[] = {48,49,50,51,52,53,54,55,56,57};
    int index=0;

    for(int i = 0; i < static_cast<int>(numbers.length()); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(numbers.at(i) == ascii[j])
            {
                index += j;
            }
        }
        
        obfuscated.insert(index, " ");
        index++;
    }
    cout << "Deobfuscated sentence: " << obfuscated;
    


    return 0;
}
