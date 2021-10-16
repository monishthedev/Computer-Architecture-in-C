#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

void push(char stack[], char element, int *topStack) {
    stack[*topStack] = element;
    *topStack++;
}

char peekStack(char stack[], int *topStack) {
    return stack[*topStack--];
}

char pop(char stack[], int *topStack) {
    if (*topStack == 0) 
        // Stack is empty
        return '\0';
    *topStack = *topStack - 1;
    char popVar = stack[*topStack];
    return popVar;
}

int checkCounter(char thisVal, char popVal) {
    if ((thisVal == ')' && popVal == '(') || 
        (thisVal == '}' && popVal == '{') ||
        (thisVal == ']' && popVal == '[')){
        return 1;
    }
    return 0;
}

char braceCounter(char brace) {
    if (brace == '('){
        return ')';
    } 
    if (brace == '{'){
        return '}';
    } 
    if (brace == '['){
        return ']';
    } 

    printf("\nError in the input");
    exit(0);
}

int checkBalance(const char *inpStr) {
   char stack[strlen(inpStr)];
   int topStack = 0;
   int *topStackptr = &topStack;
   int indexVal = 0;
   while(inpStr[indexVal] != '\0') {
        char thisVal = inpStr[indexVal];
        if (thisVal == '(' || thisVal == '{' || thisVal == '['){
            push(stack, thisVal, topStackptr);
        }
        else if (thisVal == ')' || thisVal == '}' || thisVal == ']') {
            char poppedBrace = peekStack(stack, topStackptr);
            if (!checkCounter(thisVal, poppedBrace)) {
                printf("%d: %c", indexVal, thisVal);
                return EXIT_FAILURE;
            }
            pop(stack, topStackptr);
        }
        indexVal++;
   }
    if (topStack == 0) {
        return EXIT_SUCCESS;
    }

   while (topStack != 0) {
        char topStackBrace = pop(stack, topStackptr);
        printf("%c", braceCounter(topStackBrace));
    }
    return EXIT_FAILURE;
}

int main(int argc, char **argv) {
    char *actStr = argv[1];
    int result = checkBalance(actStr);
    return result;
}