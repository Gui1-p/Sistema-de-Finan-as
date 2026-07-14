#include "dialogobjetivo.h"
#include "ui_dialogobjetivo.h"

DialogObjetivo::DialogObjetivo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogObjetivo)
{
    ui->setupUi(this);
}

DialogObjetivo::~DialogObjetivo()
{
    delete ui;
}
