#include "wrightvaluedialog.h"
#include "ui_wrightvaluedialog.h"
#include <QToolButton>
#include <QSplashScreen>
WrightValueDialog::WrightValueDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WrightValueDialog)
{
	ui->setupUi(this);
	//connect(d.pushButton, SIGNAL("clicked()"), this->clicked());
//	connect(, SIGNAL(clicked()),this,SLOT(openingslot());
//	connect(,SIGNAL(osman()),this,SLOT(open));
}

WrightValueDialog::~WrightValueDialog()
{
	delete ui;
}
void WrightValueDialog::openingslot(QString ID1,QString Address1,QString Quantity1,int Index)
{
//	ID,Address,Quantity
	int addres = (Address1.toInt()+Index);
	ui->lineEdit->setText(ID1);
	ui->lineEdit_2->setText(Address1);
	ui->lineEdit_2->setText(QString::number(addres));
	ui->lineEdit_3->setText(Quantity1);
	ui->lineEdit_4->setText("");

	int w = ui->Resultlabel->width();
	int h = ui->Resultlabel->height();


	if(good && !error)
	{
		i = new QImage(":/images/green.png");
		QImage podng = i->scaled(w,h,Qt::KeepAspectRatio);
		ui->Resultlabel->setPixmap(QPixmap::fromImage(podng,Qt::AutoColor));
	}
	else if(!good && error)
	{
		i = new QImage(":/images/red.png");
		QImage podng = i->scaled(w,h,Qt::KeepAspectRatio);
		ui->Resultlabel->setPixmap(QPixmap::fromImage(podng,Qt::AutoColor));
	}
	else
	{
		i = new QImage(":/images/yellow.png");
		QImage podng = i->scaled(w,h,Qt::KeepAspectRatio);
		ui->Resultlabel->setPixmap(QPixmap::fromImage(podng,Qt::AutoColor));
	}
//	ui->lineEdit->setText("asd");
//	qDebug() << "Hello world.";
//	qDebug() << ID1;
//	ui->lineEdit->setText("1");
}





void WrightValueDialog::on_pushButton_clicked()
{
	QString sendpackage = ModBusMaster_new.PreparePack(ui->lineEdit->text(),6,ui->lineEdit_2->text(),ui->lineEdit_3->text());
	ui->lineEdit_4->setText(sendpackage);

	int w = ui->Resultlabel->width();
	int h = ui->Resultlabel->height();
	i = new QImage(":/images/red.png");
	QImage podng = i->scaled(w,h,Qt::KeepAspectRatio);
	ui->Resultlabel->setPixmap(QPixmap::fromImage(podng,Qt::AutoColor));
}





