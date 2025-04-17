#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setMainUi();
    setupMainConnections();

    this->setStyleSheet(ui_style);
}

void MainWindow::setMainUi()
{
    setWindowTitle("AUTOGEN STRATEGY");
    setFixedSize(400, 400);
    stackedWidget = new QStackedWidget(this);

    QWidget *navbar = new QWidget();
    movebutton = new QPushButton("MOVE");
    shootbutton = new QPushButton("SHOOT");
    getbutton = new QPushButton("GET");
    receivebutton = new QPushButton("RECEIVE");

    movebutton->setFixedSize(60, 20);
    shootbutton->setFixedSize(60, 20);
    getbutton->setFixedSize(60, 20);
    receivebutton->setFixedSize(60, 20);

    QHBoxLayout *navbarbutton = new QHBoxLayout;
    navbarbutton->addStretch();
    navbarbutton->addWidget(movebutton);
    navbarbutton->addWidget(shootbutton);
    navbarbutton->addWidget(getbutton);
    navbarbutton->addWidget(receivebutton);
    navbarbutton->addStretch();

    QVBoxLayout *navbarLayout = new QVBoxLayout;
    navbarLayout->addLayout(navbarbutton);
    navbar->setLayout(navbarLayout);

    AddBehaviorButt = new QPushButton("ADD BEHAVIOR");
    AddBehaviorButt->setFixedSize(120, 20);

    DeleteBehaviorButt = new QPushButton("DELETE BEHAVIOR");
    DeleteBehaviorButt->setFixedSize(120, 20);

    savebutton = new QPushButton("SAVE");
    savebutton->setFixedSize(60, 20);

    QWidget *botbar = new QWidget();
    QHBoxLayout *botbarbutton = new QHBoxLayout;
    botbarbutton->addStretch();
    botbarbutton->addWidget(AddBehaviorButt);
    botbarbutton->addWidget(savebutton);
    botbarbutton->addWidget(DeleteBehaviorButt);
    botbarbutton->addStretch();

    QVBoxLayout *botbarLayout = new QVBoxLayout;
    botbarLayout->addLayout(botbarbutton);
    botbar->setLayout(botbarLayout);

    //Target Format
    QRegExp regex("^\\d+;\\d+;\\d+$"); 
    QValidator *validator = new QRegExpValidator(regex, this);

    // ###     Move Menu
    QWidget *movemenu = new QWidget();
    QLabel *targetLabel = new QLabel("Target :");
    targetinput = new QLineEdit();
    targetinput->setValidator(validator);

    QLabel *movetypeLabel = new QLabel("Move Type :");
    movetypeinput = new QComboBox();
    movetypeinput->addItem("PATH");
    movetypeinput->addItem("GLOBAL");
    movetypeinput->addItem("AVOID_BALL");

    QLabel *nameMoveLabel = new QLabel("Name: ");
    nameMoveinput = new QLineEdit();

    QLabel *toleranceLabel = new QLabel("Tolerance :");
    toleranceinput = new QLineEdit();
    toleranceinput->setValidator(validator);

    QLabel *stateLabel = new QLabel("Robot State:");
    state_robotinput = new QComboBox();
    state_robotinput->addItem("RUNNING");
    state_robotinput->addItem("FINISH");
    state_robotinput->addItem("READY");
    state_robotinput->addItem("KICK");

    QFormLayout *inputMoveLayout = new QFormLayout;
    inputMoveLayout->addRow(nameMoveLabel, nameMoveinput);
    inputMoveLayout->addRow(targetLabel, targetinput);
    inputMoveLayout->addRow(toleranceLabel, toleranceinput);
    inputMoveLayout->addRow(movetypeLabel, movetypeinput);
    inputMoveLayout->addRow(stateLabel, state_robotinput);

    // ####################

    // ### Shoot Menu
    QWidget *shootmenu = new QWidget();

    // Labels and Inputs
    QLabel *nameKickLabel = new QLabel("Name Behavior:");
    kickNameinput = new QLineEdit();

    targetKickLabel = new QLabel("Target Kick:");
    kickTargetinput = new QLineEdit();
    kickTargetinput->setValidator(validator);

    // Initially hide the Target Kick UI
    targetKickLabel->setVisible(false);
    kickTargetinput->setVisible(false);

    kickTypeLabel = new QLabel("Kick Type:");
    kickTypeinput = new QComboBox();
    kickTypeinput->addItems({"Pass", "Shoot"});

    QLabel *shootTypeLabel = new QLabel("Shoot Type:");
    shootTypeinput = new QComboBox();
    shootTypeinput->addItems({"Lob Shoot", "Flat Shoot"});

    QLabel *kickPowerLabel = new QLabel("Power:");
    kickSlider = new QSlider(Qt::Horizontal);
    kickSlider->setRange(0, 255);
    kickSlider->setEnabled(false);

    kickPowerValueLabel = new QLabel("0");

    // Buttons
    Kickbutton = new QPushButton("KICK");
    Kickbutton->setFixedSize(60, 20);

    resetKickButton = new QPushButton("Reset Power");
    resetKickButton->setFixedSize(120, 20);

    // Form layout for inputs
    QFormLayout *inputKickLayout = new QFormLayout;
    inputKickLayout->addRow(nameKickLabel, kickNameinput);
    inputKickLayout->addRow(targetKickLabel, kickTargetinput);
    inputKickLayout->addRow(kickTypeLabel, kickTypeinput);
    inputKickLayout->addRow(shootTypeLabel, shootTypeinput);

    // Layout for slider and power label
    QHBoxLayout *powerLayout = new QHBoxLayout;
    powerLayout->addWidget(kickPowerLabel);
    powerLayout->addWidget(kickSlider);
    powerLayout->addWidget(kickPowerValueLabel);

    // Vertical layout for the whole menu
    QVBoxLayout *shootLayout = new QVBoxLayout;
    shootLayout->setSpacing(10);
    shootLayout->setContentsMargins(30, 20, 30, 20); // padding from edges
    shootLayout->addLayout(inputKickLayout);
    shootLayout->addWidget(Kickbutton, 0, Qt::AlignHCenter);
    shootLayout->addLayout(powerLayout);
    shootLayout->addWidget(resetKickButton, 0, Qt::AlignHCenter);

    shootmenu->setLayout(shootLayout);

    // ####################

    QVBoxLayout *moveLayout = new QVBoxLayout;
    moveLayout->addSpacing(30);
    moveLayout->addLayout(inputMoveLayout);
    movemenu->setLayout(moveLayout);

    stackedWidget->addWidget(movemenu);
    stackedWidget->addWidget(shootmenu);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(navbar);
    mainLayout->addWidget(stackedWidget);
    mainLayout->addWidget(botbar);

    QWidget *central = new QWidget(this);
    central->setLayout(mainLayout);
    setCentralWidget(central);


}

