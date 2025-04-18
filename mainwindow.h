#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QRadioButton>
#include <QString>
#include <QLineEdit>
#include <QFormLayout>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include "icecream.hpp"
#include <QComboBox>
#include "tinyxml2.h"
#include <iostream>
#include <string>
#include "QFileDialog"
#include "QInputDialog"

using namespace tinyxml2;

enum KickType
{
    PASS,
    SHOOT
};

struct Pose2D
{

    Pose2D() : x_(0), y_(0), theta_(0)
    {
    }
    Pose2D(int x, int y, int theta) : x_(x), y_(y), theta_(theta)
    {
    }

    int x_, y_, theta_;
};



QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    QString ui_style =
        "QWidget {"
        "background-color: #24253A;"
        "}"
        "QPushButton {"
        "font-size: 10px;"
        "font-weight: bold;"
        "font-family: Sans-serif;"
        "background-color: #D745CE;"
        "color: white;"
        "border: none;"
        "border-radius: 5px;"
        "}"
        "QPushButton::hover {"
        "background-color:#B038A3;"
        "}"
        "QRadioButton {"
        "font-size: 10px;"
        "font-weight: bold;"
        "font-family: Sans-serif;"
        "color: white;"
        "}"
        "QLabel {"
        "font-weight: bold;"
        "font-family: Sans-serif;"
        "color: white;"
        "}"
        "QLineEdit {"
        "background-color:rgb(247, 246, 247);"
        "}"

        "QComboBox {"
        "background-color: white;"
        "font-size: 10px;"
        "font-weight: bold;"
        "font-family: Sans-serif;"
        "color: black;"
        "border-radius: 5px;"
        "padding: 5px 30px 5px 10px;"
        "min-width: 6em;"
        "}"

        "QComboBox:hover {"
        "border: 1px solid #B038A3;"
        "}"

        "QComboBox::drop-down {"
        "subcontrol-origin: padding;"
        "subcontrol-position: top right;"
        "width: 20px;"
        "border-left: 1px solid #D745CE;"
        "border-top-right-radius: 5px;"
        "border-bottom-right-radius: 5px;"
        "background-color: #D745CE;"
        "}"

        "QComboBox::down-arrow {"
        // "image: url(:/icons/arrow-down.png);" // optional: change or comment if unused
        "width: 10px;"
        "height: 10px;"
        "}"

        "QComboBox QAbstractItemView {"
        "background-color: white;"
        "selection-background-color: #D745CE;"
        "selection-color: white;"
        "}";

private slots:
    void addBehavorAct();
    void deleteBehavorAct();
    void saveBehavorAct();

private:
    QStackedWidget *stackedWidget;

    // Navigation Buttons
    QPushButton *movebutton;
    QPushButton *shootbutton;
    QPushButton *getbutton;
    QPushButton *receivebutton;

    // Bottom bar buttons
    QPushButton *AddBehaviorButt;
    QPushButton *DeleteBehaviorButt;
    QPushButton *savebutton;

    // Move menu
    QLineEdit *targetinput;
    QComboBox *movetypeinput;
    QLineEdit *toleranceinput;
    QComboBox *state_robotinput;
    QLineEdit *nameMoveinput;

    // UI Setup
    void setMainUi();
    void setupMainConnections();

    // Behavior Generate
    void addMove();
    void addKick();
    void addGet();
    void createFirstRoot();

    // Kick menu
    QPushButton *Kickbutton;
    QSlider *kickSlider;
    QLabel *kickPowerValueLabel;
    QPushButton *resetKickButton;
    QComboBox *kickTypeinput;
    QComboBox *shootTypeinput;
    QLineEdit *kickNameinput;
    QLineEdit *kickTargetinput;
    QLabel *kickTypeLabel;
    QLabel *targetKickLabel;
    // Variable
    int ui_selected = 1;

    // Store Value From UI
    QString nameMove, targetMove, toleranceMove, movetypeMove = "PATH", state_robot = "RUNNING";
    QString nameKick, targetKick, kickType = "Pass", shootType = "Flat Shoot", kickPower;
    

    QString selectedBehavior = "MOVE";
    int num_get = 0, num_receive = 0, getBallType=0;


    // XML Document
    XMLDocument doc;
    XMLElement *sequence, *bt;

};
#endif // MAINWINDOW_H
