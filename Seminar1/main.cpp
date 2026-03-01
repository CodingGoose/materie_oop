#include <iostream>
// #include <monga>
void ex1() {

    std::string vorname;
    std::string nachname;
    std::cout<<"Vorname: ";
    std::cin>>vorname;
    std::cout<<"Nachname: ";
    std::cin>>nachname;

    std::cout<<"Halllo "<<vorname<<" "<<nachname<<std::endl;
    std::cout<<vorname.size() + nachname.size();

}

int main() {
    ex1();
    return 0;
}