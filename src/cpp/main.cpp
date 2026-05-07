#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

// Inserta un nodo en el arbol binario de busqueda
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return new Nodo(valor);
    if (valor < raiz->dato)
        raiz->izquierda = insertar(raiz->izquierda, valor);
    else if (valor > raiz->dato)
        raiz->derecha = insertar(raiz->derecha, valor);
    return raiz;
}

// Cuenta el total de nodos del arbol
int contarNodos(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

// Cuenta solo los nodos hoja (sin hijos)
int contarHojas(Nodo* raiz) {
    if (raiz == nullptr) return 0;
    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) return 1;
    return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}

void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";
        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

int main() {
    Nodo* raiz = nullptr;

    // Arbol inicial con valores predefinidos
    int inicial[] = {10, 5, 15, 2, 7, 12, 20};
    for (int v : inicial) raiz = insertar(raiz, v);

    int opcion;
    do {
        cout << "\n=== ARBOLES BINARIOS - UTA ===" << endl;
        cout << "1. Insertar nodo" << endl;
        cout << "2. Preorden" << endl;
        cout << "3. Inorden" << endl;
        cout << "4. Postorden" << endl;
        cout << "5. BFS (por niveles)" << endl;
        cout << "6. Contar nodos" << endl;
        cout << "7. Contar hojas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

void preorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    cout << raiz->dato << " ";
    preorden(raiz->izquierda);
    preorden(raiz->derecha);
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    inorden(raiz->izquierda);
    cout << raiz->dato << " ";
    inorden(raiz->derecha);
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) return;
    postorden(raiz->izquierda);
    postorden(raiz->derecha);
    cout << raiz->dato << " ";
}

void bfs(Nodo* raiz) {
    if (raiz == nullptr) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->dato << " ";

        if (actual->izquierda != nullptr) cola.push(actual->izquierda);
        if (actual->derecha != nullptr) cola.push(actual->derecha);
    }
}

int main() {
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(2);
    raiz->izquierda->derecha = new Nodo(7);
    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(20);

    cout << "RECORRIDOS DE ARBOLES BINARIOS - UTA" << endl;

    cout << "Preorden: ";
    preorden(raiz);

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPostorden: ";
    postorden(raiz);

    cout << "\nBFS: ";
    bfs(raiz);

    cout << endl;
    return 0;
}

        cin >> opcion;

        switch (opcion) {
            case 1:
                int valor;
                cout << "Ingrese el valor a insertar: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                cout << "Nodo " << valor << " insertado." << endl;
                break;
            case 2:
                cout << "Preorden: ";
                preorden(raiz);
                cout << endl;
                break;
            case 3:
                cout << "Inorden: ";
                inorden(raiz);
                cout << endl;
                break;
            case 4:
                cout << "Postorden: ";
                postorden(raiz);
                cout << endl;
                break;
            case 5:
                cout << "BFS: ";
                bfs(raiz);
                cout << endl;
                break;
            case 6:
                cout << "Total de nodos: " << contarNodos(raiz) << endl;
                break;
            case 7:
                cout << "Total de hojas: " << contarHojas(raiz) << endl;
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}