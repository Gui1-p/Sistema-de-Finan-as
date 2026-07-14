#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pessoa.h"
#include "dialogtransacao.h"
#include "dialogobjetivo.h"
#include "dialogfundos.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots: // esse private slots é uma espécie de semaphore do mROS
    void AoAdicionarTransacao();
    void AoAdicionarObjetivo();
    void AoRegistrarFundo();

private:
    Ui::MainWindow *ui;
    Pessoa * m_Pessoa;

    void CarregarDadosExemplo();
    void AtualizarDashboard();
    void AtualizarMetas();
};
#endif // MAINWINDOW_H
