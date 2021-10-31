#include <iostream>
using namespace std;

#include <CApp.h>

int main(int argc, char **argv){
    cout << "------ Entering DVD_Screensaver ------" << endl;

    CApp theApp(800, 600, "DVD Screensaver", (sf::Style::Titlebar|sf::Style::Close));

    cout << "------ Exiting  DVD_Screensaver ------" << endl;
    
    return EXIT_SUCCESS;
}