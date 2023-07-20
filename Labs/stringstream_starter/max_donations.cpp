#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  
  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  
  // read data
  istringstream inSS;
  string line;
  int id;
  double donations;
  double total = 0;
  int count = 0;

  while(!ifs.eof())
  {
    inSS.clear();
    getline(ifs, line);
    inSS.str(line);
    inSS >> id;
    while(!inSS.eof())
    {
      inSS>>donations;
      total += donations;
      count++;
    }
    if(total > maxTotalDonation && count > 1)
    {
      maxTotalDonation = total;
      maxTotalCollector = id;
    }
    total = 0;
    count = 0;
  }
  if(maxTotalCollector ==0 && maxTotalDonation == 0)
  {
    cout << "No donations." << endl;
    return 0;
  }

  
  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
  return 0;
}
