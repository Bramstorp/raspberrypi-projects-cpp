// Mathias 23:08:2021

#include <iostream>
#include <string>
using namespace std;

int main()
{
  // for loop init 0-25
  for (int i = 1; i <= 25; i++) {

    // if int number found prints out word
    if (i % 3 & i % 5) {
      cout << "vaniljebudding" << endl;
    } else if (i % 3) {
      cout << "vanilje" << endl;
    } else if (i % 5) {
      cout << "budding" << endl;
    } else {
      cout << i << endl;
    }
  }
  return 0;
}

