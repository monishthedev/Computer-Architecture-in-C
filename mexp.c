#include <stdio.h>
#include <malloc.h>
int main(int argc, char *argv[]) {
   if(argc == 2) {
	   //creating file with arguments passed to utilize within code
   	FILE *inp = fopen(argv[1], "r");
   	if(inp) {
		   //matrix param
   		int i;
   		int j;
   		int k; 
   		int l; 
   		int n; 
   		int o; 
   		int sum = 0;
   		int **first, **second, **tempo;
   		fscanf(inp, "%d", &n);
   		first = (int **)malloc(sizeof(int *)*n);
   		second = (int **)malloc(sizeof(int *)*n);
   		for(i = 0; i < n; ++i) {
   			first[i] = (int *)malloc(sizeof(int)*n);
   			second[i] = (int *)malloc(sizeof(int)*n);
   		}
   		for(i = 0; i < n; ++i) {
   			for(j = 0; j < n; ++j) {
   				fscanf(inp, "%d", &first[i][j]);
   			}
   		}
   		fscanf(inp, "%d", &o);
   		for(i = 0; i < o-1; ++i) {
   			for(j = 0; j < n; ++j) {
   				for(k = 0; k < n; ++k) {
   					sum = 0;
   					for(l = 0; l < n; ++l) {
   						sum += first[j][l] * first[l][k];
   					}
   					second[j][k] = sum;
   				}
   			}
   			//replacement
   			tempo = first;
   			first = second;
   			second = tempo;
   		}
   		for(i = 0; i < n; ++i) {
   			for(j = 0; j < n; ++j) {
   				printf("%d ", first[i][j]);
   			}
   			printf("\n");
   		}
		   //present file
   		fclose(inp);
   	}
   }
}