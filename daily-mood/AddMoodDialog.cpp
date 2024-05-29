#include "AddMoodDialog.h"
#include <QMessageBox>
#include <QIcon>

AddMoodDialog::AddMoodDialog(QWidget* parent)
    : QDialog(parent), acceptButton(new QPushButton("Accept", this)), layout(new QVBoxLayout(this)) {
    this->resize(400, 300);
    
    QLabel* labelRating = new QLabel(this);
    labelRating->setText("Your rating");
    QVBoxLayout* starLayout = new QVBoxLayout(this);
    starLayout->setDirection(QBoxLayout::LeftToRight);

    for (int i = 0; i < 5; i++) {
        QPushButton* star = new QPushButton(this);
        star->setIcon(QIcon("star-blank.png"));
        star->setIconSize(QSize(65, 65));
        this->stars.push_back(star);
        connect(star, &QPushButton::clicked, this, [=]() { onStarClick(i); });
        starLayout->addWidget(star);
    }


    QLabel* labelDescription = new QLabel(this);
    labelDescription->setText("Your description");
    QLineEdit* lineEditDescription = new QLineEdit(this);
    labelRating->setObjectName(QString::fromUtf8("labelName"));
    acceptButton->setText("Update todays mood");

    layout->addWidget(labelRating);
    layout->addLayout(starLayout);
    layout->addWidget(labelDescription);
    layout->addWidget(lineEditDescription);
    layout->addWidget(acceptButton);
    connect(acceptButton, &QPushButton::clicked, this, &AddMoodDialog::onAccept);
    setLayout(layout);
    setWindowTitle("Update Mood");
}


void AddMoodDialog::onAccept() {
    QMessageBox::information(this, "Modal Dialog", "Accept button clicked");
    accept();
}

void AddMoodDialog::onStarClick(int count) {
    for (int i = 0; i < 5; i++) {
        if (i <= count) {
            this->stars[i]->setIcon(QIcon("star.png"));
        }
        else {
            this->stars[i]->setIcon(QIcon("star-blank.png"));
        }
        this->stars[i]->setIconSize(QSize(65, 65));
    }
    
}
