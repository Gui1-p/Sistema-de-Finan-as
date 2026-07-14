#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Pessoa = new Pessoa("Guilherme", Data(1, 15, 2006));
    CarregarDadosExemplo();
    AtualizarDashboard();
}

MainWindow::~MainWindow()
{
    delete m_Pessoa;
    delete ui;
}

void MainWindow::CarregarDadosExemplo()
{
    size_t idConta  = m_Pessoa->GerarId();
    size_t idCdb    = m_Pessoa->GerarId();
    size_t idCartao = m_Pessoa->GerarId();

    m_Pessoa->AdicionarFundo(new Poupanca("Conta Corrente", Data(1,1,2026), 2000.0, 0.0f, idConta));
    m_Pessoa->AdicionarFundo(new Investimento("CDB Inter", Data(1,1,2026), 20000.0, 10.0f, Data(1,1,2027), idCdb));
    m_Pessoa->AdicionarFundo(new CartaoCredito("Nubank", Data(1,1,2026), 0.0, Data(5,1,2026), Data(15,1,2026), idCartao, 12000.0));

    m_Pessoa->AdicionarTransacao(Transacao("Salario", "", "Outros", Data(5,7,2026),
                                           TipoTransacao::Entrada, FormaPagamento::Transferencia, 8420.0f, idConta));
    m_Pessoa->AdicionarTransacao(Transacao("Aluguel", "", "Moradia", Data(6,7,2026),
                                           TipoTransacao::Saida, FormaPagamento::Pix, 1900.0f, idConta));
    m_Pessoa->AdicionarTransacao(Transacao("Mercado", "", "Alimentacao", Data(8,7,2026),
                                           TipoTransacao::Saida, FormaPagamento::Cartao, 1100.0f, idCartao));
}

void MainWindow::AtualizarDashboard()
{
    ui->Nome->setText(QString("Olá, %1").arg(QString::fromStdString(m_Pessoa->GetNome())));
    ui->SaldoTotal->setText(QString("R$ %1").arg(m_Pessoa->SaldoTotal(), 0, 'f', 2));
    ui->Entradas->setText(QString("R$ %1").arg(m_Pessoa->Entradas(7, 2026), 0, 'f', 2));
    ui->Saidas->setText(QString("R$ %1").arg(m_Pessoa->Saidas(7, 2026), 0, 'f', 2));
}
