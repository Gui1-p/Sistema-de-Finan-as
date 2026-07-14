#ifndef DIALOGTRANSACAO_H
#define DIALOGTRANSACAO_H

#include <QDialog>
#include "pessoa.h"

namespace Ui {
class DialogTransacao;
}

class DialogTransacao : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTransacao(QWidget *parent = nullptr);
    ~DialogTransacao();

    void PreencherFundos(vector<Fundos*>& ListaFundos);
    Transacao CriarTransacao();

private:
    Ui::DialogTransacao *ui;
};

#endif // DIALOGTRANSACAO_H
