#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    // QWidget window;
    // window.setWindowTitle("Dialog");
    // window.setFixedSize(400, 300);

    // QStackedWidget *stackedWidget = new QStackedWidget();

    // QWidget *navbar = new QWidget();
    // QPushButton *movebutton = new QPushButton("MOVE");
    // movebutton->setFixedSize(60, 20);
    // QPushButton *shootbutton = new QPushButton("SHOOT");
    // shootbutton->setFixedSize(60, 20);
    // QPushButton *passbutton = new QPushButton("PASS");
    // passbutton->setFixedSize(60, 20);
    // QPushButton *getbutton = new QPushButton("GET");
    // getbutton->setFixedSize(60, 20);
    // QPushButton *receivebutton = new QPushButton("RECEIVE");
    // receivebutton->setFixedSize(60, 20);

    // QHBoxLayout *navbarbutton = new QHBoxLayout;
    // navbarbutton->addStretch();
    // navbarbutton->addWidget(movebutton);
    // navbarbutton->addWidget(shootbutton);
    // navbarbutton->addWidget(passbutton);
    // navbarbutton->addWidget(getbutton);
    // navbarbutton->addWidget(receivebutton);
    // navbarbutton->addStretch();

    // QVBoxLayout *navbarLayout = new QVBoxLayout;
    // navbarLayout->addLayout(navbarbutton);
    // navbar->setLayout(navbarLayout);

    // QWidget *botbar = new QWidget();
    // QPushButton *undobutton = new QPushButton("UNDO");
    // undobutton->setFixedSize(60, 20);
    // QPushButton *redobutton = new QPushButton("REDO");
    // redobutton->setFixedSize(60, 20);
    // QPushButton *savebutton = new QPushButton("SAVE");
    // savebutton->setFixedSize(60, 20);

    // QHBoxLayout *botbarbutton = new QHBoxLayout;
    // botbarbutton->addStretch();
    // botbarbutton->addWidget(undobutton);
    // botbarbutton->addWidget(savebutton);
    // botbarbutton->addWidget(redobutton);
    // botbarbutton->addStretch();

    // QVBoxLayout *botbarLayout = new QVBoxLayout;
    // botbarLayout->addLayout(botbarbutton);
    // botbar->setLayout(botbarLayout);

    // QWidget *movemenu = new QWidget();

    // QPushButton *okbutton = new QPushButton("OK");
    // okbutton->setFixedSize(60, 20);

    // QPushButton *cancelbutton = new QPushButton("CANCEL");
    // cancelbutton->setFixedSize(60, 20);

    // QLabel *target = new QLabel(" Target :");
    // QLineEdit *targetinput = new QLineEdit;

    // QLabel *movetype = new QLabel("Move Type :");
    // QLineEdit *movetypeinput = new QLineEdit;

    // QFormLayout *inputLayout = new QFormLayout;
    // inputLayout->addRow(target, targetinput);
    // inputLayout->addRow(movetype, movetypeinput);

    // QHBoxLayout *acceptLayout = new QHBoxLayout;
    // acceptLayout->addWidget(okbutton);
    // acceptLayout->addSpacing(-15);
    // acceptLayout->addWidget(cancelbutton);

    // QVBoxLayout *moveLayout = new QVBoxLayout;
    // moveLayout->addSpacing(50);
    // moveLayout->addLayout(inputLayout);
    // moveLayout->addLayout(acceptLayout);
    // movemenu->setLayout(moveLayout);

    // QWidget *shootmenu = new QWidget();

    // QPushButton *lowshootbutton = new QPushButton("LOW SHOOT");
    // lowshootbutton->setFixedSize(100, 20);
    // lowshootbutton->setCheckable(true);

    // QPushButton *loftedshootbutton = new QPushButton("LOFTED SHOOT");
    // loftedshootbutton->setFixedSize(100, 20);
    // loftedshootbutton->setCheckable(true);

    // QLabel *sliderlowshoot = new QLabel("0");
    // QSlider *lowshootval = new QSlider(Qt::Horizontal);
    // lowshootval->setMinimum(0);
    // lowshootval->setMaximum(255);
    // lowshootval->setEnabled(false);

    // QLabel *sliderloftedshoot = new QLabel("0");
    // QSlider *loftedshootval = new QSlider(Qt::Horizontal);
    // loftedshootval->setMinimum(0);
    // loftedshootval->setMaximum(255);
    // loftedshootval->setEnabled(false);

    // QPushButton *resetlowshootbutton = new QPushButton("RESET");
    // resetlowshootbutton->setFixedSize(60, 20);

    // QPushButton *resetloftedshootbutton = new QPushButton("RESET");
    // resetloftedshootbutton->setFixedSize(60, 20);

    // QVBoxLayout *lowshoot = new QVBoxLayout;
    // QVBoxLayout *loftedshoot = new QVBoxLayout;
    // QVBoxLayout *lowshootLayout = new QVBoxLayout;
    // QVBoxLayout *loftedshootLayout = new QVBoxLayout;

    // lowshootLayout->addWidget(lowshootbutton,0 ,Qt::AlignCenter);
    // lowshootLayout->addWidget(sliderlowshoot, 0, Qt::AlignCenter);
    // lowshootLayout->addWidget(lowshootval, 0, Qt::AlignCenter);
    // lowshootLayout->addWidget(resetlowshootbutton, 0, Qt::AlignCenter);

    // loftedshootLayout->addWidget(loftedshootbutton,0 ,Qt::AlignCenter);
    // loftedshootLayout->addWidget(sliderloftedshoot, 0, Qt::AlignCenter);
    // loftedshootLayout->addWidget(loftedshootval, 0, Qt::AlignCenter);
    // loftedshootLayout->addWidget(resetloftedshootbutton, 0, Qt::AlignCenter);

    // lowshoot->addLayout(lowshootLayout);
    // loftedshoot->addLayout(loftedshootLayout);

    // QHBoxLayout *shootlayout = new QHBoxLayout;
    // shootlayout->addLayout(lowshoot);
    // shootlayout->addLayout(loftedshoot);

    // shootmenu->setLayout(shootlayout);

    // QWidget *passmenu = new QWidget();

    // QPushButton *lowpassbutton = new QPushButton("LOW PASS");
    // lowpassbutton->setFixedSize(100, 20);
    // lowpassbutton->setCheckable(true);

    // QPushButton *loftedpassbutton = new QPushButton("LOFTED PASS");
    // loftedpassbutton->setFixedSize(100, 20);
    // loftedpassbutton->setCheckable(true);

    // QLabel *sliderlowpass = new QLabel("0");
    // QSlider *lowpassval = new QSlider(Qt::Horizontal);
    // lowpassval->setMinimum(0);
    // lowpassval->setMaximum(255);
    // lowpassval->setEnabled(false);

    // QLabel *sliderloftedpass = new QLabel("0");
    // QSlider *loftedpassval = new QSlider(Qt::Horizontal);
    // loftedpassval->setMinimum(0);
    // loftedpassval->setMaximum(255);
    // loftedpassval->setEnabled(false);

    // QPushButton *resetlowpassbutton = new QPushButton("RESET");
    // resetlowpassbutton->setFixedSize(60, 20);

    // QPushButton *resetloftedpassbutton = new QPushButton("RESET");
    // resetloftedpassbutton->setFixedSize(60, 20);

    // QVBoxLayout *lowpass = new QVBoxLayout;
    // QVBoxLayout *loftedpass = new QVBoxLayout;
    // QVBoxLayout *lowpassLayout = new QVBoxLayout;
    // QVBoxLayout *loftedpassLayout = new QVBoxLayout;

    // lowpassLayout->addWidget(lowpassbutton,0 ,Qt::AlignCenter);
    // lowpassLayout->addWidget(sliderlowpass, 0, Qt::AlignCenter);
    // lowpassLayout->addWidget(lowpassval, 0, Qt::AlignCenter);
    // lowpassLayout->addWidget(resetlowpassbutton, 0, Qt::AlignCenter);

    // loftedpassLayout->addWidget(loftedpassbutton,0 ,Qt::AlignCenter);
    // loftedpassLayout->addWidget(sliderloftedpass, 0, Qt::AlignCenter);
    // loftedpassLayout->addWidget(loftedpassval, 0, Qt::AlignCenter);
    // loftedpassLayout->addWidget(resetloftedpassbutton, 0, Qt::AlignCenter);

    // lowpass->addLayout(lowpassLayout);
    // loftedpass->addLayout(loftedpassLayout);

    // QHBoxLayout *passlayout = new QHBoxLayout;
    // passlayout->addLayout(lowpass);
    // passlayout->addLayout(loftedpass);

    // passmenu->setLayout(passlayout);

    // stackedWidget->addWidget(movemenu);
    // stackedWidget->addWidget(shootmenu);
    // stackedWidget->addWidget(passmenu);

    // QVBoxLayout *mainLayout = new QVBoxLayout;
    // mainLayout->addWidget(navbar);
    // mainLayout->addWidget(stackedWidget);
    // mainLayout->addWidget(botbar);
    // window.setLayout(mainLayout);

    // QObject::connect(movebutton, &QPushButton::clicked, [&]() {
    //     stackedWidget->setCurrentIndex(0);
    // });

    // QObject::connect(shootbutton, &QPushButton::clicked, [&]() {
    //     stackedWidget->setCurrentIndex(1);
    // });
    // QObject::connect(passbutton, &QPushButton::clicked, [&]() {
    //     stackedWidget->setCurrentIndex(2);
    // });
    // QObject::connect(savebutton, &QPushButton::clicked, [&]() {QMessageBox::StandardButton reply;
    //                     reply = QMessageBox::question(&window, "Dialog", "Save config ?",
    //                             QMessageBox::Yes | QMessageBox::No);

    //     if (reply == QMessageBox::Yes) {
    //         QMessageBox::information(&window, "Dialog", "Save");
    //     } else {
    //         QMessageBox::information(&window, "Dialog", "Cancel");
    //     }
    // });

    // QObject::connect(okbutton, &QPushButton::clicked, [&]() {QMessageBox::StandardButton reply;
    //                     reply = QMessageBox::question(&window, "Dialog", "Save data ?",
    //                             QMessageBox::Yes | QMessageBox::No);

    //     if (reply == QMessageBox::Yes) {
    //         QMessageBox::information(&window, "Dialog", "Save");
    //     } else {
    //         QMessageBox::information(&window, "Dialog", "Cancel");
    //     }
    // });

    // QObject::connect(lowshootbutton, &QPushButton::toggled, [&](bool checked) {
    //     lowshootval->setEnabled(checked);
    // });

    // QObject::connect(loftedshootbutton, &QPushButton::toggled, [&](bool checked) {
    //     loftedshootval->setEnabled(checked);
    // });

    // QObject::connect(lowshootbutton, &QPushButton::clicked, [&]() {
    //     sliderlowshoot->setText(QString::number(lowshootval->value()));
    // });

    // QObject::connect(loftedshootbutton, &QPushButton::clicked, [&]() {
    //     sliderloftedshoot->setText(QString::number(loftedshootval->value()));
    // });

    // QObject::connect(resetlowshootbutton, &QPushButton::clicked, [&]() {
    //     lowshootval->setValue(0);
    //     sliderlowshoot->setText("0");
    // });

    // QObject::connect(resetloftedshootbutton, &QPushButton::clicked, [&]() {
    //     loftedshootval->setValue(0);
    //     sliderloftedshoot->setText("0");
    // });

    // QObject::connect(lowshootval, &QSlider::valueChanged, [&](int value) {
    //     sliderlowshoot->setText(QString::number(value));
    // });

    // QObject::connect(loftedshootval, &QSlider::valueChanged, [&](int value) {
    //     sliderloftedshoot->setText(QString::number(value));
    // });

    // QObject::connect(lowpassbutton, &QPushButton::toggled, [&](bool checked) {
    //     lowpassval->setEnabled(checked);
    // });

    // QObject::connect(loftedpassbutton, &QPushButton::toggled, [&](bool checked) {
    //     loftedpassval->setEnabled(checked);
    // });

    // QObject::connect(lowpassbutton, &QPushButton::clicked, [&]() {
    //     sliderlowpass->setText(QString::number(lowshootval->value()));
    // });

    // QObject::connect(loftedpassbutton, &QPushButton::clicked, [&]() {
    //     sliderloftedpass->setText(QString::number(loftedshootval->value()));
    // });

    // QObject::connect(resetlowpassbutton, &QPushButton::clicked, [&]() {
    //     lowpassval->setValue(0);
    //     sliderlowpass->setText("0");
    // });

    // QObject::connect(resetloftedpassbutton, &QPushButton::clicked, [&]() {
    //     loftedpassval->setValue(0);
    //     sliderloftedpass->setText("0");
    // });

    // QObject::connect(lowpassval, &QSlider::valueChanged, [&](int value) {
    //     sliderlowpass->setText(QString::number(value));
    // });

    // QObject::connect(loftedpassval, &QSlider::valueChanged, [&](int value) {
    //     sliderloftedpass->setText(QString::number(value));
    // });

    // QString buttonstyle =
    //     "QWidget {"
    //         "background-color: #24253A;"
    //     "}"
    //     "QPushButton {"
    //         "font-size: 10px;"
    //         "font-weight: bold;"
    //         "font-family: Sans-serif;"
    //         "background-color: #D745CE;"
    //         "color: white;"
    //         "border: none;"
    //         "border-radius: 5px;"
    //     "}"
    //     "QPushButton::hover {"
    //         "background-color:#B038A3 ;"
    //     "}"
    //     "QRadioButton {"
    //         "font-size: 10px;"
    //         "font-weight: bold;"
    //         "font-family: Sans-serif;"
    //         "color: white;"
    //     "}"
    //     "QPushButton:hover {"
    //         "background-color: #B038A3;"
    //     "}"
    //     "QLabel {"
    //         "font-weight: bold;"
    //         "font-family: Sans-serif;"
    //         "color: white;"
    //     "}";


    // window.setStyleSheet(buttonstyle);

    // window.show();
    return a.exec();
}
