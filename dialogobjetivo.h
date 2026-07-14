#ifndef DIALOGOBJETIVO_H
#define DIALOGOBJETIVO_H

#include <QDialog>
#include "objetivo.h"

namespace Ui {
class DialogObjetivo;
}

class DialogObjetivo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogObjetivo(QWidget *parent = nullptr);
    ~DialogObjetivo();

    Objetivo CriarObjetivo();

private:
    Ui::DialogObjetivo *ui;
};

#endif // DIALOGOBJETIVO_H
