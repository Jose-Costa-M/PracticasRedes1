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


void funTipoIP(unsigned char *IP, unsigned char *tipoIP, unsigned char clase){
    //en base a la clase vamos a ver en que inidice iniciar a comparar
    unsigned char i, j, bits = 0;
    switch(clase){
        case 'A':
        //haremos el corrimiento de bits contando los 1 que haya
        for (i = 1; i < sizeof(IP)/sizeof(IP[0]); i++) {
           unsigned char currentByte = IP[i];
           for (int j = 0; j < 8; j++) {
            if (currentByte & 1)
                bits++;
            currentByte = currentByte >> 1;
        }
        }
        //Si hay 24 bits encendidos es una IP de broadcast
        if(bits == 24){
            tipoIP[0]='B';
            tipoIP[1]='r';
            tipoIP[2]='o';
            tipoIP[3]='a';
            tipoIP[4]='d';
            tipoIP[5]='c';
            tipoIP[6]='a';
            tipoIP[7]='s';
            tipoIP[8]='t';

        }else if(bits == 0){
            //si no hay bits encendidos es una IP de red
            tipoIP[0]='R';
            tipoIP[1]='e';
            tipoIP[2]='d';
            tipoIP[3]=' ';
            tipoIP[4]=' ';
            tipoIP[5]=' ';
            tipoIP[6]=' ';
            tipoIP[7]=' ';
            tipoIP[8]=' ';


           
        }else{
            //si no es ninguna de las anteriores es una IP de host
            tipoIP[0]='H';
            tipoIP[1]='o';
            tipoIP[2]='s';
            tipoIP[3]='t';
            tipoIP[4]=' ';
            tipoIP[5]=' ';
            tipoIP[6]=' ';
            tipoIP[7]=' ';
            tipoIP[8]=' ';

        }
            
            break;
        case 'B':
        //haremos el corrimiento de bits contando los 1 que haya
        for (i = 2; i < sizeof(IP)/sizeof(IP[0]); i++) {
           unsigned char currentByte = IP[i];
           for (int j = 0; j < 8; j++) {
            if (currentByte & 1)
                bits++;
            currentByte = currentByte >> 1;
        }
        }
        //Si hay 16 bits encendidos es una IP de broadcast
        if(bits == 16){
            tipoIP[0]='B';
            tipoIP[1]='r';
            tipoIP[2]='o';
            tipoIP[3]='a';
            tipoIP[4]='d';
            tipoIP[5]='c';
            tipoIP[6]='a';
            tipoIP[7]='s';
            tipoIP[8]='t';
         } else if(bits == 0){
            //si no hay bits encendidos es una IP de red
            tipoIP[0]='R';
            tipoIP[1]='e';
            tipoIP[2]='d';
            tipoIP[3]=' ';
            tipoIP[4]=' ';
            tipoIP[5]=' ';
            tipoIP[6]=' ';
            tipoIP[7]=' ';
            tipoIP[8]=' ';
         }else{
            //si no es ninguna de las anteriores es una IP de host
            tipoIP[0]='H';
            tipoIP[1]='o';
            tipoIP[2]='s';
            tipoIP[3]='t';
            tipoIP[4]=' ';
            tipoIP[5]=' ';
            tipoIP[6]=' ';
            tipoIP[7]=' ';
            tipoIP[8]=' ';
         }


            
            break;
        case 'C':
        //haremos el corrimiento de bits contando los 1 que haya
        for (i = 3; i < sizeof(IP)/sizeof(IP[0]); i++) {
          unsigned char currentByte = IP[i];
           for (int j = 0; j < 8; j++) {
            if (currentByte & 1)
                bits++;
            currentByte = currentByte >> 1;
        }
        }
        //Si hay 8 bits encendidos es una IP de broadcast
        if(bits == 8){
            tipoIP[0]='B';
            tipoIP[1]='r';
            tipoIP[2]='o';
            tipoIP[3]='a';
            tipoIP[4]='d';
            tipoIP[5]='c';
            tipoIP[6]='a';
            tipoIP[7]='s';
            tipoIP[8]='t';
        }else if(bits == 0){
            //si no hay bits encendidos es una IP de red
            tipoIP[0]='R';
            tipoIP[1]='e';
            tipoIP[2]='d';
            tipoIP[3]=' ';
            tipoIP[4]=' ';
            tipoIP[5]=' ';
            tipoIP[6]=' ';
            tipoIP[7]=' ';
            tipoIP[8]=' ';
        }else{
            //si no es ninguna de las anteriores es una IP de host
            tipoIP[0]='H';
            tipoIP[1]='o';
            tipoIP[2]='s';
            tipoIP[3]='t';
            tipoIP[4]=' ';
            tipoIP[5]=' ';
            tipoIP[6]=' ';
            tipoIP[7]=' ';
            tipoIP[8]=' ';
        }
            
        break;        
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

