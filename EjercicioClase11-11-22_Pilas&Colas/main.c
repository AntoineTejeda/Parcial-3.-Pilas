#include <stdio.h>
#include <stdlib.h>
#define N 6
typedef struct
{
    int pila[N];
    int tope;
    int tam;
}Tpila;
typedef struct
{
    int cola[N];
    int ini, fin;
    int tam;
}Tcola;

void IncializaPila(Tpila *p, int tam);
int PilaVacia(Tpila p);
int PilaLlena(Tpila p);
int push(Tpila *p, int n);
int pop(Tpila *p, int *n);
void InicializaCola(Tcola*co,int tam);
int colaLlena(Tcola co);
int colaVacia(Tcola co);
int enqueue(Tcola * co, int n);
int dequeue(Tcola *co, int *n);
void AtiendeYDespacha(Tpila p, Tcola co,int Clientes[], int Sandwich[]);



int main()
{
    Tpila p;
    Tcola co;
    int tam=6, Sandwich[N]={1,1,1,0,1,0,0};
    int Clientes[N]={0,1,1,0,1,0,1};
    InicializaCola(&co,tam);
    IncializaPila(&p,tam);
    for(int i=0;i<N;i++)
    {
        push(&p,Sandwich[i]);
        enqueue(&co,Clientes[i]);
    }
    AtiendeYDespacha(p,co,Clientes,Sandwich);
    if(!PilaLlena(p))
    {
        printf("La pila esta vacia");
    }
}
void AtiendeYDespacha(Tpila p, Tcola co,int Clientes[],int Sandwich[])
{
    int cont=0;
    while(!PilaVacia(p)&&!colaVacia(co))
    {
        if(p.pila[p.tope-1]==co.cola[cont])
        {
            printf("\n");
            printf("%d\t",p.tope-1);
            printf("%d\t",co.ini);
            pop(&p,&Clientes[cont]);
            dequeue(&co,&Sandwich[cont]);
            printf("%d\t",co.cola[co.ini]);
        }
        if(p.pila[p.tope-1]!=co.cola[cont])
        {
            co.cola[cont]=co.cola[co.fin];
        }
        cont++;
    }
    printf("%d",cont);

}


//PILAS
void IncializaPila(Tpila *p, int tam)
{
    p->tam=tam<=N?tam:N;
    p->tope=0;
}

int PilaVacia(Tpila p)
{
    int reg=1;
    if(p.tope>0)
        reg=0;
    return(reg);
}
int PilaLlena(Tpila p)
{
    int reg=1;
    if(p.tope<p.tam)
        reg=0;
    return(reg);
}
int push(Tpila *p, int n)
{
    int reg=0;
    if(!PilaLlena(*p))
    {
        p->pila[p->tope]=n;
        p->tope++;
        reg=1;
    }
    return(reg);
}
int pop(Tpila *p, int *n)
{
    int reg=0;
    if(!PilaVacia(*p))
    {
        p->tope--;
        *n=p->pila[p->tope];
        reg=1;
    }
    return(reg);

}
//colas
void InicializaCola(Tcola*co,int tam)
{
    co->tam=tam=N?tam:N;
    co->ini=co->fin=0;
}

int colaVacia(Tcola co)
{
    int reg;
    reg = co.ini == co.fin ? 1 : 0;
    return(reg);
}
int colaLlena(Tcola co)
{
    int reg;
    reg = (co.fin + 1) % co.tam == co.ini? 1:0;
    return(reg);
}
int enqueue(Tcola * co, int n)
{
    int reg = 0;
    if(!colaLlena(*co))
    {
        co->cola[co->fin] = n;
        co->fin = (co->fin + 1) % co->tam;
        reg = 1;
    }
    return(reg);
}
int dequeue(Tcola *co, int *n)
{
    int reg = 0;
    if(!colaVacia(*co))
    {
        *n = co->cola[co->ini];
        co->ini = (co->ini + 1) % co->tam;
        reg = 1;
    }
    return(reg);
}
