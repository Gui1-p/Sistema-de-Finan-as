#include "classes_auxiliares.h"

Data::Data() {}
Data::Data(size_t Dia, size_t Mes, size_t Ano) : m_Dia(Dia), m_Mes(Mes), m_Ano(Ano) {}

size_t Data::GetDia() const {return m_Dia; }
size_t Data::GetMes() const {return m_Mes; }
size_t Data::GetAno() const {return m_Ano; }


void Data::SetDia(size_t Dia) {m_Dia = Dia;}
void Data::SetAno(size_t Mes) {m_Mes = Mes;}
void Data::SetMes(size_t Ano) {m_Ano = Ano;}