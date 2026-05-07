import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Nodo {
    int dato;
    Nodo izquierda;
    Nodo derecha;
    public Nodo(int dato) {
        this.dato = dato;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    // Inserta un nodo en el arbol binario de busqueda
    public static Nodo insertar(Nodo raiz, int valor) {
        if (raiz == null) return new Nodo(valor);
        if (valor < raiz.dato)
            raiz.izquierda = insertar(raiz.izquierda, valor);
        else if (valor > raiz.dato)
            raiz.derecha = insertar(raiz.derecha, valor);
        return raiz;
    }

    // Cuenta el total de nodos del arbol
    public static int contarNodos(Nodo raiz) {
        if (raiz == null) return 0;
        return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha);
    }

    // Cuenta solo los nodos hoja (sin hijos)
    public static int contarHojas(Nodo raiz) {
        if (raiz == null) return 0;
        if (raiz.izquierda == null && raiz.derecha == null) return 1;
        return contarHojas(raiz.izquierda) + contarHojas(raiz.derecha);
    }

    public static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    public static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecha);
    }

    public static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.print(raiz.dato + " ");
    }

    public static void bfs(Nodo raiz) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Nodo raiz = null;

        // Arbol inicial con valores predefinidos
        int[] inicial = {10, 5, 15, 2, 7, 12, 20};
        for (int v : inicial) raiz = insertar(raiz, v);

        int opcion;
        do {
            System.out.println("\n=== ARBOLES BINARIOS - UTA ===");
            System.out.println("1. Insertar nodo");
            System.out.println("2. Preorden");
            System.out.println("3. Inorden");
            System.out.println("4. Postorden");
            System.out.println("5. BFS (por niveles)");
            System.out.println("6. Contar nodos");
            System.out.println("7. Contar hojas");
            System.out.println("0. Salir");
            System.out.print("Opcion: ");
            opcion = sc.nextInt();

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el valor a insertar: ");
                    int valor = sc.nextInt();
                    raiz = insertar(raiz, valor);
                    System.out.println("Nodo " + valor + " insertado.");
                    break;
                case 2:
                    System.out.print("Preorden: ");
                    preorden(raiz);
                    System.out.println();
                    break;
                case 3:
                    System.out.print("Inorden: ");
                    inorden(raiz);
                    System.out.println();
                    break;
                case 4:
                    System.out.print("Postorden: ");
                    postorden(raiz);
                    System.out.println();
                    break;
                case 5:
                    System.out.print("BFS: ");
                    bfs(raiz);
                    System.out.println();
                    break;
                case 6:
                    System.out.println("Total de nodos: " + contarNodos(raiz));
                    break;
                case 7:
                    System.out.println("Total de hojas: " + contarHojas(raiz));
                    break;
                case 0:
                    System.out.println("Saliendo...");
                    break;
                default:
                    System.out.println("Opcion no valida.");
            }
        } while (opcion != 0);

        sc.close();
    }
}