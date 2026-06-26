#include "classes_auxiliares.h"

Data::Data(size_t Dia, size_t Mes, size_t Ano) : m_Dia(Dia), m_Mes(Mes), m_Ano(Ano) {}

size_t Data::GetDia() const {return m_Dia; }
size_t Data::GetMes() const {return m_Mes; }
size_t Data::GetAno() const {return m_Ano; }