#include "ArBin.h"
typedef Arbin DicBin;


/*********************************Funcion InsOrd******************************/
//Toma como entrada elemento por elemento que se quiere ingresar al arbol, y el Arbol en cuestión.
DicBin InsOrd (Elem e, DicBin a)
{
  //Si el arbol es vacio, solo se inserta el elemento en el hijo izquierdo
  if (esvacio (a)) 
    return cons (e, vacio (), vacio ());
  //Si el árbol no es vacio, se evalua si el elemento a ingresar es menor a la raiz del arbol
  else if (EsMenor (e, raiz (a)))
    //Si lo es, se ingresa el nuevo elemnto en el hijo izquierdo
    return cons (raiz (a), InsOrd (e, izquierdo (a)), derecho (a));
  else
    //Si es mayor o igual, se ingresa el elemento en la hoja derecha
    return cons (raiz (a), izquierdo (a), InsOrd (e, derecho (a)));
}
