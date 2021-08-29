// Mathias 23:08:2021

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
  
  // string sentence variable with sentence
  std::string sentence = "Larsten er underviser på AARHUS TECH";

  // find and replace first letter L found in sentence and replace it with K
  std::replace( sentence.begin(), sentence.end(), 'L', 'K');

  // prints out sentence
  cout << "Sentence is: "<< sentence <<endl;
}