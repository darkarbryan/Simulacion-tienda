#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void snd_tecla(){	
	Beep(1100,350);	
}

using namespace std;

int main(){
	
	int cant, opc, pos_elemt=5, aux, sltfil=1, sltcolm=1, tmp;
	boolean exist=false,flg=false;
	string nom, tmp2;
	string productos[10][3];	//[10] es la cantidad de productos, esto se vera representado en las filas
								//[3] es la cantidad  de elementos o atributos del producto a registrar, los cuales seria: codigo, nombre y cantidad.
	string compra[10][3];							
						
	productos[1][1]="Avast";		productos[1][2]="001"; productos[1][3]="20";		
	productos[2][1]="Netbeans";		productos[2][2]="002"; productos[2][3]="20";
	productos[3][1]="Windows 10";	productos[3][2]="003"; productos[3][3]="30";
	productos[4][1]="Windows 7";	productos[4][2]="004"; productos[4][3]="50";
	productos[5][1]="Windows 11";	productos[5][2]="005"; productos[5][3]="10";			
	
	//Por ahora se registraron manualmente 5 productos de software a nuestra matriz.
	
	cout << "\t\tBienvenido al sistema de tienda virtual"<<endl;
	cout << ""<<endl;
	snd_tecla();	
	Sleep(2000);
	
	do{
		cout << "\nComo desea ingresar?"<<endl;
		cout << "1.Como cliente		";		cout<<"2.Como administrador\n"<<endl;
		cout << "Seleccione su opcion : "; cin >> opc;
		
	}while(opc<1 || opc>2);
	
	system("CLS");
	
	switch(opc){
		
		case 1:
			cout << "--------------------------------------------------------------------------------\n";	
			cout << "\t\t\tLista de productos diponibles:\n"<<endl;
			
			for(int i=1;i<=pos_elemt;i++){
				
				cout << "\t\t-"<<productos[i][1]<<"\n";
				
			}
			cout << "--------------------------------------------------------------------------------\n"<<endl;	
			
			while(flg==false && exist==false){
				
				cout << "Ingrese el nombre del producto a comprar : "; snd_tecla(); cin >> nom;
				cout << "Ingrese ahora la cantidad : "; snd_tecla(); cin >> cant;
				system("CLS");
				
				for(int i=1;i<=pos_elemt;i++){	//es para saber si el producto que quiere comprar el usuario, existe.
					
					if(nom==productos[i][1]){
						exist=true;
						aux=i;
					}
					
				}
				
				tmp=atoi(productos[aux][3].c_str());
			
				if(cant<=tmp){
					
					tmp-=cant;
					tmp2=to_string(tmp);
					productos[aux][3]=tmp2;
					flg=true;
					
				}else{
					
					cout << "\nNo hay disponible esa cantidad solicitada para el producto : "<<productos[aux][1]<<"\n"<<endl;
					
				}
				
			}
			
			cout << "COMPRA REALIZADA CON EXITO!\n"<<endl;	
			cout << "DETALLES DE COMPRA : \n"<<endl;
			
			cout << "PRODUCTO SELECCIONADO : \t"<<productos[aux][1]<<"\n";
			cout << "CANTIDAD REQUERIDA: \t\t"<<productos[aux][3]<<"\n"<<endl;		
			
		break;
		
		case 2:
			
			flg=false;
			
			cout << "\t\tLISTADO DE INVENTARIO EXISTENTE.\n"<<endl;
			
			cout << "--------------------------------------------------------------------------------\n"<<endl;	
			
			for(int i=1;i<pos_elemt;i++){
				
				cout << "[";
				
				for(int j=1;j<=3;j++){
					
					cout << productos[i][j];
					
				}
				
				cout << "]\n"<<endl;
				
			}
			
			cout << "--------------------------------------------------------------------------------\n"<<endl;	
			
			cout << "Ahora se procedera a actualizar inventario.\n";
			cout << "Espere por favor";Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<".\n"<<endl;
			
			while(flg==false && exit==false){
				
				cout << "Ingrese el codigo del producto a modificar : "; snd_tecla(); cin >> nom;
				cout << "Ingrese ahora la cantidad : "; snd_tecla(); cin >> cant;
				system("CLS");
				
				for(int i=1;i<=pos_elemt;i++){	//es para saber si el producto que quiere modificar el administrador, existe.
					
					if(nom==productos[i][2]){
						exist=true;
						aux=i;
					}
					
				}
				
				tmp=atoi(productos[aux][3].c_str());					
				tmp-=cant;
				tmp2=to_string(tmp);
				productos[aux][3]=tmp2;
				flg=true;	
				
			}
			
			cout << "\t\tLISTADO DE INVENTARIO *NUEVO*.\n"<<endl;
			
			cout << "--------------------------------------------------------------------------------\n"<<endl;	
			
			for(int i=1;i<pos_elemt;i++){
				
				cout << "[";
				
				for(int j=1;j<=3;j++){
					
					cout << productos[i][j];
					
				}
				
				cout << "]\n"<<endl;
				
			}
			
			cout << "--------------------------------------------------------------------------------\n"<<endl;
			
		break;
	}
	
	cout << "\nHEMOS TERMINADO. HASTA PRONTO!"<<endl;	
	
	getch();
	return 0;
}
