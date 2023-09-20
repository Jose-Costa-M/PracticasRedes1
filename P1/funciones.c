#include "header.h"

void funcClass(unsigned char IP[4], unsigned char *clase){
     if (IP[0] & 128) {
        if (IP[0] & 64) {
            if (IP[0] & 32) {
                if (IP[0] & 16) {
                    // Es clase E
                    *clase = 'E';
                } else {
                    // Es clase D
                    *clase = 'D';
                }
            } else {
                // Es clase C
                *clase = 'C';
            }
        } else {
            // Es clase B
            *clase = 'B';
        }
    } else {
        // Es clase A
        *clase = 'A';
    }
}

void funRed(unsigned char IP[4], unsigned char MR[4], unsigned char IPred[4]){
    
    for (unsigned char i = 0; i < 4; i++) {
        IPred[i] = IP[i] & MR[i];
    }

}

void funcBroadcast(unsigned char IP[4], unsigned char MR[4], unsigned char IPbroad[4]){
   
     for (unsigned char i = 0; i < 4; i++) {
        IPbroad[i] = IP[i] | (~MR[i] & 0xFF);
    }

}


void funRango(unsigned char IPred[4], unsigned char IPbroad[4], unsigned char inferior[4], unsigned char superior[4]){
    inferior[0] = IPred[0];
    inferior[1] = IPred[1];
    inferior[2] = IPred[2];
    inferior[3] = IPred[3] + 1;

    superior[0] = IPbroad[0];
    superior[1] = IPbroad[1];
    superior[2] = IPbroad[2];
    superior[3] = IPbroad[3] - 1;
}

