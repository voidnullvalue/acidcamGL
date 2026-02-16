#include"main_window.hpp"
#include<cstdio>
#include<iostream>
#include<string>
#include<QTextStream>
#include<QApplication>
#include<QDir>
#include<fstream>
#include<thread>
#include<mutex>
#include<iomanip>
#include<sstream>
#include<QProcess>
#include<QtConcurrent>
#include<QThread>
#include<QLabel>
#include<QFileDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QFormLayout>
#include<QGridLayout>
#include<QGroupBox>
#include<QSplitter>
#include<QFrame>

QThread *threadx;
ServerThread *tv;
QString application_path = ".";

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setMinimumSize(960, 750);
    resize(1280, 950);
    setWindowTitle("acidcamGL - Start New Session");
    setWindowIcon(QPixmap(":/images/icon.png"));
    settings = new QSettings("LostSideDead", "acidcamGL");

    
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(10, 6, 10, 10);
    mainLayout->setSpacing(6);

    
    QHBoxLayout *cmdRow = new QHBoxLayout();
    cmdRow->setSpacing(6);
    command = new QLineEdit("", this);
    command->setReadOnly(false);
    command->setPlaceholderText(tr("Command line arguments..."));
    start_button = new QPushButton(tr("Launch"), this);
    start_button->setObjectName("btnPrimary");
    start_button->setMinimumWidth(100);
    start_button->setMinimumHeight(32);
    cmdRow->addWidget(command, 1);
    cmdRow->addWidget(start_button);
    mainLayout->addLayout(cmdRow);

    
    
    
    QGroupBox *sourceGrp = new QGroupBox(tr("Source"), this);
    QGridLayout *srcGrid = new QGridLayout(sourceGrp);
    srcGrid->setColumnStretch(1, 1);
    srcGrid->setHorizontalSpacing(8);
    srcGrid->setVerticalSpacing(6);

    
    srcGrid->addWidget(new QLabel(tr("Mode:")), 0, 0);
    QWidget *modeWidget = new QWidget(this);
    QHBoxLayout *modeLay = new QHBoxLayout(modeWidget);
    modeLay->setContentsMargins(0, 0, 0, 0);
    modeLay->setSpacing(8);
    mode_select = new QComboBox(this);
    mode_select->addItem(tr("Capture Device"));
    mode_select->addItem(tr("Input File"));
    mode_select->setMinimumWidth(140);
    modeLay->addWidget(mode_select);
    modeLay->addSpacing(6);
    modeLay->addWidget(new QLabel(tr("Device Index:")));
    device_edit = new QLineEdit("0", this);
    device_edit->setMaximumWidth(80);
    modeLay->addWidget(device_edit);
    modeLay->addSpacing(6);
    syphon_enabled = new QCheckBox(tr("Syphon"), this);
    syphon_enabled->hide();
    modeLay->addWidget(syphon_enabled);
    video_repeat = new QCheckBox(tr("Repeat"), this);
    modeLay->addWidget(video_repeat);
    modeLay->addStretch();
    srcGrid->addWidget(modeWidget, 0, 1, 1, 2);

    
    srcGrid->addWidget(new QLabel(tr("Shaders:")), 1, 0);
    QString pwd = getShaderPath();
    select_filters_text = new QLineEdit(pwd + "/filters", this);
    srcGrid->addWidget(select_filters_text, 1, 1);
    select_filters = new QPushButton(tr("Select"), this);
    srcGrid->addWidget(select_filters, 1, 2);

    
    srcGrid->addWidget(new QLabel(tr("Input:")), 2, 0);
    select_video_text = new QLineEdit("", this);
    srcGrid->addWidget(select_video_text, 2, 1);
    select_video = new QPushButton(tr("Select"), this);
    srcGrid->addWidget(select_video, 2, 2);

    
    srcGrid->addWidget(new QLabel(tr("Path:")), 3, 0);
    select_path_text = new QLineEdit("", this);
    QString homeLocation = QStandardPaths::locate(QStandardPaths::PicturesLocation,
                                                   QString(), QStandardPaths::LocateDirectory);
    select_path_text->setText(homeLocation + "acidcamGL_Snapshot");
    srcGrid->addWidget(select_path_text, 3, 1);
    select_path = new QPushButton(tr("Select"), this);
    srcGrid->addWidget(select_path, 3, 2);

    
    custom_on = new QCheckBox(tr("Custom:"), this);
    srcGrid->addWidget(custom_on, 4, 0);
    custom_file = new QLineEdit("", this);
    srcGrid->addWidget(custom_file, 4, 1);
    custom_set = new QPushButton(tr("Select"), this);
    srcGrid->addWidget(custom_set, 4, 2);

    mainLayout->addWidget(sourceGrp);

    
    
    
    QGroupBox *displayGrp = new QGroupBox(tr("Display"), this);
    QVBoxLayout *dispLay = new QVBoxLayout(displayGrp);
    dispLay->setSpacing(6);

    QHBoxLayout *dispRow1 = new QHBoxLayout();
    dispRow1->setSpacing(8);
    enable_cam = new QCheckBox(tr("Camera Resolution:"), this);
    dispRow1->addWidget(enable_cam);
    camera_res = new QLineEdit(tr("1280x720"), this);
    camera_res->setMaximumWidth(120);
    dispRow1->addWidget(camera_res);
    dispRow1->addSpacing(16);
    enable_res = new QCheckBox(tr("Window Resolution:"), this);
    dispRow1->addWidget(enable_res);
    window_res = new QLineEdit(tr("1280x720"), this);
    window_res->setMaximumWidth(120);
    dispRow1->addWidget(window_res);
    dispRow1->addStretch();
    dispLay->addLayout(dispRow1);

    QHBoxLayout *dispRow2 = new QHBoxLayout();
    dispRow2->setSpacing(8);
    full_screen = new QCheckBox(tr("Full Screen"), this);
    dispRow2->addWidget(full_screen);
    full_screen_resize = new QCheckBox(tr("Resize"), this);
    dispRow2->addWidget(full_screen_resize);
    dispRow2->addSpacing(16);
    dispRow2->addWidget(new QLabel(tr("Monitor:")));
    monitor_ = new QLineEdit("0", this);
    monitor_->setMaximumWidth(50);
    dispRow2->addWidget(monitor_);
    dispRow2->addSpacing(16);
    dispRow2->addWidget(new QLabel(tr("FPS:")));
    fps = new QLineEdit("", this);
    fps->setMaximumWidth(60);
    dispRow2->addWidget(fps);
    dispRow2->addStretch();
    dispLay->addLayout(dispRow2);

    mainLayout->addWidget(displayGrp);

    
    
    
    QHBoxLayout *midRow = new QHBoxLayout();
    midRow->setSpacing(6);

    
    QGroupBox *startGrp = new QGroupBox(tr("Start"), this);
    QFormLayout *startForm = new QFormLayout(startGrp);
    startForm->setHorizontalSpacing(10);
    startForm->setVerticalSpacing(6);
    start_shader = new QLineEdit("0", this);
    startForm->addRow(tr("Shader:"), start_shader);
    start_filter = new QLineEdit("0", this);
    startForm->addRow(tr("Filter:"), start_filter);
    start_sec = new QLineEdit("0", this);
    startForm->addRow(tr("Start At:"), start_sec);
    max_frames = new QLineEdit("500", this);
    startForm->addRow(tr("Max Frames:"), max_frames);
    midRow->addWidget(startGrp);

    
    QGroupBox *recGrp = new QGroupBox(tr("Recording"), this);
    QVBoxLayout *recLay = new QVBoxLayout(recGrp);
    recLay->setSpacing(6);

    QHBoxLayout *recRow1 = new QHBoxLayout();
    recRow1->setSpacing(8);
    record_video = new QCheckBox(tr("Record"), this);
    recRow1->addWidget(record_video);
    record_type = new QComboBox(this);
    record_type->addItem("x264");
    record_type->addItem("x265");
    record_type->addItem("nvenc");
    record_type->addItem("qsv");
    record_type->addItem("amf");
    record_type->addItem("videotoolbox");
    recRow1->addWidget(record_type);
    codec_select = new QComboBox(this);
    codec_select->addItem("Software");
    codec_select->addItem("h264_nvenc");
    codec_select->addItem("hevc_nvenc");
    codec_select->addItem("av1_nvenc");
    codec_select->addItem("h264_qsv");
    codec_select->addItem("hevc_qsv");
    codec_select->addItem("av1_qsv");
    codec_select->addItem("h264_amf");
    codec_select->addItem("hevc_amf");
    codec_select->addItem("h264_videotoolbox");
    codec_select->addItem("hevc_videotoolbox");
    codec_select->addItem("h264_cuda");
    codec_select->addItem("hevc_cuda");
    codec_select->addItem("h264_dxva2");
    codec_select->addItem("hevc_d3d11va");
    recRow1->addWidget(codec_select);
    recRow1->addWidget(new QLabel(tr("CRF:")));
    record_crf = new QLineEdit("22", this);
    record_crf->setMaximumWidth(60);
    recRow1->addWidget(record_crf);
    recRow1->addStretch();
    recLay->addLayout(recRow1);

    QHBoxLayout *recRow2 = new QHBoxLayout();
    recRow2->setSpacing(8);
    recRow2->addWidget(new QLabel(tr("Output:")));
    record_name = new QLineEdit("", this);
    recRow2->addWidget(record_name, 1);
    record_set = new QPushButton(tr("Select"), this);
    recRow2->addWidget(record_set);
    recLay->addLayout(recRow2);

    midRow->addWidget(recGrp, 1);
    mainLayout->addLayout(midRow);

    
    
    
    QHBoxLayout *botRow = new QHBoxLayout();
    botRow->setSpacing(6);

    
    QGroupBox *mediaGrp = new QGroupBox(tr("Media && Playback"), this);
    QVBoxLayout *mediaLay = new QVBoxLayout(mediaGrp);
    mediaLay->setSpacing(6);

    QHBoxLayout *matRow = new QHBoxLayout();
    matRow->setSpacing(8);
    matRow->addWidget(new QLabel(tr("Material:")));
    material_filename = new QLineEdit("", this);
    matRow->addWidget(material_filename, 1);
    material_set = new QPushButton(tr("Select"), this);
    matRow->addWidget(material_set);
    mediaLay->addLayout(matRow);

    QHBoxLayout *plRow = new QHBoxLayout();
    plRow->setSpacing(8);
    plRow->addWidget(new QLabel(tr("Playlist:")));
    playlist_file = new QLineEdit("", this);
    plRow->addWidget(playlist_file, 1);
    playlist_set = new QPushButton(tr("Select"), this);
    plRow->addWidget(playlist_set);
    mediaLay->addLayout(plRow);

    QHBoxLayout *pbRow = new QHBoxLayout();
    pbRow->setSpacing(8);
    enable_playback = new QCheckBox(tr("Enable Playback"), this);
    pbRow->addWidget(enable_playback);
    pbRow->addSpacing(6);
    pbRow->addWidget(new QLabel(tr("BPM:")));
    enable_bpm = new QLineEdit("60", this);
    enable_bpm->setMaximumWidth(60);
    pbRow->addWidget(enable_bpm);
    enable_shuffle = new QCheckBox(tr("Shuffle"), this);
    pbRow->addWidget(enable_shuffle);
    pbRow->addStretch();
    mediaLay->addLayout(pbRow);

    botRow->addWidget(mediaGrp, 1);

    
    QGroupBox *audioGrp = new QGroupBox(tr("Filters && Audio"), this);
    QVBoxLayout *audioLay = new QVBoxLayout(audioGrp);
    audioLay->setSpacing(6);

    QHBoxLayout *afRow = new QHBoxLayout();
    afRow->setSpacing(8);
    afRow->addWidget(new QLabel(tr("AutoFilter:")));
    auto_filter = new QLineEdit("", this);
    afRow->addWidget(auto_filter, 1);
    auto_set = new QPushButton(tr("Select"), this);
    afRow->addWidget(auto_set);
    audioLay->addLayout(afRow);

    QHBoxLayout *adRow = new QHBoxLayout();
    adRow->setSpacing(8);
    audio_disable = new QCheckBox(tr("Disable Audio"), this);
    adRow->addWidget(audio_disable);
    adRow->addSpacing(6);
    adRow->addWidget(new QLabel(tr("Sensitivity:")));
    audio_sense = new QLineEdit("25.0", this);
    audio_sense->setMaximumWidth(60);
    adRow->addWidget(audio_sense);
    adRow->addSpacing(6);
    adRow->addWidget(new QLabel(tr("Channels:")));
    audio_channel = new QLineEdit("2", this);
    audio_channel->setMaximumWidth(50);
    adRow->addWidget(audio_channel);
    adRow->addStretch();
    audioLay->addLayout(adRow);

    botRow->addWidget(audioGrp, 1);
    mainLayout->addLayout(botRow);

    
    
    
    command_stdout = new QTextEdit("acidcamGL Launcher - written by Jared Bruni", this);
    command_stdout->setReadOnly(true);
    command_stdout->setObjectName("consoleOutput");
    mainLayout->addWidget(command_stdout, 1);

    
    
    
    connect(mode_select, SIGNAL(currentIndexChanged(int)), this, SLOT(comboChanged_mode(int)));
    connect(device_edit, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(select_filters, SIGNAL(clicked()), this, SLOT(selectShaders()));
    connect(select_video, SIGNAL(clicked()), this, SLOT(selectVideo()));
    connect(select_video_text, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(select_path, SIGNAL(clicked()), this, SLOT(selectPath()));
    connect(select_path_text, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(syphon_enabled, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(video_repeat, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(custom_on, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(custom_file, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(custom_set, SIGNAL(clicked()), this, SLOT(setCustomFile()));
    connect(enable_cam, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(camera_res, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(enable_res, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(window_res, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(full_screen, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(full_screen_resize, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(monitor_, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(fps, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(start_shader, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(start_filter, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(start_sec, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(max_frames, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(record_video, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(record_type, SIGNAL(currentIndexChanged(int)), this, SLOT(comboChanged_mode(int)));
    connect(codec_select, SIGNAL(currentIndexChanged(int)), this, SLOT(updateCommand()));
    connect(record_name, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(record_crf, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(record_set, SIGNAL(clicked()), this, SLOT(setOutputFile()));
    connect(material_set, SIGNAL(clicked()), this, SLOT(setMatPath()));
    connect(material_filename, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(playlist_file, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(playlist_set, SIGNAL(clicked()), this, SLOT(setPlaylistPath()));
    connect(enable_playback, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(enable_bpm, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(enable_shuffle, SIGNAL(clicked()), this, SLOT(updateCommand()));
    connect(auto_filter, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(auto_set, SIGNAL(clicked()), this, SLOT(setAutoFilter()));
    connect(audio_disable, SIGNAL(clicked()), this, SLOT(setAudioDisable()));
    connect(audio_sense, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(audio_channel, SIGNAL(editingFinished()), this, SLOT(updateCommand()));
    connect(start_button, SIGNAL(clicked()), this, SLOT(launchProgram()));

    audio_disable->setChecked(true);
    audio_channel->setEnabled(false);
    audio_sense->setEnabled(false);

    
    tv = new ServerThread();
    threadx = new QThread;
    tv->moveToThread(threadx);
    connect(tv, SIGNAL(Log(const QString &)), this, SLOT(Log(const QString &)));
    connect(threadx, SIGNAL(started()), tv, SLOT(process()));
    threadx->start();

    
    file_menu = menuBar()->addMenu(tr("&File"));
    run_menu = menuBar()->addMenu(tr("&Run"));
    help_menu = menuBar()->addMenu(tr("Help"));

    file_options = new QAction(tr("Options"), this);
    file_options->setShortcut(tr("Ctrl+O"));
    file_menu->addAction(file_options);
    connect(file_options, SIGNAL(triggered()), this, SLOT(menu_Options()));

    open_auto = new QAction(tr("AutoFilter Editor"), this);
    file_menu->addAction(open_auto);
    connect(open_auto, SIGNAL(triggered()), this, SLOT(menu_Auto()));

    file_exit = new QAction(tr("E&xit"), this);
    file_exit->setShortcut(tr("Ctrl+X"));
    file_menu->addAction(file_exit);

    help_about = new QAction(tr("About"), this);
    help_about->setShortcut(tr("Ctrl+A"));
    help_menu->addAction(help_about);

    run_exec = new QAction(tr("Execute"), this);
    run_exec->setShortcut(tr("Ctrl+E"));
    run_menu->addAction(run_exec);

    connect(file_exit, SIGNAL(triggered()), this, SLOT(menu_Exit()));
    connect(help_about, SIGNAL(triggered()), this, SLOT(menu_About()));
    connect(run_exec, SIGNAL(triggered()), this, SLOT(launchProgram()));

    options_window = new Options(this);
    options_window->settings = settings;
    options_window->hide();
    options_window->load();

    auto_window = new Auto(this);
    auto_window->settings = settings;
    auto_window->hide();

    load();
    updateCommand();
}

MainWindow::~MainWindow() {
    save();
}

void MainWindow::menu_About() {
    QMessageBox qbox;
    QString v = "acidcamGL Launcher v" + QString(GUI_VERSION)
                + "\nSoftware Programmed by Jared Bruni"
                + "\n(C) 2022 LostSideDead Software"
                + "\nVisit me online @: https://lostsidedead.biz"
                + "\n\n\nThis Software is dedicated to all the people who experience mental illness.";
    qbox.setText(tr(v.toStdString().c_str()));
    QPixmap pixmap = QPixmap(":/images/icon.png");
    QPixmap spix = pixmap.scaled(64, 64);
    qbox.setIconPixmap(spix);
    qbox.setWindowTitle(tr("About this Software"));
    qbox.exec();
}

void MainWindow::menu_Exit() {
    QCoreApplication::quit();
}

void MainWindow::menu_Options() {
    options_window->show();
}

void MainWindow::menu_Auto() {
    auto_window->show();
}

void MainWindow::load() {
    if(options_window->save_options->isChecked()) {
        device_edit->setText(settings->value("opt_device", "0").toString());
        select_video_text->setText(settings->value("opt_video_t", "").toString());
        select_path_text->setText(settings->value("opt_path_t", "").toString());
        select_filters_text->setText(settings->value("opt_filter_t", getShaderPath()).toString());
        camera_res->setText(settings->value("opt_camera_res", "1280x720").toString());
        window_res->setText(settings->value("opt_window_res", "1280x720").toString());
        start_shader->setText(settings->value("opt_start_sh", "0").toString());
        start_filter->setText(settings->value("opt_start_fi", "0").toString());
        start_sec->setText(settings->value("opt_start_sec", "0").toString());
        material_filename->setText(settings->value("opt_material_filename", "").toString());
        custom_file->setText(settings->value("opt_custom", "").toString());
        monitor_->setText(settings->value("opt_monitor", "0").toString());
        fps->setText(settings->value("opt_fps", "0").toString());
        record_crf->setText(settings->value("opt_crf", "22").toString());
        enable_bpm->setText(settings->value("opt_bpm", "60").toString());
        codec_select->setCurrentIndex(settings->value("opt_codec", 0).toInt());
    }
}

void MainWindow::save() {
    if(options_window->save_options->isChecked()) {
        settings->setValue("opt_device", device_edit->text());
        settings->setValue("opt_video_t", select_video_text->text());
        settings->setValue("opt_path_t", select_path_text->text());
        settings->setValue("opt_filter_t", select_filters_text->text());
        settings->setValue("opt_camera_res", camera_res->text());
        settings->setValue("opt_window_res", window_res->text());
        settings->setValue("opt_start_sh", start_shader->text());
        settings->setValue("opt_start_fi", start_filter->text());
        settings->setValue("opt_start_sec", start_sec->text());
        settings->setValue("opt_material_filename", material_filename->text());
        settings->setValue("opt_custom", custom_file->text());
        settings->setValue("opt_monitor", monitor_->text());
        settings->setValue("opt_fps", fps->text());
        settings->setValue("opt_crf", record_crf->text());
        settings->setValue("opt_bpm", enable_bpm->text());
        settings->setValue("opt_codec", codec_select->currentIndex());
    }
}

QString MainWindow::getShaderPath() {
    QFileInfo fi(QCoreApplication::applicationFilePath());
    QString exeDir = fi.absolutePath();
    return exeDir;
}

QProcess *acidcam_process = nullptr;

void MainWindow::launchProgram() {
    Log(tr("\nacidcamGL Launcher - Executing ...\n"));
    QString cmd_string;
#ifdef __APPLE__
    QString exePath = QCoreApplication::applicationFilePath();
    cmd_string = exePath + "/acidcamGL ";
#else
    cmd_string = "acidcamGL ";
#endif
    if(options_window->exec_enable->isChecked())
        cmd_string = options_window->exec_path->text() + " ";

    cmd_string += command->text();

    if (acidcam_process && acidcam_process->state() != QProcess::NotRunning) {
        acidcam_process->kill();
        acidcam_process->waitForFinished();
        delete acidcam_process;
        acidcam_process = nullptr;
    }

    acidcam_process = new QProcess(this);

    connect(acidcam_process, &QProcess::readyReadStandardOutput, this, [this]() {
        QByteArray data = acidcam_process->readAllStandardOutput();
        QTextCursor cursor = command_stdout->textCursor();
        cursor.movePosition(QTextCursor::End);
        command_stdout->setTextCursor(cursor);
        command_stdout->insertPlainText(QString::fromLocal8Bit(data));
        command_stdout->ensureCursorVisible();
    });
    connect(acidcam_process, &QProcess::readyReadStandardError, this, [this]() {
        QByteArray data = acidcam_process->readAllStandardError();
        QTextCursor cursor = command_stdout->textCursor();
        cursor.movePosition(QTextCursor::End);
        command_stdout->setTextCursor(cursor);
        command_stdout->insertPlainText(QString::fromLocal8Bit(data));
        command_stdout->ensureCursorVisible();
    });
    connect(acidcam_process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this](int exitCode, QProcess::ExitStatus) {
        command_stdout->append(tr("\nProcess finished with exit code %1\n").arg(exitCode));
    });

    QString program;
    QStringList arguments;

#ifdef __APPLE__
    QFileInfo fi(QCoreApplication::applicationFilePath());
    QString exeDir = fi.absolutePath();
    program = exeDir + "/acidcamGL";
#else
    program = "acidcamGL";
#endif

    if(options_window->exec_enable->isChecked())
        program = options_window->exec_path->text();

    arguments = QProcess::splitCommand(command->text());

    acidcam_process->start(program, arguments);

    if (!acidcam_process->waitForStarted(3000)) {
        command_stdout->append(tr("Error: Could not start acidcamGL process.\n"));
        command_stdout->append(tr("QProcess error: %1").arg(acidcam_process->errorString()));
        command_stdout->append(tr("Program: %1").arg(program));
        command_stdout->append(tr("Arguments: %1").arg(arguments.join(" ")));
    }
}

void MainWindow::Log(const QString &text) {
    QString t = command_stdout->toPlainText();
    t += tr(text.toStdString().c_str());
    command_stdout->setPlainText(t);
    QTextCursor tmpCursor = command_stdout->textCursor();
    tmpCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    command_stdout->setTextCursor(tmpCursor);
}

void MainWindow::selectShaders() {
    QString dir_path = settings->value("dir_shaders", "").toString();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Shaders Directory"),
                  dir_path, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.length() > 0) {
        select_filters_text->setText(dir);
        settings->setValue("dir_shaders", dir);
    }
    updateCommand();
}

void MainWindow::selectPath() {
    QString dir_path = settings->value("dir_path1", "").toString();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Snapshot Directory"),
                  dir_path, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.length() > 0) {
        select_path_text->setText(dir);
        settings->setValue("dir_path1", dir);
    }
    updateCommand();
}

void MainWindow::setMatPath() {
    QString dir_path = settings->value("dir_path2", "").toString();
    QString name = QFileDialog::getOpenFileName(this, tr("Open Video/Image"), dir_path,
                   tr("Image/Video Files (*.mov *.mp4 *.mkv *.avi *.m4v *.jpg *.png *.bmp *.tif)"));
    if(name.length() > 0) {
        material_filename->setText(name);
        std::string val = name.toStdString();
        auto pos = val.rfind("/");
        if(pos == std::string::npos) pos = val.rfind("\\");
        if(pos != std::string::npos) val = val.substr(0, pos);
        settings->setValue("dir_path2", val.c_str());
    }
    updateCommand();
}

void MainWindow::setPlaylistPath() {
    QString dir_path = settings->value("dir_path3", "").toString();
    QString name = QFileDialog::getOpenFileName(this, tr("Open Playlist"), dir_path,
                   tr("Playlist Files (*.key)"));
    if(name.length() > 0) {
        playlist_file->setText(name);
        std::string val = name.toStdString();
        auto pos = val.rfind("/");
        if(pos == std::string::npos) pos = val.rfind("\\");
        if(pos != std::string::npos) val = val.substr(0, pos);
        settings->setValue("dir_path3", val.c_str());
    }
    updateCommand();
}

void MainWindow::setAudioDisable() {
    if(audio_disable->isChecked()) {
        audio_sense->setEnabled(false);
        audio_channel->setEnabled(false);
    } else {
        audio_sense->setEnabled(true);
        audio_channel->setEnabled(true);
    }
    updateCommand();
}

void MainWindow::setAutoFilter() {
    QString dir_path = settings->value("dir_path4", "").toString();
    QString name = QFileDialog::getOpenFileName(this, tr("Open Autofilter"), dir_path,
                   tr("Autofilter Files (*.af)"));
    if(name.length() > 0) {
        std::string val = name.toStdString();
        auto pos = val.rfind("/");
        if(pos == std::string::npos) pos = val.rfind("\\");
        if(pos != std::string::npos) val = val.substr(0, pos);
        settings->setValue("dir_path4", val.c_str());
        auto_filter->setText(name);
    }
    updateCommand();
}

void MainWindow::setOutputFile() {
    QString dir_path = settings->value("dir_path5", "").toString();
    QString name = QFileDialog::getSaveFileName(this, tr("Open Video"), dir_path,
                   tr("Video Files (*.mp4 *.mkv *.m4v *.mov)"));
    if(name.length() > 0) {
        std::string val = name.toStdString();
        auto pos = val.rfind("/");
        if(pos == std::string::npos) pos = val.rfind("\\");
        if(pos != std::string::npos) val = val.substr(0, pos);
        settings->setValue("dir_path5", val.c_str());
        record_name->setText(name);
    }
    updateCommand();
}

void MainWindow::setCustomFile() {
    QString dir_path = settings->value("dir_path7", "").toString();
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Custom Index Directory"),
                  dir_path, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(dir.length() > 0) {
        custom_file->setText(dir);
        settings->setValue("dir_path7", dir);
    }
    updateCommand();
}

void MainWindow::selectVideo() {
    QString dir_path = settings->value("dir_path6", "").toString();
    QString name = QFileDialog::getOpenFileName(this, tr("Open Video"), dir_path,
                   tr("Image/Video Files (*.mov *.mp4 *.mkv *.avi *.m4v *.jpg *.png *.bmp *.tif)"));
    if(name.length() > 0) {
        std::string val = name.toStdString();
        auto pos = val.rfind("/");
        if(pos == std::string::npos) pos = val.rfind("\\");
        if(pos != std::string::npos) val = val.substr(0, pos);
        settings->setValue("dir_path6", val.c_str());
        select_video_text->setText(name);
    }
    updateCommand();
}

void MainWindow::LogMessage(const QString &text) {
    Log(text);
    emit LogString(text);
}

void MainWindow::textChanged_device(const QString &) {
    updateCommand();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (acidcam_process != nullptr && acidcam_process->state() == QProcess::Running) {
        acidcam_process->terminate();
        if (!acidcam_process->waitForFinished(10000)) {
            acidcam_process->kill();
        }
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::comboChanged_mode(int) {
    updateCommand();
}

void MainWindow::updateCommand() {
    cmd_list.clear();
    cmd_list << "-P";
    cmd_list << "-g";
    cmd_list << "-p";
    QString temp = "";
    temp += select_filters_text->text();
    cmd_list << QString("\"") + temp + "\"";
    select_video->setEnabled(true);
    select_video_text->setEnabled(true);
    device_edit->setEnabled(true);
    if(mode_select->currentIndex() == 0) {
        select_video->setEnabled(false);
        select_video_text->setEnabled(false);
        int value = atoi(device_edit->text().toStdString().c_str());
        if(value >= 0) {
            cmd_list << "-d";
            cmd_list << device_edit->text();
        }
        std::string vf = camera_res->text().toStdString();
        if(vf.find("x") != std::string::npos) {
            std::string left = vf.substr(0, vf.find("x"));
            std::string right = vf.substr(vf.find("x")+1, vf.length());
            if(atoi(left.c_str()) >= 320 && atoi(right.c_str()) >= 240) {
                if(enable_cam->isChecked()) {
                    cmd_list << "-c";
                    cmd_list << camera_res->text();
                }
            }
        }
    } else if(mode_select->currentIndex() == 1) {
        device_edit->setEnabled(false);

        if(video_repeat->isChecked()) {
            cmd_list << "-R";
        }

        if(select_video_text->text().length() > 0) {
            cmd_list << "-i";
            cmd_list << QString("\"") + select_video_text->text() + "\"";
        }
    } else if(mode_select->currentIndex() == 2) {
        cmd_list << "-G";
    }

    if(select_path_text->text().length() > 0) {
        cmd_list << "-e";
        cmd_list << QString("\"") + select_path_text->text() + "\"";
    }
    std::string vf = window_res->text().toStdString();
    if(vf.find("x") != std::string::npos) {
        std::string left = vf.substr(0, vf.find("x"));
        std::string right = vf.substr(vf.find("x")+1, vf.length());
        if(atoi(left.c_str()) >= 320 && atoi(right.c_str()) >= 240) {
            if(enable_res->isChecked()) {
                cmd_list << "-r";
                cmd_list << window_res->text();
            }
        }
    }

    if(syphon_enabled->isChecked()) {
        cmd_list << "-Y";
    }
    if(full_screen->isChecked()) {
        if(full_screen_resize->isChecked()) {
            cmd_list << "-f";
        } else {
            cmd_list << "-F";
        }
        cmd_list << "-M";
        cmd_list << monitor_->text();
    }
    if(start_shader->text() != "0")
        cmd_list << "-H" << start_shader->text();
    if(start_filter->text() != "0")
        cmd_list << "-S" << start_filter->text();
    if(start_sec->text() != "0")
        cmd_list << "-7" << start_sec->text();

    if(record_video->isChecked() && record_name->text() != "") {
        int codec_idx = codec_select->currentIndex();
        QString hw_codec = "";

        if(codec_idx == 0) {
            if(record_type->currentIndex() == 0) {
                cmd_list << "-4";
            } else {
                cmd_list << "-5";
            }
        } else {
            hw_codec = codec_select->currentText();
            cmd_list << "-E" << hw_codec;
        }

        cmd_list << "-o";
        cmd_list << QString("\"") + record_name->text() + "\"";
        cmd_list << "-m" << record_crf->text();
    }

    if(material_filename->text() != "") {
        cmd_list << "-T";
        QString filename = QString("\"") + material_filename->text() + "\"";
        cmd_list << filename;
    }

    if(playlist_file->text() != "") {
        cmd_list << "-L" << (QString("\"") + playlist_file->text() + "\"");
    }

    if(enable_playback->isChecked() && playlist_file->text() != "") {
        cmd_list << "-B";

        if(enable_shuffle->isChecked())
            cmd_list << "-q";

        cmd_list << "-w" << enable_bpm->text();
    }

    if(auto_filter->text() != "") {
        cmd_list << "-A" << QString("\"") + auto_filter->text() + "\"";
    }

    if(custom_on->isChecked() && custom_file->text() != "") {
        cmd_list << "-W" << QString("\"") + custom_file->text() + "\"";
    }

    if(audio_disable->isChecked()) {
        cmd_list << "-y";
    } else {
        cmd_list << "-V" << audio_sense->text();
        cmd_list << "-I" << audio_channel->text();
    }
    cmd_list << "-8" << max_frames->text();

    if(fps->text() != "") {
        cmd_list << "-u" << fps->text();
    }

    QString buf;
    for(int i = 0; i < cmd_list.size(); ++i) {
        buf += cmd_list.at(i) + " ";
    }

    command->setText(buf);
}
