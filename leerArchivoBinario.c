#include <stdio.h>
#include <stdlib.h>

struct persona {
	char nombre[100];
	unsigned int edad;

};

int main(int argc, const char * argv[]) {
	FILE * in;
	char buffer[100];

	if (argc < 2) {
		printf("Indique el nombre del archivo de entrada\n");
		return -1;
	}
	if(!(in = fopen(argv[1], "r"))) {
		printf("No puedo leer el archivo %s\n", argv[1]);
		return -2;
		
	}
	struct persona p;
    while (fread(&p, sizeof(struct persona),1, in)) {
            printf("%s tiene %d anios\n", p.nombre, p.edad);
    }
	

	fclose(in);
	return 0;	
	
}
