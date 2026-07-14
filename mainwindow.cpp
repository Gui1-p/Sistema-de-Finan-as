#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->AreaMetas->setLayout(new QVBoxLayout(ui->AreaMetas));
    ui->FundosRegistrados->setLayout(new QVBoxLayout(ui->FundosRegistrados));

    m_Pessoa = new Pessoa("Guilherme", Data(15, 1, 2006));

    if (!m_Pessoa->Carregar())   // false = arquivo não existe
        CarregarDadosExemplo();

    AtualizarDashboard();

    //são basicamente funções de callback de um subscriber em um node do ROS2
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::AoAdicionarTransacao);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::AoAdicionarObjetivo);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::AoRegistrarFundo);
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

    AtualizarMetas();
    AtualizarFundos();
    AtualizarCartao();
}

void MainWindow::AoAdicionarTransacao()
{
    DialogTransacao dlg(this);
    dlg.PreencherFundos(m_Pessoa->GetFundos());

    if (dlg.exec() == QDialog::Accepted) {
        m_Pessoa->AdicionarTransacao(dlg.CriarTransacao());
        m_Pessoa->Salvar();
        AtualizarDashboard();
    }
}

void MainWindow::AoAdicionarObjetivo()
{
    DialogObjetivo dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        m_Pessoa->AdicionarObjetivo(dlg.CriarObjetivo());
        m_Pessoa->Salvar();
        AtualizarDashboard();
    }
}

void MainWindow::AoRegistrarFundo()
{
    DialogFundos dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        m_Pessoa->AdicionarFundo(dialog.CriarFundo(m_Pessoa->GerarId()));
        m_Pessoa->Salvar();
        AtualizarDashboard();
    }
}

void MainWindow::AtualizarMetas()
{
    QLayout* lay = ui->AreaMetas->layout();

    //limpa os itens antigos
    QLayoutItem* item;
    while ((item = lay->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (Objetivo& o : m_Pessoa->GetObjetivos()) {
        int percentual = 0;
        if (o.GetValorAlvo() > 0) // evita divisão por zero
            percentual = (int)((o.GetValorAtual() / o.GetValorAlvo()) * 100);
        if (percentual > 100) percentual = 100;

        QProgressBar* barra = new QProgressBar();
        barra->setRange(0, 100);
        barra->setValue(percentual);
        barra->setFormat(QString("%1 — R$ %2 / R$ %3  (%p%)")
            .arg(QString::fromStdString(o.GetNome()))
            .arg(o.GetValorAtual(), 0, 'f', 2)
            .arg(o.GetValorAlvo(), 0, 'f', 2));
        lay->addWidget(barra);
    }

}

void MainWindow::AtualizarFundos()
{
    QLayout* lay = ui->FundosRegistrados->layout();
    if (!lay) return;

    // limpa os itens antigos
    QLayoutItem* item;
    while ((item = lay->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (Fundos* f : m_Pessoa->GetFundos()) {
        double saldo = f->Saldo(m_Pessoa->GetTransacoes());

        QLabel* linha = new QLabel(QString("[%1] %2        R$ %3")
            .arg(QString::fromStdString(f->Tipo()))
            .arg(QString::fromStdString(f->GetNome()))
            .arg(saldo, 0, 'f', 2));
        lay->addWidget(linha);
    }
}

void MainWindow::AtualizarCartao()
{
    CartaoCredito* cartao = m_Pessoa->AcharCartao();
    if (!cartao) return;                                  // sem cartão cadastrado

    vector<Transacao>& Movimentacao = m_Pessoa->GetTransacoes();
    int percentual = (int) cartao->PercentualLimiteUsado(Movimentacao);

    ui->ValorFatura->setText(QString("R$ %1").arg(cartao->Fatura(Movimentacao), 0, 'f', 2));
    ui->BarraLimite->setRange(0, 100);
    ui->BarraLimite->setValue(percentual);
    ui->LimiteInfo->setText(QString("Limite usado · %1%").arg(percentual));
    ui->Disponivel->setText(QString("R$ %1 disponível").arg(cartao->LimiteDisponivel(Movimentacao), 0, 'f', 2));

    Data v = cartao->GetVencimento();
    ui->Vencimento->setText(QString("Vence em %1/%2")
        .arg(v.GetDia(), 2, 10, QChar('0'))
        .arg(v.GetMes(), 2, 10, QChar('0')));
}
