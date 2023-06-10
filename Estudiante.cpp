//
// Created by crism on 9/05/2023.
//

#include "Estudiante.h"

Estudiante::Estudiante(): marcaTiempo(0) {}
Estudiante::Estudiante(int tiempo): marcaTiempo(tiempo) {}

int Estudiante::obtenerMarca()const {
    return marcaTiempo;
}

int Estudiante::tiempoEspera(int tiempoActual)const {
    return  tiempoActual- marcaTiempo;
}


