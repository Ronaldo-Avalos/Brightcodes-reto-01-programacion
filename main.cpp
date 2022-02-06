#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void guion(int anch); // guión superior
void colum(int alt);  // columna derecha
void spacecolum(int alt, int anch); //columna con un espacio variable 
void esq_space_InDe(int alt, int anch); // Esquina inferior derecha con espacio
void esq_InIz(int alt, int anch);	// Esquina inferior izquierda
void double_colum(int alt, int anch); // Doble columna con espacio variables entre ellas
void double_colum_guion(int alt, int anch); // Doble columna con guiones variables entre ellas
////////
int main() {
	int i, //iterador 
	num[10], //números tecleados
	num__digitos,// digitos a solicitar
	alt, //altura tecleada
	anch, //ancho tecleado
	t = 0 ; //cierre del programa
	char res; //respuesta del usuario
	do{
		system("cls");			
		cout<<"De cuantos digitos no mayor a 9 sera tu numero a teclear?";
		cin>>num__digitos;
		if(num__digitos>=1 && num__digitos<=9){ //comprueba que el n�mero de digitos no sea mayor a 10
			if(num__digitos>1){
				cout<<"Teclea los digitos: \n";
			}else{
				cout<<"Teclea el digito: \n";
			}
			//pide los digitos
			for(i = 1; i <= num__digitos; i++){
				cout<<"Digito "<<i<<"--> ";
			    cin>>num[i];
			}
			cout<<"Quieres cambiar la altura y anchura de los digitos? S/N \n";
			cin>>res;
			alt = 1; //altura por defecto 
			anch = 1; //anchura por defecto
			if(res == 'S' || res == 's'){		
					cout<<"Introduce la altura: ";
						cin>>alt;
					cout<<"Introduce el ancho: ";
						cin>>anch;
			}
				if(alt>=0 && anch>=0){ 			 //Evalua que la altura y la anchura sean un n�mero mayor a 0 
					for(int i=0;i<=num__digitos;i++){ 	// Itera los digitos para ser evaluados por el switch
						switch(num[i]) {
						   case 1 :
						   		if(alt>=2){
						   			cout<<"\n";
						   			colum (alt+1);
								   }else{
								   cout<<"\n";
						   			colum (alt);
								   }	
						    break;						      
							case 2:
								if(alt>1){ 
									guion(anch);
									cout<<"\n";
									spacecolum (alt, anch);
									cout<<" ";
									esq_space_InDe(alt, anch);
									cout<<"\n";
									colum (alt);
									esq_InIz(alt,anch);
									cout<<"\n";}
								else{
									cout<<" _\n _|\n|_\n";}
							break;   
							case 3:
							    guion(anch);
							    cout<<"\n";
								spacecolum (alt, anch);
								cout<<" ";
								esq_space_InDe(alt, anch);
								cout<<"\n";
								spacecolum (alt, anch);
								cout<<" ";
								esq_space_InDe(alt, anch);
								cout<<"\n";
							break;							      
							case 4:
								cout<<"\n";
								double_colum(alt, anch);
								double_colum_guion(alt, anch);
								cout<<"\n";
								spacecolum (alt+1, anch);
							break; 							    
							case 5:
								if(alt>1){
								    guion(anch);
								    cout<<"\n";
								    colum (alt);
									esq_InIz(alt,anch);
									cout<<"\n";
									spacecolum (alt, anch);
									cout<<" ";
									esq_space_InDe(alt, anch);
									cout<<"\n";}
								else{
									cout<<" _\n|_\n _|\n";}
							break; 							    
							case 6:
								if(alt>1){
							    	guion(anch);
							    	cout<<"\n";
							    	colum (alt);
									esq_InIz(alt,anch);
									cout<<"\n";
									double_colum(alt, anch);
									double_colum_guion(alt, anch);
									cout<<"\n";}
								else{
									cout<<" _\n|_\n|_|\n";}
							break; 							    
							case 7:
								if(alt>1){
									guion(anch);
									cout<<"\n";
									spacecolum (alt+1, anch);}
								else{
									cout<<" _\n  |\n  |\n";}
							break;								   
							case 8:
							   if(alt>1){
									guion(anch);
									cout<<"\n"; 
									double_colum(alt, anch);
									double_colum_guion(alt, anch);
									cout<<"\n";
									double_colum(alt, anch);
									double_colum_guion(alt, anch);
									cout<<"\n";}
								else{
									cout<<" _\n|_|\n|_|\n";}
							break; 							      
							case 9 :
							    if(alt>1){
								    guion(anch);
								    cout<<"\n"; 
									double_colum(alt, anch);
									double_colum_guion(alt, anch);
									cout<<"\n";
									spacecolum (alt+1, anch);}
								else{
									cout<<" _\n|_|\n _|\n";}
							break; 
						}// termia el switch
					}//termina la iteraci�n de digitos (for)	
					cout<<"Desea continuar con el programa? S/N: ";
					cin>>res;
					if(res == 'N' || res == 'n') //Evalua que el usuario quiera seguir en el programa	
							t = 1;
				}else cout<<"una de las medidas es demasiado chica intenta con otras medidas\n"; 															 
		}else {cout<<"numero incorrecto"; getch();}	
	}while(t==0); 
}
		 
// _       guion
// |	   colum
// XX|     spacecolum
// X_|	   esq-spacio-InDe
// _|	   esq InDe
// |_	   esq InIz

void guion(int anch){ 
	cout<<" ";
	for(int i=0;i<anch;i++){
		cout<<"_";
	}	
}

void colum(int alt){ 
	if(alt>1){
	for(int i=0;i<alt-1;i++){
		cout<<"|";
		if(i<=alt+1)
		cout<<"\n";
	}
	}//if
	else{
		cout<<" |\n";
		cout<<" |\n";
	}
	
}
void spacecolum(int alt, int anch){
	for(int di=0; di<=alt-2; di++){
		for(int i=0;i<=anch;i++){
		cout<<" ";
		
		}
		cout<<"|";
		if(di<=alt)
		cout<<"\n";
	}
}
void esq_space_InDe(int alt, int anch){
	
	for(int i=0;i<anch;i++){
		cout<<"_";
	}
		cout<<"|";	
}
void esq_InIz(int alt, int anch){
	
	cout<<"|";
	for(int i=0;i<anch;i++){
		cout<<"_";
	}	
}
void double_colum(int alt, int anch){
	
	for(int di=0; di<=alt-2; di++){
	cout<<"|";	
	for(int i=0;i<=anch-1;i++){
	cout<<" ";
		}
		cout<<"|";
		if(di<=alt)
		cout<<"\n";
	}
}
void double_colum_guion(int alt, int anch){
	
	cout<<"|";
	for(int i=0;i<anch;i++){
		cout<<"_";
	}	
	cout<<"|";
}





	

