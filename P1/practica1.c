#include "header.h"
unsigned char main(){
//declaramos la IP y la MR para almacenar
unsigned char IP[4] ={150,1,2,3}, MR[4] ={255,255,0,0};
//declaramos la variable de clase
unsigned char clase;
//declaramos la IP de red y de Broadcast
unsigned char IPred[4], IPbroad[4];
//declaramos la variable de tipo de IP broadcast
unsigned char tipoIP[10]={'H','O','S','T'};
//decñaramos los rangos de host
unsigned char inferior[4], superior[4];



//determinamos la clase de la IP
funcClass(IP, &clase);

//Determinamos el tipo de IP acorde a la MR


// determinamos la IP RED
funRed(IP, MR, IPred);

// Determinamos la IP de Broadcast
funcBroadcast(IP, MR, IPbroad);

// Determinamos el rango de host (ip red +1 - ip broadcast -1)
funRango(IPred, IPbroad, inferior, superior);











//ya que tenemos todos los resultamos los tabulamos
printf("\n|------------------------------------------------------------------------------------------------------------------|");
printf("\n|          IP        |  CLASE  |  TIPO BROADCAST   |   IP RED   |          RANGO HOST       |       BROADCAST      |");
printf("\n|--------------------|---------------------------------------------------------------------------------------------|");
printf("\n|     %d.%d.%d.%d    |    %c    |        %s         |  %d.%d.%d.%d  |     %d.%d.%d.%d - %d.%d.%d.%d   |        %d.%d.%d.%d    |",IP[0],IP[1],IP[2],IP[3],clase,tipoIP,IPred[0],IPred[1],IPred[2],IPred[3],inferior[0],inferior[1],inferior[2],inferior[3],superior[0],superior[1],superior[2],superior[3],IPbroad[0],IPbroad[1],IPbroad[2],IPbroad[3] );
printf("\n|--------------------|---------------------------------------------------------------------------------------------|");



    return 0;
}