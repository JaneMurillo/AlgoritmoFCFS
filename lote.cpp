#include "lote.h"

Procesamiento::Procesamiento() {

}

Procesamiento::~Procesamiento(){
  cout << "\n\n--------------------------------------------------------\n| Fin del Procesamiento por Lotes\t\t\t|\n--------------------------------------------------------" << endl;
}

// MENU PRINCIPAL
void Procesamiento::menu(){
  cout<<"Algoritmo First come, first served - FCFS\n\nBienvenido al programa, \nIngresa los siguientes datos: ";
  procesos();//Establece el numero de procesos
  configProcesos();//Asigna los valores de los procesos
  //setlote();//Identifica el lote de cada proceso
  //cambioLoteRellenado();//Agrega el lote 1 a la fila
  asignarListos();//Conexion entre Nuevos y Listos
  //setlote();
  imprimir();
}
void Procesamiento::procesos(){
  cout << "\n\nIntroduce la cantidad de procesos a realizar: ";
  cin>>nproces;
  timeProgram+=nproces;
}
void Procesamiento::estados(){
	state.push_back(0);
}
// CONFIG MULTI, CONFIG OPER MULTI Y TIME MULTI
void Procesamiento::configProcesos(){
  for(int i=0;i<nproces;i++){
    setNuevo(i);//Mete a cola de procesos nuevos
    setIdentificador(i);
    tmeMulti(i); // Tiempo entre 6 y 16
    estados();
    configOperador();// Es equivalente a configoper y operacion
  }
}
void Procesamiento::setNuevo(int num){// ID random
  nuevo.push(num+1);
}
void Procesamiento::setIdentificador(int num){// ID random
  processid.push_back(num+1);
}
void Procesamiento::tmeMulti(int num){ // Tiempo
  int time = 1 + (rand() % 16);
  timeProgram+=time;
  timemax.push_back(time);
  timeRestante.push_back(time);
  timeTotal.push_back(0);
}
void Procesamiento::configOperador(){ // Operacion
  float n1= 1 + (rand() % 100);
  float n2= 1 + (rand() % 99);
  num1.push_back(n1);
  num2.push_back(n2);
  int oper= 1 + (rand() % 5);
  process.push_back(oper);
  operacion();
}
void Procesamiento::operacion(){
    if(process.back() == 1){
      numpro.push_back(num1.back() + num2.back());
    }else if(process.back() == 2){
      numpro.push_back(num1.back() - num2.back());
    }else if(process.back() == 3){
      numpro.push_back(num1.back() * num2.back()) ;
    }else if(process.back() == 4){
      numpro.push_back(num1.back() / num2.back()) ;
    }else{
      int n1;
      int n2;
      n1 = num1.back();
      n2 = num2.back();
      numpro.push_back(fmod(n1,n2));
    }
}
/*
void Lote::setlote(){
  int l=1; // Lote
  int n=1; // Contador de 1 a 5 procesos
  for(int i=1; i <= nproces; i++){
    if(((i % 6==0)&&i<7)||(((i-1)%5==0)&&i>10)){
      l++;
      n=1;
      numlote.push_back(l);
      cout<<numlote.front();
    }
    else{
      numlote.push_back(l);
      n++;
    }
  }
  loteres=l;
  for(int i=1;i<=l;i++){
    filaLote.push(i);
  }
}*//*
void Lote::cambioLoteRellenado(){
	if(filaLote.size()!=0){
		  for(int o = 0; o < nproces; o++){
    		if (numlote[o] == filaLote.front()){
      			fila.push(o);
   			 }
 		 }
 		temp=fila.front();
	}else{
		finalizado();
	}
}*/

void Procesamiento::asignarListos(){
  cout<<nuevo.size();
  while((listo.size()<4)){
    cout<<"Paso de parametro";
    listo.push(nuevo.front());
    nuevo.pop();
    }
}
void Procesamiento::procesoActual(){
    if(timemax[temp]==timeRestante[temp]||timeRestante[temp]==0){
        temp=fila.front();
        restante=timemax[temp];
    }
        cout << "\n| Num. de lote actual: " << filaLote.front() << " \t\t\t\t|";
      cout <<"\n\n--------------------------------------------------------\n| Cola de procesos  \t\t\t\t\t|\n--------------------------------------------------------";
      cout << endl << "ID\t\tTME" << endl;
      for(int x = 1; x < fila.size(); x++){
		  	fila.pop();
            fila.push(fila.front());
            processcola(fila.front());
      }
      cout << "\n--------------------------------------------------------\n| Proceso en  Ejecucion  \t\t\t\t|\n--------------------------------------------------------" << endl;
      cout << "ID\t\tTME\t\tT. Transcurrido\t\tTiempo Restante\n";
      processejec(temp);
      cout << "\t00:00:";
      if(timeTotal[temp] <= 9)
        cout << "0";
      cout << timeTotal[temp] << "\t\t00:00:";
      timeTotal[temp]++;
      if(timeRestante[temp] <= 9)
        cout <<"0";
      cout << timeRestante[temp] << endl;

      timeRestante[temp]--;
	  if(timeRestante[temp] == 0){
	  	if(fila.empty()==true){
	  		filaLote.pop();
		  }else{
		  	fila.pop();
		  }
      }
}

