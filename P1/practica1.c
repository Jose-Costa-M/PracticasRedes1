#include "header.h"
unsigned char main(){
//declaramos la IP y la MR para almacenar
unsigned char IP[4] ={150,10,255,255}, MR[4] ={255,255,0,0};
//declaramos la variable de clase
unsigned char clase;
//declaramos la IP de red y de Broadcast
unsigned char IPred[4], IPbroad[4];
//declaramos la variable de tipo de IP broadcast
unsigned char tipoIP[9];
//decñaramos los rangos de host
unsigned char inferior[4], superior[4];



//determinamos la clase de la IP
funcClass(IP, &clase);

if(clase!='E' && clase!='D'){
 //Determinamos el tipo de IP acorde a la MR
funTipoIP(IP, tipoIP,clase);

// determinamos la IP RED
funRed(IP, MR, IPred);

// Determinamos la IP de Broadcast
funcBroadcast(IP, MR, IPbroad);

// Determinamos el rango de host (ip red +1 - ip broadcast -1)
funRango(IPred, IPbroad, inferior, superior);

}else{
    //si es clase E o D no tiene tipo de IP, guardamos IP en tipoIP
    tipoIP[0]='I';
    tipoIP[1]='P';
    tipoIP[2]=' ';
    tipoIP[3]=' ';
    tipoIP[4]=' ';
    tipoIP[5]=' ';
    tipoIP[6]=' ';
    tipoIP[7]=' ';
    tipoIP[8]=' ';

        
    //no tiene IP de red
    IPred[0]=0;
    IPred[1]=0;
    IPred[2]=0;
    IPred[3]=0;
    //no tiene IP de broadcast
    IPbroad[0]=0;
    IPbroad[1]=0;
    IPbroad[2]=0;
    IPbroad[3]=0;
    //no tiene rango de host
    inferior[0]=0;
    inferior[1]=0;
    inferior[2]=0;
    inferior[3]=0;
    
    superior[0]=0;
    superior[1]=0;
    superior[2]=0;
    superior[3]=0;

}

//imprimimos los datos IP, CLASE, TIPO BROADCAST , IP RED, RANGO HOST, BROADCAST
printf("IP: %d.%d.%d.%d\n", IP[0], IP[1], IP[2], IP[3]);
printf("Clase: %c\n", clase);
printf("Tipo: %s", tipoIP);
printf("IP de red: %d.%d.%d.%d\n", IPred[0], IPred[1], IPred[2], IPred[3]);
printf("Rango de host: %d.%d.%d.%d - %d.%d.%d.%d\n", inferior[0], inferior[1], inferior[2], inferior[3], superior[0], superior[1], superior[2], superior[3]);
printf("IP de broadcast: %d.%d.%d.%d\n", IPbroad[0], IPbroad[1], IPbroad[2], IPbroad[3]);



    return 0;
}
