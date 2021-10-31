# DVD Screensaver
This program was supposed to be a test, to see if everything worked in my current MinGW installation. And I had fun continuing it so here it is

## How to build it
You need to have SFML 2.5.1 installed. And then it's as simple as typing 
```bash
cmake . && make
```

## How to use it
It's a screensaver, but I've put in a few things :
- F2 : Toggles the frame counter visibility
- F1 : Toggles between frametime and framerate indicators

## Known bugs
Well I've coded it on Windows using the latest TDM GCC suite, in 64bits mode and when moving the window around it can offset the DVD logo and it gets stuck in a "wall"(the viewport border basically..)
But besides that, nothing alarming.