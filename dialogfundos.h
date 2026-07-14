#ifndef DIALOGFUNDOS_H
#define DIALOGFUNDOS_H

#include <QDialog>
#include "fundos.h"

namespace Ui {
class DialogFundos;
}

class DialogFundos : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFundos(QWidget *parent = nullptr);
    ~DialogFundos();

    Fundos* CriarFundo(size_t Id);

private:
    Ui::DialogFundos *ui;
};

#endif // DIALOGFUNDOS_H
