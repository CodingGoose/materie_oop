#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

//* Problem 8.

// ii o functie care returneaza un pointer catre unde incepe lista (quasi returneaza lista)
// si returneaza prin parametrul length si lungimea listei
int* readArray(int &length) {
    // o sa incerc sa fac ceva magie din aia cu alocare dinamica
    int capacity = 5; // <- incepem in mod arbitrar cu 5 elemente, dar cu timpul (cu nevoia) o sa devina mai mare capacitatea
    int actual_length = 0;

    int *a = new int [capacity]; // creem o lista in memorie cu 5 elemente la inceput

    int current_number;

    do {
        cin>>current_number;
        if (current_number != 0){
            //* daca am umplut spatiul din a, marim lista
            if (actual_length>=capacity) {
                capacity = capacity * 2;
                int *temp = new int [capacity]; // alocam in memorie mai mult spatiu pt lista noastr
                // copiem lista a in lista temp
                for (int i=0; i<actual_length; i++) {
                    temp[i]=a[i];
                }

                delete[] a; // stergem din memorie valorile adresei spre care pointeaza a, ca asa e politicos
                a = temp; // facem pe a sa pointeze catre nou-alocata lista mai marE
            }
            //* adaugam elementul nou
            a[actual_length] = current_number;
            actual_length++;
        }
    }while (current_number !=0);

    length = actual_length; // salvam lungimea finala a listei (dupa ce s-a terminat citirea)
    return a; // returnam lista a (adica pointerul a care pointeaza catre primul element - de tip int - din lista)
}

/* * 8a. Bestimmen Sie die ersten n Paare von Zwillingszahlen,
 * wobei n eine gegebene natürliche Zahl ungleich Null ist.
 * Zwei Primzahlen p und q heißen twin, wenn q - p = 2 ist.
*/

bool isPrime(int number) {
    if (number<=1){return false;}
    for (int i=2; i<=number/2; i++) {
        if (number%i==0) {
            return false;
        }
    }
    return true;
}

int findNextPrime(int number) {
    do {
        number++;
    }while (!isPrime(number));
    return number;
}

void Zwillingszahlen(int n) {
    // erstes paar ist immer 3,5
    int p=3;
    int q=5;
    while (n!=0) {
        cout<<"("<<p<<","<<q<<")\n";
        do {
            p=findNextPrime(p);
            q=findNextPrime(q);
        }while (q-p!=2);
        n--;
    }
    cout<<endl;
}

/* *
8b. Gegeben sei ein Vektor von Zahlen, finde die am längsten abnehmende aufeinanderfolgende Teilfolge.

ii aproape exact aceeasi chestie ca la ex 3
*/

int* langsteTeilfolge(int* array, int array_length, int &max_teilfolge_lange) {

    max_teilfolge_lange=0;
    int max_teilfolge_start_index=0;

    int aktuelle_teilfolge_lange=1;
    int aktuelle_teilfolge_start_index=0;

    for (int i=0; i<array_length-1; i++) {
        if (array[i]>array[i+1]) {
            aktuelle_teilfolge_lange++;

        } else {
            // s-o rupt continuitatea
            if (max_teilfolge_lange<aktuelle_teilfolge_lange) {
                max_teilfolge_lange=aktuelle_teilfolge_lange;
                max_teilfolge_start_index = aktuelle_teilfolge_start_index;
            }

            aktuelle_teilfolge_lange = 1;
            aktuelle_teilfolge_start_index = i+1;
        }

    }
    // mai trebuie verificat o data la final
    if (max_teilfolge_lange<aktuelle_teilfolge_lange) {
        max_teilfolge_lange=aktuelle_teilfolge_lange;
        max_teilfolge_start_index = aktuelle_teilfolge_start_index;
    }


    //* facem arrayul nou si il returnam

    int* max_teilfolge = new int [max_teilfolge_lange];
    for (int i=0; i<max_teilfolge_lange; i++) {
        max_teilfolge[i] = array[max_teilfolge_start_index+i];
    }

    return max_teilfolge;
}

int main() {

    /* * a. Lesen Sie eine Sequenz von natürlichen Zahlen (Sequenz mit 0 beendet)
    und bestimmen Sie die Anzahl von 0 Ziffern des Produkts der gelesenen Zahlen.
    */

    Zwillingszahlen(10);

    int birromo_len = 0;
    cout<<"Schreiben sie eine folge von zahlen und eine 0 am Ende bitte sehr!\n";
    int* birromo = readArray(birromo_len);

    int langste_tf_len=0;
    int *langste_tf = langsteTeilfolge(birromo, birromo_len, langste_tf_len);


    // 5 6
    cout<<"Langste Teilfolge hat "<<langste_tf_len<<" Elemente\n";
    for (int i=0; i<langste_tf_len; i++) {
        cout<<langste_tf[i]<<" ";
    }

    delete[] birromo;
    delete[] langste_tf;

    return 0;
}