#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::set_players(Player** players)
{
    this->players = players;
}

void Settings::on_buttonBox_accepted()
{
    players[0]->color = ui->OLineEdit->text();
    players[1]->color = ui->XLineEdit->text();
}
