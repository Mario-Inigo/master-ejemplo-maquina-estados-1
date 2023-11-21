#include "mbed.h"

enum estados {esperandoPulsar, pulsado, esperandoSoltar} estado;
 
Timer temporizador;
 
DigitalIn boton(ARDUINO_UNO_D2);
DigitalOut led(ARDUINO_UNO_D3);
 
void EsperandoPulsar()
{
    if(boton == 1) {
        temporizador.reset();
        led=1;
        estado=pulsado;
    }
}
 
void Pulsado()
{
    if(temporizador.read()>2.0f && boton == 0) {
        temporizador.reset();
        led=0;
        estado=esperandoPulsar;
     }
     else if(temporizador.read()>2.0f && boton == 1) {
        led=0;
        estado=esperandoSoltar;
     }
}
//lhjkdfrgkhd
void EsperandoSoltar()
{
    if (boton == 0){
        estado = esperandoPulsar;
    }
}
 
int main()
{
    led=0;
    estado=esperandoPulsar;
    temporizador.reset();
    temporizador.start();
    while(1) {
        switch(estado) {
            case esperandoPulsar:
                EsperandoPulsar();
                break;
            case pulsado:
                Pulsado();
                break;
            case esperandoSoltar:
                EsperandoSoltar();
                break;
        }
     }
}