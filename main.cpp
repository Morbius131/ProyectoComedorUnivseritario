#include "List.cpp"
#include "Cola.cpp"
#include "Comedor.h"
#include "Estudiante.h"
#include <random>
#include <list>


bool nuevoEstudiante(){
    float promedioEstudiante = 344.6;
    float S = round(1/(promedioEstudiante/3600));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, S);
    int numero = dis(gen);

    return numero == S;
}

list<double> simulacion(int numeroSegundos, float tasaServicio){

    Comedor comedorUniversitario(tasaServicio);
    Cola<Estudiante> colaComedor;
    List<int> tiempoEspera;
    Estudiante estudiante, estudianteSiguiente;
    int esperaPromedio = 0;
    list<double> resultados;

    for(int segundoActual=0 ; segundoActual<numeroSegundos;segundoActual++){

        if(nuevoEstudiante()){
            estudiante = Estudiante(segundoActual);
            colaComedor.push(estudiante);
        }

        if(!comedorUniversitario.ocupada() && (colaComedor.size()>0)){
            estudianteSiguiente = colaComedor.front();
            colaComedor.pop();
            tiempoEspera.insert(tiempoEspera.size(),estudianteSiguiente.tiempoEspera(segundoActual));
            comedorUniversitario.iniciarNueva(&estudianteSiguiente);
        }

        comedorUniversitario.tictac();

    }

    for(int i=0 ; i< tiempoEspera.size();i++){
        esperaPromedio = esperaPromedio + tiempoEspera.get(i);
    }

    cout << "Tiempo de espera promedio " << 1.0* esperaPromedio/tiempoEspera.size() << " segundos, estudiantes restantes " << colaComedor.size() << endl;

    resultados.push_back(1.0* esperaPromedio/tiempoEspera.size());
    resultados.push_back(colaComedor.size());

    return resultados;

}

int main() {

    double tiempoEsperaPromedio=0, estudiantesRestantesPromedio = 0;

    list<double> resultados;

    for(int i=0 ; i<100; i++){
        resultados = simulacion(3600,51);
        tiempoEsperaPromedio += resultados.front();
        estudiantesRestantesPromedio += resultados.back();
    }

    cout << "Tiempo de espera promedio: " << tiempoEsperaPromedio/100 << endl;
    cout << "Estudiantes restantes promedio: " << round(estudiantesRestantesPromedio/100);

    return 0;
}
