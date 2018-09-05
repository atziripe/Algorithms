#include "Elem.h"
typedef struct Nodo
{
  Elem raiz;
  struct Nodo *izq;
  struct Nodo *der;
} *Arbin;

Arbin
cons (Elem r, Arbin i, Arbin d)
{
  Arbin t = (Arbin) malloc (sizeof (struct Nodo));
  t->raiz = r;
  t->izq = i;
  t->der = d;
  return t;
}

Arbin
vacio ()
{
  return NULL;
}

int
esvacio (Arbin a)
{
  return a == NULL;
}

Elem
raiz (Arbin a)
{
  return a->raiz;
}

Arbin
izquierdo (Arbin a)
{
  return a->izq;
}

Arbin
derecho (Arbin a)
{
  return a->der;
}

void
ImpPreorden (Arbin a)
{
  if (!esvacio (a))
    {
      ImpElem (raiz (a));
      ImpPreorden (izquierdo (a));
      ImpPreorden (derecho (a));
    }
}


void
ImpInorden (Arbin a)
{
  if (!esvacio (a))
    {
      ImpInorden (izquierdo (a));
      ImpElem (raiz (a));
      ImpInorden (derecho (a));
    }
}

void
ImpPostorden (Arbin a)
{
  if (!esvacio (a))
    {
      ImpPostorden (izquierdo (a));
      ImpPostorden (derecho (a));
      ImpElem (raiz (a));

    }
}

int
maximo (int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

int
altura (Arbin a)
{
  if (esvacio (a))
    return 0;
  else
    return 1 + maximo (altura (izquierdo (a)), altura (derecho (a)));
}
