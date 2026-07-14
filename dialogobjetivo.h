#ifndef DIALOGOBJETIVO_H
#define DIALOGOBJETIVO_H

#include <QDialog>

namespace Ui {
class DialogObjetivo;
}

class DialogObjetivo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogObjetivo(QWidget *parent = nullptr);
    ~DialogObjetivo();

private:
    Ui::DialogObjetivo *ui;
};

#endif // DIALOGOBJETIVO_H
