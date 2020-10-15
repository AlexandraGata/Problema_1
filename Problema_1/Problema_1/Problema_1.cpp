//Problema 1:
//Scrieti un program care sa calculeze suma primelor n numere prime, unde 0 <= n <= 1000000.

#include <iostream>
#include <math.h>
#include <assert.h>

int prim(long long int x)
{
    //functia determina daca un numar este prim sau nu
    //input: x - un numar intreg
    //output: true - daca e prim, false - daca nu e prim

    //daca numarul e <=1 nu e prim
    if (x <= 1)
        return false;
    //daca numarul e 2 atunci e prim
    if (x == 2)
        return true;
    //daca numarul e >2, cautam un divizor pana la radacina patrata din numar
    //daca gasim divizor atunci nu e prim, in caz contrar e prim
    int divizor = 2;
    bool ok = true;
    while (ok && divizor <= sqrt(x))
    {
        if (x % divizor == 0)
            return false;
        divizor++;

    }
    return true;
}

void test_prim()
{
    //testeaza functia prim
    assert(prim(-3)==false);
    assert(prim(0) == false);
    assert(prim(1) == false);
    assert(prim(2) == true);
    assert(prim(11) == true);
    assert(prim(20) == false);
}


int suma_numerelor_prime(int n)
{
    //functia calculeaza suma primelor n numere prime
    //input: n - un numar, unde 0 <= n <= 1000000
    //output: suma - numar reprezentand suma ceruta

    //daca n=0 atunci suma va fi 0
    if (n == 0)
        return 0;
    //daca n e nenul, atunci suma va porni de la 0 si se vor verifica numerele incepand cu 2 daca sunt prime sau nu
    //daca numarul nu este prim se trece la urmatorul
    //daca este prim se aduna la suma si n scade (pentru a vedea cate numere mai trebuie gasite)
    unsigned long long int suma = 0, numar_curent=2;
    while (n!=0)
    {
        while (prim(numar_curent) == false)
            numar_curent++;
        suma = suma + numar_curent;
        numar_curent++;
        n--;
    }
    return suma;
}

void test_suma_numerelor_prime()
{
    //testeaza functia suma_numerelor_prime
    assert(suma_numerelor_prime(0) == 0);
    assert(suma_numerelor_prime(1) == 2);
    assert(suma_numerelor_prime(5) == 28);
    assert(suma_numerelor_prime(10000) == 496165411);
}

void teste()
{
    //ruleaza testele
    test_prim();
    test_suma_numerelor_prime();
}



int n;

int main()
{   
    //se ruleaza testele pentru functii
    teste();

    //citim numarul n
    std::cout << "Dati un numar n: ";
    std::cin >> n;
   
    //afisam suma primelor n numere prime
    std::cout <<"Suma primelor n numere prime este: "<< suma_numerelor_prime(n);
}


