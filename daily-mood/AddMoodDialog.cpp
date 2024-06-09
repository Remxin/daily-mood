#include "AddMoodDialog.h"
#include "fileReader.h"
#include "dailymood.h"
#include <QMessageBox>
#include <QIcon>

AddMoodDialog::AddMoodDialog(QWidget* parent)
    : QDialog(parent), acceptButton(new QPushButton("Accept", this)), layout(new QVBoxLayout(this)) {
    this->resize(400, 300);
    
    QLabel* labelRating = new QLabel(this);
    labelRating->setText("Your rating");
    QVBoxLayout* starsLayout = new QVBoxLayout(this);
    starsLayout->setDirection(QBoxLayout::LeftToRight);
    this->rating = 0;

    for (int i = 0; i < 5; i++) {
        QPushButton* star = new QPushButton(this);
        star->setObjectName("starButton");
        star->setIcon(QIcon("star-blank.png"));
        star->setIconSize(QSize(65, 65));
        this->stars.push_back(star);
        connect(star, &QPushButton::clicked, this, [=]() { onStarClick(i); });
        starsLayout->addWidget(star);
    }


    QLabel* labelDescription = new QLabel(this);
    labelDescription->setText("Your description");
    QLineEdit* lineEditDescription = new QLineEdit(this);
    labelRating->setObjectName(QString::fromUtf8("labelName"));
    this->acceptButton->setText("Update todays mood");

    this->labelRating = labelRating;
    this->starsLayout = starsLayout;
    this->labelDescription = labelDescription;
    this->lineEditDescription = lineEditDescription;
    this->setButtonAvailability();

    layout->addWidget(labelRating);
    layout->addLayout(starsLayout);
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
    this->rating = count+1;
    this->setButtonAvailability();
}

void AddMoodDialog::setButtonAvailability() {
    if (this->rating < 1) {
        this->acceptButton->setEnabled(false);
    } else {
        this->acceptButton->setEnabled(true);
    }
}

int AddMoodDialog::getRating() { return this->rating; };
std::string AddMoodDialog::getDescription() { return this->lineEditDescription->text().toStdString(); };