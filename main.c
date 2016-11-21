#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){
	
	int filas = 1024;
	int conlumnas = 1024;
	int matrix[filas][conlumnas];
	int i, j;
	//llenar la matriz de ceros
		for(j=1; j<1024; j++){
			matrix[i][j] = 0;
			//printf("%d ", matrix[i][j]); // imprime elemento de matriz
		}
	
	
	FILE* fp;
	char* filename;
	char ch;

	char num_char;
	char num2_char;
	int num2_int;
	int num_int;

	char single_line[150];
	// check if a filename has been specified in the command

	if(argc < 2){

		printf("Missing filename\n");
		exit(-1);
		return 1;

	} else {
		filename = argv[1];
		//printf("Filename: %s\n", filename);
	}

	// Open file in read-only mode
	fp = fopen(filename, "r");

	// if the file opens succesfully, then prints contents
	int renglones = 0;
	if(fp){
		while(!feof(fp)){
			fgets(single_line, 150, fp);
			int index = 0;
			
			while(single_line[index] && (renglones == 0)){
				//printf("%c \n",single_line[index]);

				if(isalpha(single_line[index])){
					// busqueda de vectores
					
					//cant_nodos_char[0] = '1';
					
					// printf("%c \n", single_line[index]);
					while(isalpha(single_line[index]) || single_line[index] == '=' || single_line[index] == ' '){
						index++;
					}
					int cant_nodos_index = 0;
					char cant_nodos_char[3];
					while(single_line[index] != '\n'){
						
						
						cant_nodos_char[cant_nodos_index] = single_line[index];
						//printf("Cant nodos char:  %c\n",cant_nodos_char[cant_nodos_index] );
						index++;
						cant_nodos_index++;
					}
					printf(" cantidad de vertices %s\n",cant_nodos_char);
					int vertices = atoi(cant_nodos_char);
					printf("%d \n", vertices);
				}

				index++;
				renglones++;
				printf(" ulti %c  \n",single_line[index+8]);
			}
		}
	}else{
		printf("Failed to open the file.\n");
	} // end of else failed to open file  

	
	return(0);
}



