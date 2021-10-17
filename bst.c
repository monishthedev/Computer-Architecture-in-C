#include <stdio.h>
#include <stdlib.h>
//modifying node type
typedef struct Node{
	int amount;
	struct Node* left;
	struct Node* right;
}
Node;
//prints node desired
//test node present
void printer(Node* initNode){
	if(initNode == NULL){
		return;
	}
	printer(initNode->left);
	printf("%d\t", initNode->amount);
	printer(initNode->right);
	free(initNode);
}

int main(int argc, char* argv[]){
	//creating file with arguments passed to utilize within code
	FILE* util = fopen(argv[1], "r");
	//if arguments have no value
	if(util == NULL){
		fclose(util);
		printf("error\n");
		return 0;
	}
	
	Node* headNode = NULL;
	int info;

	while(fscanf(util, "i\t%d\n", &info) == 1){
		Node* changer = (Node*)malloc(sizeof(Node));
		changer->amount = info;
		changer->right = NULL;
		changer->left = NULL;
		if(headNode == NULL){
			headNode = changer;
			continue;
		}
		else{

			Node* secondary = NULL;
			Node* presptr = headNode;
			//loop through nodes until we see empty or reach bottom of tree
			while(presptr!= NULL){
				secondary = presptr;
				if(presptr->amount < changer->amount){
					presptr = presptr->right;
				}
				else if(presptr->amount > changer->amount){
					presptr = presptr->left;
				}
				else{
					break;
				}
			}
			//rids of temp variable
			if(presptr != NULL){
				free(changer);
				continue;
			}
			else{
				if(changer->amount> secondary->amount){
					secondary->right = changer;
				}
				else{
					secondary->left = changer;
				}
			}	
		}
	}
	printer(headNode); printf("\n");
	//closes object(s)
	fclose(util);
}