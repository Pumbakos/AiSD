#include <iostream>

using namespace std;

/**
 * ANCHOR
 * Zadanie 1
 */
struct elem{
    int dane;
    elem* nast;
};

void insert(elem *&lista, int i, int x){
    elem *nowy = new elem;
    nowy->dane = x;
    if (i == 1){
        nowy->nast = lista;
        lista = nowy;
    }
    else if (i > 1){
        elem *tmp = lista;
        int j = 0;
        while (j != (i - 2)){
            tmp = tmp->nast;
            j++;
            if (tmp == NULL){
                cerr << "Lista jest za krotka";
                break;
            }
        }
        nowy->nast = tmp->nast;
        tmp->nast = nowy;
    }
    else{
        cerr<< "Nieprawidlowa wartosc \'i\'";
    }
}

void remove(elem *&lista, int i){
    if (lista != NULL){
        if (i == 1){
            elem *stary = lista;
            lista = lista->nast;
            delete stary;
        }
        else if (i > 1){
            elem *tmp = lista;
            int j = 0;
            while (j != (i - 2)){
                tmp = tmp->nast;
                j++;
                if (tmp == NULL)
                {
                    cerr << "Lista jest za krotka!";
                    break;
                }
            }

            elem *stary = tmp->nast;
            if (stary == NULL){
                cerr << "Brak elementow w liscie";
            }
            tmp->nast = stary->nast;
            delete stary;
        }
        else{
            cerr << "Nieprawidlowa wartosc \'i\'";
        }
    }
}

int read(elem *&lista, int i){
    if (lista != NULL){
        if (i >= 1){
            elem *tmp = lista;
            int j = 0;
            while (j != (i - 1)){
                tmp = tmp->nast;
                j++;
                if (tmp == NULL){
                    cerr << "Lista jest za krotka";
                    break;
                }
            }
            return tmp->dane;
        }
    }
}

/**
 * ANCHOR
 * Zadanie 2
 */
int size(elem* &lista){
    if(lista != NULL){
        elem* tmp = lista;
        int i = 0;
        while(tmp != NULL){
            tmp = tmp->nast;
            i++;
        }
        return i;
    }
}

/**
 * ANCHOR
 * Zadanie 3
 */
void print(elem* &lista){
    if(lista != NULL){
        elem* tmp = lista;
        while(tmp != NULL){
            cout << tmp->dane << ", ";
            tmp = tmp->nast;
        }
    }
    else { cerr << endl << "Lista nie istnieje!"; }
}
/**
 * ANCHOR
 * Zadanie 4
 */
struct stack{
    int dane;
    stack* nast;
};

void push(stack* &stos, int x){
    stack* nowy = new stack;
    nowy->dane = x;
    nowy->nast = stos;
    stos = nowy;
}

void printStack(stack* &stos)
{
    stack *temp = stos;

    cout << "\n\t";
    while(temp)
    {
        cout << temp->dane << ", ";
        temp = temp->nast;
    }
}

void reverseListByStack(elem* &lista){
    stack *stos = NULL;

    if(lista != NULL){
        elem* tmp = lista;
        while(tmp != NULL){
            push(stos, tmp->dane);
            tmp = tmp->nast;
        }
        printStack(stos);
    }
    else { cerr << endl << "Lista nie istnieje!"; }
}

/**
 * ANCHOR
 * Zadanie 5
 */
void reverseList(elem* &lista){
    int s = size(lista);
    cout << "\n\t";
    for(int i=s; i > 0; i--){
        cout << read(lista, i) << ", ";
    }
}
/**
 * ANCHOR
 * Zadanie 6
 */
void destroy(elem* &lista){
    if(lista != NULL){
        while(lista != NULL){
            elem* stary = lista;
            lista = lista->nast;
            delete stary;
        }
    }
}
/**
 * ANCHOR
 * Zadanie 7
 */
elem* search(int x, elem* lista){
    if(lista != NULL){
        elem* tmp = lista;
        while(tmp != NULL){
            if(tmp->dane == x){
                return tmp;
            }
            else if(tmp->dane == NULL){
                cerr << "Nie znaleziono elementu!\n";
            }
            else{
                tmp = tmp->nast;
            }
        }
    }
}

int main()
{
    elem *lista = NULL;
    // NOTE: Zadanie 1
    insert(lista, 1, 45);   // 1 element
    insert(lista, 1, 123);  // 2 element
    insert(lista, 2, 1643); // 3 element
    insert(lista, 3, 234);  // 4 element
    insert(lista, 4, 924);  // 5 element
    insert(lista, 3, 3);    // 6 element

    // NOTE: Zadanie 2
    cout << "Wielkosc listy(Zadanie 2): " << size(lista) << "\n";

    // NOTE: Zadanie 3
    cout << "Lista (Zadanie 3): ";
    print(lista);

    remove(lista, 5);
    cout << endl << "\nPo usunieciu 5 pozycji (924): ";
    print(lista);

    cout << endl << "\nCzwarty element listy: " << read(lista, 4);

    // NOTE: Zadanie 4
    cout << "\nODWROCONY PRZY POMOCY STOSU (Zadanie 4): \n";
    reverseListByStack(lista);

    // NOTE: Zadanie 5
    cout << "\nODWROCONY BEZ WYKORZYSTANIA STRUKTURY DANYCH (Zadanie 5): \n";
    reverseList(lista);

    cout << "\n\n(Zadanie 7) Szukamy elementu \'1643\', jest on pod adresem: " << search(1643, lista) << endl;

    // NOTE: Zadanie 6
    destroy(lista);
    return EXIT_SUCCESS;
}
