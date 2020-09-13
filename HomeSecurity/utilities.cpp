#include "utilities.h"
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>

QString Utilities::getDataPath(){
	QString user_movie_path=QStandardPaths::standardLocations(QStandardPaths::MoviesLocation)[0];
	QDir movie_dir(user_movie_path);
	movie_dir.mkpath("Home Security");
	return movie_dir.absoluteFilePath("Home Security");
	}

QString Utilities::newSavedVideoName(){
	QDateTime time=QDateTime::currentDateTime();
	return time.toString("yyyy-MM-dd+HH:mm:ss");
	}

QString Utilities::getSavedVideoPath(QString name,QString postfix){
	return QString("%1/%2.%3").arg(Utilities::getDataPath(),name,postfix);
	}
