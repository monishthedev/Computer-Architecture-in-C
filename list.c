#include <stdio.h>
#include <stdlib.h>
//common node definition
struct Node{
    int data;
    struct Node *next;
};

// initial empty head
struct Node *head = NULL;
//common LL methods for modifying, accessing, deleting, printing
struct Node *insertNode(struct Node* newNode, int checkKey){

    if(head == NULL){
        head = newNode;
        return head;
    }
    else if(head ->data > newNode -> data){
        newNode ->next = head;
        head = newNode;
        return head;
    }
    else{
    struct Node *change = head;
    while(change->next != NULL && change -> next -> data < newNode -> data){
        change = change->next;
}
    newNode -> next = change -> next;
    change -> next = newNode;
    }

    return head;
}

void deleteNode(int checkKey){
    if(head == NULL){
        return;
    }

    struct Node *ptr = NULL;
    struct Node *one;
    struct Node *back;

    if(head ->data == checkKey){
        ptr = head->next;
        free(head);
        head = ptr;
        return;
    }

    one = head->next;
    back = head;

    while(one != NULL){
        if(one->data == checkKey){
            //replace present node
            struct Node *newNode = one;
            back->next = one->next;
            free(newNode);
            return;
        }
        one = one->next;
        back = back->next;
    }

    return;
}
void printLL(){
    struct Node *one = head;
    while(one != NULL){
        if(one ->next == NULL){
            printf("%d", one ->data);
            break;
        }
        //prints present list
        printf("%d ", one ->data);
        one = one->next;
    }
    return;
}
//checks for existence m
int checker(int checkKey){
    int amount = 0;
    struct Node *change = head;
    while(change != NULL){
        if(change -> data == checkKey){
            amount = 1;
        break;
        }
    change = change -> next;
    }
    return amount;
}



int main(int argc, char *argv[]){
    if(argc < 1){
        //less argument 
        printf("Not enough arguments");
       return EXIT_SUCCESS;
    }
    if(argc == 1){
    char let;
    int actual = 0, number;
    //takes in all of the available lists
        while(scanf("%c\t%d", &let, &number) != EOF){
            int presentNum = checker(number);
            if(let == 'i'){
                if(presentNum == 0){
					//reallocation of val
                    struct Node *secondary = (struct Node*)malloc(sizeof(struct Node));
                    secondary->data = number;
                    secondary->next = NULL; 
                    head = insertNode(secondary, number);
                    actual++; 
                }
                if(actual == 0){
                    printf("%d :", actual);
                    printLL();
                    printf("\n");
                }
                else{ 
                    printf("%d : ", actual);
                    printLL();
                    printf("\n");
                }
            }   
            if(let == 'd'){
                if(presentNum== 1){
                    actual--;
                        deleteNode(number);
                }
                if(actual == 0){
                    printf("%d :", actual);
                    printLL();
                    printf("\n");
                }
                else{ 
                    printf("%d : ", actual);
                    printLL();
                    printf("\n");
                }
            }   
        }   
    }   
    return EXIT_SUCCESS;
}
