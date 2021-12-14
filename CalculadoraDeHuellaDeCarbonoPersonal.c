#include <stdio.h>

// LINEA DE COMANDO: gcc CalculadoraDeHuellaDeCarbonoPersonal.c -o main

// Número de personas del hogar del usuario.
int numeroPersonasHogar;

// Mensaje de Bienvenida y explicación breve del programa.
void MensajeDeBienvenida(){

    printf("\n************************************************************************************************************************************************************************************************************\n");
    
    printf("                                                                     -------------------------------------------\n");
    printf("                                                                    | CALCULADORA DE HUELLA DE CARBONO PERSONAL |\n");
    printf("                                                                     -------------------------------------------\n");

    // Mensaje
    printf("\nBienvenid@ al programa de Calculadora de Huella de Carbono Personal.\n");
    printf("Con esta calculadora podras saber si tus emisiones familiares/hogare%cas de CO2 se ajustan al promedio nacional o lo sobrepasan. Ten en cuenta que necesitaras los siguientes datos:\n",164);
    printf("Consumo de electricidad, consumo de gas (natural/licuado), uso del auto, uso de aviones y habitos de consumo alimenticio como: KG de carnes rojas y blancas, consumo de huevos y leche. Todo esto para calcular tu huella de carbono. \n");
    
    printf("\n************************************************************************************************************************************************************************************************************\n");
}

// Eje 1: Energía en el hogar.
float EnergiaEnElHogar(){
    printf("\n************************************************************************************************************************************************************************************************************\n");
    printf("\n ----------------------------\n");
    printf("| Eje 1: Energia en el hogar |\n");
    printf(" ----------------------------\n");

    float emision = 0;
    float dato_de_entrada;

    printf("\n1. %cCuanto es el consumo en su hogar (en kWh) de electricidad al mes?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.4195 * 12);

    printf("\n2. %cCuanto es el consumo en su hogar (en metros cubicos) de gas natural al mes?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 2.097 * 12);

    printf("\n3. %cCuanto es el consumo en su hogar (en kilogramos) de gas licuado al mes?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 2.957 * 12);

    emision = emision / numeroPersonasHogar;

    return emision;

}

// Eje 2: Energía en el transporte.
float EnergiaEnElTransporte(){
    printf("\n************************************************************************************************************************************************************************************************************\n");
    printf("\n ---------------------------------\n");
    printf("| Eje 2: Energia en el transporte |\n");
    printf(" ---------------------------------\n");

    float emision = 0;
    float dato_de_entrada;

    printf("\n1. %cCuantos kilometros recorre en auto al mes?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.18568 * 12);

    printf("\n2. Si viaja en avion %cCuantos kilometros recorre al a%co?\n",168,164);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.285);

    return emision;

}

// Eje 3: Hábitos de consumo.
float HabitosDeConsumo(){
    printf("\n************************************************************************************************************************************************************************************************************\n");
    printf("\n ---------------------------\n");
    printf("| Eje 3: Habitos de consumo |\n");
    printf(" ---------------------------\n");

    float emision = 0;
    float dato_de_entrada;

    printf("\n1. %cCuantos kilogramos de carne de vacuno consume a la semana?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 26.5 * 52);

    printf("\n2. %cCuantos kilogramos de carne de cerdo consume a la semana?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 1.5 * 52);

    printf("\n3. %cCuantos kilogramos de carne de ave consume a la semana?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.6 * 52);

    printf("\n4. %cCuantos litros de leche consume a la semana?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.874 * 52);

    printf("\n5. %cCuantos huevos consume a la semana?\n",168);
    scanf("%f", &dato_de_entrada);
    emision += (dato_de_entrada * 0.04 * 52);

    printf("\n6. %cCual es el consumo en su hogar (en metros cubicos) de agua al mes?\n",168);
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
    printf("\n%cCuantas personas viven en su hogar?\n",168);
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
    printf("\n************************************************************************************************************************************************************************************************************\n");
    printf("\n ------------------------------------\n");
    printf("| Emisiones anuales totales por eje: |");
    printf("\n ------------------------------------\n");

    // Se imprime el resultado.
    printf("\nEmisiones en el eje \"Energia en el hogar\": %f (kgCO2eq)\n", emisionHogar);
    printf("\nEmisiones en el eje \"Energia en el transporte\": %f (kgCO2eq)\n", emisionTransporte);
    printf("\nEmisiones en el eje \"Habitos de consumo\": %f (kgCO2eq)\n", emisionHabitos);
    printf("\nEmisiones en Total: %f (kgCO2eq)\n", emisionTotalAnual);
    printf("\n************************************************************************************************************************************************************************************************************\n");
    /* Si las emisiones totales no superan el promedio nacional, se le motiva al usuario a que se mantenga
       en los niveles. Por el contrario, si supera el promedio nacional, se le recomienda una serie de
       actividades que el usuario puede realizar para contribuir a la disminución de emisiones. */
    if(emisionTotalAnual < 4600){
        printf("\nFELICITACIONES !\n");
        printf("Sus niveles de emisiones de CO2 estan bajo el promedio nacional.\n");
        printf("Mantenga sus niveles de emision.\n");
    }else{
        printf("\n ----------------------------------------------------------------\n");
        printf("|                       MALAS NOTICIAS !                          |\n");
        printf("| Sus niveles de emisiones de CO2 sobrepasan el promedio nacional |\n");
        printf("| Es por eso que le entregamos las siguientes recomendaciones:    |\n");
        printf(" ----------------------------------------------------------------\n");
        printf("\n************************************************************************************************************************************************************************************************************\n");
        printf("\n1. Utilice medios de transporte menos contaminantes que un auto particular, como por ejemplo el uso de transporte publico, o medios de transporte de emision 0, como la bicicleta, 1 o 2 veces a la semana.\n");
        printf("\n2. Reemplace las carnes por alimentos vegetales. La OMS recomienda entre 200-500 gramos SEMANALES de consumo de carnes, no es algo escencial de la dieta humana\n");
        printf("\n3. Reduzca su uso de agua potable. Hay localidades de Chile que viven con 100 Litros de agua diarios, reducir nuestro consumo en duchas, lavado de manos, riego, etc. es nuestra obligacion \n   no solo por la huella de carbono, si no por la sequia y la necesidad de adaptarse a nuevos tiempos.\n");
        printf("\n4. Si no esta utilizando los artefactos electricos, desconectelos de la corriente. Si bien, el gasto energetico cuando no estan en uso es minimo, aun asi existe un gasto que no se esta aprovechando, y suma\n   a los kW de fin de mes, y finalmente a la huella de carbono personal.\n");
        printf("\n5. Planta flora nativa. Idealmente arboles, ya que al ser nativos su consumo de agua esta adaptado para el ambiente en el que viviran, y te ayudaran, a largo plazo, a reducir el CO2 del ambiente.\n");
        printf("\n6. Recuerda las 3 R: Reduce, Reutiliza y Recicla. Informate de los puntos de reciclaje cercanos a tu hogar, y comienza a separar tu basura. Es un acto minimo, pero a largo plazo el impacto sera significativo\n    (y de paso, te daras cuenta lo impresionante de la cantidad de basura que desechas y estara degradandose y contaminando el suelo por incluso mas tiempo que el que viviras tu).\n");
        printf("\n***************************************************************************************************************************************************************************************************************\n");
    }



    return 0;
}
