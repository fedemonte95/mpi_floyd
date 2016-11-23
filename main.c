#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int get_cantidad_vertices(char pfilename[]){
	FILE* fp;
	char single_line[150];
	char cant_nodos_char[4];
	int renglones = 0;
	int index;
	int cant_nodos_index;
	int vertices;
	fp = fopen(pfilename, "r");
	while(!feof(fp)){
		fgets(single_line, 150, fp);
			index = 0;
			while(single_line[index] && (renglones == 0)){
				if(isalpha(single_line[index])){
					while(isalpha(single_line[index]) || single_line[index] == '=' || single_line[index] == ' '){
						index++;
					}
					cant_nodos_index = 0;
					while(single_line[index] != '\n'){
						cant_nodos_char[cant_nodos_index] = single_line[index];
						index++;
						cant_nodos_index++;
					}
					vertices = atoi(cant_nodos_char);
				}
					index++;
					renglones++;
			}
	}
	fclose(fp);
	return(vertices);
}

int main(int argc, char* argv[]){
	FILE* 	fp;
	char* 	filename;
	char 	single_line[150];
	char 	num_char[4];
	char 	num2_char[4];
	int 	num2_int;
	int 	num_int;
	int 	number_index;
	int 	cant_vertices;
	int 	renglones;
	int 	index;
	int 	i, j;
	if(argc < 2){
		printf("Missing filename\n");
		exit(-1);
		return 1;
	} else {
		filename = argv[1];
		cant_vertices = get_cantidad_vertices(filename);
		//llenar la matriz de ceros
		//printf(" Cantidad de vertices %d\n", cant_vertices);
	}

	int matrix[cant_vertices][cant_vertices];
	for(i=0; i <cant_vertices; i++){
		for(j=0; j<cant_vertices; j++){
		matrix[i][j] = 0;
		}
	}
	
	fp = fopen(filename, "r"); // Opens file in read-only mode
	if(fp){ // if the file opens succesfully, then prints contents
		int renglon = 0;
		while(!feof(fp)){
			fgets(single_line, 150, fp);
			index = 0;
			while(single_line[index]){
				if (single_line[index] == '(') { // si encuentra un parentesis abierto
					//printf("Encontro parentesis abierto \n");
					index++; // aumenta una posicion para ver numero
					number_index = 0;
					// empieza concatenacion de primer numero char
					while(single_line[index] != ','){
						// mientras el indice del renglon sea un numero y diferente de , concatenamos la posicion del numero
						num_char[number_index] = single_line[index];
						index++;
						number_index++;
					}
					num_int = atoi(num_char);  
					// ahora a buscar el segundo numero de la tupla
					index++;
					number_index = 0;
					strcpy(num2_char, " ");
					num2_char[3] = ' ';
					while(single_line[index] != ')'){
						num2_char[number_index] = single_line[index];
						index++;
						number_index++;
					}
					num2_int = atoi(num2_char);
					matrix[num_int][num2_int] = 1;
					//printf("%d\n", num2_int);
					
				}// end of if 
				index++;
			}
			renglon++;
		} // while principal 
		for(i=0; i <cant_vertices; i++){
			for(j=0; j<cant_vertices; j++){
				printf("%d, ", matrix[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("Failed to open the file.\n");
	} // end of else failed to open file  
	return(0);
}