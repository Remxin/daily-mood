#pragma once
#ifndef MOODCARD_H
#define MOODCARD_H

#include <QWidget>
#include "mood.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

class MoodCard : public QWidget {
    Q_OBJECT

public:
    MoodCard(Mood &mood, QWidget* parent = nullptr);


};

#endif