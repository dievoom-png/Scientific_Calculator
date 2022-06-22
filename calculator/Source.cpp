#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Stack
{
	char* arr;
	int sp;
	int size;

	Stack()
	{
		arr = NULL;
		sp = -1;
		size = 0;
	}
};

bool initialize(Stack* s, int n)
{
	s->arr = (char*)malloc(sizeof(char) * n);
	if (s->arr == NULL)
		return false;
	s->size = n;
	return true;
}

int push(Stack* s, char item)
{
	if (s->arr == NULL)
		return -1;
	if (s->sp + 1 == s->size)
		return -2;
	s->sp++;
	s->arr[s->sp] = item;
	return 1;
}

int pop(Stack* s, char* item)
{
	if (s->arr == NULL)
		return -1;
	if (s->sp == -1)
		return -2;
	*item = s->arr[s->sp];
	s->sp--;
	return 1;
}

bool isEmpty(Stack s)
{
	if (s.sp == -1)
		return true;
	return false;
}
bool peek(Stack s, char* item)
{
	if (s.arr == NULL)
		return false;
	if (s.sp == -1)
		return false;
	*item = s.arr[s.sp];
	return true;
}

int getP(char op) {
	if (op == '^')
		return 3;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else 
		return 0;
}
struct fStack
{
	float* arr;
	int sp;
	int size;

	fStack()
	{
		arr = NULL;
		sp = -1;
		size = 0;
	}
};

bool finitialize(fStack* fs, int n)
{
	fs->arr = (float*)malloc(sizeof(float) * n);
	if (fs->arr == NULL)
		return false;
	fs->size = n;
	return true;
}

int fpush(fStack* s, float item)
{
	if (s->arr == NULL)
		return -1;
	if (s->sp + 1 == s->size)
		return -2;
	s->sp++;
	s->arr[s->sp] = item;
	return 1;
}

int fpop(fStack* s, float* item)
{
	if (s->arr == NULL)
		return -1;
	if (s->sp == -1)
		return -2;
	*item = s->arr[s->sp];
	s->sp--;
	return 1;
}

bool fisEmpty(fStack s)
{
	if (s.sp == -1)
		return true;
	return false;
}
bool fpeek(fStack s, float* item)
{
	if (s.arr == NULL)
		return false;
	if (s.sp == -1)
		return false;
	*item = s.arr[s.sp];
	return true;
}
int main() {
	Stack s;
	initialize(&s, 100);
	char infix[100];
	char postfix[100];
	int index = 0;
	scanf("%s", &infix);
	for (int i = 0; i < strlen(infix); i++) 
	{
		if (infix[i] >= '0' && infix[i] <= '9')
		{
			postfix[index++] = infix[i];
		}
		else if (infix[i] == '(')
			push(&s, infix[i]);
		else if (infix[i] == ')') {
			char temp;
			peek(s, &temp);
			while (temp != '(') {
				pop(&s, &postfix[index++]);
				peek(s, &temp);
			}
			pop(&s, &temp);
		}
		else {
			char temp;
			peek(s, &temp);

			while (isEmpty(s) != true && getP(infix[i]) <= getP(temp))
			{
				pop(&s, &postfix[index++]);
				peek(s, &temp);
				


			}
			push(&s, infix[i]);
		}
	}
	while (!isEmpty(s))
		pop(&s, &postfix[index++]);//empties the stack
		postfix[index] = '\0';
		printf("the postfix is:");
	puts(postfix);

	fStack fs;
	finitialize(&fs, 100);
	for (int i = 0; i < strlen(postfix); i++)
	{
		if(postfix[i] >= '0' && postfix[i] <= '9')
			fpush(&fs,postfix[i]-'0');
		else {
			if (postfix[i] == '+')
			{
				float lhs, rhs;
				fpop(&fs, &rhs);
				fpop(&fs, &lhs);
				float res = lhs + rhs;
				fpush(&fs, res);
			}
			else if (postfix[i] == '-')
			{
				float lhs, rhs;
				fpop(&fs, &rhs);
				fpop(&fs, &lhs);
				float res = lhs - rhs;
				fpush(&fs, res);
			}
			else if (postfix[i] == '^')
			{
				float lhs,  rhs;
				fpop(&fs, &rhs);
				fpop(&fs, &lhs);
				float res = pow(lhs, rhs);
				
				fpush(&fs, res);
			}
			else if (postfix[i] == '*')
			{
				float lhs, rhs;
				fpop(&fs, &rhs);
				fpop(&fs, &lhs);
				float res = lhs * rhs;
				fpush(&fs, res);
			}
			else if (postfix[i] == '/')
			{
				float lhs, rhs;
				fpop(&fs, &rhs);
				fpop(&fs, &lhs);
				float res = lhs / rhs;
				fpush(&fs, res);
			}
			else
			{
				printf("Error");
			}
		}
	}
	float temp;
	fpop(&fs, &temp);
	printf("The result is %f", temp);
	return 0;
}