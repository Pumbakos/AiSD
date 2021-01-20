#include <iostream>

using namespace std;

// NOTE: Nie działa

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

void reverseList(elem* &lista){
    int s = size(lista);
    cout << "\n\t";
    for(int i=s; i > 0; i--){
        cout << read(lista, i) << ", ";
    }
}

void destroy(elem* &lista){
    if(lista != NULL){
        while(lista != NULL){
            elem* stary = lista;
            lista = lista->nast;
            delete stary;
        }
    }
}

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
    
    return EXIT_SUCCESS;
}
