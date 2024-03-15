//Este é um código para calibração da celula de carga

//Incluir biblioteca do modulo conversor
#include "HX711.h"

//Conexoes fisicas com a placa
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

//Variavel
HX711 escala;

//Definimos o valor de serial de cada conexao com placa e iniciamos a balanca
void setup (){
    Serial.begin(9600);
    escala.begin(LOADCELL_SCK_PIN, LOADCELL_DOUT_PIN);
}

void loop(){

    Serial.println("Configure a balança");
    Serial.print("Ler: \t\t");
    Serial.println(escala.read()); //Obtem uma leitura bruta do sensor da celula

    Serial.print("Ler média: \t\t");
    Serial.print(escala.read_average(20)); //Vai mostrar a media das ultimas 20 leituras da balanca
    
    Serial.print("Pegar valor: \t\t");
    Serial.print(escala.get_value(5)); //Vai mostrar a media das ultimas 5 leituras da balanca menos a carga

    Serial.print("Pegar unidade: \t\t");
    Serial.print(escala.get_units(5), 1); //Mostra a média das ultimas 5 leituras menos o peso da tara dividido pelo fator de calibração

    escala.set_scale(10.2); //Inserir o seu fator de calibração encontrado
    escala.tare();
}