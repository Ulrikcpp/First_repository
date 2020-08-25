#include <stdio.h>
#include <stdlib.h>



int main(){
    int AnoRegular[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int AnoBisiesto[] = {0,3,4,0,2,5,0,3,6,1,4,6};
    int dia, mes, ano, diaR, mesR;
    int Bisiesto = 0, valido = 0;

    //Pide los datos 1 x 1
    int r1, r2, r3, r4, r5;
    printf("Introduce el día: ");
    scanf("%d", &dia);
    printf("Introduce el mes: ");
    scanf("%d", &mes);
    printf("Introduce el year: ");
    scanf("%d", &ano);

    //Checamos si el year es bisiesto o not bisiesto
    if((ano % 4 == 0) && !(ano % 100 == 0)){
        mesR = AnoBisiesto[mes-1];
        Bisiesto = 0;
    }else if(ano % 400 == 0){
        mesR = AnoBisiesto[mes-1];
        Bisiesto = 0;
    }else{
        mesR = AnoRegular[mes-1];
    }

    //Verificar si el dia es valido
    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia < 32){
        valido = 1;
    }else if(mes == 2){
        if(Bisiesto = 1 && dia < 30){
            valido = 1;
        }else if(dia < 29){
            valido = 1;
        }
    }else if(dia < 31){
        valido = 1;
    }

    if(dia < 32)
        //Aplicamos formula rara
        //Partimos en partes
        r1 = (ano-1) % 7;
        r2 = (ano-1) / 4;
        r3 = (3*((ano-1) / 100) + 1) / 4;
        r4 = (r2 - r3) % 7;
        r5 = dia % 7;
        diaR = (r1 + r4 + mesR +r5) % 7;

    //Con switch muestro el dia porque serian muches elses si no
    if(valido = 1){
        switch(diaR){
            case 0:
                printf("Domingo\n");
                break;
        
            case 1:
                printf("Lunes\n");
                break;
        
            case 2:
                printf("Martes\n");
                break;
        
            case 3:
                printf("Miercoles\n");
                break;
        
            case 4:
                printf("Jueves\n");
                break;
        
            case 5:
                printf("Viernes\n");
                break;
        
            case 6:
                printf("Sabado\n");
                break;
        }
    }

    return 0;
}