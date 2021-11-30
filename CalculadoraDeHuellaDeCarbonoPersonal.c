#include <stdio.h>

int numeroPersonasHogar;

void MensajeDeBienvenida(){

    printf(" -------------------------------------------\n");
    printf("| CALCULADORA DE HUELLA DE CARBONO PERSONAL |\n");
    printf(" -------------------------------------------\n");

    // Mensaje

}

float EnergiaEnElHogar(){

    printf("\n ----------------------------\n");
    printf("| Eje 1: Energia en el hogar |\n");
    printf(" ----------------------------\n");

    float emision = 0;
    float dato_de_entrada;

    printf("\n1. ¿Cuanto es el consumo en su hogar (en kWh) de electricidad al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.4195 * 12);

    printf("\n2. ¿Cuanto es el consumo en su hogar (en metros cúbicos) de gas natural al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 2.097 * 12);

    printf("\n3. ¿Cuanto es el consumo en su hogar (en kilogramos) de gas licuado al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 2.957 * 12);

    emision = emision / numeroPersonasHogar;

    return emision;

}

float EnergiaEnElTransporte(){

    printf("\n ---------------------------------\n");
    printf("| Eje 2: Energia en el transporte |\n");
    printf(" ---------------------------------\n");

    float emision = 0;
    float dato_de_entrada;

    printf("\n1. ¿Cuantos kilometros recorre en auto al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.18568 * 12);

    printf("\n2. Si viaja en avión ¿Cuantos kilometros recorre al año?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.285);

    return emision;

}

float HabitosDeConsumo(){

    printf("\n ---------------------------\n");
    printf("| Eje 3: Habitos de consumo |\n");
    printf(" ---------------------------\n");

    float emision = 0;
    float dato_de_entrada;

    printf("\n1. ¿Cuantos kilogramos de carne de vacuno consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 26.5 * 52);

    printf("\n2. ¿Cuantos kilogramos de carne de cerdo consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 1.5 * 52);

    printf("\n3. ¿Cuantos kilogramos de carne de ave consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.6 * 52);

    printf("\n4. ¿Cuantos litros de leche consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.874 * 52);

    printf("\n5. ¿Cuantos huevos consume a la semana?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.04 * 52);

    printf("\n6. ¿Cual es el consumo en su hogar (en metros cúbicos) de agua al mes?\n");
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.708 * 12 / numeroPersonasHogar);

    return emision;

}


int main(){

    // Inicialización de variables
    float emisionTotalAnual;
    float emisionHogar;
    float emisionTransporte;
    float emisionHabitos;
    

    MensajeDeBienvenida();


    emisionTotalAnual = 0;

    printf("\n¿Cuantas personas viven en su hogar?\n");
    scanf("%d", &numeroPersonasHogar);

    emisionHogar = EnergiaEnElHogar();
    emisionTransporte = EnergiaEnElTransporte();
    emisionHabitos = HabitosDeConsumo();

    emisionTotalAnual = emisionHogar + emisionTransporte + emisionHabitos;
    
    printf("\nEmisiones en el eje \"Energia en el hogar\": %f (kgCO2eq)\n", emisionHogar);
    printf("\nEmisiones en el eje \"Energia en el transporte\": %f (kgCO2eq)\n", emisionTransporte);
    printf("\nEmisiones en el eje \"Habitos de consumo\": %f (kgCO2eq)\n", emisionHabitos);
    printf("\nEmisiones en Total: %f (kgCO2eq)\n", emisionTotalAnual);

    if(emisionTotalAnual < 5000){
        
    }else{

        // Recomendaciones para disminuir las emisiones
    }



    return 0;
}
