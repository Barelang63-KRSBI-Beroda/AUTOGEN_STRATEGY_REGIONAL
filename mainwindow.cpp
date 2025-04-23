#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createFirstRoot();
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
    shootbutton = new QPushButton("KICK");
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

    // Target Format
    QRegExp regex("^-?\\d+;-?\\d+;-?\\d+$");
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
    shootTypeinput->addItems({"Flat Shoot", "Lob Shoot"});

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

void MainWindow::clearAllInput()
{
    // Clear all input fields
    nameMoveinput->clear();
    targetinput->clear();
    toleranceinput->clear();
    movetypeinput->setCurrentIndex(0);
    state_robotinput->setCurrentIndex(0);

    kickNameinput->clear();
    kickTargetinput->clear();
    kickSlider->setValue(0);
    kickTypeinput->setCurrentIndex(0);
    shootTypeinput->setCurrentIndex(0);
}

void MainWindow::setupMainConnections()
{
    // Navigation Buttons
    connect(movebutton, &QPushButton::clicked, [this]()
            { stackedWidget->setCurrentIndex(0); 
            selectedBehavior = "MOVE";
            clearAllInput();
            this->ui_selected = 1; });
    connect(shootbutton, &QPushButton::clicked, [this]()
            { stackedWidget->setCurrentIndex(1); this->ui_selected=2;
    clearAllInput();
            selectedBehavior = "KICK"; });

    // Get Button Action
    connect(getbutton, &QPushButton::clicked, [this]()
            { this->ui_selected = 3;
                 getBallType = 1; selectedBehavior = "GET"; clearAllInput(); });

    // Receive Button Action
    connect(receivebutton, &QPushButton::clicked, [this]()
            { this->ui_selected = 4; 
                getBallType = 0; selectedBehavior = "RECEIVE";  clearAllInput(); });
    // End Navigation Buttons

    // Shoot Menu
    connect(kickSlider, &QSlider::valueChanged, [this](int value)
            {QString value_str =  QString::number(value); 
            kickPowerValueLabel->setText(value_str); 
            this->kickPower = value_str; });

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
        bool isShoot = (text == "Shoot");
        this->targetKickLabel->setVisible(isShoot);
        this->kickTargetinput->setVisible(isShoot);
        
        this->kickType = text; });

    connect(shootTypeinput, &QComboBox::currentTextChanged, [this](const QString &text)
            { this->shootType = text; });
    // End Shoot Menu

    // Move Menu
    connect(targetinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->targetMove = text; });
    connect(nameMoveinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->nameMove = text; });
    connect(toleranceinput, &QLineEdit::textChanged, [this](const QString &text)
            { this->toleranceMove = text; });
    connect(movetypeinput, &QComboBox::currentTextChanged, [this](const QString &text)
            { this->movetypeMove = text; });
    connect(state_robotinput, &QComboBox::currentTextChanged, [this](const QString &text)
            { this->state_robot = text; });
    // End Move Menu

    // Add Behavior Button
    connect(AddBehaviorButt, &QPushButton::clicked, this, &MainWindow::addBehavorAct);
    connect(DeleteBehaviorButt, &QPushButton::clicked, this, &MainWindow::deleteBehavorAct);
    connect(savebutton, &QPushButton::clicked, this, &MainWindow::saveBehavorAct);
}

void MainWindow::createFirstRoot()
{
    // Create the root element
    doc.InsertFirstChild(doc.NewDeclaration());
    auto *root = doc.NewElement("root");
    root->SetAttribute("BTCPP_format", "4");
    doc.InsertEndChild(root);

    bt = doc.NewElement("BehaviorTree");
    bt->SetAttribute("ID", "COBA1");
    root->InsertEndChild(bt);

    sequence = doc.NewElement("Sequence");
    bt->InsertEndChild(sequence);
}

