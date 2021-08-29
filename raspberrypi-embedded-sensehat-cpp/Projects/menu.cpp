//Mathias Bramstorp - 24:08:2021 

#include <iostream>
#include <SenseHat.h>

using namespace std;


// next color void function
void CouleurSuivante( uint8_t pix[3]){
    uint8_t r = pix[0];
    uint8_t g = pix[1];
    uint8_t b = pix[2];

    if (r == 255 && g < 255 && b == 0)
        g += 1;

    if (g == 255 && r > 0 && b == 0)
        r -= 1;

    if (g == 255 && b < 255 && r == 0)
        b += 1;

    if (b == 255 && g > 0 && r == 0)
        g -= 1;

    if (b == 255 && r < 255 && g == 0)
        r += 1;

    if (r == 255 && b > 0 && g == 0)
        b -= 1;

    pix[0] = r;
    pix[1] = g;
    pix[2] = b;
}

// string function for hour structure 
string ObtenirHeure()
{
    time_t  t = time(nullptr);
    stringstream ss;
    ss  <<  put_time( localtime(&t), "  %H:%M" );
    return ss.str();
}

int main()
{
    // current choice
    int choice;

    // if menu is closed show and hide
    bool closed = true;

    // sense hat variable
    SenseHat carte;

    // variables for humidity, pressure, rotation, angle and pixels
    float humi;
    float pressure;
    float x,y,z;
    float ro,teta,delta;
    int angle;
    uint16_t pixel;

    // image object for 8x8 matrix for what color pixel for each row
    uint8_t image[8][8][3] = {
    	{{255,   0,   0}, {255,   0,   0}, {255,  87,   0}, {255, 196,   0}, {205, 255,   0}, { 95, 255,   0}, {  0, 255,  13}, {  0, 255, 122}},
    	{{255,   0,   0}, {255,  96,   0}, {255, 205,   0}, {196, 255,   0}, { 87, 255,   0}, {  0, 255,  22}, {  0, 255, 131}, {  0, 255, 240}},
    	{{255, 105,   0}, {255, 214,   0}, {187, 255,   0}, { 78, 255,   0}, {  0, 255,  30}, {  0, 255, 140}, {  0, 255, 248}, {  0, 152, 255}},
    	{{255, 223,   0}, {178, 255,   0}, { 70, 255,   0}, {  0, 255,  40}, {  0, 255, 148}, {  0, 253, 255}, {  0, 144, 255}, {  0,  34, 255}},
    	{{170, 255,   0}, { 61, 255,   0}, {  0, 255,  48}, {  0, 255, 157}, {  0, 243, 255}, {  0, 134, 255}, {  0,  26, 255}, { 83,   0, 255}},
    	{{ 52, 255,   0}, {  0, 255,  57}, {  0, 255, 166}, {  0, 235, 255}, {  0, 126, 255}, {  0,  17, 255}, { 92,   0, 255}, {201,   0, 255}},
    	{{  0, 255,  66}, {  0, 255, 174}, {  0, 226, 255}, {  0, 117, 255}, {  0,   8, 255}, {100,   0, 255}, {210,   0, 255}, {255,   0, 192}},
    	{{  0, 255, 183}, {  0, 217, 255}, {  0, 109, 255}, {  0,   0, 255}, {110,   0, 255}, {218,   0, 255}, {255,   0, 183}, {255,   0,  96}}
    };

    // sense hat init
    carte.Effacer();

    // check if closed true for menu
    while (closed != false) {
    // menu output options
    cout << "-------------------------------\n";
    cout << " 1 - Temp.\n";
    cout << " 2 - Humi.\n";
    cout << " 3 - Pressure.\n";
    cout << " 4 - Rainbow.\n";
    cout << " 5 - Clock.\n";
    cout << " 6 - Exit.\n";
    cout << " Enter what value u wanna see: ";

    // input for current choice
    cin >> choice;

    // checks choice made and outputs out from current choice
    switch (choice)
    {
        case 1:
        	carte << setrotation(angle) << "Temp is: " << carte.ObtenirTemperature() << "'" << flush;
            break;
        case 2:
    	    carte << setrotation(angle) << "Humi is: " << carte.ObtenirHumidite() << "'" << flush;
            break;
        case 3:
        	carte << setrotation(angle) << "Pressure is: " << carte.ObtenirPression() << "'" << flush;
            break;
        case 4:
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    pixel = carte.ConvertirRGB565(image[i][j]);
                    carte.AllumerPixel(i,j,pixel);
                    CouleurSuivante(image[i][j]);
                }
            }
	        usleep(100);    
            break;
        case 5:
            carte << setcouleur(carte.ConvertirRGB565(64,84,0));

            do{
                carte.ObtenirAcceleration(x,y,z);
                    if (x < -0.8)
                        angle = 270;
                    if (x > +0.8)
                        angle = 90;
                    if (y < -0.8)
                        angle = 180;
                if (y > 0.8)
                    angle = 0;

                carte << setrotation(angle) << ObtenirHeure() << endl;

                sleep(1);

            }while(z > -0.5);
            break;
        case 6:
            cout << "End of Program.\n";
            closed = false;
            break;
        default:
            cout << "Not a Valid Choice. \n";
            cout << "Choose again.\n";
            cin >> choice;
            break;
    }

}
    return 0;
}