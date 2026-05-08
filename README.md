# Recorridos de Árboles Binarios

**Universidad Técnica de Ambato**
**Carrera:** Ingeniería de Software
**Asignatura:** Estructura de Datos
**Curso:** Tercero B
**Tema:** Recorridos de árboles binarios: Inorden, Preorden, Postorden y BFS

---

## Descripción general

Este repositorio contiene la implementación de los principales recorridos de árboles binarios utilizando **C++** y **Java**. Se aplican conceptos de estructuras de datos dinámicas, recursividad y colas (BFS), con el objetivo de analizar y comparar el comportamiento de cada recorrido sobre el mismo árbol.

---

## Objetivos

- Implementar y comparar recorridos DFS (Inorden, Preorden, Postorden) y BFS en C++ y Java.
- Aplicar recursividad para los recorridos en profundidad.
- Utilizar una cola para implementar el recorrido por niveles (BFS).
- Adaptar los recorridos a un caso real del proyecto final.

---

## Estructura del repositorio

```
tarea2.2_recorridos_arboles_uta/
├── src/
│   ├── cpp/
│   │   └── main.cpp          # Implementación en C++
│   └── java/
│       └── Main.java         # Implementación en Java
├── docs/
│   └── guia_practica.md      # Guía de la práctica
├── exercises/
│   └── ejercicios.md         # Enunciados de ejercicios
├── moodle/
│   └── preguntas_moodle.md   # Banco de preguntas
└── README.md
```

---

## Árbol utilizado

El árbol binario trabajado en los ejercicios es el siguiente:

```
        10
       /  \
      5    15
     / \   / \
    2   7 12  20
```

Con nodos adicionales en el Ejercicio 2: **1, 3, 18 y 25**.

---

## Reglas de recorrido

| Recorrido | Orden de visita            | Tipo |
| --------- | -------------------------- | ---- |
| Preorden  | Raíz → Izquierda → Derecha | DFS  |
| Inorden   | Izquierda → Raíz → Derecha | DFS  |
| Postorden | Izquierda → Derecha → Raíz | DFS  |
| BFS       | Nivel por nivel (cola)     | BFS  |

---

## Ejecución

### C++

```bash
cd src/cpp
g++ main.cpp -o recorridos
./recorridos
![alt text](image-1.png)
```

### Java

```bash
cd src/java
javac Main.java
java Main
![alt text](image.png)
```

---

## Salida esperada en consola

```
RECORRIDOS DE ARBOLES BINARIOS - UTA
Preorden:   10 5 2 7 15 12 20
Inorden:    2 5 7 10 12 15 20
Postorden:  2 7 5 12 20 15 10
BFS:        10 5 15 2 7 12 20
```

---

**¿Qué recorrido usar según la tarea?**

| Tarea                                                 | Recorrido recomendado | Justificación                                                                             |
| ----------------------------------------------------- | --------------------- | ----------------------------------------------------------------------------------------- |
| Mostrar el menú principal (raíz primero)              | **Preorden**          | Visita la raíz antes que los subárboles, ideal para mostrar jerarquías de menú.           |
| Procesar primero los módulos internos (hojas primero) | **Postorden**         | Procesa los hijos antes que el padre, útil para liberar recursos o calcular dependencias. |
| Mostrar módulos nivel por nivel                       | **BFS**               | Recorre por niveles usando cola, ideal para mostrar un menú organizado por profundidad.   |

---

## Comparación C++ vs Java

| Aspecto                | C++                                     | Java                           |
| ---------------------- | --------------------------------------- | ------------------------------ |
| Definición del nodo    | `struct Nodo` con punteros (`*`)        | `class Nodo` con referencias   |
| Manejo de memoria      | Manual (`new`, sin `delete` en ejemplo) | Automático (Garbage Collector) |
| Cola para BFS          | `queue<Nodo*>` de `<queue>`             | `Queue<Nodo>` con `LinkedList` |
| Valor nulo             | `nullptr`                               | `null`                         |
| Imprimir               | `cout << valor`                         | `System.out.print(valor)`      |
| Complejidad sintáctica | Mayor (punteros, cabeceras)             | Menor (OOP puro)               |

---

## Preguntas de reflexión

1. **¿Qué recorrido sirve para ordenar valores en un BST?**
   El **Inorden** (Izquierda → Raíz → Derecha), ya que en un Árbol Binario de Búsqueda visita los nodos en orden ascendente.

2. **¿Qué diferencia existe entre DFS y BFS?**
   DFS recorre en profundidad (sigue una rama hasta el final antes de explorar otra), mientras que BFS recorre por niveles (visita todos los nodos de un nivel antes de bajar al siguiente).

3. **¿Por qué BFS requiere una cola?**
   Porque necesita recordar los nodos pendientes de visitar en orden de llegada (FIFO). La cola garantiza que se procesen nivel por nivel sin saltarse nodos.

4. **¿En qué caso real se puede usar Preorden?**
   Para serializar o copiar la estructura de un árbol, o para mostrar menús jerárquicos donde el elemento padre aparece antes que sus hijos.

5. **¿En qué caso real se puede usar Postorden?**
   Para eliminar un árbol de memoria (liberar hijos antes que el padre), o para evaluar expresiones matemáticas en árboles de expresiones (operandos antes que el operador).

---

_Universidad Técnica de Ambato — Ingeniería de Software — Estructura de Datos — 2025_