#include<stdio.h>

void funcClass(unsigned char IP[4], unsigned char *clase);
void funTipoIP(unsigned char *IP, unsigned char *tipoIP, unsigned char clase);
void funRed(unsigned char IP[4], unsigned char MR[4], unsigned char IPred[4]);
void funcBroadcast(unsigned char IP[4], unsigned char MR[4], unsigned char IPbroad[4]);
void funRango(unsigned char IPred[4], unsigned char IPbroad[4], unsigned char inferior[4], unsigned char superior[4]);
void funElection(unsigned char bits,unsigned char *tipoIP);
