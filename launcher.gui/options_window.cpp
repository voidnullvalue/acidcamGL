#include"options_window.hpp"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>

Options::Options(QWidget *parent) : QDialog(parent) {
    setMinimumSize(400, 140);
    resize(550, 160);
    setWindowTitle("acidcamGL - Options");
    setWindowIcon(QPixmap(":/images/icon.png"));
    create_window();
}

Options::~Options() {
    save();
}

void Options::load() {
    QString save_opt = settings->value("save_opt", "0").toString();
    if(save_opt == "0")
        save_options->setChecked(false);
    else
        save_options->setChecked(true);

    QString prog_path = settings->value("prog_path", "acidcamGL").toString();
    exec_path->setText(prog_path);
    QString e_checked = settings->value("prog_chk", "0").toString();
    if(e_checked == "0") {
        exec_enable->setChecked(false);
    } else {
        exec_select->setEnabled(true);
        exec_path->setEnabled(true);
        exec_enable->setChecked(true);
    }
}

void Options::save() {
    if(save_options->isChecked()) {
        settings->setValue("prog_path", exec_path->text());
        settings->setValue("prog_chk", exec_enable->isChecked() ? "1" : "0");
    }
    settings->setValue("save_opt", save_options->isChecked() ? "1" : "0");
}

void Options::chkClicked() {
    if(exec_enable->isChecked()) {
        exec_path->setEnabled(true);
        exec_select->setEnabled(true);
        save();
    } else {
        exec_path->setEnabled(false);
        exec_select->setEnabled(false);
    }
}

void Options::okClicked() {
    save();
    hide();
}

void Options::selectExecutable() {
    QString dir_path = settings->value("dpath1", "").toString();
    QString name = QFileDialog::getOpenFileName(this, tr("Open EXE"), dir_path,
                   tr("All Files (*.*)"));
    if(name.length() > 0) {
        exec_path->setText(name);
        std::string val = name.toStdString();
        auto pos = val.rfind("/");
        if(pos == std::string::npos) pos = val.rfind("\\");
        if(pos != std::string::npos) val = val.substr(0, pos);
        settings->setValue("dpath1", val.c_str());
    }
}

void Options::setDefaults() {
    exec_path->setText("acidcamGL");
}

void Options::create_window() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(10);

    
    QHBoxLayout *execRow = new QHBoxLayout();
    execRow->setSpacing(8);
    exec_enable = new QCheckBox(tr("Executable Path:"), this);
    execRow->addWidget(exec_enable);
    exec_path = new QLineEdit("acidcamGL", this);
    exec_path->setEnabled(false);
    execRow->addWidget(exec_path, 1);
    exec_select = new QPushButton(tr("Select"), this);
    exec_select->setEnabled(false);
    execRow->addWidget(exec_select);
    mainLayout->addLayout(execRow);

    connect(exec_enable, SIGNAL(clicked()), this, SLOT(chkClicked()));
    connect(exec_select, SIGNAL(clicked()), this, SLOT(selectExecutable()));

    
    QHBoxLayout *bottomRow = new QHBoxLayout();
    bottomRow->setSpacing(8);
    save_options = new QCheckBox(tr("Save Options"), this);
    bottomRow->addWidget(save_options);
    bottomRow->addStretch();
    def_button = new QPushButton(tr("Defaults"), this);
    bottomRow->addWidget(def_button);
    ok_button = new QPushButton(tr("Okay"), this);
    ok_button->setObjectName("btnPrimary");
    bottomRow->addWidget(ok_button);
    mainLayout->addLayout(bottomRow);

    mainLayout->addStretch();

    connect(ok_button, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(def_button, SIGNAL(clicked()), this, SLOT(setDefaults()));
}
