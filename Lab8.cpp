#include <iostream>
#include <stdio.h> // Para usar printf y scanf_s
using namespace std;

// Clase Primo
class Primo {
private:
    int numero;

public:
    //Constructor
    Primo(int n) : numero(n) {}

    //Método
    bool esPrimo() {
        if (numero <= 1) return false; //Los números de menor o igual a 1 no son primos
        for (int i = 2; i * i <= numero; i++) {
            if (numero % i == 0) return false; //Si es divisible no es primo
        }
        return true; //Si no es divisible por ningún número es primo
    }
};

// Clase CalFactorial
class CalFactorial {
private:
    int numero;

public:
    //Constructor
    CalFactorial(int n) : numero(n) {}

    //Método
    long long calcularFactorial() {
        long long factorial = 1; //Inincia el factorial 1
        for (int i = 1; i <= numero; i++) {
            factorial *= i; //Multiplica el factorial por cada número hasta el número dado
        }
        return factorial;
    }
};

// Clase Estudiante
class Estudiante {
private:
    int calificacion;

public:
    //Constructor
    Estudiante(int cal) : calificacion(cal) {}
    
    //Método
    string determinarResultado() {
        if (calificacion >= 61) {
            return "Aprobado"; //Si la calificación es 61 o más, aprueba
        } else {
            return "Reprobado"; //Si la calificación es menos de 61, reprobó
        }
    }
};

// Clase NumNaturales
class NumNaturales {
private:
    int numero;

public:
    //Constructor
    NumNaturales(int n) : numero(n) {}
    
    //Método
    bool esNatural() {
        return numero >= 0; //Los numeros naturales son mayores o iguales a 0
    }
};

// Clase TablaMultiplicar
class TablaMultiplicar {
private:
    int numero;

public:
    //Constructor
    TablaMultiplicar(int n) : numero(n) {}

    //Método
    void mostrarTabla() {
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", numero, i, numero * i); //Muestra la multiplicación
        }
    }
};

// Clase OrdenarNumero
class OrdenarNumero {
private:
    int numeros[5];

public:
    //Constructor
    OrdenarNumero(int n1, int n2, int n3, int n4, int n5) {
        numeros[0] = n1;
        numeros[1] = n2;
        numeros[2] = n3;
        numeros[3] = n4;
        numeros[4] = n5;
    }

    //Método
    void ordenarYMostrar() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (numeros[j] > numeros[j + 1]) {
                    // Intercambiar valores si están en el orden incorrecto
                    int temp = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = temp;
                }
            }
        }

        // Mostrar números ordenados
        printf("Numeros ordenados: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", numeros[i]); //Imprime los números ordenados
        }
        printf("\n");
    }
};

// Función principal
int main() {
    int opcion;
    printf("Seleccione la clase que desea ejecutar:\n");
    printf("1. Primo\n");
    printf("2. Calcular Factorial\n");
    printf("3. Estudiante (Aprobado/Reprobado)\n");
    printf("4. Numero Natural\n");
    printf("5. Tabla de Multiplicar\n");
    printf("6. Ordenar Numeros\n");
    printf("Ingrese su opcion: ");
    if (scanf_s("%d", &opcion) != 1) {
    printf("Error: Entrada no válida.\n");
    return 1; // Salir del programa si la entrada no es válida
    }

    switch (opcion) {
    case 1: { //Número primo
        int num;
        printf("Ingrese un numero para determinar si es primo: ");
        if (scanf_s("%d", &num) != 1) {
            printf("Error: Entrada no válida.\n");
            return 1;
        }
        Primo p(num);
        if (p.esPrimo()) {
            printf("%d es un numero primo.\n", num);
        }
        else {
            printf("%d no es un numero primo.\n", num);
        }
        break;
    }
    case 2: { //Factorial de un número
        int num;
        printf("Ingrese un numero para calcular su factorial: ");
        if (scanf_s("%d", &num) != 1) {
            printf("Error: Entrada no válida.\n");
            return 1;
        }
        CalFactorial cf(num);
        printf("El factorial de %d es %lld\n", num, cf.calcularFactorial());
        break;
    }
    case 3: { //Estudiante aprueba o desaprueba
        int cal;
        printf("Ingrese la calificacion del estudiante: ");
        if (scanf_s("%d", &cal) != 1) {
            printf("Error: Entrada no válida.\n");
            return 1;
        }
        Estudiante e(cal);
        printf("El estudiante esta %s\n", e.determinarResultado().c_str());
        break;
    }
    case 4: { //Número natural
        int num;
        printf("Ingrese un numero para determinar si es natural: ");
        if (scanf_s("%d", &num) != 1) {
            printf("Error: Entrada no válida.\n");
            return 1;
        }
        NumNaturales nn(num);
        if (nn.esNatural()) {
            printf("%d es un numero natural.\n", num);
        }
        else {
            printf("%d no es un numero natural.\n", num);
        }
        break;
    }
    case 5: { //Tabla de multiplicar
        int num;
        printf("Ingrese un numero para mostrar su tabla de multiplicar: ");
        if (scanf_s("%d", &num) != 1) {
            printf("Error: Entrada no válida.\n");
            return 1;
        }
        TablaMultiplicar tm(num);
        tm.mostrarTabla();
        break;
    }
    case 6: { //Orden de números
        int n1, n2, n3, n4, n5;
        printf("Ingrese 5 numeros: ");
        if (scanf_s("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5) != 5) {
            printf("Error: Entrada no válida.\n");
            return 1;
        }
        OrdenarNumero on(n1, n2, n3, n4, n5);
        on.ordenarYMostrar();
        break;
    }
    default:
        printf("Opcion no valida.\n");
        break;
    }

    return 0;
}