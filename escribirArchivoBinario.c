#include <stdio.h>
#include <stdlib.h>

struct persona {
	char nombre[100];
	unsigned int edad;

};

int main(int argc, const char * argv[]) {
	FILE * out;
	char buffer[100];

	if (argc < 2) {//si no le pasan parametros al programa
		printf("Indique el nombre del archivo de salida\n");
		return -1;
	}
	if(!(out = fopen(argv[1], "w"))) { //recibe el nombre del archivo a crear
		printf("No puedo escribir el archivo %s\n", argv[1]);
		return -2;
		
	}
	struct persona p; //creando un struct para guardar datos de persona
	do {
		printf("Ingrese el nombre de la persona:");
		scanf("%99s", p.nombre);
		printf("Ingrese la edad de la persona");
		scanf("%d", &(p.edad));
		fwrite(&p, sizeof(struct persona), 1, out);
		printf("Grabado! Quiere grabar otra? (s/n) ");
		scanf("%1s", buffer);
	} while(buffer[0] != 'n'); //sigue ingresando datos hasta que se ingrese n

	fclose(out);
	return 0;	
	
}
