#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct yigin
{
    char isaret;
    struct yigin *next;
    struct yigin *prev;
}yigin;
struct yigin *head=NULL;
struct yigin *tail=NULL;
struct yigin *p;
void push(char in)
{
    //struct yigin *p=(struct yigin*)malloc(sizeof(struct yigin));
    //p->isaret=malloc(sizeof(char));
    if(head==NULL)
    {
        p=head;
        p->isaret=in;
        p=tail;
        p->next=tail;
        p->prev=head;
        return;
    }
    p=tail->next;
    p->isaret=in;
    p->prev=tail;
    tail=p;
}
void pop()
{
    struct yigin *p=(struct yigin*)malloc(sizeof(struct yigin));
    if(head==NULL)
    {
        printf("yigin bos\n");
        return;
    }
    p=tail;
    tail=p->prev;
    free(tail);
}
int degerler(char isaret)
{
    if(isaret == '*' || isaret == '/')
        return 2;
    else if(isaret == '+' || isaret == '-')
        return 1;
    else
        return 0;
}
int main()
{
    struct yigin *p=(struct yigin*)malloc(sizeof(struct yigin));
    char girilen[100];
    char cikti[100];
    int i=0,j=0;
    printf("islemi bosluk birakmadan giriniz\n");
    scanf("%s",&girilen);
    while(girilen[i]!='\0')
    {
        if(girilen=='(')
        {
            push(girilen[i]);
        }
        else if(girilen[i]=='+' || girilen[i]=='-' || girilen[i]=='*' || girilen[i]=='/')
        {
            if(head==NULL)
                push(girilen[i]);
            else
            {
                p=tail;
                while(degerler(p->isaret)>degerler(girilen[i]))
                {
                    cikti[j]=p->isaret;
                    j++;
                    pop();
                }
                push(girilen[i]);
            }
        }
        else if(girilen[i]==')')
        {
            p=tail;
            while(p->isaret!='(')
            {
                cikti[j]=p->isaret;
                j++;
                pop();
            }
            pop();
        }
        else
        {
        cikti[j]=girilen[i];
        j++;
        }
        printf("infix----------stack----------postfix\n");
        int k=i;
        while(girilen[k]!='\0')
        {
            if(girilen[k+1]=='\0')
            {
              break;
            }
            printf("%c",girilen[k+1]);
            k++;
        }
        printf("\t\t");
        p=tail;
        while(p!=head)
        {
            printf("%c",p->isaret);
            p=p->prev;
        }
        if(head!=NULL)
            printf("%c\t\t",p->isaret);
        else
            printf("\t\t");
        printf("%s\n",cikti);
        i++;
    }
    if(head!=NULL)
    {
        p=tail;
        cikti[j]=p->isaret;
        j++;
        pop();
    }

    return 0;
}
