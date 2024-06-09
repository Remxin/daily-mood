#include "MoodCard.h"

MoodCard::MoodCard(Mood& mood, QWidget* parent) {
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setDirection(QBoxLayout::TopToBottom);
    layout->setObjectName("moodContainer");

    QString rating = QString::number(mood.getRating()) + "/5";
    // Create labels for displaying Todo details
    QLabel* titleLabel = new QLabel("Your mood");
    titleLabel->setObjectName("moodTitle");
    QLabel* dateLabel = new QLabel(QString::fromStdString(mood.getDate()));
    dateLabel->setObjectName("moodDate");
    QLabel* ratingLabel = new QLabel(rating);
    ratingLabel->setObjectName("moodRating");
    QLabel* descriptionLabel = new QLabel(QString::fromStdString(mood.getDescription()));
    descriptionLabel->setObjectName("moodDescription");
 

    // Add widgets to layout
    layout->addWidget(titleLabel);
    layout->addWidget(dateLabel);
    layout->addWidget(ratingLabel);
    layout->addWidget(descriptionLabel);

    // Set layout to the widget
    setLayout(layout);
}