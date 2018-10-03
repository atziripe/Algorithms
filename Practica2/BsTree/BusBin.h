#include "ArBin.h"
typedef Arbin DicBin;


DicBin
InsOrd (Elem e, DicBin a)
{
  if (esvacio (a))
    return cons (e, vacio (), vacio ());
  else if (EsMenor (e, raiz (a)))
    return cons (raiz (a), InsOrd (e, izquierdo (a)), derecho (a));
  else
    return cons (raiz (a), izquierdo (a), InsOrd (e, derecho (a)));
}
