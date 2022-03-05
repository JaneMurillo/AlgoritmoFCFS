
#ifndef _LOTE
#define _LOTE
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

class Procesamiento {

private:
  vector<float>num1;
  vector<float>num2;
  vector<int> process;
  vector<int>state;
  vector<int>processid;
  vector<int>timemax;
  vector<int>timeRestante;
  vector<int>timeTotal;
  vector<string>programador;
  vector<float>numpro;
  vector<int>numlote;//Numero del lote del proceso
  vector<int>pfinished;
  int currentLote;//Se�ala el lote que est� trabajando
  queue<int>nuevo;//Aquí se guardan
  queue<int>listo;//5 procesos traidos de "Nuevo"
  queue<int>bloqueado;//Interrumpidos
  queue<int>fila;//Es la que se recorre por cada lote
  queue<int>finalizados;//Se guarda el orden de los procesos finalizados
  queue<int>filaLote;//Es la que almacena los lotes

  vector<int>estado;//Interrupcion, pausa, error, continua
  vector<int>prioridad;
  int timeProgram;
  int temp;
  int loteres;
  int transcurrido;
  int restante;
  int oper;
  int tmax=0;
  int nprog;
  int nproces;
  int id;
  int contseg;
  int contmin;
  int contlotes;
  bool fin = true;
  bool pausado = true;
  char tecla;
  bool est;

public:
  Procesamiento();
  ~Procesamiento();
  void menu();//Menu especifico para esta actividad
  void interrupcion();//Asigna los numeros de la prioridad
  void procesos();//Asigna el n�mero de proceso a realizar
  void procesoActual();
  void configProcesos();//Configura todos los proceso que se multiprocesaran
  void cambioLoteRellenado();//Se cargan los nuevos datos del lote
  void estados();
  void tmeMulti(int num);
  void identificadorMulti(int num);
  void setNuevo(int num);
  void configOperador();
  void setlote();//Asigna lotes y agrega prioridad en los lotes
  void finalizado();
  void colaProcesos();
  void procesoFinalizado();
  void processcola(int i);
  void processejec(int i);
  void processfin(int i);
  void procesosListos(); // NUEVO
  void procesosBloqueados(); // NUEVO
   void procesoEjecucion(); // NUEVO
  void asignarListos(); // NUEVO
  void operacion();
  void imprimir();

  void funcionkbhit(char tecla);
  void errorkbhit();
};

#endif
