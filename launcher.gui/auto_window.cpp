
#include"auto_window.hpp"
#include<fstream>
#include<QFileDialog>
#include<QTextStream>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QFormLayout>

Auto::Auto(QWidget *parent) : QDialog(parent) {
    setMinimumSize(450, 350);
    resize(640, 480);
    setWindowTitle("AutoFilter - Editor");
    setWindowIcon(QPixmap(":/images/icon.png"));
    createControls();
}

void Auto::createControls() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(8);

    
    box = new QListWidget(this);
    mainLayout->addWidget(box, 1);

    
    QFormLayout *inputForm = new QFormLayout();
    inputForm->setHorizontalSpacing(10);
    inputForm->setVerticalSpacing(6);
    in_shader = new QLineEdit("acidcam.glsl", this);
    inputForm->addRow(tr("Shader:"), in_shader);
    in_filter = new QLineEdit("No Filter", this);
    inputForm->addRow(tr("Filter:"), in_filter);
    in_frames = new QLineEdit("10", this);
    inputForm->addRow(tr("Frames:"), in_frames);
    mainLayout->addLayout(inputForm);

    
    QHBoxLayout *actionRow = new QHBoxLayout();
    actionRow->setSpacing(6);
    auto_add = new QPushButton(tr("Add"), this);
    actionRow->addWidget(auto_add);
    auto_remove = new QPushButton(tr("Remove"), this);
    actionRow->addWidget(auto_remove);
    auto_insert = new QPushButton(tr("Insert"), this);
    actionRow->addWidget(auto_insert);
    actionRow->addStretch();
    mainLayout->addLayout(actionRow);

    
    QHBoxLayout *fileRow = new QHBoxLayout();
    fileRow->setSpacing(6);
    auto_save = new QPushButton(tr("Save"), this);
    fileRow->addWidget(auto_save);
    auto_load = new QPushButton(tr("Load"), this);
    fileRow->addWidget(auto_load);
    fileRow->addStretch();
    mainLayout->addLayout(fileRow);

    connect(auto_add, SIGNAL(clicked()), this, SLOT(btn_Add()));
    connect(auto_remove, SIGNAL(clicked()), this, SLOT(btn_Rmv()));
    connect(auto_insert, SIGNAL(clicked()), this, SLOT(btn_Insert()));
    connect(auto_save, SIGNAL(clicked()), this, SLOT(btn_Save()));
    connect(auto_load, SIGNAL(clicked()), this, SLOT(btn_Load()));
}

QString Auto::createString() {
    QString text;
    QTextStream stream(&text);
    stream << in_shader->text().trimmed() << ":" << in_filter->text().trimmed() << ":" << in_frames->text().trimmed();
    return text;
}

void Auto::btn_Add() {
    box->addItem(createString());
}

void Auto::btn_Rmv() {
    int pos = box->currentRow();
    if(pos != -1) {
        box->takeItem(pos);
    }
}

void Auto::btn_Insert() {
    int pos = box->currentRow();
    if(pos != -1) {
        QListWidgetItem *item = box->item(pos);
        item->setText(createString());
    }
}

void Auto::btn_Save() {
    QString dir_path = settings->value("af_path2", "").toString();
    QString name = QFileDialog::getSaveFileName(this, tr("Save AutoFilter File"),
                   dir_path, tr("AF Files (*.af)"));
    if(name != "") {
        std::fstream file;
        file.open(name.toStdString(), std::ios::out);
        if(!file.is_open()) return;
        for(int i = 0; i < box->count(); ++i) {
            QListWidgetItem *item = box->item(i);
            file << item->text().toStdString() << "\n";
        }
        file.close();
        if(name.length() > 0) {
            std::string val = name.toStdString();
            auto pos = val.rfind("/");
            if(pos == std::string::npos) pos = val.rfind("\\");
            if(pos != std::string::npos) val = val.substr(0, pos);
            settings->setValue("af_path2", val.c_str());
        }
    }
}

void Auto::btn_Load() {
    QString dir_path = settings->value("af_path1", "").toString();
    QString name = QFileDialog::getOpenFileName(this, tr("Open AutoFilter file"),
                   dir_path, tr("AF Files (*.af)"));
    if(name != "") {
        std::fstream file;
        file.open(name.toStdString(), std::ios::in);
        if(!file.is_open()) return;
        box->clear();
        while(!file.eof()) {
            std::string s;
            std::getline(file, s);
            if(file) {
                box->addItem(s.c_str());
            }
        }
        file.close();
        if(name.length() > 0) {
            std::string val = name.toStdString();
            auto pos = val.rfind("/");
            if(pos == std::string::npos) pos = val.rfind("\\");
            if(pos != std::string::npos) val = val.substr(0, pos);
            settings->setValue("af_path1", val.c_str());
        }
    }
}
