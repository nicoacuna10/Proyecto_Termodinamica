#include <stdio.h>

// Número de personas del hogar del usuario.
int numeroPersonasHogar;

// Mensaje de Bienvenida y explicación breve del programa.
void MensajeDeBienvenida(){

    printf(" -------------------------------------------\n");
    printf("| CALCULADORA DE HUELLA DE CARBONO PERSONAL |\n");
    printf(" -------------------------------------------\n");

    // Mensaje

}

// Eje 1: Energía en el hogar.
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

// Eje 2: Energía en el transporte.
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

// Eje 3: Hábitos de consumo.
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

// Sección principal del programa.
int main(){

    // Emisiones de CO2 en total al año.
    float emisionTotalAnual;

    // Emisión total en el eje 1.
    float emisionHogar;

    // Emisión total en el eje 2.
    float emisionTransporte;

    // Emisión total en el eje 3.
    float emisionHabitos;

    MensajeDeBienvenida();

    // Se inicializa la emisión total en 0.
    emisionTotalAnual = 0;

    // Se pregunta al usuario cuántas personas componen su hogar.
    printf("\n¿Cuantas personas viven en su hogar?\n");
    scanf("%d", &numeroPersonasHogar);
    while(numeroPersonasHogar < 1){
        printf("\nPor favor, ingrese una cantidad valida...\n");
        scanf("%d", &numeroPersonasHogar);
    }

    emisionHogar = EnergiaEnElHogar();
    emisionTransporte = EnergiaEnElTransporte();
    emisionHabitos = HabitosDeConsumo();

    // Se suman las emisiones de los tres ejes.
    emisionTotalAnual = emisionHogar + emisionTransporte + emisionHabitos;
    
    printf("\nEmisiones en el eje \"Energia en el hogar\": %f (kgCO2eq)\n", emisionHogar);
    printf("\nEmisiones en el eje \"Energia en el transporte\": %f (kgCO2eq)\n", emisionTransporte);
    printf("\nEmisiones en el eje \"Habitos de consumo\": %f (kgCO2eq)\n", emisionHabitos);
    printf("\nEmisiones en Total: %f (kgCO2eq)\n", emisionTotalAnual);

    /* Si las emisiones totales no superan el promedio nacional, se le motiva al usuario a que se mantenga
       en los niveles. Por el contrario, si supera el promedio nacional, se le recomienda una serie de
       actividades que el usuario puede realizar para contribuir a la disminución de emisiones. */
    if(emisionTotalAnual < 4600){
        printf("\nFELICITACIONES !\n");
        printf("Sus niveles de emisiones de CO2 estan bajo el promedio nacional.\n");
        printf("Mantenga sus niveles de emision.\n");
    }else{
        printf("\nMALAS NOTICIAS !\n");
        printf("Sus niveles de emisiones de CO2 sobrepasan el promedio nacional.\n");
        printf("Es por eso que le entregamos las siguientes recomendaciones:\n");
        printf("1.\n");
        printf("2.\n");
        printf("3.\n");
        printf("4.\n");
        printf("5.\n");
    }



    return 0;
}