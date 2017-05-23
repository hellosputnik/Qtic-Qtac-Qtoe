#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

#include "tic-tac-toe.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:

    Player** players;

    explicit Settings(QWidget *parent = 0);
    ~Settings();

    void set_players(Player** players);

private slots:

    void on_buttonBox_accepted();

private:

    Ui::Settings *ui;

};

#endif // SETTINGS_H
