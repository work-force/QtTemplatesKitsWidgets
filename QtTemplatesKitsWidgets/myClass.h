#pragma once

#include <QtWidgets/QWidget>
#include "ui_myClass.h"

void STLstyleItr();
void qvariant();

class myClass : public QWidget
{
	Q_OBJECT

public:
	myClass(QWidget *parent = Q_NULLPTR);

private:
	Ui::myClassClass ui;
};
