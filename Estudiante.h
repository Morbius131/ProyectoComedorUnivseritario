//
// Created by crism on 9/05/2023.
//

#ifndef COMEDOR_UNIVERSIARIO_ESTUDIANTE_H
#define COMEDOR_UNIVERSIARIO_ESTUDIANTE_H


class Estudiante {
     int marcaTiempo;

     public:

     Estudiante();
     explicit Estudiante(int tiempo);
     [[nodiscard]] int obtenerMarca()const;
     [[nodiscard]] int tiempoEspera(int tiempoActual)const;



};


#endif //COMEDOR_UNIVERSIARIO_ESTUDIANTE_H
