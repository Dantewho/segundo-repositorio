#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int mapa[30][30];
int mapa2[30][30];
int hacer=1;
int cont=1;
int y, x;
int PartidasTotales = 0;
int PartidasTotales2 = 0;
int DatosDeLasPartidas[10000][3];
int DatosDeLasPartidas2[10000][3];
int Barcos_hundidos2;
int Barcos_hundidos;
bool terminar;
/*
2 fragatas
1 Portaaviones
3 submarinos
3 Destructores
*/

int inicio(){
	//PARA PODER USAR LA FUNCION SLEEP()
	cout.flush();
	//ESTA ES LA BIENVENIDA
	cout<<" |BIENVENIDOS|"<<endl;
	cout<<" **************************"<<endl;
	cout<<"De los creadores de |Assassins Creed| y de |Candy Crush| \n|PRESENTAN| \n\n";
	sleep(3);
	system("cls");
	cout<<" |BATTLESHIP|"<<endl;
	sleep(1);
	system("cls");

	//PANTALLA DE CARGA
	cout<<"CARGANDO...";

	while (hacer==1){
	  	if (cont==1){
	      	cout<<"0 %";
	      	cont=cont+1;
	  	}

	    sleep(1);
	    system("cls");

	  	if (cont==2){
	      	cout<<"cargando..." <<"10 %";
	      	cont=cont+1;
	  	}

	  	sleep(1);
	  	system("cls");

	  	if (cont==3){
	  		cout<<"cargando..." <<"15 %";
	      	cont=cont+1;
	  	}
	  	sleep(1);
	  	system("cls");
	  	if (cont==4){
	      	cout<<"cargando..." <<"23 %";
	      	cont=cont+1;
	  	}
	  	sleep(1);
	  	system("cls");
	  	if(cont==5){
	      	cout<<"cargando..." <<"56 %";
	      	cont=cont+1;
	  	}
	  	sleep(1);
	  	system("cls");
	  	if (cont==6){
	      	cout<<"cargando..." <<"72 %";
	      	cont=cont+1;
	  	}
	  	sleep(1);
	  	system("cls");
	  	if (cont==7){
	 		cout<<"cargando..." <<"100 %";
		}
	  	hacer=2;
	}
	sleep(2);
	system("cls");

	cout<<"°°°LISTO!!!"<<endl;
	sleep(1);
	system("cls");

	//AQUI SE ESCRIBEN LAS REGLAS
	cout<<"|REGLAS|\n";
	cout<<"Cada uno tendra:\n\n";
	cout<<"1 Portaaviones\n";
	cout<<"3 Submarinos\n";
	cout<<"3 Destructores\n";
	cout<<"1 Fragata\n";
	cout<<"Todos se exparciran por el tablero al azar\n\n";
	cout<<"En cada turno vas a tener que poner latitud y longitud de donde creas que esten los barcos enemigos\n";
	cout<<"Si uno de los dos jugadores da a algun barco NO se especificara a que barco le\n";
	cout<<"dio \n\n";
	cout<<"PRESIONA TECLA ENTER PARA CONTINUAR\n";
	getch();
	system("cls");
}

void mostrar_mapa(){
  	cout<<"\n \ntu mapa\n";
  	cout<<" ||";
  	for(int x=0;x<=29;x++){
      	if(x<=9){
      		cout<<"  "<<x;
      	}else{
          	cout<<" "<<x;
      	}
  	}
  	for(int y=0;y<=29;y++){
      	if(y<=9){
          	cout<<"\n"<<y<<" |";
      	}else{
      	    cout<<"\n"<<y<<"|";
      	}
      	for(int x=0;x<=29;x++){
         	cout<<"||"<<mapa[x][y];
      	}
  	}
	sleep(10);
}

void mostrar_mapa2(){
  	cout<<"\n\nmapa enemigo\n";
	cout<<" ||";
  	for(int x=0;x<=29;x++){
      	if(x<=9){
      		cout<<"  "<<x;
      	}else{
          cout<<" "<<x;
      	}
  	}
  	for(int y=0;y<=29;y++){
  		if(y<=9){
      		cout<<"\n"<<y<<" |";
      	}else{
          	cout<<"\n"<<y<<"|";
      	}
  		for(int x=0;x<=29;x++){
          	cout<<"||"<<mapa2[x][y];
      	}
  	}
  sleep(10);
}

