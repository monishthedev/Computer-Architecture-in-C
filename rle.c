#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char **argv) {
    int place=0;
    int letSize=0;
    place++;    place--;
    for(int i = 0; i < strlen(argv[1]); i++) {
		//look at current value
        if(isdigit(argv[1][i])) {
			printf("Error");
			return 0;
        }
		//reset amount
        int amount =1;
        while(argv[1][i] == argv[1][i+1]) {
            amount++;
            i++;
        }
		//temporary variable
        char change[5];
        sprintf(change,"%c%d",argv[1][i],amount);
        letSize+=strlen(change);  
    }
    if(letSize>strlen(argv[1])){
        printf("%s",argv[1]);
    }
    else if(letSize <= strlen(argv[1])&&!place){
        for(int i = 0; i < strlen(argv[1]); i++) {
			//amount reset
            int amount = 1;
            while(argv[1][i]== argv[1][i+1]) {
                amount++;
                i++;
            }
            printf("%c%d",argv[1][i],amount);
        }
    }
    return 0;
}
