#include <iostream>

using namespace std;

struct elem
{
    int dane;
    elem *poprz;
    elem *nast;
};
/**
 * ANCHOR
 * NOTE: wywołanie w main();
 * Zadanie 1
 */

void insert(int x, int i, elem* &a)
{
    if (i == 1)
    {
        elem *nowy = new elem;
        nowy->dane = x;
        nowy->nast = a;
        nowy->poprz = NULL;

        if (a != NULL)
        {
            a->poprz = nowy;
        }
        a= nowy;
    }
    else if (i > 1)
    {
        elem *tmpE = a;
        for (int j = 1; j < i; j++)
        {
            if (tmpE->nast != NULL)
            {
                tmpE = tmpE->nast;
            }
        }

        elem *nowy = new elem;
        nowy->dane = x;

        elem *tmpNast = tmpE->nast;
        tmpE->nast = nowy;

        if (tmpNast != NULL)
        {
            tmpNast->poprz = nowy;
        }

        nowy->poprz = tmpE;
        nowy->nast = tmpNast;
        tmpNast = nowy;
    }
}

void remove(elem* &lista)
{
    elem *tmp = lista;
    lista = lista->nast;

    if (lista != NULL)
    {
        lista->poprz = NULL;
    }
    delete tmp;
}

void remove(int i, elem* &lista)
{
    elem *tmp = lista;
    elem *tmpPoprzed = NULL;

    for (int j = 1; j < i; j++)
    {
        tmpPoprzed = tmp;
        tmp = tmp->nast;
    }

    if (tmpPoprzed == NULL)
    {
        lista = lista->nast;
    }
    else
    {
        tmpPoprzed->nast = tmp->nast;
    }
}

/**
 * ANCHOR
 * Zadanie 2
 * NOTE: wywołanie w main();
 */

void reverse(elem* &lista)
{
    if (!lista || !lista->nast)
    {
        return;
    }

    elem *tmp;
    while (lista->nast)
    {
        tmp = lista->nast;
        lista->nast = lista->poprz;

        lista->poprz = tmp;
        lista = tmp;
    }

    lista->nast = lista->poprz;
    lista->poprz = NULL;
}

/**
 * ANCHOR
 * Zadanie 3
 * NOTE: wywołanie w main();
 */

void to_cyclic(elem* lista)
{
    elem *pierw = lista;
    while (lista->nast != NULL)
    {
        lista = lista->nast;
    }

    lista->nast = pierw;
}

/**
 * ANCHOR
 * Zadanie 4
 * NOTE: wywołanie w main();
 */

void reverse_cyclic(elem *lista)
{
    elem *pocz = lista->nast;
    elem *tmpPoprzed = lista;
    elem *tmpNast = NULL;

    lista = lista->nast;
    do{
        tmpNast = lista->nast;
        lista->nast = tmpPoprzed;

        tmpPoprzed = lista;
        lista = tmpNast;
    }while (lista != pocz);
}

void print(elem* lista)
{
    while (lista != NULL)
    {
        cout << lista->dane << " ";
        lista = lista->nast;
    }
}

void printCyclic(elem* lista)
{
    elem* pocz = lista;
    bool iteracja = false;
    while (lista != NULL)
    {
        if (lista == pocz && iteracja)
        {
            break;
        }
        iteracja = true;
        cout << lista->dane << " ";
        lista = lista->nast;
    }
}

int main()
{
    elem* lista = NULL;
    insert(24, 1, lista);
    insert(16, 2, lista);
    insert(13, 3, lista);
    insert(64, 4, lista);
    insert(26, 5, lista);
    insert(72, 6, lista);

    cout << "Lista: ";
    print(lista);

    cout << "\n\nLista odwrocona (zadanie 2): ";
    reverse(lista);
    print(lista);

    cout << "\n\nPrzeksztalcam liste w liste cykliczna. (zadanie 3)\n";
    to_cyclic(lista);

    cout << "\nZmieniam kierunek wskaznikow (zadanie 4): ";
    reverse_cyclic(lista);
    printCyclic(lista);

    return EXIT_SUCCESS;
}
