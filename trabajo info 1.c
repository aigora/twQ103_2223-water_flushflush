	#include<stdio.h>
	
	
	float calidad(float);

	int main () {
		
		float TDS; // la conductividad depende de la cantidad disueltos totales(ppm)
		
		printf("introduzca la cantidad disueltos totales(TDS)(ppm) \n");
		scanf("%f",&TDS);
		calidad(TDS);
		
		return 0;
	}
	float calidad(float TDS){
		
		if ( 50 <=TDS && TDS<= 250) {
			printf("Bajo:  Carece de minerales, como calcio, magnesio y zinc\n");
		} else if (300<=TDS && TDS<=500) {
			printf("Ideal: este nivel es el punto óptimo para los TDS en el agua potable. Lo más probable es que el agua contenga minerales y no tenga un sabor plano\n");
		} else if (600<=TDS && TDS<=900) {
			printf("No muy bien:considere un sistema de ósmosis inversa para filtrar TDS.\n");
		} else if (1000<=TDS && TDS<=2000) {
			printf("Malo:no se recomienda beber agua a este nivel de TDS\n");
		} else if (TDS>2000) {
			printf("Inaceptable:Un nivel de TDS superior a 2000 ppm no es seguro y los filtros domésticos no pueden filtrar adecuadamente este nivel de contaminación\n");
		} else {
			printf("Error. cantidad de solidos disuelto totales no esta en el rango");
		}
		return TDS;
	 }

