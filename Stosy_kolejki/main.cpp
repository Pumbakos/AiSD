#include <iostream>
#include <climits>

using namespace std;

struct elem {
    int dane;
    elem* nast;
};

/**
 * ANCHOR
 * Zadanie 1
 */

void push(elem* &stos, int x)
{
    elem* nowy_elem = new elem;
    nowy_elem->dane = x;
    nowy_elem->nast = stos;
    stos = nowy_elem;
}

int pop(elem* &stos)
{
    elem *temp = stos;

    stos = stos->nast;
    return temp->dane;
}

int topEl(elem* stos)
{
    return stos->dane;
}

void printStack(elem* &stos)
{
    elem *temp = stos;

    while(temp)
    {
        cout << temp->dane << endl;
        temp = temp->nast;
    }
}

bool isEmpty(elem *stos)
{
    return stos;
}

/**
 * ANCHOR
 * Zadanie 2
 */

void add(elem* &pocz_kolejki, elem* &kon_kolejki, int x){
    elem* nowyEle = new elem;
    nowyEle->dane = x;

    if (kon_kolejki == NULL){
        pocz_kolejki = nowyEle;
        kon_kolejki = nowyEle;
        nowyEle->nast = NULL;
    }
    else{
        nowyEle->nast = pocz_kolejki;
        pocz_kolejki = nowyEle;
    }
}

int next(elem* &pocz_kolejki, elem* &kon_kolejki){
    if (kon_kolejki != NULL && kon_kolejki == pocz_kolejki){
        int x = kon_kolejki->dane;
        delete kon_kolejki;
        pocz_kolejki = kon_kolejki = NULL;
        return x;
    }
    else if (kon_kolejki != NULL){
        elem* tmp = pocz_kolejki;

        while (tmp->nast != kon_kolejki){
            tmp = tmp->nast;
        }

        int x = kon_kolejki->dane;
        delete kon_kolejki;

        kon_kolejki = tmp;
        return x;
    }
}

int firstEl(elem* pocz_kolejki){
    if (pocz_kolejki){
        return pocz_kolejki->dane;
    }
    else{
        return 1;
    }
}

bool isQueueEmpty(elem* pocz_kolejki){
    if (pocz_kolejki){
        return false;
    }
    else{
        return true;
    }
}

/**
 * ANCHOR
 * NOTE: wywo�anie jest w main()
 * Zadanie 5
 */

class Queue5{
private:
    elem *stos_1 = NULL;
    elem *stos_2 = NULL;

public:
    Queue5();
    ~Queue5();
    void add(int value);
    int next();
    int firstEl();
    bool is_empty();
    void print();
};

Queue5::Queue5(){}

Queue5::~Queue5(){
    while (isEmpty(stos_2)){
        pop(stos_2);
    }

    while (isEmpty(stos_1)){
        pop(stos_1);
    }
}

void Queue5::add(int value){
    if(isEmpty(stos_2)){
        while (isEmpty(stos_2)){
            push(stos_1, pop(stos_2));
        }
    }
    push(stos_1, value);

    while (isEmpty(stos_1))
    {
        push(stos_2, pop(stos_1));
    }
}

int Queue5::next(){
    return pop(stos_2);
}

void Queue5::print(){
    printStack(stos_2);
}

int Queue5::firstEl(){
    int temp = pop(stos_2);
    push(stos_2, temp);
    return temp;
}

bool Queue5::is_empty(){
    if(isEmpty(stos_2)){
        return false;
    }
    else {
        return true;
    }
}

/**
 * ANCHOR
 * NOTE: wywo�anie jest w main()
 * Zadanie 6
 */

class Queue6{
private:
    int queue_size;
    int head;
    int elem_counter;
    int *_queue;

public:
    Queue6(int initial_size);
    ~Queue6();
    bool isEmpty();
    int topEl();
    void add(int value);
    void next();
};

Queue6::Queue6(int initial_size){
    queue_size = initial_size;
    _queue = new int[initial_size];
    head = elem_counter = 0;
}

Queue6::~Queue6(){
    delete[] _queue;
}

bool Queue6::isEmpty(){
    return !elem_counter;
}

int Queue6::topEl(){
    if (elem_counter){
        return _queue[head];
    }
    return 0;
}

void Queue6::add(int value){
    int i;
    if (elem_counter < queue_size)
    {
        i = head + elem_counter++;

        if (i >= queue_size){
            i -= queue_size;
        }
        _queue[i] = value;
    }
}

void Queue6::next(){
    if (elem_counter)
    {
        elem_counter--;
        head++;
        if (head == queue_size){
            head = 0;
        }
    }
}

