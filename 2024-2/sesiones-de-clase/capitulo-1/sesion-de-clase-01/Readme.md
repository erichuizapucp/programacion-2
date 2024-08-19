# Sesión de clase 01
En esta sesión se hizo una revisión de punteros y arreglos. Así como una revisión del paso de punteros por valor o referencia.

##Variables y Punteros
```cpp
int a = 5;
int* p = &a; // El valor de p ahora es la dirección de memoria de a.
*p = 6; // Se modifica el dato al que apunta p. Ahora a es 6.
a = 7; // Se modifica a. Ahora *p es 7.
cout << *p << endl; // Imprime 7.
cout << &a << endl; // Imprime la dirección de memoria de a.
```

##Aritmética de Punteros y Arreglos
```cpp
const int num = 3;
int dnis[num + 1] { 12345678, 56738494, 18349578, -1 };

int *pa = dnis; 
cout << *pa << endl; // Imprime 12345678.
pa++; // Se mueve al siguiente elemento del arreglo.
cout << *pa << endl; // Imprime 56738494.
pa = &dnis[2]; // El puntero pa ahora contiene la dirección de memoria del tercer elemento.
cout << *pa << endl; // Imprime 18349578.
```

##Recorrido de un Arreglo usando Aritmética de Punteros
```cpp
for (int* pa = dnis; *pa != -1; pa++) {
    cout << *pa << endl;
}
```

##Memoria Dinámica
Asignación y liberación de memoria dinámica en el heap.

```cpp
int *d = new int; // El puntero d apunta a un entero en el heap.
*d = 5;
cout << *d << endl; // Imprime 5.
delete d; // Libera la memoria asignada dinámicamente.
```
##Arreglos Dinámicos
Asignación y liberación de memoria para un arreglo en el heap.

```cpp
int* numEnteros = new int[4] { 1, 2, 3, -1 };
for (int* pnums = numEnteros; *pnums != -1; pnums++) {
    cout << *pnums << endl;
}
delete[] numEnteros; // Libera la memoria asignada al arreglo.
```

##Función porValor
Esta función toma un puntero como parámetro y lo modifica. Sin embargo, dado que el puntero se pasa por valor, cualquier cambio en la dirección a la que apunta no afecta al puntero original fuera de la función.

```cpp
void porValor(int* x) {
    *x = 80; // Cambia el valor al que apunta el puntero a 80.
    x = new int; // El puntero apunta a una nueva dirección en el heap.
    *x = 100; // El dato en esa nueva dirección es 100.
}
```

##Función porReferencia
Esta función toma una referencia a un puntero como parámetro, lo que significa que cualquier cambio en la dirección a la que apunta afectará al puntero original fuera de la función.
```cpp
void porReferencia(int*& x) {
    *x = 80; // Cambia el valor al que apunta el puntero a 80.
    x = new int; // El puntero apunta a una nueva dirección en el heap.
    *x = 100; // El dato en esa nueva dirección es 100.
}
```

##Ejemplo de Paso por Valor y Referencia
```cpp
int* g = new int(10);
porValor(g);
cout << *g; // Imprime 80, porque en la función porValor x es pasado por valor.

porReferencia(g);
cout << *g; // Imprime 100, porque en la función porReferencia x es pasado por referencia.
```

## Recursos
Memoria RAM: [Heap y Stack](https://www.youtube.com/watch?v=a17EyMjGcdc)

Memoria RAM: [Segmentos de memoria](https://medium.com/@human_fsi/different-memory-segments-when-a-typical-program-is-executed-3bc9472d93c8)