int portaaviones(){
  	int repetir=0;
  	while(repetir==0){
      	x=0;
      	srand(time(NULL));
      	x=rand()%29;
      	//Para el segundo numero al azar
      	if(x==29){
          	x-3;
      	}
      	if(x==0){
          	x+3;
      	}
      	y=1;
      	y=rand()%26-3;
		if(mapa[x][y]==0 and mapa[x][y+1]==0 and mapa[x][y+2]==0 and mapa[x][y+3]==0 and mapa[x][y-1]==0 and mapa[x][y-2]==0 and mapa[x-1][y+2]==0 and mapa[x-1][y+1]==0 and mapa[x-1][y]==0 and mapa[x-1][y-1]==0 and mapa[x+1][y+2]==0 and mapa[x+1][y+1]==0 and mapa[x+1][y]==0 and mapa[x+1][y-1]==0){
      		repetir++;
          	if(y > 4 and y < 27){
             	mapa[x][y]=5;
				mapa[x][y-1]=5;
             	mapa[x][y-2]=5;
          		mapa[x][y-3]=5;
          	}else{
              	mapa[x][0]=5;
              	mapa[x][1]=5;
              	mapa[x][2]=5;
              	mapa[x][3]=5;
          	}
      	}
  	}
}
int fragata(){
	int repetir=0;
  	while(repetir<2){
       	int x,y;
       	x=0;
       	srand(time(NULL));
       	x=rand()%29;
       	if(x == 29){
           	x-2;
       	}
       	if(x == 0){
           	x+2;
      	}
       	y=0;
       	y=rand()%29;
       	if(y == 29){
           	y-2;
       	}
       	if(y == 0){
           	y+2;
       	}
       	if(mapa[x][y]==0 and mapa[x][y-1]==0 and  mapa[x][y+1]==0 and mapa[x-1][y]==0 and mapa[x+1][y]==0){
      		repetir++;
      		mapa[x][y]=2;
   		}
   	}
}
void azarsubmarino(){
   	int repetir = 0;
   	while(repetir<3){
       	x=0;
       	x=rand()%29;
       	if(x==29){
           	x-1;
       	}
       	if(x==0){
           	x++;
       	}
       	y=0;
       	y=rand()%29;
       	if(y==29){
           	y-1;
       	}
       	if(y==0){
           	y++;
       	}
       	if(mapa[x][y]==0 and mapa[x][y+1]==0 and mapa[x][y+2]==0 and mapa[x][y-1]==0 and mapa[x][y-2]==0 and mapa[x-1][y]==0 and mapa[x-1][y-1]==0 and mapa[x-1][y+1]==0 and mapa[x+1][y]==0 and mapa[x+1][y+1]==0 and mapa[x+1][y-1]==0){
           	repetir++;
            mapa[x][y]=4;
            mapa[x][y+1]=4;
        	mapa[x][y-1]=4;
       	}
   	}
}
int destructor(){
   	int repetir=0;
   	int x,y;
   	//se genera un while para poner los numeros alatorios sin chocar
   	while(repetir<3){
       	x=0;
       	x=rand()%20 + 9;
       	if(x ==29){
       	    x-1;
       	}
       	if(x == 0){
           	x++;
       	}
       	y=0;
       	y=rand()%20 + 9;
       	if(y == 29){
           	y-1;
       	}
       	if(y == 0){
           	y++;
       	}
       	if(mapa[x][y]==0 and mapa[x][y+1]==0 and mapa[x][y-1]==0 and mapa[x][y-2]==0 and mapa[x-1][y-1]==0 and mapa[x-1][y]==0 and mapa[x+1][y-1]==0 and mapa[x+1][y]==0){
           	repetir++;
           	mapa[x][y]=3;
           	mapa[x][y-1]=3;
       	}
   	}
}


