#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <RF24/RF24.h>

using namespace std;

RF24 radio(22,0);

// Radio pipe addresses for the 2 nodes to communicate.
uint8_t pipes[][6] = {"1Node","2Node"};


int main(int argc, char** argv){

    uint8_t tank1pipes[][6] = {"1Node","2Node"};
    uint8_t tank2pipes[][6] = {"3Node","4Node"};
    
    if (argc > 1)
    {
        int tank;
        sscanf(argv[1],"%d", &tank);
        int num;
        sscanf(argv[2],"%d", &num);
        
        radio.begin();
        
        radio.setRetries(15,15);
        
        if(tank>0 && tank < 3){
            if(tank==1)
            {
                radio.openWritingPipe(tank1pipes[1]);
                radio.openReadingPipe(1,tank1pipes[0]);
            }
            if(tank==2)
            {
                radio.openWritingPipe(tank2pipes[1]);
                radio.openReadingPipe(1,tank2pipes[0]);
            }
            bool ok = radio.write( &num, sizeof(int) );
            if (!ok){
                printf("failed.\n");
            }
        }
        else
        {
            printf("Usage: senddata <tanknumber> <action number>\n");
        }
    }
    else
    {
        printf("Usage: senddata <tanknumber> <action number>\n");
    }
    
    return 0;
}