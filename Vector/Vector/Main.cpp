#include <iostream>
#include "Vectore.h"

int main() 
{
    TVector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    std::cout << "vec1 taille : " << vec1.get_size() << ", capacite : " << vec1.get_capacity() << std::endl;

    TVector<int> vec2(5);
    std::cout << "vec2 (taille 5) taille : " << vec2.get_size() << std::endl;

    TVector<int> vec3(3, 42);
    std::cout << "vec3 rempli de 42 : ";
    for (size_t i = 0; i < vec3.get_size(); ++i)
    {
        std::cout << vec3[i] << " ";
    }
    std::cout << "\n\n";

    TVector<int> nombres;
    nombres.push_back(5);
    nombres.push_back(15);
    nombres.push_back(25);
    nombres.push_back(35);

    std::cout << "Elements du vecteur : ";
    for (size_t i = 0; i < nombres.get_size(); ++i)
    {
        std::cout << nombres[i] << " ";
    }
    std::cout << "\n\n";

    nombres.insert(1, 99);
    std::cout << "Apres insertion de 99 a l'index 1 : ";
    for (size_t i = 0; i < nombres.get_size(); ++i)
    {
        std::cout << nombres[i] << " ";
    }
    std::cout << "\n\n";

    int tableauAnnexe[] = { 77, 88 };
    nombres.insert(2, tableauAnnexe, 2);
    std::cout << "Apres insertion du tableau {77, 88} a l'index 2 : ";
    for (size_t i = 0; i < nombres.get_size(); ++i) {
        std::cout << nombres[i] << " ";
    }
    std::cout << "\n\n";

    nombres.remove(0);
    std::cout << "Apres suppression de l'element a l'index 0 : ";
    for (size_t i = 0; i < nombres.get_size(); ++i) {
        std::cout << nombres[i] << " ";
    }
    std::cout << "\n\n";

    int recherche1 = 99;
    int recherche2 = 500;

    std::cout << "Le vecteur contient " << recherche1 << " ? "
        << (nombres.contains(recherche1) ? "Oui" : "Non") << std::endl;

    std::cout << "Le vecteur contient " << recherche2 << " ? "
        << (nombres.contains(recherche2) ? "Oui" : "Non") << std::endl;

    return 0;
}