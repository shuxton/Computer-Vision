
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStatusBar>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QMap>

#include "editor_plugin_interface.h"

class MainWindow : public QMainWindow
{
 Q_OBJECT
 public:
 explicit MainWindow(QWidget *parent=nullptr);
 ~MainWindow();
 
 private:
 void initUI();
 void createActions();
 void showImage(QString);
 void setupShortcuts();
 void loadPlugins();
 
 private:
 QMenu *fileMenu;
 QMenu *viewMenu;
 QMenu *editMenu;
 
 QToolBar *editToolBar; 
 QToolBar *fileToolBar;
 QToolBar *viewToolBar;
 
 QGraphicsScene *imageScene;
 QGraphicsView *imageView;
 
 QStatusBar *mainStatusBar;
 QLabel *mainStatusLabel;
 
  QAction *openAction;
  QAction *blurAction;
  
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *prevAction;
    QAction *nextAction;
   
  QGraphicsPixmapItem *currentImage;
  QString currentImagePath;
  
  QMap<QString, EditorPluginInterface*> editPlugins;
  
  private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void prevImage();
    void nextImage();
    void saveAs();
    void blurImage();
    void pluginPerform();
};

#endif
