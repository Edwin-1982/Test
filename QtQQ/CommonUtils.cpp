#include "CommonUtils.h"
#include<QPainter>
#include<QFile>
#include<QWidget>
#include<QApplication>
#include<QSettings>

CommonUtils::CommonUtils()
{

}
QPixmap CommonUtils::getRoundImage(const QPixmap& src, QPixmap& mask, QSize masksize)
{
	if (masksize == QSize(0, 0))
	{
		masksize = mask.size();
	}
	else
	{
		mask = mask.scaled(masksize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	}
	QImage resultIamge(masksize, QImage::Format_A2BGR30_Premultiplied);
	QPainter painter(&resultIamge);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.fillRect(resultIamge.rect(), Qt::transparent);
	painter.drawPixmap(0, 0, mask);
	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	painter.drawPixmap(0, 0, src.scaled(masksize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	painter.end();
	return QPixmap::fromImage(resultIamge);
}

void CommonUtils::loadStyleSheet(QWidget* widget, const QString& sheetName)
{
	QFile file(":/Resoutces/QSS/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		widget->setStyleSheet("");
		QString qssytleSheet = QLatin1String(file.readAll());
		widget->setStyleSheet(qssytleSheet);
	}
	file.close();
}

