// Mathias 26:08:2021


#include <SenseHat.h>                  
#include <string>
#include <ncurses.h> 

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
    // sensehat libary
    SenseHat carte;

    /* ncurses start */
    initscr();
    noecho();
    cbreak();

    // get screen size 
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create window
    WINDOW * menuwin = newwin(8, xMax-12, yMax-8, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    // keypad for arrow keys
    keypad(menuwin, true);

    // all objects choices
    string choices[6] = {"Temp", "Humi", "Pressure", "Rainbow", "Clock", "exit"};

    // current choice
    int choice;

    // choice hightlighter for menu
    int highlight = 0;
    
    // angle and rotaion variable
    float x,y,z;
    int angle;

    // pixels for matrix variable
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

    // sensehat init
    carte.Effacer();

    while(1)
    {
        // write outs menu
        for(int i = 0; i < 6; i++)
        {
            if (i == highlight){
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i+1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }

        // gets current choice input
        choice = wgetch(menuwin);

        // close if key q
        if(choice == 'q') break;

        // switch for each choice
        switch(choice)
        {
            // key up in menu
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;

            // key down in menu
            case KEY_DOWN:
                highlight++;
                if(highlight == 6)
                    highlight = 5;
                break;
            case '\n':
                // check hightlight number and writes to matrix og read sensor data and write in terminal
                switch(highlight)
                {
                    case 0:
                        printw("Temp is: %s", carte.ObtenirTemperature());
                        break;
                    case 1:
                        printw("Humi is: %s", carte.ObtenirHumidite());
                        break;
                    case 2:
                        printw("Pressure is: %s", carte.ObtenirPression());
                        break;
                    case 3:
                        for(int i=0; i<8; i++)
                        {
                            for(int j=0; j<8; j++)
                            {
                                pixel = carte.ConvertirRGB565(image[i][j]);
                                carte.AllumerPixel(i,j,pixel);
                                CouleurSuivante(image[i][j]);
                            }
                        }
                        break;
                    case 4:
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
                    case 5:
                        endwin();
                        break;
                } 
            default:
                break;

        }
        if(choice == 10)
            break;
    }

    getch();
    endwin();
    /* ncurses end */

    return 0;
}
