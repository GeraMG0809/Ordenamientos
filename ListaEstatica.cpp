#include <iostream>

template <class obj>
class ListaEstatica {
private:
    obj datos[50];
    int ultimo;

public:
    ListaEstatica();
    ListaEstatica(const ListaEstatica<obj>& other);
    bool Vacia() const;
    bool Llena() const;
    bool inserta(obj, int);
    bool elimina(int);
    obj recupera(int) const;
    int primero() const;
    int Ultimo() const;
    void imprime();
    int buscar(obj) const;
    void QuickSortPublic();
    int BusquedaBinaria(obj&);
    void QuickSortPriv(int, int);
};


template <class obj>
ListaEstatica<obj>::ListaEstatica() {
    ultimo = -1;
}

template <class obj>
ListaEstatica<obj>::ListaEstatica(const ListaEstatica<obj>& other) {
    ultimo = other.ultimo;
    for (int i = 0; i <= ultimo; i++) {
        datos[i] = other.datos[i];
    }
}

template <class obj>
bool ListaEstatica<obj>::Vacia() const {
    return (ultimo == -1);
}

template <class obj>
bool ListaEstatica<obj>::Llena() const {
    return (ultimo == 49);
}

template <class obj>
bool ListaEstatica<obj>::inserta(obj dato, int pos) {
    if (Llena() || pos < 0 || pos > ultimo + 1) {
        return false;
    }
    for (int i = ultimo + 1; i > pos; i--) {
        datos[i] = datos[i - 1];
    }
    datos[pos] = dato;
    ultimo++;
    return true;
}

template <class obj>
bool ListaEstatica<obj>::elimina(int pos) {
    if (Vacia() || pos < 0 || pos > ultimo) {
        return false;
    }
    for (int i = pos; i < ultimo; i++) {
        datos[i] = datos[i + 1];
    }
    ultimo--;
    return true;
}

template <class obj>
obj ListaEstatica<obj>::recupera(int pos) const {
    if (Vacia() || pos < 0 || pos > ultimo) {
       std::cout<<"ERROR";
    }
    return datos[pos];
}

template <class obj>
int ListaEstatica<obj>::primero() const {
    if (Vacia()) {
        return -1;
    }
    return 0;
}

template <class obj>
void ListaEstatica<obj>::imprime() {
    if (Vacia()) {
        std::cout << "Lista vacía, nada que imprimir..." << std::endl;
    } else {
        for (int i = 0; i <= ultimo; i++) {
            std::cout << datos[i] << std::endl;
        }
    }
}

template <class obj>
int ListaEstatica<obj>::buscar(obj dat) const {
    for (int i = 0; i <= ultimo; i++) {
        if (dat == datos[i]) {
            return i;
        }
    }
    return -1;
}

template <class obj>
int ListaEstatica<obj>::Ultimo() const {
    return ultimo;
}

template <class obj>
void ListaEstatica<obj>::QuickSortPublic() {
    QuickSortPriv(0, ultimo);
}

template <class obj>
void ListaEstatica<obj>::QuickSortPriv(int leftSide, int rightSide) {
    if (leftSide >= rightSide || Vacia()) {
        return;
    }

    int i = leftSide;
    int j = rightSide - 1;

    while (i <= j) {
        while (i <= j && datos[i] <= datos[rightSide]) {
            i++;
        }
        while (i <= j && datos[j] >= datos[rightSide]) {
            j--;
        }
        if (i < j) {
            obj aux = datos[i];
            datos[i] = datos[j];
            datos[j] = aux;
        }
    }

    obj temp = datos[i];
    datos[i] = datos[rightSide];
    datos[rightSide] = temp;

    QuickSortPriv(leftSide, i - 1);
    QuickSortPriv(i + 1, rightSide);
}

template <class obj>
int ListaEstatica<obj>::BusquedaBinaria(obj& dat) {
    if (Vacia()) {
        return -1;
    } else {
        int i = 0;
        int j = ultimo;
        while (i <= j) {
            int medio = (i + j) / 2;
            if (datos[medio] == dat) {
                return medio;
            } else {
                if (dat < datos[medio]) {
                    j = medio - 1;
                } else {
                    i = medio + 1;
                }
            }
        }
        return -1;
    }
}