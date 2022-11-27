#include <iostream>
#include <ctime>

void input(const std::string& text, const std::string& error, int& var);
std::string test_number(int value, int random_value);

int main() {
    std::srand(std::time(nullptr));
    std::string error { "Merci de taper un nombre valide :" };
    int max {};
    input("Valeur maximale :", error, max);

    int value {};
    int random_value {(rand()%(max-1))+1};

    while(value != random_value){
        input("Entrez votre valeur :", error, value);
        std::cout << test_number(value, random_value) << std::endl;
    }

    return 0;
}

void input(const std::string& text, const std::string& error, int& var){
    std::cout << text << std::endl;
    while(!(std::cin >> var)){
        std::cout << std::endl << error << std::endl;
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
}

std::string test_number(int value, int random_value){
    if (value > random_value) return "Le nombre est trop grand.";
    else if (value < random_value) return "Le nombre est trop petit";
    return "Le nombre est correct.";
}