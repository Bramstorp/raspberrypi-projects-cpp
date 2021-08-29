//Mathias Bramstorp - 24:08:2021 

#include <SenseHat.h>
#include <iostream>


int main(){

    // Sensehat variables
    SenseHat carte; 

    // Sensor variables
    float humi;    
    int angle;      

    // sesnsehat init
    carte.Effacer();

    // read data from humidity sensor and outputs value
    while(1){
	    carte << setrotation(angle) << "Temp is: " << carte.ObtenirHumidite() << "'" << flush;
    }
}