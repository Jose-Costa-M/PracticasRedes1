#include<stdio.h>

 unsigned char main(){

 printf("\tHola maestra Nidia :)\n\n");

 unsigned char x = 'R', y = 0x52, z = 82;

 // A) imprimir cada variable en caracter, decimal y hexadecimal
 printf("\tImprimir en decimal:\n");
 printf("x = %d\n",x);
 printf("y = %d\n",y);
 printf("z = %d\n",z);

 printf("\tImprimir en caracter:\n");
 printf("x = %c\n",x);
 printf("y = %c\n",y);
 printf("z = %c\n",z);


 printf("\tImprimir en Hexadecimal:\n");
 printf("x = 0x%x\n",x);
 printf("y = 0x%x\n",y);
 printf("z = 0x%x\n",z);


// A.1) Cuantos bits encendidos tiene tu nombre
unsigned char i, j, bits = 0;
unsigned char red[] ={'R', 'e', 'd', 'e','s'};

for (i = 0; i < sizeof(red)/sizeof(red[0]); i++) {
        for (j = 0; j < 8; j++) {
            if (red[i] & 1)
                bits++;
            red[i] = red[i] >> 1;
        }
    }

 printf ("\nRedes tiene %d bits encendidos\n\n", bits);

 unsigned char nombre[] ={'M', 'i', 'g', 'u','e','l'};
  bits = 0;

    for (i = 0; i < sizeof(nombre)/sizeof(nombre[0]); i++) {
        for (j = 0; j < 8; j++) {
            if (nombre[i] & 1)
                bits++;
            nombre[i] = nombre[i] >> 1;
        }
    }

    printf ("Mi nombre: ");
    for (i = 0; i < sizeof(nombre)/sizeof(nombre[0]); i++) {
        printf("%c",nombre[i]);
    }
    printf( "tiene %d bits encendidos\n\n", bits);


 // B) Indicar la clase de la dirección IP así como la mascara de red correspondiente
printf("\tIndicador de clase de IP\n");

    unsigned char IP[] = {15, 111, 111, 111};
    unsigned char MR[] = {255, 255, 255, 0};

    if (IP[0] & 128) {
        if (IP[0] & 64) {
            if (IP[0] & 32) {
                if (IP[0] & 16) {
                    // Es clase E
                    printf("\nLa IP %d.%d.%d.%d es clase E.\n", IP[0], IP[1], IP[2], IP[3]);
                    MR[4] = 255;
                    printf("La mascara de red es: %d.%d.%d.%d\n", MR[0], MR[1], MR[2], MR[3]);
                } else {
                    // Es clase D
                    printf("\nLa IP %d.%d.%d.%d es clase D.\n", IP[0], IP[1], IP[2], IP[3]);
                    MR[4] = 255;
                    printf("La mascara de red es: %d.%d.%d.%d\n", MR[0], MR[1], MR[2], MR[3]);

                }
            } else {
                // Es clase C
                printf("\nLa IP %d.%d.%d.%d es clase C.\n", IP[0], IP[1], IP[2], IP[3]);
                printf("La mascara de red es: %d.%d.%d.%d\n", MR[0], MR[1], MR[2], MR[3]);

            }
        } else {
            // Es clase B
            printf("\nLa IP %d.%d.%d.%d es clase B.\n", IP[0], IP[1], IP[2], IP[3]);
            MR[2] = 0;
        printf("La mascara de red es: %d.%d.%d.%d\n", MR[0], MR[1], MR[2], MR[3]);

        }
    } else {
        // Es clase A
        printf("\nLa IP %d.%d.%d.%d es clase A.\n", IP[0], IP[1], IP[2], IP[3]);
        MR[1] = 0;
        MR[2] = 0;
        //imprimimos la mascara de red
        printf("La mascara de red es: %d.%d.%d.%d\n", MR[0], MR[1], MR[2], MR[3]);
    }




  return 0;
}