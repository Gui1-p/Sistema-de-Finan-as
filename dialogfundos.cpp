#include "dialogfundos.h"
#include "ui_dialogfundos.h"

DialogFundos::DialogFundos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogFundos)
{
    ui->setupUi(this);
}

DialogFundos::~DialogFundos()
{
    delete ui;
}
