# include <iostream>
# include <string>
 
// Can struct
struct Can {
    std::string food = "";
    std::string brand = "";
};
 
// outputs can foods
void outputFoods(Can**& cans, unsigned int& shelves) {
    std::cout << "Shelf:\n";
 
    for (unsigned int shelf = 0; shelf < shelves; shelf++) {
        for (unsigned int can = 0; can < 8; can++) {
            std::cout << cans[shelf][can].food<< " ";
        }
        std::cout << '\n';
    }
 
    std::cout << '\n';
}
 
// adds shelf
void addShelf(Can**& cans, unsigned int& shelves) {
    // TODO: add shelf for 8 cans
    unsigned new_capacity = shelves + 1;
    Can** newCans = new Can*[new_capacity];//new matrix of cans with increased capacity of shelves
    for (unsigned int shelf = 0; shelf < new_capacity; shelf++) {
            newCans[shelf] = new Can[8];
    }
    for(unsigned int shelf = 0; shelf < shelves; shelf++)//copying the old shelves into the new
    {
        for (unsigned int can = 0; can < 8; can++) {
            
            newCans[shelf][can].food = cans[shelf][can].food;
            newCans[shelf][can].brand = cans[shelf][can].brand;
        }
    }
    for(unsigned int shelf = new_capacity-1; shelf < new_capacity; shelf++)//making the new shelf full of empty strings
    {
        for (unsigned int can = 0; can < 8; can++) {
            
            newCans[shelf][can].food = "";
            newCans[shelf][can].brand = "";
        }
    }
    for (unsigned int shelf = 0; shelf < shelves; shelf++) {//deallocate memory
        delete[] cans[shelf];
    }
    delete[] cans;
    cans = newCans;
    newCans = nullptr;
    shelves = new_capacity;
    
 
}
 
// adds Can
void addCan(Can**& cans, unsigned int& shelves, std::string _Food, std::string _Brand) {
    // TODO: add can to shelf
    
    
    //addShelf(cans, shelves);
    if(shelves == 0) //if shelves 0 add a shelf and update it with empty strings
    {
        shelves++;
        cans = new Can*[shelves];
        for (unsigned int shelf = 0; shelf < shelves; shelf++) {
            cans[shelf] = new Can[8];
        }
        for (unsigned int shelf = 0; shelf < shelves; shelf++) {
            for (unsigned int can = 0; can < 8; can++) {
                cans[shelf][can].food = "";
                cans[shelf][can].brand = "";
            }
        }
    }
    bool canAdded = false;//boolean to check if a shelf is full. If the shelf is full call addShelf
    for (unsigned int shelf = 0; shelf < shelves; shelf++) {
        for (unsigned int can = 0; can < 8; can++) {
            if(cans[shelf][can].food == "")//if place is empty then set it to the added can
            {
                cans[shelf][can].food = _Food;
                cans[shelf][can].brand = _Brand;
                canAdded = true;//shelf is not empty
                break;
            }
        }
    }
    if(canAdded == false)//a shelf was empty so add a shelf
    {
        addShelf(cans, shelves);
        addCan(cans, shelves, _Food, _Brand);
    }
 
}
 
int main() {
    std::string Food;
    std::string Brand;
 
    Can** cans = nullptr;
    unsigned int shelves = 0;
 
    while (true) {
        std::cout << "Enter name of can (q to exit): ";
        std::cin >> Food;
 
        if (Food == "q") {
            break;
        }
 
        std::cout << "Enter the brand: ";
 
        Brand = "";
        std::cin >> Brand;
 
        addCan(cans, shelves, Food, Brand);
 
        outputFoods(cans, shelves);
    }
 
    // deallocate dynamic memory
    if (cans != nullptr) {
        for (unsigned int shelf = 0; shelf < shelves; shelf++) {
            delete[] cans[shelf];
        }
 
        delete[] cans;
    }
}
