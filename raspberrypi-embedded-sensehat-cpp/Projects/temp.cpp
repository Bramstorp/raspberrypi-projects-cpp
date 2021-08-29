//Mathias Bramstorp - 24:08:2021 

#include <SenseHat.h>
#include <iostream>
#include <string>


using namespace std;

int main() {

    // sensehat variable
    SenseHat carte;

    // sensor varibales
    float x,y,z;
    int angle;

    // sensehat init
    carte.Effacer();

    // write 8x8 colors to matrix board
    carte << setcouleur(carte.ConvertirRGB565(64,84,0));

    // acceleration sensor writer for angle
    while(1){
	carte.ObtenirAcceleration(x,y,z);
       	if (x < -0.8)
            angle = 270;
        if (x > +0.8)
            angle = 90;
        if (y < -0.8)
            angle = 180;
	if (y > 0.8)
	    angle = 0;

    // write angle rotation + read temp data from board and prints it out
	carte << setrotation(angle) << "Temp is: " << carte.ObtenirTemperature() << "'" << flush;
	sleep(1);
    }
    return 0;
}