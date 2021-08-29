// Mathias 23:08:2021

#include<iostream>
#include<string>
using namespace std;

int main()
{
        // postion variabl
        int pos;

        // sentence variable
        string sentence = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
        
        // string word need to be found in sentence
        string word = "ipsum";

        // forloops sentice and find word and what position the word is 
        for (int i=1;(pos=sentence.find(word)) != -1 ;i++)
        {
                sentence = sentence.substr(++pos);

                // prints out word find in sentence
                cout<<"Word is: "<< word <<endl;
        }


}
