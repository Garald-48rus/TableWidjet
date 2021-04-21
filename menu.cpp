#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    mGameField = new GameField();// Инициализируем игрово окно
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    QObject::connect(mGameField,&GameField::firstWindow, this, &Menu::show);
}
//========================================================
Menu::~Menu()
{
    delete ui;
    delete mGameField;
}
//=========================================================

void Menu::on_pushButton_2_clicked()
{
    QApplication::exit(); //закрытие программы
}
//=========================================================
void Menu::on_pushButton_clicked()
{
    mGameField->show();  // Показываем игровое окно
    this->close();    // Закрываем основное окно
}