int portaaviones2(){
  	int repetir=0;
	while(repetir==0){
      	x=0;
      	srand(time(NULL));
      	x=rand()%29;
		//para el segundo numero al azar
      	if(x==29){
          	x-3;
      	}
      	if(x==0){
          	x+3;
      	}
      	y=1;
      	y=rand()%26-3;
      	if(mapa2[x][y]==0 and mapa2[x][y+1]==0 and mapa2[x][y+2]==0 and mapa2[x][y+3]==0 and mapa2[x][y-1]==0 and mapa2[x][y-2]==0 and mapa2[x-1][y+2]==0 and mapa2[x-1][y+1]==0 and mapa2[x-1][y]==0 and mapa2[x-1][y-1]==0 and mapa2[x+1][y+2]==0 and mapa2[x+1][y+1]==0 and mapa2[x+1][y]==0 and mapa2[x+1][y-1]==0){
          	repetir++;
          	if(y > 4 and y < 27){
          		mapa2[x][y]=5;
          		mapa2[x][y-1]=5;
          		mapa2[x][y-2]=5;
          		mapa2[x][y-3]=5;
          	}else{
              	mapa2[x][0]=5;
              	mapa2[x][1]=5;
				mapa2[x][2]=5;
          		mapa2[x][3]=5;
          	}
      	}
  	}
}
int fragata2(){
  	int repetir=0;
  	//se genera un while para poner los numeros aleatorios sin chocar
  	while(repetir<2){
      	int x,y;
      	//primero de generan dos numeros al azar
      	x=0;
      	srand(time(NULL));
      	x=rand()%29;
      	if(x == 29){
          	x-2;
  		}
      	if(x == 0){
          	x+2;
      	}
      	y=0;
      	y=rand()%29;
      	if(y == 29){
          	y-2;
      	}
      	if(y == 0){
          	y+2;
      	}
		if(mapa2[x][y]==0){
          	//aqui se ve si con el conjunto de los dos numeros aleatorios no caen justo encima de un barco
      		int yy = y+1;
          	if(mapa2[x][yy]==0){
          		//a qui se verifica si el espacio arriba de la fragata esta libre
              	int yyy = y-1;
              	if(mapa2[x][yyy]==0){
                  	//a qui se verifica si el punto abajo del barco esta basio
                  	int xx = x-1;
					if(mapa2[xx][y]==0){
                  		// a qui verifica si el costado del varco esta libre (el izquierdo)
                  		int xxx = x+1;
						if(mapa2[xxx][y]==0){
                  			// a qui verifica si el costado del varco esta libre (el derecho)
                          	repetir++;
                          	mapa2[x][y]=2;
                      	}
              		}
              	}
      		}
      	}
  	}
}
void azarsubmarino2(){
  	int repetir = 0;
  	while(repetir<3){
      	//para el primer numero al azar
      	x=0;
      	srand(time(NULL));
      	x=rand()%29;
      	//para el segundo numero al azar
      	if(x==29){
      		x-1;
      	}
      	if(x==0){
          	x++;
      	}
      	y=0;
      	y=rand()%29;
      	if(y==29){
          	y-1;
      	}
      	if(y==0){
          	y++;
      	}
      	if(mapa2[x][y] == 0){
          	//este if es para saber si el conjunto de los dos numeros al azar caiga encima de otro barco
          	int yy = y + 1;
          	if(mapa2[x][yy]== 0){
              	//este es parasaber si el punto de arriba esta diponible para alargar el barco
              	int yyy = y - 1;
              	if(mapa2[x][yyy] == 0){
                  	// este es para saber el numero de abaja de y es cero para alargar el barco
                  	int xx = xx-1;
                  	if(mapa2[xx][yyy] == 0){
                      	// este es para saber si el punto de asta abajo del submarino del lado izquierdo esta libre
                      	if(mapa2[xx][y] == 0){
                      		//este es para saber si el punto de en medio de la izquierda sea cero
                          	if(mapa2[xx][yy] == 0){
                              	//este es para saber si el punto mas alto del barco del lado izquiedo esta libre
                              	int xxx = x + 1;
                              	if(mapa2[xxx][yyy]== 0){
                              		//este es para saber si el punto que esta asta abjao del barco del lado derecho esta basio
                                  	if(mapa2[xxx][y]==0){
                                      	//este es para saber si el punto de enmedio del barco del lado derecho esta basio
                                      	if(mapa2[xxx][yy]==0){
                                      		//este es para saber si el punto de asta arriba del barco del lado dereco esta basio
                                          	int yyyy = yyy - 1;
                                      		if(mapa2[x][yyyy]==0){
                                              	//este es para saber si el punto abajo del barco esta basio
                                              	int yyyyy = yy + 1;
                                              	if(mapa2[x][yyyyy]==0){
                                                  	//este es para saber si el punto arriba del barco esta basio
                                                  	mapa2[x][y]=4;
                                                  	mapa2[x][yy]=4;
                                                  	mapa2[x][yyy]=4;
                                                  	repetir++;
                                              	}
                                          	}
                                      	}
                                  	}
                              	}
                          	}
                      	}
                  	}
              	}
          	}
      	}
  	}
}
int destructor2(){
  	int repetir =0;
  	int x,y;
	//se jenera un whelid para poner los numeros alatorios sin chocar
  	while(repetir<3){
      	x=0;
      	srand(time(NULL));
      	x=rand()%29;
  		if(x ==29){
   	   	x-1;
    	}
    	if(x == 0){
        x++;
    	}
    	y=0;
    	y=rand()%29;
    	if(y == 29){
    	    y-1;
    	}
    	if(y == 0){
    	    y++;
    	}
    	if(mapa2[x][y]==0){
    	    //para 2verificar que el barco no caiga encima de otro
    	    int yy = y+1;
    	    if(mapa2[x][yy]==0){
    	      	//para verificar si la parte de adelnte esta basia
    	      	int yyy= yy+1;
    	      	if(mapa2[x][yyy]==0){
    	      		//para verificar si el punto de ariba del barco esta bacante
    	            int yyyy = y-1;
    	            if(mapa2[x][yyyy]==0){
    	            	//para verificar si el punto abajo del barco esta disponible
    	                int xx = x-1;
    	                if(mapa2[xx][y]==0){
    	                    //para verificar si a la izquierda del punto mas bajo del barco esta disponible
    	                    if(mapa2[xx][yy]==0){
    	                        //para verificar si a la izquierda del punto mas alto del barco esta disponible
    	                        int xxx=x+1;
       	                    	 if(mapa2[xxx][y]==0){
       	                         	//para verificar si a la derecha del barco (su punto mas bajo) esta libre
       	                         	if(mapa2[xxx][yy]==0){
       	                            	//para verificar si a la derecha del punto mas alto del barco esta disponible
       	                            	mapa2[x][y]=3;
       	                            	mapa2[x][yy]=3;
       	                            	repetir++;
       	                       		}
       	                    	}
       	                	}
						}
       	        	}
       	    	}
       		}
    	}
	}
}
void ganadorU(){
  	if(Barcos_hundidos==9){
      	cout<< "Felicidades, has ganado, falla un tiro para salir del juego";
  		terminar=true;
	}
}
void ganadorM(){
  	if(Barcos_hundidos2==9){
      	cout<< "El juego acabo, jugaste bien pero la maquina mejor, perdiste";
      	terminar=true;
  	}
}
void disparar_maquina(){
 	x=rand()%29;
  	y=rand()%29;
  	if(x<=29 and x>=0){
      	if (y<=29 and y>=0){
      		if(mapa[x][y]!= 9 and mapa[x][y]!= 8){
      	      	PartidasTotales2++;
          		cout<<"x=" <<x;
            	cout<<"y=" <<y;
              	cout<<"la maquina disparo en.."<<x<<","<<y;
              	if (mapa[x][y]==0){
                  	cout<<"\n esa posicion fue agua\n ";
                  	mapa[x][y]=9;
              	}
              	if (mapa[x][y]==2){
                  	cout<<"\n esa posicion fue fragata\n";
          			cout<<"\n Tu barco fue destruido\n";
              		DatosDeLasPartidas2[PartidasTotales2][1]=1;
              		DatosDeLasPartidas2[PartidasTotales2][2]=2;
              		Barcos_hundidos2++;
                	getch();
                  	mapa[x][y]=8;
                  	ganadorM();
                  	cout<<"\n mala surte, la maquina tiene otro tiro";
					disparar_maquina();
              	}
              	if (mapa[x][y]==3){
              		cout<<"\n esa posicion fue destructor\n";
                 	if(mapa[x][y+1]==mapa[x][y] || mapa[x][y+2]==mapa[x][y] ||  mapa[x][y+3]==mapa[x][y] || mapa[x][y-1]==mapa[x][y] || mapa[x][y-2]==mapa[x][y] || mapa[x][y-3]==mapa[x][y]){
                      	cout<<"\n Tu barco fue daniado\n";
                      	DatosDeLasPartidas2[PartidasTotales2][1]=2;
                      	DatosDeLasPartidas2[PartidasTotales2][2]=3;
					}else{
                  		cout<<"\n Tu barco fue destruido\n";
                      	DatosDeLasPartidas2[PartidasTotales2][1]=1;
                      	DatosDeLasPartidas2[PartidasTotales2][2]=3;
                      	Barcos_hundidos2++;
                  	}
                  	mapa[x][y]=8;
                  	getch();
                  	ganadorM();
                  	cout<<"\n mala surte, la maquina tiene otro tiro";
					disparar_maquina();
              	}
              	if (mapa[x][y]==4){
              		cout<<"\n esa posicion fue submarino\n";
                  	if(mapa[x][y+1]==mapa[x][y] || mapa[x][y+2]==mapa[x][y] || mapa[x][y+3]==mapa[x][y] || mapa[x][y-1]==mapa[x][y] || mapa[x][y-2]==mapa[x][y] || mapa[x][y-3]==mapa[x][y]){
                      	cout<<"\n Tu barco fue daniado\n";
                      	DatosDeLasPartidas2[PartidasTotales2][1]=2;
                      	DatosDeLasPartidas2[PartidasTotales2][2]=4;
                  	}else{
						cout<<"\n Tu barco fue destruido\n";
                  		DatosDeLasPartidas2[PartidasTotales2][1]=1;
						DatosDeLasPartidas2[PartidasTotales2][2]=4;
                      	Barcos_hundidos2++;
                  	}
                  	mapa[x][y]=8;
                  	getch();
                  	ganadorM();
                   	cout<<"\n mala surte, la maquina tiene otro tiro";
					disparar_maquina();
              	}
              	if (mapa[x][y]==5){
                  	cout<<"\n esa posicion fue portaaviones\n";
                  	if(mapa[x][y+1]==mapa[x][y] || mapa[x][y+2]==mapa[x][y] || mapa[x][y+3]==mapa[x][y] || mapa[x][y-1]==mapa[x][y] || mapa[x][y-2]==mapa[x][y] || mapa[x][y-3]==mapa[x][y]){
                      	cout<<"\n Tu barco fue daniado\n";
                      	DatosDeLasPartidas2[PartidasTotales2][1]=2;
                      	DatosDeLasPartidas2[PartidasTotales2][2]=5;
                  	}else{
                      	cout<<"\n Tu barco fue destruido\n";
                      	DatosDeLasPartidas2[PartidasTotales2][1]=1;
                      	DatosDeLasPartidas2[PartidasTotales2][2]=5;
                      	Barcos_hundidos2++;
                  	}
                  	mapa[x][y]=8;
                  	getch();
                  	ganadorM();
                  	cout<<"\n mala surte, la maquina tiene otro tiro";
					disparar_maquina();
              	}
          	}else{
          		cout<<"\n esa posicion ya fue disparda\n ";
          		getch();
              	disparar_maquina();
          	}
      	}else{
      		cout<<"\n esa posicion no existe\n ";
        	getch();
          	disparar_maquina();
      	}
  	}else{
      	cout<<"\n esa posicion no existe\n ";
      	getch();
      	disparar_maquina();
  	}
}
void disparar(){
  	cout<<"\n\nCual posicion deseas eliminar?(lado y)\n";
  	cin>>y;
  	cout<<"\nCual posicion deseas eliminar?(lado x)\n";
  	cin>>x;
  	if(x<=29 and x>=0){
      	if (y<=29 and y>=0){
          	if(mapa2[x][y]!= 9 and mapa2[x][y]!= 8){
                PartidasTotales++;
				if (mapa2[x][y]==0){
                  	cout<<"\n esa posicion fue agua\n";
                  	mapa2[x][y]=9;
              	}
              	if (mapa2[x][y]==2){
              		cout<<"\n esa posicion fue fragata\n";
                  	cout<<" El barco fue destruido\n";
					DatosDeLasPartidas[PartidasTotales][1]=1;
					DatosDeLasPartidas[PartidasTotales][2]=2;
					Barcos_hundidos++;
					mapa2[x][y]=8;
					getch();
					ganadorU();
					cout<<"\n felicidades, tienes otro tiro ";
					disparar();
              	}
              	if (mapa2[x][y]==3){
                  	cout<<"\n esa posicion fue destructor\n";
                  	if(mapa2[x][y+1]==mapa2[x][y] || mapa2[x][y+2]==mapa2[x][y] ||  mapa2[x][y+3]==mapa2[x][y] || mapa2[x][y-1]==mapa2[x][y] || mapa2[x][y-2]==mapa2[x][y] || mapa2[x][y-3]==mapa2[x][y]){
                      	cout<<" El barco fue lastimado\n";
                      	DatosDeLasPartidas[PartidasTotales][1]=2;
                      	DatosDeLasPartidas[PartidasTotales][2]=3;
  					}else{
                      	cout<<" El barco fue destruido\n";
                      	DatosDeLasPartidas[PartidasTotales][1]=1;
						DatosDeLasPartidas[PartidasTotales][2]=3;
                    	Barcos_hundidos++;
					}
                  	mapa2[x][y]=8;
					getch();
					ganadorU();
					cout<<"\n felicidades, tienes otro tiro ";
					disparar();
              	}
              	if (mapa2[x][y]==4){
                  	if(mapa2[x][y+1]==mapa2[x][y] || mapa2[x][y+2]==mapa2[x][y] || mapa2[x][y+3]==mapa2[x][y] || mapa2[x][y-1]==mapa2[x][y] || mapa2[x][y-2]==mapa2[x][y] || mapa2[x][y-3]==mapa2[x][y]){
                  		cout<<"\n esa posicion fue submarino\n";
                      	cout<<" El barco fue daniado\n";
                      	DatosDeLasPartidas[PartidasTotales][1]=2;
                      	DatosDeLasPartidas[PartidasTotales][2]=4;
                  	}else{
                      	cout<<" El barco fue destruido\n";
                      	DatosDeLasPartidas[PartidasTotales][1]=1;
                      	DatosDeLasPartidas[PartidasTotales][2]=4;
                      	Barcos_hundidos++;
                  	}
                  	mapa2[x][y]=8;
					getch();
					ganadorU();
					cout<<"\n felicidades, tienes otro tiro ";
					disparar();
              	}
              	if (mapa2[x][y]==5){
                  	cout<<"\n esa posicion fue portaaviones\n";
                  	if(mapa2[x][y+1]==mapa2[x][y] || mapa2[x][y+2]==mapa2[x][y] || mapa2[x][y+3]==mapa2[x][y] || mapa2[x][y-1]==mapa2[x][y] || mapa2[x][y-2]==mapa2[x][y] || mapa2[x][y-3]==mapa2[x][y]){
                      	cout<<" El barco fue daniado\n";
                      	DatosDeLasPartidas[PartidasTotales][1]=2;
                      	DatosDeLasPartidas[PartidasTotales][2]=5;
                  	}else{
                  		cout<<" El barco fue destruido\n";
                      	DatosDeLasPartidas[PartidasTotales][1]=1;
                      	DatosDeLasPartidas[PartidasTotales][2]=5;
                      	Barcos_hundidos++;
                  	}
                  	mapa2[x][y]=8;
              		getch();
              		ganadorU();
              	 	cout<<"\n felicidades, tienes otro tiro ";
					disparar();
              	}
          	}else{
              	cout<<"\n esa posicion ya fue disparda\n ";
              	getch();
              	disparar();
          	}
      	}else{
      		cout<<"\n esa posicion no existe\n ";
			getch();
          	disparar();
      	}
  	}else{
      	cout<<"\n esa posicion no existe\n ";
      	getch();
      	disparar();
  	}
}
void usuario(){
  	portaaviones();
  	azarsubmarino();
  	destructor();
  	fragata();
}
void maquina(){
  	portaaviones2();
  	fragata2();
  	azarsubmarino2();
  	destructor2();
}
//Funcion
int main(){
	inicio();
  	int s;
  	int hack;
	int trucos;
  	cout<<"EL SISTEMA ESTA COLOCANDO BARCOS AUTOMATICAMENTE...\n";
	maquina();
	system("cls");
	cout<<"BARCOS CASI COLOCADOS";
	usuario();
	system("cls");
	cout<<"BARCOS COLOCADOS CORRECTAMENTE";
	sleep(1);
	system("cls");
	while(terminar==false){
		cout<<"A destruir barcos \n1=Si \n2=No\n";
  		cin>>s;
  		if(s==1){
  			system("cls");
      		cout<<"Quieres activar los hacks? \n1= Si \n2 o cualquier otro numero= No\n";
      		cin>>hack;
      		system("cls");
      		if(hack==1){
      		    mostrar_mapa2();
      		}else{
      		    cout<<"Ok, juegas limpio, felicidades\n";
      		}
      		mostrar_mapa();
      		disparar();
      		disparar_maquina();
      		system("cls");
  		}
  		if(s==2){
  		    system("cls");
  		    cout<<"GRACIAS POR JUGAR\n";
  		    terminar=true;
  		}
  		if(s!=1 and s!=2){
  		    system("cls");
  		    cout<<"Tiene que ser 1 o 2\n";
			terminar=false;
  		}
	}
	for(int CC1=0;CC1<=PartidasTotales;CC1++){
      	if(DatosDeLasPartidas[CC1][1]!=0 ||DatosDeLasPartidas[CC1][2]==2||DatosDeLasPartidas[CC1][2]==3||DatosDeLasPartidas[CC1][2]==4||DatosDeLasPartidas[CC1][2]==5){
      		cout<<"\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\b";
          	cout<<"\nEn la partida "<<CC1;
          	cout<<" un jugador";
          	if(DatosDeLasPartidas[CC1][1]==1){
              	cout<<" hundio";
          	}else{
          		if(DatosDeLasPartidas[CC1][1]==2){
              		cout<<" lastimo";
          		}
        	}
          	cout<<" un barco que era ";
          	if(DatosDeLasPartidas[CC1][2]==5){
          		cout<<" un porta aviones";
          	}else{
      			if(DatosDeLasPartidas[CC1][2]==4){
              		cout<<" un submarino";
              	}else{
					if(DatosDeLasPartidas[CC1][2]==3){
                      	cout<<" un destructor";
                  	}else{
                      	if(DatosDeLasPartidas[CC1][2]==2){
                      		cout<<" un fragata";
                      	}
                  	}
				}
          	}
      	}
	}
	for(int CC2=0;CC2<=PartidasTotales2;CC2++){
      	if(DatosDeLasPartidas2[CC2][1]!=0 ||DatosDeLasPartidas2[CC2][2]==2||DatosDeLasPartidas2[CC2][2]==3||DatosDeLasPartidas2[CC2][2]==4||DatosDeLasPartidas2[CC2][2]==5){
      		cout<<"\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\b";
            cout<<"\nEn la partida "<<CC2;
            cout<<" la maquina ";
          	if(DatosDeLasPartidas2[CC2][1]==1){
              	cout<<" hundio";
          	}else{
          		if(DatosDeLasPartidas2[CC2][1]==2){
              		cout<<" lastimo";
          		}
          	}
          	cout<<" un barco que era ";
          	if(DatosDeLasPartidas2[CC2][2]==5){
          		cout<<" un porta aviones";
          	}else{
      			if(DatosDeLasPartidas2[CC2][2]==4){
            		cout<<" un submarino";
              	}else{
					if(DatosDeLasPartidas2[CC2][2]==3){
                      	cout<<" un destructor";
                  	}else{
                      	if(DatosDeLasPartidas2[CC2][2]==2){
                      		cout<<" un fragata";
                      	}
                  	}
				}
          	}
      	}
	}
	cout<<"\nA la maquina le hundieron "<<Barcos_hundidos;
	cout<<"\nAl usuario le hundieron "<<Barcos_hundidos2;
	int Barcos_a_flote=9-Barcos_hundidos;
	int Barcos_a_flote2=9-Barcos_hundidos2;
	cout<<"\nLe quedan a la maquina "<<Barcos_a_flote<<" Barcos a flote";
	cout<<"\nLe quedan al usuario "<<Barcos_a_flote2<<" Barcos a flote";
  	return 0;

}
