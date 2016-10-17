#include <string>
#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include <sys/ioctl.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

using namespace std;


class Led
{
private:
    bool mode;
    uint8_t pinNumber;
    
   
public:
    // Member functions declaration
    Led();
    bool getMode(void);
    void setMode( bool m );
    uint8_t getPinNumber( void );
    void setPinNumber( uint8_t p );
};

// Member functions definitions

Led::Led(void){
    cout << "Create an Led."
    wiringPiSetup();

    mode = false;
    pinNumber = 0;

}

bool Led::getMode(void)
{
    return mode;
}

void Led::setMode( bool m ){
    mode = m;
}

uint8_t Led::getPinNumber( void ){
    return pinNumber;
}

void Led::setPinNumber( uint8_t p ){
    pinNumber = p;
}

//###############################
int main (void){
	printf("Start main function.");
	
	Led led1;
	
    cout << "1.) Pin Number "<< led1.getPinNumber() << " is set to " << led1.getMode()<<"\n";

    led1.setMode(TRUE);
    led1.setPinNumber(10);

    cout << "2.) Pin Number "<< led1.getPinNumber() << " is set to " << led1.getMode()<<"\n";	

    return 0;
}