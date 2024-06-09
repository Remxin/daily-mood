#include "MoodCard.h"

MoodCard::MoodCard(Mood& mood, QWidget* parent) {
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setDirection(QBoxLayout::TopToBottom);

    QString rating = QString::number(mood.getRating()) + "/5";
    // Create labels for displaying Todo details
    QLabel* titleLabel = new QLabel("Your mood");
    QLabel* dateLabel = new QLabel(QString::fromStdString(mood.getDate()));
    QLabel* ratingLabel = new QLabel(rating);
    QLabel* descriptionLabel = new QLabel(QString::fromStdString(mood.getDescription()));
   
 

    // Add widgets to layout
    layout->addWidget(titleLabel);
    layout->addWidget(dateLabel);
    layout->addWidget(ratingLabel);
    layout->addWidget(descriptionLabel);

    // Set layout to the widget
    setLayout(layout);
}