void Procesamiento::imprimir(){
  int actual = 0;
  contseg = 0;
  contmin = 0;
  temp=listo.front()-1;

    system("cls");
    restante = timemax[actual];
   // temp=fila.front();
    for(int x = 1 ; x < timeProgram ; x++){
	  if(finalizados.size()==nproces){
	  	 finalizado();
         x=timeProgram;
	  }
	  procesosListos();
	  if(finalizados.size()==nproces){
         finalizado();
		 x=timeProgram;
	  }
	  else{
	  	    procesoEjecucion();
	        procesoFinalizado();
	  }
      sleep(1);
      system("cls");
      if(timeRestante[temp]==0){
        finalizados.push(temp);
      }

      if(kbhit() == true){ // Devuelve F o T; si kbhit es verdadero
        tecla = getch();
        funcionkbhit(tecla);
        }
        /*if(fila.size()==0){
        	if((filaLote.size()-1)==0){
        		x=timeProgram;
			}
		}*/
   }
    finalizado();
}
void Procesamiento::procesosListos(){
        cout << "\n| Num. de procesos restantes: " << nuevo.size() << " \t\t\t\t|" << endl;
      cout<<"\n\n-----------------------------------------\n| Procesos Listos  \t\t\t\t\t|\n-----------------------------------------";
      cout<<endl<<"ID\t\tTME"<<endl;

      for(int x = 1; x <= listo.size();x++){

        processcola(listo.front());

        listo.push(listo.front());
        listo.pop();  //ahcarai
        }
}
void Procesamiento::procesoEjecucion(){
  cout << "\n-----------------------------------------\n| Proceso en Ejecucion  \t\t\t\t|\n-----------------------------------------" << endl;
      cout << "ID\t\tTME\t\tT. Transcurrido\t\tTiempo Restante\n";
      processejec(temp);
      cout<<"00:00:";
      if(timeTotal[temp]<=9)
        cout <<"0";
      cout << timeTotal[temp]<<"\t\t\t00:00:";
      timeTotal[temp]++;
      if(timeRestante[temp]<=9)
        cout <<"0";
      cout << timeRestante[temp] << endl;
      timeRestante[temp]--;

      if(timeRestante[temp]==0){
        finalizados.push(temp);
        temp=listo.front()-1;
        listo.pop();
      }
      restante--;
}

void Procesamiento::colaProcesos(){/*
	cout << "\n| Num. de lotes pendientes: ";
     cout<<filaLote.size();
      if (fila.empty()==true){//Detecta si se cambió de lote
        	cout<<"Primera parte";

        if((filaLote.size()-1)==0){
        	cout<<"Segunda parte";
        	filaLote.pop();
        	finalizado();
		}else{
			filaLote.pop();
			cambioLoteRellenado();
		}
      }*/
      procesosListos();
      procesoEjecucion();
}

void Procesamiento::procesoFinalizado(){
	cout << "\n--------------------------------------------------------\n| Procesos Finalizados  \t\t\t\t|\n--------------------------------------------------------" << endl;
      cout << "ID\tOperacion\tResultado\tNum. Lote" << endl;
      for(int g = 0; g < finalizados.size(); g++){
        processfin(finalizados.front());
        int temp2=finalizados.front();
        finalizados.pop();
        finalizados.push(temp2);
      }
      contseg++;
      if(contseg == 60){
        contmin++;
        contseg = 0;
      }
      cout << "\n| Contador: 00:";
      if(contmin<9)
        cout <<"0";
      cout << contmin <<":";
      if(contseg<9)
        cout <<"0";
      cout << contseg <<"\t\t\t\t\t|" << endl;
}
void Procesamiento::procesosBloqueados(){
        cout << "\n-----------------------------------------\n| Procesos bloqueados  \t\t\t\t|\n-----------------------------------------" << endl;
        for(int x = 1; x <= bloqueado.size();x++){
        processcola(bloqueado.front());
        bloqueado.push(bloqueado.front());
        bloqueado.pop();
        }
}

