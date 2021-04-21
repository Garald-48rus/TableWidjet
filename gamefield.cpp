#include "gamefield.h"
#include "ui_gamefield.h"

GameField::GameField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameField)
{
    ui->setupUi(this);

}

GameField::~GameField()
{
    delete ui;



}
//==========================================
void GameField::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    ui->tableWidget->clear();//очищаю поле инвентарь
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
