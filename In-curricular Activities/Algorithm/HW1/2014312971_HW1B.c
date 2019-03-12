#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//2014312971 ÀÌ¿µ°Ç
#define MAX_STACK 100
typedef enum { false, true } bool;
typedef int Data;

typedef struct
{
	Data items[MAX_STACK];
	int top;
}Stack;

void initStack(Stack *pstack);
bool isFull(Stack *pstack);
bool isEmpty(Stack *pstack);

Data Peek(Stack *pstack);
Data Pop(Stack *pstack);
void Push(Stack *pstack, Data item);
int Calculator(char *str, int len);
int OctToDec(int oct);
int StringToArray(char* str);

int arr[50];
int main()
{
	char s[1000];
	scanf(" %[^\n]s ", s);						//get input from user, including space
	fflush(stdin);								//clear the buffer
	printf("%0.4o", Calculator(s, strlen(s)));

	return 0;
}

int index = 0, idx = 0;							//using global variables to have same variables in different functions.
int Calculator(char *exp, int len)				
{
	Stack stack;
	int op1, op2, temp;
	initStack(&stack);
	for (index = 0; index < len; ) {
		//Push operand(number) using StringToArray function.
		if (exp[index] != '+' && exp[index] != '-' && exp[index] != '*' && exp[index] != '/' && exp[index] != '%')//operand ->Push
		{
			Push(&stack, StringToArray(exp));
			index += 2;												//considering the space. index has to be +=2.
		}
		else {
			// Evaluate an operator according to its own property and Push the result back.
			op2 = Pop(&stack);
			op1 = Pop(&stack);
			if (exp[index] == '+')
				Push(&stack, op1 + op2);
			else if (exp[index] == '-')
				Push(&stack, op1 - op2);
			else if (exp[index] == '*')
				Push(&stack, op1 * op2);
			else if (exp[index] == '/')
				Push(&stack, op1 / op2);
			else if (exp[index] == '%')
				Push(&stack, op1 % op2);
			if (Peek(&stack) > 4095)
				Push(&stack, Pop(&stack) % 4096);		//discarding carry. if the value is larger than 4096 in decmial number, it should be modified; %4096.
			index+=2;
		}
	}

	return Peek(&stack);
}


int StringToArray(char * str)	//convert 'char' to 'int' in decimal form. Use the property of 8-base number - 8^3 for first digit, 8^2 for second digit ,,,
{
	arr[idx] = (str[index]-48) * 8 * 8 * 8;
	arr[idx] += (str[++index]-48) * 8 * 8;
	arr[idx] += (str[++index]-48) * 8;
	arr[idx] += (str[++index]-48);


	return arr[idx++];						//save the converted 
}

//stack operations
void initStack(Stack *pstack)
{
	pstack->top = -1;
}
bool isFull(Stack *pstack)
{
	return pstack->top == MAX_STACK;
}
bool isEmpty(Stack *pstack)
{
	return pstack->top == -1;
}

Data Peek(Stack *pstack)
{
	if (isEmpty(pstack)) {
		printf("The stack is empty");
		exit(1);
	}
	else
		return pstack->items[pstack->top];
}
Data Pop(Stack *pstack)
{
	if (isEmpty(pstack)) {
		printf("The stack is empty");
		exit(1);
	}
	else
		return pstack->items[(pstack->top)--];
}
void Push(Stack *pstack, Data item)
{
	if (isFull(pstack)) {
		printf("The stack is full");
		exit(1);
	}
	else
		pstack->items[++(pstack->top)] = item;

}