// PROCESOS
void Procesamiento::processcola(int i){
  cout << processid[i] << "\t\t" << timemax[i] << endl;//cout <<tiempotranscurrido[i];
}
void Procesamiento::processejec(int i){
  cout << processid[i] <<"\t\t00:";
  if(timemax[i]<9)
    cout <<"0";
  cout << timemax[i] <<"\t";
}
void Procesamiento::processfin(int i){
  cout << processid[i] << "\t";
  if(state[i]==0){
  	cout << num1[i];
	  if(process[i] == 1)
	    cout << " + ";
	  else
	  if(process[i] == 2)
	    cout << " - ";
	  else
	  if(process[i] == 3)
	    cout << " * ";
	  else
	  if(process[i] == 4)
	    cout << " / ";
	  else
	  if(process[i] == 5)
	    cout << " % ";
	  if(num2[i]<=0)
	    cout << "   ";
	  cout << num2[i] << " = " << "\t"<< numpro[i] <<"\t\t" << numlote[i] << endl;
  }else{
      cout << num1[i];
	  if(process[i] == 1)
	    cout << " + ";
	  else
	  if(process[i] == 2)
	    cout << " - ";
	  else
	  if(process[i] == 3)
	    cout << " * ";
	  else
	  if(process[i] == 4)
	    cout << " / ";
	  else
	  if(process[i] == 5)
	    cout << " % ";
      cout<< num2[i] << " = " << "\t" << "ERROR"<<"\t\t"<<endl;
  }

}

void Procesamiento::finalizado(){
 cout << "\n\n\n| Num. de lotes pendientes:"<<filaLote.size()<< "\t\t\t|"; // N Lotes
  cout << "\n| Num. de lote actual: 0 \t\t\t\t|";
  cout<<"\n\n--------------------------------------------------------\n| Cola de procesos  \t\t\t\t\t|\n--------------------------------------------------------";
  cout<<endl<<"ID\t\tTME"<<endl;
  cout << "\n--------------------------------------------------------\n| Proceso en  Ejecucion  \t\t\t\t|\n--------------------------------------------------------" << endl;
  cout << "Nombre: "<<endl;
  cout << "ID\t\tTME\t\tT. Transcurrido\t\tTiempo Restante\n";
  cout << "\n--------------------------------------------------------\n| Procesos Finalizados  \t\t\t\t|\n--------------------------------------------------------" << endl;
  cout << "ID\tOperacion\tResultado" << endl;
  for(int g = 0; g < process.size() ; g++){
    processfin(g);
  };
  cout << "\n| Contador: 00:";
  if(contmin<9)
    cout <<"0";
  cout << contmin <<":";
  if(contseg<9)
    cout <<"0";
  cout << contseg <<"\t\t\t\t\t|" << endl;
}

// KBHIT
void Procesamiento::interrupcion(){// Gestor de prioridad
  fila.push(temp);
  timemax[temp]=timeRestante[temp];
  timeTotal[temp] =timeRestante[temp];
  fila.pop();
  temp = fila.front();
  timeProgram++;
}

void Procesamiento::errorkbhit(){// Gestor de prioridad
  finalizados.push(temp);
  state[temp]=1;
  if(fila.size()==0){
  	if(filaLote.size()==0){
  		finalizado();
	  }
  }else{
  	fila.pop();
  temp=fila.front();
  }

}

void Procesamiento::funcionkbhit(char tecla){
  bool pausado=true;
  cout << "ya entre wii" << endl;
  while(pausado==true){
    //sleep(1);
    //cout << "ya entre al while";
    switch(tecla){ // Vemos qué tecla con getch
      case 'p':
        while (pausado == true){
            tecla = getch();
            if (tecla == 'c'){
                pausado = false;}
        }
        break;
      case 'i': // Interrumpe el proceso y pasa a el que sigue
        interrupcion();
        pausado = false;
        break;
      case 'e':
        errorkbhit();
        pausado = false;
        break;
      default:
          if(kbhit() == true){ // Devuelve F o T; si kbhit es verdadero
        tecla = getch();
        //cout << "ya entre de nuevo wi";
        //cout << tecla << endl;
        }
        break;
      } // SWITCH
  } // WHILE
} // FINAL
