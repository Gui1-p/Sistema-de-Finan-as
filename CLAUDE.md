# Sistema de Finanças — Guia do Projeto

## O que é este projeto

Aplicativo desktop de controle financeiro pessoal, escrito em **C++ com Qt Widgets**.
Está em fase inicial de desenvolvimento.

## Stack técnica

- **Linguagem:** C++17
- **Framework UI:** Qt (Widgets)
- **Build system:** qmake (`.pro`)
- **IDE alvo:** Qt Creator
- **Plataforma:** Windows

## Estrutura atual

```
Sistema_Financas/
├── main.cpp           # Ponto de entrada, instancia QApplication e MainWindow
├── mainwindow.h/.cpp  # Janela principal
├── mainwindow.ui      # Layout da UI (800x600, tema escuro)
└── Sistema_Financas.pro
```

A janela principal tem fundo escuro (`rgb(9, 8, 15)`) com um painel lateral esquerdo (`rgb(22, 19, 31)`) e um `QListView` placeholder.

## Funcionalidades planejadas

> Preencher conforme decidirmos juntos.

- [ ] ...

## Convenções

- Código em **inglês** (nomes de variáveis, funções, classes)
- Interface e textos visíveis ao usuário em **português**
- Sem comentários óbvios no código — apenas onde o "porquê" não é imediato
- Preferir editar arquivos existentes a criar novos desnecessariamente
- Não adicionar abstrações antes de precisar delas

## Como compilar

Abrir `Sistema_Financas.pro` no Qt Creator e buildar normalmente (Ctrl+B).

## Decisões tomadas

| Data | Decisão | Motivo |
|------|----------|--------|
| 2026-06-23 | Tema escuro como padrão | Definido no `.ui` inicial |

## Notas abertas

> Questões e dúvidas ainda sem resposta — resolver antes de implementar.

- Quais dados financeiros serão registrados? (contas, categorias, metas?)
- Persistência: banco de dados local (SQLite) ou arquivos?
- A UI terá navegação por abas, sidebar com ícones, ou outra estrutura?
