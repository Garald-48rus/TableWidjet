#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>


namespace Ui {
class GameField;
}

class GameField : public QWidget
{
    Q_OBJECT

public:
    explicit GameField(QWidget *parent = nullptr);
    ~GameField();

private:
    Ui::GameField *ui;

public:
signals:
    void firstWindow();  // Сигнал для первого окна на открытие


private slots:
    void on_pushButton_clicked();


};

#endif // GAMEFIELD_H
