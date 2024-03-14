//Este é um código para calibração da celula de carga

//Incluir biblioteca do modulo conversor
#include "HX711.h"

//Conexoes fisicas com a placa
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

//Variavel
HX711 escala;

//Definimos o valor de serial de cada conexao com placa
void setup (){
    Serial.begin(9600);
    escala.begin(LOADCELL_SCK_PIN, LOADCELL_DOUT_PIN);
}

void loop(){
    
}