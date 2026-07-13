#ifndef CLASSES_AUXILIARES_H
#define CLASSES_AUXILIARES_H

#include <iostream>

using namespace std;

class Data
{
private:
    size_t m_Dia;
    size_t m_Mes;
    size_t m_Ano;

public:
    Data(size_t Dia, size_t Mes, size_t Ano);

    size_t GetDia() const;
    size_t GetMes() const;
    size_t GetAno() const;

    void SetDia(size_t Dia);
    void SetAno(size_t Mes);
    void SetMes(size_t Ano);
};


#endif // CLASSES_AUXILIARES_H
