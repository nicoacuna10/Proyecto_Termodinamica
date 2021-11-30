#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int numeroPersonasHogar;

void MensajeDeBienvenida(){

    // Mensaje

}

float EnergiaEnElHogar(){

    float emision = 0;
    float dato_de_entrada;

    printf("1. ¿Cuanto es el consumo en su hogar (en kWh) de electricidad al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.4195 * 12);

    printf("2. ¿Cuanto es el consumo en su hogar (en metros cúbicos) de gas natural al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 2.097 * 12);

    printf("3. ¿Cuanto el consumo en su hogar (en kilogramos) de gas licuado al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 2.957 * 12);

    emision = emision / numeroPersonasHogar;

    return emision;

}

float EnergiaEnElTransporte(){

    float emision = 0;
    float dato_de_entrada;

    printf("1. ¿Cuantos kiometros recorre en auto al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.18568 * 12);

    printf("2. Si viaja en avión ¿Cuantos kilometros recorre al año?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.285);

    return emision;

}

float HabitosDeConsumo(){

    float emision = 0;
    float dato_de_entrada;

    printf("1. ¿Cuantos kilogramos de carne de vacuno consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 26.5 * 52);

    printf("2. ¿Cuantos kilogramos de carne de cerdo consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 1.5 * 52);

    printf("3. ¿Cuantos kilogramos de carne de ave consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.6 * 52);

    printf("4. ¿Cuantos litros de leche consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.874 * 52);

    printf("5. ¿Cuantos huevos consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.04 * 52);

    printf("6. ¿Cual es el consumo en su hogar (en metros cúbicos) de agua al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.708 * 12);

    return emision;

}


int main(){

    // Inicialización de variables
    float emisionTotalAnual;
    float emisionHogar;
    float emisionTransporte;
    float emisionHabitos;
    
    char opcion[10];
    bool permanecer_en_calculadora = true;

    MensajeDeBienvenida();

    while(permanecer_en_calculadora){

        emisionTotalAnual = 0;

        printf("\n¿Cuantas personas viven en su hogar?\n");
        scanf("%d", &numeroPersonasHogar);

        emisionHogar = EnergiaEnElHogar();
        emisionTransporte = EnergiaEnElTransporte();
        emisionHabitos = HabitosDeConsumo();

        emisionTotalAnual = emisionHogar + emisionTransporte + emisionHabitos;
        
        printf("%f\n", emisionHogar);
        printf("%f\n", emisionTransporte);
        printf("%f\n", emisionHogar);
        printf("%f\n", emisionTotalAnual);

        if(emisionTotalAnual < 5000){
            
        }else{

            // Recomendaciones para disminuir las emisiones
        }

        printf("Desea reiniciar la calculadora?\n");
        printf("Escriba SI para reiniciar o NO para salir de la calculadora\n");
        scanf("%s", opcion);

        for(int i = 0; opcion[i]; i++){
            opcion[i] = toupper(opcion[i]);
        }

        if(opcion[0] == 'N' && opcion[1] == 'O'){
            permanecer_en_calculadora = false;
        }

    }

    return 0;
}