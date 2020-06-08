#include "CommonUtils.h"

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
}