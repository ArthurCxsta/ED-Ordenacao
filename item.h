#include <iostream>
using namespace std;
class Item{

private:
    int chave;
    string nome;

public:

    //Construtor
    Item():chave(0),nome(""){

    }

    //Getter & Setter
    int getChave() const
    {
        return chave;
    }
    void setChave(int newChave)
    {
        chave = newChave;
    }

    void setNome(const string &newNome)
    {
        nome = newNome;
    }
    string getnome()const{
        return nome;
    }
};

