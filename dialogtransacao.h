#ifndef DIALOGTRANSACAO_H
#define DIALOGTRANSACAO_H

#include <QDialog>

namespace Ui {
class DialogTransacao;
}

class DialogTransacao : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTransacao(QWidget *parent = nullptr);
    ~DialogTransacao();

private:
    Ui::DialogTransacao *ui;
};

#endif // DIALOGTRANSACAO_H
