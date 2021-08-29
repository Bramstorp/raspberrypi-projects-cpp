//Mathias Bramstorp - 24:08:2021 

#include <SenseHat.h>
#include <iostream>


int main(){

    // Sensehat variables
    SenseHat carte;

    // sensor variables
    float pressure;
    int angle;

    // sensehat init
    carte.Effacer();

    // read data from pressure sensor and outputs value
    while(1){
	    carte << setrotation(angle) << "Pressure is: " << carte.ObtenirPression() << "'" << flush;
    }
}