#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;


// ! ex asta (Problem 3) plus inca un exercitiu la alegere

// Der Code muss gut lesbar sein, und wo notwendig Kommentare enthalten.

//* Problem 3.

/* * a. Lesen Sie eine Sequenz von natürlichen Zahlen (Sequenz mit 0 beendet)
und bestimmen Sie die Anzahl von 0 Ziffern des Produkts der gelesenen Zahlen.
*/

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


int calculateArrayProduct(int *array, int array_length) {
    int product = 1;
    for (int i=0; i<array_length; i++) {
        product *= array[i];
    }

    return product;
}

int countZerosInNumber(int number) {
    int zeros_count=0; //hehe
    while (number!=0) {
        if (number%10==0) {
            zeros_count++;
        }
        number /= 10;
    }
    return zeros_count;
}

/* *
b. Gegeben sei ein Vektor von Zahlen, finde die längste zusammenhängende Teilfolge
so, dass die Summe von zwei aufeinanderfolgenden Elementen eine Primzahl ist.
*/

int main() {

    int ariru_len=0;
    int *ariru = readArray(ariru_len);

    for (int i=0; i<ariru_len; i++) {
        cout<<ariru[i]<<" ";
    }

    cout<<calculateArrayProduct(ariru, ariru_len)<<endl;

    delete[] ariru; // dealocam ce i-am alocat lui ariru la inceput

    cout<<countZerosInNumber(100389020); // <- mere :D


    return 0;
}