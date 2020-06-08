#pragma once

#include <QObject>

class NotifyManager : public QObject
{
	Q_OBJECT

public:
	NotifyManager();
	~NotifyManager();

signals:
	void signalSkinChanged(const QColor& color);

public:
	static NotifyManager* getInstance();

	void notifyOtherWindowChangedSkin(const QColor& color);

private:
	static NotifyManager* instance;
};
