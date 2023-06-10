//
// Created by crism on 9/05/2023.
//

#include "Comedor.h"

Comedor::Comedor(): tasaServicio(0), estudianteActual(nullptr), tiempoRestante(0) {}
Comedor::Comedor(int servicio): tasaServicio(servicio), estudianteActual(nullptr), tiempoRestante(0) {}

void Comedor::tictac() {
    if(estudianteActual!= nullptr){
        tiempoRestante = tiempoRestante-1;
        if(tiempoRestante==0){
            estudianteActual = nullptr;
        }
    }
}

bool Comedor::ocupada() {

    if(estudianteActual!= nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Comedor::iniciarNueva(Estudiante *nuevoEstudiante) {
    estudianteActual = nuevoEstudiante;
    tiempoRestante = tasaServicio;
}
