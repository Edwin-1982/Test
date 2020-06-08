#pragma once

#include<QProxyStyle>
#include<QPixmap>
#include<QSize>

//改变默认部件风格
class CustomProxyStyle :public QProxyStyle
{
public:
	CustomProxyStyle(QObject* parent)
	{
		setParent(parent);
	}
	virtual void drawPrimitive(PrimitiveElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget = 0)const
		{
		if (PE_FrameFocusRect == element)
		{
			//去掉Windows中部件默认的边框或虚线框,部件获取焦点是直接收回

			return;
		}
		else
		{
			QProxyStyle::drawPrimitive(element, option, painter, widget);

		}
		
}
};
class CommonUtils
{
public:
	CommonUtils();
public:
	static QPixmap getRoundImage(const QPixmap& src, QPixmap& mask, QSize masksize = QSize(0, 0));
	static void loadStyleSheet(QWidget* widget, const QString& sheetName);
	static void setDefaultSkinColor(const QColor& color);
	static void getDefaultSkinColor();
};