int main(int argc, const char * argv[]) {

    /**
     * ANCHOR
     * Zadanie 3
     */
    cout << "\t\tZADANIE 3: \n";
    elem *_queue3 = NULL;
    elem *_queue_end3 = NULL;
    elem *stos3 = NULL;
    string stos_output3="", queue_output3="";

    push(stos3, 'E');
    push(stos3, 'A');
    push(stos3, 'S');
    stos_output3 += pop(stos3);

    push(stos3, 'Y');
    stos_output3 += pop(stos3);

    push(stos3, 'Q');
    push(stos3, 'U');
    push(stos3, 'E');

    stos_output3 += pop(stos3);
    stos_output3 += pop(stos3);
    stos_output3 += pop(stos3);

    push(stos3, 'S');
    push(stos3, 'T');

    stos_output3 += pop(stos3);
    stos_output3 += pop(stos3);
    stos_output3 += pop(stos3);

    push(stos3, 'I');
    push(stos3, 'O');
    stos_output3 += pop(stos3);

    push(stos3, 'N');

    stos_output3 += pop(stos3);
    stos_output3 += pop(stos3);
    stos_output3 += pop(stos3);

    cout << "STOS: \n";
    cout << stos_output3 << endl;

    //---------------------------
    add(_queue3, _queue_end3, 'E');
    add(_queue3, _queue_end3, 'A');
    add(_queue3, _queue_end3, 'S');
    queue_output3 += next(_queue3, _queue_end3);

    add(_queue3, _queue_end3, 'Y');
    queue_output3 += next(_queue3, _queue_end3);

    add(_queue3, _queue_end3, 'Q');
    add(_queue3, _queue_end3, 'U');
    add(_queue3, _queue_end3, 'E');

    queue_output3 += next(_queue3, _queue_end3);
    queue_output3 += next(_queue3, _queue_end3);
    queue_output3 += next(_queue3, _queue_end3);

    add(_queue3, _queue_end3, 'S');
    add(_queue3, _queue_end3, 'T');

    queue_output3 += next(_queue3, _queue_end3);
    queue_output3 += next(_queue3, _queue_end3);
    queue_output3 += next(_queue3, _queue_end3);

    add(_queue3, _queue_end3, 'I');
    add(_queue3, _queue_end3, 'O');
    queue_output3 += next(_queue3, _queue_end3);

    add(_queue3, _queue_end3, 'N');

    queue_output3 += next(_queue3, _queue_end3);
    queue_output3 += next(_queue3, _queue_end3);
    queue_output3 += next(_queue3, _queue_end3);

    cout << "\nKOLEJKA: \n" << queue_output3;

    /**
     * ANCHOR
     * Zadanie 4
     */

    cout << "\n\n\t\tZADANIE 4: \n";
    elem *stos4 = NULL;
    string stos_output4="";

    push(stos4, 'E');
    push(stos4, 'A');
    stos_output4 += pop(stos4);
    push(stos4, 'S');
    stos_output4 += pop(stos4);

    push(stos4, 'Y');
    stos_output4 += pop(stos4);
    stos_output4 += pop(stos4);

    push(stos4, 'Q');
    push(stos4, 'U');
    push(stos4, 'E');
    push(stos4, 'S');
    push(stos4, 'T');
    push(stos4, 'I');
    push(stos4, 'O');
    push(stos4, 'N');

    cout << "CI�G ZWRACANY ZE STOSU: \n";
    cout << stos_output4 << endl;

    /**
     * NOTE: Wywolanie zadania 5
     */

    cout << "\n\n\n\t\tZADANIE 5: \n";
    Queue5 Q;

    Q.add(1);
    Q.add(2);
    Q.add(3);
    Q.add(4);
    Q.add(5);

    cout << "KOLEJKA: " << endl;
    Q.print();

    cout << "\n\n";

    cout << "ZDEJMUJEMY 2 ELEMENTY: " << endl;
    Q.next();
    Q.next();

    Q.print();

    cout << endl << "PIERWSZY ELEMENT: " << Q.firstEl() << endl;

    cout << "\nKOLEJKA: " << endl;
    Q.print();

    cout << "\nCZY KOLEJKA JEST PUSTA PUSTA? -> " << Q.is_empty();

    /**
     * NOTE: Wywolanie zadania 6
     */
    cout << "\n\n\n\t\tZADANIE 6: \n";

    int _size_ = 13;
    Queue6 test(_size_);


    for (int i = 1; i <= _size_; i++){
        test.add(i);
    }

    cout << "\nSTOS: ";
    while (!test.isEmpty()){
        cout << test.topEl() << " ";
        test.next();
    }
    cout << "\n";

    /**
     * ANCHOR
     * Zadanie 7.1
     */

    cout << "\t\tZADANIE 7.1: \n";
    elem *stos7 = NULL;
    elem *stos_temp7 = NULL;

    for (int i = 1; i <= 10; i++){
        push(stos7, i);
    }

    printStack(stos7);

    while (isEmpty(stos7))
    {
        push(stos_temp7, pop(stos7));
    }


    cout << "ODWOCONE: " << endl;
    printStack(stos_temp7);

    /**
     * ANCHOR
     * Zadanie 7.2
     */
    cout << "\t\tZADANIE 7.2: \n";

    elem *_queue72 = NULL;
    elem *queue_end72 = NULL;
    elem *stos72 = NULL;

    for (int i = 1; i <= 11; i++)
    {
        push(stos72, i);
    }

    cout << "STOS PIERWOTNY" << endl;
    printStack(stos72);

    while (isEmpty(stos72))
    {
        add(_queue72, queue_end72, pop(stos72));
    }

    while (!isQueueEmpty(_queue72))
    {
        push(stos72, next(_queue72, queue_end72));
    }

    cout << "STOS ODWROCONY" << endl;
    printStack(stos72);

    /**
     * ANCHOR
     * Zadanie 8
     */

    cout << "\t\tZadanie 8\n";

    elem *stos81 = NULL;
    elem *stos82 = NULL;
    int a8,b8, stack_size8 = 13, good_values8 = 0;

    for(int i = 0; i < stack_size8; i++){
        push(stos81, rand()%INT_MAX/93);
    }

    cout << "STOS: \n";
    printStack(stos81);

    while(good_values8 != stack_size8 -1){
        a8 = pop(stos81);
        b8 = pop(stos81);

        for(int i = 0; i < stack_size8 - good_values8 -2; i++){
            if(a8 > b8){
                push(stos82, a8);
                a8 = pop(stos81);
            }
            else if (a8 < b8){
                push(stos82, b8);
                b8 = pop(stos81);
            }
            else{
                push(stos82, a8);
                a8 = pop(stos81);
            }
        }
        good_values8++;

        if(a8 > b8){
                push(stos82, a8);
                push(stos82, b8);
            }
            else if (a8 < b8){
                push(stos82, b8);
                push(stos82, a8);
            }
            else{
                push(stos82, a8);
                push(stos82, b8);
            }

        while(isEmpty(stos82)){
            push(stos81, pop(stos82));
        }

    }

    cout << "\n\nSTOS POSORTOWANY: \n";
    printStack(stos81);


    /**
     * ANCHOR
     * Zadanie 9
     */

    cout << "\n\t\tZadanie 8\n";

    elem *stos91 = NULL;
    elem *stos92 = NULL;
    elem *stos93 = NULL;

    for (int i = 1; i <= 4; i++)
    {
        push(stos91, i);
    }

    cout << "PRZENIESIENIE PRZY UZYCIU STOSU:\n\n";
    cout << "STOS PIERWOTNY: " << endl;
    printStack(stos91);

    while (isEmpty(stos91))
    {
        push(stos92, pop(stos91));
    }

    cout << "STOS TYMCZASOWY" << endl;
    printStack(stos92);

    while (isEmpty(stos92))
    {
        push(stos93, pop(stos92));
    }

    cout << "STOS PRZENIESIONY: " << endl;
    printStack(stos93);

    cout << "\nPRZENIESIENIE PRZY UZYCIU ZMIENNEJ:\n\n";
    elem *stos_4 = NULL;
    elem *stos_5 = NULL;
    int temp, counter=1, s = 12;

    for (int i = s; i >= 1; i--){
        push(stos_4, i);
    }

    cout << "STOS PIERWOTNY: " << endl;
    printStack(stos_4);

    temp = pop(stos_4);
    push(stos_5, pop(stos_4));
    push(stos_5, temp);

    for(int i = 0; i < s - 2; i++){
        temp = pop(stos_4);
        counter++;

        for(int j = 0; j < counter; j++){
            push(stos_4, pop(stos_5));
        }

        push(stos_5, temp);
        for(int k = 0; k < counter; k++){
            push(stos_5, pop(stos_4));
        }

        if(!isEmpty(stos_4)){
            break;
        }
    }

    cout << "STOS PRZENIESIONY: " << endl;
    printStack(stos_5);

    return EXIT_SUCCESS;
}
