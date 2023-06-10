//
// Created by crism on 9/05/2023.
//

#ifndef COMEDOR_UNIVERSIARIO_COMEDOR_H
#define COMEDOR_UNIVERSIARIO_COMEDOR_H

#include "Estudiante.h"

class Comedor {
     int tasaServicio;
     Estudiante* estudianteActual;
     int tiempoRestante = 0;

    public:
    Comedor();
    explicit Comedor(int servicio);
    void tictac();
    bool ocupada();
    void iniciarNueva(Estudiante* nuevoEstudiante);


};


#endif //COMEDOR_UNIVERSIARIO_COMEDOR_H