void MainWindow::deleteBehavorAct()
{
    QStringList behaviorList;

    // Step 1: Collect all getBall "name" attributes
    for (XMLElement *rf = sequence->FirstChildElement(); rf != nullptr; rf = rf->NextSiblingElement())
    {
        IC(rf->Name());
        for (XMLElement *child = rf->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
        {

            const char *nameAttr = child->Attribute("name");
            IC(child->Name(), nameAttr);
            if (nameAttr)
                behaviorList.append(QString(nameAttr));
        }
    }

    if (behaviorList.isEmpty())
    {
        QMessageBox::information(this, "No Behaviors", "No getBall behaviors available to delete.");
        return;
    }

    // Step 2: Let user choose which to delete
    bool ok;
    QString selectedBehavior = QInputDialog::getItem(this, "Select Behavior to Delete",
                                                     "Behavior:", behaviorList, 0, false, &ok);
    if (!ok || selectedBehavior.isEmpty())
        return;

    // Step 3: Confirm deletion
    if (QMessageBox::question(this, "Confirm Delete",
                              "Are you sure you want to delete getBall: " + selectedBehavior,
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes)
        return;

    // Step 4: Delete the selected getBall
    for (XMLElement *rf = sequence->FirstChildElement(); rf != nullptr; rf = rf->NextSiblingElement())
    {
        for (XMLElement *child = rf->FirstChildElement(); child != nullptr;)
        {
            XMLElement *nextChild = child->NextSiblingElement();
            const char *nameAttr = child->Attribute("name");
            if (nameAttr && QString(nameAttr) == selectedBehavior)
            {
                sequence->DeleteChild(rf);
                QMessageBox::information(this, "Deleted", selectedBehavior + "' deleted successfully.");
                return;
            }
            child = nextChild;
        }
    }
}
void MainWindow::saveBehavorAct()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", "command.xml", "XML Files (*.xml)");
    QFileInfo fileInfo(filePath); // Create QFileInfo object from the file path
    if (!filePath.isEmpty())
    {

        // this->savedFileName = fileInfo.fileName(); // Store the saved file name in a variable
        bt->SetAttribute("ID", fileInfo.baseName().toStdString().c_str());
        // Save the XML document
        XMLError result = doc.SaveFile(filePath.toStdString().c_str());
        if (result == XML_SUCCESS)
        {
            QMessageBox::information(this, "Save Successful", "XML saved to: " + filePath);
        }
        else
        {
            QMessageBox::warning(this, "Save Failed", "Failed to save XML. Error code: " + QString::number(result));
        }
    }
}
void MainWindow::addMove()
{
    auto *sequence_move = doc.NewElement("Sequence");

    auto *movetype = doc.NewElement("Script");
    movetype->SetAttribute("code", ("MoveType:=" + movetypeMove.toStdString()).c_str());

    auto *run_state = doc.NewElement("Script");
    run_state->SetAttribute("code", ("RobotState:=" + state_robot.toStdString()).c_str());

    auto *actionMove = doc.NewElement("Move");
    actionMove->SetAttribute("counter", "0");
    actionMove->SetAttribute("name", nameMove.toStdString().c_str());
    actionMove->SetAttribute("tarPos", targetMove.toStdString().c_str());
    actionMove->SetAttribute("tolerance", toleranceMove.toStdString().c_str());
    actionMove->SetAttribute("type", "{MoveType}");
    actionMove->SetAttribute("stateRobot", "{RobotState}");

    sequence_move->InsertEndChild(movetype);
    sequence_move->InsertEndChild(run_state);
    sequence_move->InsertEndChild(actionMove);

    sequence->InsertEndChild(sequence_move);
}

void MainWindow::addKick()
{
    auto *reactiveSeq = doc.NewElement("ReactiveSequence");

    // Create and configure the isReadyToPass element
    auto *isReadyToPass = doc.NewElement("isReadyToPass");
    isReadyToPass->SetAttribute("name", nameKick.toStdString().c_str());

    // Determine kick type and set attributes accordingly
    if (kickType == "Shoot")
    {
        isReadyToPass->SetAttribute("type", "1");
        isReadyToPass->SetAttribute("target", targetKick.toStdString().c_str());
    }
    else
    {
        isReadyToPass->SetAttribute("type", "0");
        isReadyToPass->SetAttribute("target", "0;0;0");
    }

    reactiveSeq->InsertEndChild(isReadyToPass);

    // Create and configure the pass element
    auto *pass = doc.NewElement("pass");
    pass->SetAttribute("kickPower", kickPower.toStdString().c_str());
    pass->SetAttribute("type", (shootType == "Lob Shoot" ? "1" : "0"));

    reactiveSeq->InsertEndChild(pass);

    // Add the reactive sequence to the main sequence
    sequence->InsertEndChild(reactiveSeq);
}

void MainWindow::addGet()
{
    auto *rfb_getball = doc.NewElement("ReactiveFallback");

    rfb_getball->InsertEndChild(doc.NewElement("isGrabBall"));
    std::string name = "kejarBola";
    if (getBallType == 1)
    {
        num_get++;
        name += std::to_string(num_get);
    }
    else
    {
        num_receive++;
        name += std::to_string(num_receive);
    }

    auto *getBall = doc.NewElement("getBall");
    getBall->SetAttribute("name", name.c_str());
    getBall->SetAttribute("sudut", "0");
    getBall->SetAttribute("type", std::to_string(getBallType).c_str());
    rfb_getball->InsertEndChild(getBall);

    rfb_getball->InsertEndChild(doc.NewElement("stopMotor"));

    sequence->InsertEndChild(rfb_getball);
}

void MainWindow::addBehavorAct()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Add Behavior", "Do you want to add the behavior: " + selectedBehavior + "?",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (reply == QMessageBox::Yes)
    {
        QMessageBox::information(this, "Add Behavior", "Behavior added: " + selectedBehavior);
        switch (ui_selected)
        {
        case 1:
            addMove();
            break;

        case 2:
            addKick();
            break;

        case 3:
            addGet();
            break;

        case 4:
            addGet();
            break;

        default:
            break;
        }
    }
    else
    {
        QMessageBox::information(this, "Add Behavior", "Behavior addition canceled.");
    }
}
