#pragma once

#include<QProxyStyle>
#include<QPixmap>
#include<QSize>

//�ı�Ĭ�ϲ������
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
			//ȥ��Windows�в���Ĭ�ϵı߿�����߿�,������ȡ������ֱ���ջ�

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

