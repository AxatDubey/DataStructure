#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
     char data;
     struct node *next;
} *first = NULL;

void push(char x)
{
     struct node *p;
     first = (struct node *)malloc(sizeof(struct node));
     if (first == NULL)
     {
          printf("stack is full\n");
     }
     else
     {
          p->data = x;
          p->next = first;
          first = p;
     }
}
char pop()
{
     struct node *p;
     char x = -1;
     if (first == NULL)
     {
          printf("stack is empty");
     }
     else
     {
          p = first;
          first = first->next;
          x = p->data;
          free(p);
     }
     return x;
}
int isOperatore(char x)
{
     if (x == ')' || x == '}' || x == ']' || x == '(' || x == '+' || x == '-' || x == '/' || x == '*' || x == '{' || x == '[' || x == '^')
     {
          return 1;
     }
     else
     {
          return 0;
     }

     // if (x == ')' || x = '}' || x == ']')
     // {
     //      return 2;
     // }
}

int pre(char x)
{
     if (x == '+' || x == '-')
          return 1;
     else if (x == '*' || x == '/')
          return 2;
     else if (x == '^')
          return 3;
     if (x == '[' || x == '{' || x == '(')
          return 4;
    
    return 0 ;
}
char *InTopost(char *infix)
{
     int i = 0, j = 0;
     char *postifix;
     int len = strlen(infix);
     postifix = (char *)malloc((len + 2) * sizeof(char));
     while (infix[i] != '\0')
     {
          if (isOperatore(infix[i]))
          {
               postifix[j++] = infix[i++];
          }
          else
          {
               if (pre(infix[i]) > pre(first->data))
               {
                    push(infix[i++]);
               }
               else
               {
                    if (pre(infix[i]) ==4)
                    {
                         pop();
                    }
                    postifix[j++] = pop();
               }
          }
     }
     while (first != NULL)
     {
          if (pre(infix[i]) == 4)
          {
               pop();
          }
          postifix[j++] = pop();
     }
     postifix[j] = '\0';

     return postifix;
}

int main()
{
     char *infix = "((a+b)*c)-d^e^f";
     push('#');

     char *postfix = InTopost(infix);
     printf("%s", postfix);

     return 0;
}
