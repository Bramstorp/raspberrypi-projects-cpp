//Mathias Bramstorp - 24:08:2021 

#include <SenseHat.h>
#include <iostream>
#include <string>


using namespace std;

int main() {

    // sensehat variabl
    SenseHat carte;

    // string variable for text
    string message;

    // sensehat init
    carte.Effacer();

    // message to be show
    message = "Mathias";
    
    // write color for matrix + roation 
    carte << setcouleur(carte.ConvertirRGB565(84,84,0)) << setrotation(270);
    while(1){
    
    // write out message variable on 8x8 matrix
	carte << "'" << message << "'" << flush;
	sleep(1);
    }
    return 0;
}

