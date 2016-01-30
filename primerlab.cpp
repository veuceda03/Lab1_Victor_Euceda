#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int factorial(int valor){
	int fact=1;
	for(int i=1;i<=valor;i++){
		fact*=i;
	}
	return fact;
}



double  valoreuler(int valorx){
	int denom,base=valorx;
        double sumando,euler=1;
	for(int i=1;i<=13;i++){
		denom=factorial(i);
		sumando=((pow(base,i))/denom);
		euler+=sumando;		
        }
	return euler;
}

double valordiagonal(int a1,int a2,int b1,int b2){
	double d;
	int x=pow((a2-a1),2);
	int y=pow((b2-b1),2);
	d=pow((x+y),(0.5));
	return d;
}

void imprimir(int a1,int a2,int b1,int b2){
	double d;
	int x=pow((a2-a1),2);
	int y=pow((b2-b1),2);
	d=pow((x+y),(0.5));
	cout<<"Distancia: "<<d<<endl;
}

bool puntoscolineales(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
	double pendiente1,pendiente2;	
	if((x1!=0)||(x2!=0)){
		pendiente1=((y2-y1)/(x2-x1));
		pendiente2=((y3-y2)/(x3-x2));
		if(pendiente1==pendiente2){
			return false;
		} else{
			return true;
		}	
	}else{
		if((x3==0)||(x4==0)){
			return false;
		}else{
			return true;
		}
	}
	
}

double semiperimetro(double a,double b,double c){
	double semi=((a+b+c)/2);
	cout<<endl<< "El semiperimetro es: "<<semi<<endl;
	double peri=semi*2;
	cout<<endl<< "Perimetro es: "<<peri<<endl;
	return semi;
}

double altura(double semi,double a,double b,double c){
	double haltura;
	haltura=(2/a)*pow((semi*(semi-a)*(semi-b)*(semi-c)),0.5);
	cout <<"Altura: "<<haltura<<endl;
	return haltura;
}

double triangulo(int x1,int x2,int x3,int y1,int y2,int y3){
	double a,b,c,semip;
	a=valordiagonal(x1,x2,y1,y2);
	b=valordiagonal(x1,x3,y1,y3);
	c=valordiagonal(x2,x3,y2,y3);
	semip=semiperimetro(a,b,c);
	double h;
	h=altura(semip,a,b,c);
	h=altura(semip,b,a,c);
	h=altura(semip,c,a,b);
	double area=0.5*c*h;
	cout<< " El área es: "<<area<<endl; 
	return area;
}

int main(int argc, char* argv[]){
	int opcion;
		
	cout<< "Bienvenido"<<endl<<"1: Número de Euler"<<endl
	<< "2: Área de trapezoide"<<endl;
	cout<<" x= ";
	cin>>opcion;

	if(opcion==1){
		int valorx;
		cout<< "Número de Euler"<<endl;
		cout<< "Ingrese el valor para x: ";
		cin >>valorx; 
		cout<< valoreuler(valorx)<<endl;	
	}else if(opcion==2){
		int x1,x2,x3,x4;
		int y1,y2,y3,y4;
		double diagonal;	
		bool bandera;
		cout<<"X1= ";
			cin>>x1;
			cout<<"Y1= ";
			cin>>y1;
			cout<<"X2= ";                           
		        cin>>x2;
		        cout<<"Y2= ";                           
		        cin>>y2;
			cout<<"X3= ";                           
		        cin>>x3;
		        cout<<"Y3= ";                           
		        cin>>y3;
			cout<<"X4= ";                           
		        cin>>x4;
		        cout<<"Y4= ";                           
		        cin>>y4;
		bandera=puntoscolineales(x1,x2,x3,x4,y1,y2,y3,y4);
		if(bandera==true){
			bandera=puntoscolineales(x1,x2,x4,x3,y1,y2,y4,y3);
		}
		//
		if(bandera==true){
			//		
			diagonal=valordiagonal(x1,x4,y1,y4);
			cout<<endl<<" Lados del trapezoide: "<<endl;
			imprimir(x1,x2,y1,y2);
			imprimir(x1,x3,y1,y3);
			imprimir(x3,x4,y3,y4);
			imprimir(x4,x2,y4,y2);
			cout<<endl<<" Triangulo uno: "<<endl;
			imprimir(x1,x3,y1,y3);
			imprimir(x1,x4,y1,y4);
			imprimir(x3,x4,y3,y4);
			double area1=triangulo(x1,x3,x4,y1,y3,y4);
			cout<<endl<<" Triangulo dos: "<<endl;
			imprimir(x1,x2,y1,y2);
			imprimir(x1,x4,y1,y4);
			imprimir(x2,x4,y2,y4);
			double area2=triangulo(x1,x2,x4,y1,y2,y4);
			area1+=area2;
			cout<<endl<<"El área del trapezoide es: "<<area1<<endl;
		}else{
			cout<<"Ingresó mal los puntos, vuelva a compilar"<<endl;
		}									
	}else{
		cout<<"Escribió otro dato, vuelva a ejecutar"<<endl;
	} 	


}
