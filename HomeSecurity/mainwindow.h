
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStatusBar>
#include <QLabel>
#include <QListView>
#include <QCheckBox>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QMutex>
#include <QStandardItemModel>
#include <QList>
#include <QString>
#include <QCameraInfo>
#include "capture_thread.h"


#ifdef HOME_SECURITY_USE_QT_CAMERA
#include <QCameraViewfinder>
#include <QCamera>
#endif



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow();
    
private:
 void initUI();
 void createActions();
 void populateSavedList();    

private slots:
 void updateMonitorStatus(int status); 
 void showCameraInfo();
 void openCamera();
 void updateFrame(cv::Mat*);
 void calculateFPS();
 void updateFPS(float);
 void recordingStartStop();
 void appendSavedVideo(QString name);

private:
 QMenu *fileMenu;
 
 QStandardItemModel *list_model;
 
 QAction *cameraInfoAction;
 QAction *openCameraAction;
 QAction *exitAction;
 QAction *calcFPSAction;
 
 QGraphicsScene *imageScene;
 QGraphicsView *imageView;
 
 QCheckBox *monitorCheckBox;
 QPushButton *recordButton;
 
 QListView *saved_list;
 
 QStatusBar *mainStatusBar;
 QLabel *mainStatusLabel;
 
 cv::Mat currentFrame;
 QMutex *data_lock;
 CaptureThread *capturer;
};

#endif