void MainWindow::setupMainConnections()
{
    // Navigation Buttons
    connect(movebutton, &QPushButton::clicked, [this]()
            { stackedWidget->setCurrentIndex(0); 
            
            this->ui_selected = 1; });
    connect(shootbutton, &QPushButton::clicked, [this]()
            { stackedWidget->setCurrentIndex(1); this->ui_selected=2; });

    // Shoot Menu
    connect(kickSlider, &QSlider::valueChanged, [this](int value)
            {QString value_str =  QString::number(value); 
            kickPowerValueLabel->setText(value_str); 
            this->kickPower = value_str;});

    connect(Kickbutton, &QPushButton::clicked, [this]()
            { kickSlider->setEnabled(!kickSlider->isEnabled()); });

    connect(resetKickButton, &QPushButton::clicked, [this]()
            { kickSlider->setValue(0); });

    connect(kickNameinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->nameKick = text; });
    connect(kickTargetinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->targetKick = text; });

    // Connect the Kick Type dropdown to show/hide the Target Kick UI
    connect(kickTypeinput, &QComboBox::currentTextChanged, [this](const QString &text)
            {
        kickTargetinput->clear();
        bool isPass = (text == "Shoot");
        this->targetKickLabel->setVisible(isPass);
        this->kickTargetinput->setVisible(isPass);
        
        this->kickType = text; });

    connect(shootTypeinput, &QComboBox::currentTextChanged, [this](const QString &text)
            { this->shootType = text;  });
    // End Shoot Menu


    // Move Menu
    connect(targetinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->targetMove = text;  });
    connect(nameMoveinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->nameMove = text; });
    connect(toleranceinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->toleranceMove = text;});
    connect(movetypeinput, &QComboBox::currentTextChanged, [this](const QString &text)
            { this->movetypeMove = text;  });
    connect(state_robotinput, &QComboBox::currentTextChanged, [this](const QString &text)
            { this->state_robot = text;});

    //End Move Menu

    // Get Button Action
    connect(getbutton, &QPushButton::clicked, [this]()
            { this->ui_selected = 3; });

    // Receive Button Action
    connect(receivebutton, &QPushButton::clicked, [this]()
            { this->ui_selected = 4; });
}

void MainWindow::addBehavorAct()
{
    switch (ui_selected)
    {
    case 1:
        /* code */
        break;

    case 2:
        /* code */
        break;

    case 3:
        /* code */
        break;

    case 4:
        /* code */
        break;

    default:
        break;
    }
}
