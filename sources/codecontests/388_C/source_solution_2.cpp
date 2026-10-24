#include <bits/stdc++.h>
typedef struct nodo {
  int dato;
  struct nodo *anterior;
  struct nodo *siguiente;
} nodo;
typedef struct pila {
  nodo *primero;
  nodo *ultimo;
} mazos;
void agregar(mazos *mazo, int valor);
void CrearMazo(mazos *mazo, int n);
void imprimir(mazos mazo[], int dim);
void eliminar(mazos *mazo, nodo *actual);
int main() {
  int n, i, j, valor, turno = 1, ciel = 0, mayor, jiro = 0, ban = 1, cont,
                      indice;
  nodo *direccion;
  scanf("%d", &n);
  int x[n];
  mazos mazo[n];
  CrearMazo(mazo, n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    for (j = 0; j < x[i]; j++) {
      scanf("%d", &valor);
      agregar(&mazo[i], valor);
    }
  }
  for (i = 0; i < n; i++) {
    if (x[i] % 2 == 0) {
      while (mazo[i].primero != NULL) {
        if (turno % 2 != 0) {
          ciel += mazo[i].primero->dato;
          eliminar(&mazo[i], mazo[i].primero);
        } else {
          jiro += mazo[i].ultimo->dato;
          eliminar(&mazo[i], mazo[i].ultimo);
        }
        turno++;
      }
    } else {
      while (mazo[i].primero != mazo[i].ultimo) {
        if (turno % 2 != 0) {
          ciel += mazo[i].primero->dato;
          eliminar(&mazo[i], mazo[i].primero);
        } else {
          jiro += mazo[i].ultimo->dato;
          eliminar(&mazo[i], mazo[i].ultimo);
        }
        turno++;
      }
    }
  }
  while (ban == 1) {
    ban = 0;
    indice = -1;
    mayor = 0;
    for (i = 0; i < n; i++) {
      if (mazo[i].primero != NULL) {
        if (turno % 2 == 0) {
          if (mayor < mazo[i].ultimo->dato) {
            mayor = mazo[i].ultimo->dato;
            direccion = mazo[i].ultimo;
            indice = i;
          }
        } else {
          if (mayor < mazo[i].primero->dato) {
            mayor = mazo[i].primero->dato;
            direccion = mazo[i].primero;
            indice = i;
          }
        }
      }
    }
    if (turno % 2 != 0 && indice != -1) {
      ciel += mayor;
      eliminar(&mazo[indice], direccion);
      ban = 1;
    } else if (turno % 2 == 0 && indice != -1) {
      jiro += mayor;
      eliminar(&mazo[indice], direccion);
      ban = 1;
    }
    turno++;
  }
  printf("%d %d", ciel, jiro);
  return 0;
}
void agregar(mazos *mazo, int valor) {
  nodo *nuevo = (nodo *)malloc(sizeof(nodo));
  if (mazo->ultimo != NULL) {
    nuevo->anterior = mazo->ultimo;
    mazo->ultimo->siguiente = nuevo;
  } else {
    nuevo->anterior = NULL;
    mazo->primero = nuevo;
  }
  mazo->ultimo = nuevo;
  nuevo->siguiente = NULL;
  nuevo->dato = valor;
}
void CrearMazo(mazos *mazo, int n) {
  int i;
  for (i = 0; i < n; i++) {
    mazo[i].primero = NULL;
    mazo[i].ultimo = NULL;
  }
}
void imprimir(mazos mazo[], int dim) {
  int i;
  nodo *actual;
  for (i = 0; i < dim; i++) {
    actual = mazo[i].primero;
    while (actual != NULL) {
      printf("%d ", actual->dato);
      actual = actual->siguiente;
    }
  }
}
void eliminar(mazos *mazo, nodo *actual) {
  nodo *temp = (nodo *)malloc(sizeof(nodo));
  if (mazo->ultimo == mazo->primero) {
    mazo->primero = NULL;
    mazo->ultimo = NULL;
    temp = actual;
  } else {
    if (actual->siguiente == NULL) {
      actual->anterior->siguiente = NULL;
      mazo->ultimo = actual->anterior;
    } else {
      actual->siguiente->anterior = NULL;
      mazo->primero = actual->siguiente;
    }
    temp = actual;
  }
  free(temp);
}
