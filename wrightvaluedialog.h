#ifndef WRIGHTVALUEDIALOG_H
#define WRIGHTVALUEDIALOG_H

#include <QDialog>
#include <QDebug>
#include "modbusmaster.h"

namespace Ui {
class WrightValueDialog;
}

class WrightValueDialog : public QDialog
{
	Q_OBJECT
public slots:
	void openingslot(QString,QString,QString,int);

public:
	explicit WrightValueDialog(QWidget *parent = 0);
	~WrightValueDialog();
//	void openingslot(QString &ID,QString &Address,QString &Quantity);
	QImage *i;
	bool error,good;
	ModBusMaster ModBusMaster_new;
private slots:
	void on_pushButton_clicked();

private:
	Ui::WrightValueDialog *ui;
};

#endif // WRIGHTVALUEDIALOG_H
