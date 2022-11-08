#include "mainwindow.h"
#include "ui_mainwindow.h"

std::string word {};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->description->hide();
    ui->light_mode->hide();
    this->setWindowTitle("Code Snippets");
    this->setWindowIcon(QIcon(":/imgs/imgs/coder.ico"));
    this->setFixedSize(QSize(750, 500));
    this->setStyleSheet(QString("background-color: lightgreen"));
    QFile file(":/imgs/imgs/bye.txt");
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly)) {
        exit(1);
    }
    ui->lineEdit->setText(file.readAll());
    process_langs();
    ui->titleLabel->setText(QString("Code Snippet"));
    file.close();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::process_langs() {
    if (ui->lineEdit->text() == QString("C++") || ui->lineEdit->text() == QString("c++")){
          QPixmap cpp_logo(":/imgs/imgs/cpp_logo.png");
          QPixmap *cpp_pic1 = new QPixmap(":/imgs/imgs/cpp_pic1.png");
          QPixmap *cpp_pic2 = new QPixmap(":/imgs/imgs/cpp_pic2.png");
          QPixmap *cpp_pic3 = new QPixmap(":/imgs/imgs/cpp_pic3.png");
          QPixmap *cpp_pic4 = new QPixmap(":/imgs/imgs/cpp_pic4.png");
          QPixmap *cpp_pic5 = new QPixmap(":/imgs/imgs/cpp_pic5.png");
          QPixmap *cpp_pic6 = new QPixmap(":/imgs/imgs/cpp_pic6.png");
          QPixmap *cpp_pic7 = new QPixmap(":/imgs/imgs/cpp_pic7.png");
          std::vector<QPixmap *> cpp_pics {};
          ui->logo->setPixmap(cpp_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
          cpp_pics.push_back(cpp_pic1);
          cpp_pics.push_back(cpp_pic2);
          cpp_pics.push_back(cpp_pic3);
          cpp_pics.push_back(cpp_pic4);
          cpp_pics.push_back(cpp_pic5);
          cpp_pics.push_back(cpp_pic6);
          cpp_pics.push_back(cpp_pic7);
          srand(time(NULL));
          QPixmap chosen_cpp = *(cpp_pics.at(rand() % cpp_pics.size()));
          ui->image->setPixmap(chosen_cpp.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
          delete cpp_pic1;
          delete cpp_pic2;
          delete cpp_pic3;
          delete cpp_pic4;
          delete cpp_pic5;
          delete cpp_pic6;
          delete cpp_pic7;
    }

    else if (ui->lineEdit->text() == QString("Java") || ui->lineEdit->text() == QString("java") || ui->lineEdit->text() == QString("JAVA")) {
        QPixmap java_logo(":/imgs/imgs/java_logo.png");
        QPixmap *java_pic1 = new QPixmap(":/imgs/imgs/java_pic1.png");
        QPixmap *java_pic2 = new QPixmap(":/imgs/imgs/java_pic2.png");
        QPixmap *java_pic3 = new QPixmap(":/imgs/imgs/java_pic3.png");
        QPixmap *java_pic4 = new QPixmap(":/imgs/imgs/java_pic4.png");
        ui->logo->setPixmap(java_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        std::vector<QPixmap *> java_pics {};
        java_pics.push_back(java_pic1);
        java_pics.push_back(java_pic2);
        java_pics.push_back(java_pic3);
        java_pics.push_back(java_pic4);
        srand(time(NULL));
        QPixmap chosen_java = *(java_pics.at(rand() % java_pics.size()));
        ui->image->setPixmap(chosen_java.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
        delete java_pic1;
        delete java_pic2;
        delete java_pic3;
        delete java_pic4;
    }

    else if (ui->lineEdit->text() == QString("Python") || ui->lineEdit->text() == QString("python") || ui->lineEdit->text() == QString("PYTHON")) {
        QPixmap python_logo(":/imgs/imgs/python_logo.png");
        QPixmap *python_pic1 = new QPixmap(":/imgs/imgs/python_pic1.png");
        QPixmap *python_pic2 = new QPixmap(":/imgs/imgs/python_pic2.png");
        ui->logo->setPixmap(python_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        std::vector<QPixmap *> python_pics {} ;
        python_pics.push_back(python_pic1);
        python_pics.push_back(python_pic2);
        srand(time(NULL));
        QPixmap chosen_python = *(python_pics.at(rand() % python_pics.size()));
        ui->image->setPixmap(chosen_python.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
        delete python_pic1;
        delete python_pic2;

    }

    else if (ui->lineEdit->text() == QString("Rust") || ui->lineEdit->text() == QString("rust") || ui->lineEdit->text() == QString("RUST")) {
        QPixmap rust_logo(":/imgs/imgs/rust_logo.png");
        QPixmap *rust_pic1 = new QPixmap(":/imgs/imgs/rust_pic1.png");
        std::vector<QPixmap *> rust_pics {};
        rust_pics.push_back(rust_pic1);
        srand(time(NULL));
        QPixmap chosen_rust = *(rust_pics.at(rand() % rust_pics.size()));
        ui->logo->setPixmap(rust_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        ui->image->setPixmap(chosen_rust.scaled(ui->image->width(), ui->image->height()));
        delete rust_pic1;
    }

    else {
        ui->titleLabel->clear();
        ui->image->setStyleSheet(QString("color: red;\n font-size: 20px;\n qproperty-alignment: AlignCenter;"));
        ui->image->setText(QString("Please enter a valid programming langauge"));
    }
}

void MainWindow::on_exit_button_clicked()
{
    this->close();
}

void MainWindow::on_search_button_clicked()
{
    ui->titleLabel->setText(QString("Code Snippet"));
    if (ui->light_mode->isVisible()) {
        ui->titleLabel->setStyleSheet(QString("color: yellow;\n font-weight: 750; font-size: 16px;"));
    }
    if (!ui->info->isVisible()) {
        ui->info->show();
    }
    ui->description->hide();
    process_langs();
}


void MainWindow::on_clearButton_clicked()
{
    ui->lineEdit->clear();
    ui->image->clear();
    ui->titleLabel->clear();
    ui->logo->clear();
    ui->description->clear();
    ui->info->hide();
    ui->info_2->hide();
}

void MainWindow::on_info_clicked()
{
    ui->description->show();
    ui->info->hide();
    if (ui->lineEdit->text() == QString("C++") || ui->lineEdit->text() == QString("c++")) {
        ui->image->clear();
        ui->titleLabel->clear();
        ui->logo->clear();
        ui->description->setWordWrap(true);
        ui->description->setText(QString("C++ is a high-level general-purpose programming language created by Danish computer scientist Bjarne Stroustrup as an extension of the C programming language, or C with Classes. The language has expanded significantly over time, and modern C++ now has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM, so it is available on many platforms. C++ was designed with systems programming and embedded, resource-constrained software and large systems in mind, with performance, efficiency, and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, video games, servers (e.g. e-commerce, web search, or databases), and performance-critical applications (e.g. telephone switches or space probes)."));
    }

    else if (ui->lineEdit->text() == QString("Java") || ui->lineEdit->text() == QString("java")) {
        ui->image->clear();
        ui->titleLabel->clear();
        ui->logo->clear();
        ui->description->setWordWrap(true);
        ui->description->setText(QString("Java is a high-level, class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible. It is a general-purpose programming language intended to let programmers write once, run anywhere (WORA), meaning that compiled Java code can run on all platforms that support Java without the need to recompile. Java applications are typically compiled to bytecode that can run on any Java virtual machine (JVM) regardless of the underlying computer architecture. The syntax of Java is similar to C and C++, but has fewer low-level facilities than either of them. The Java runtime provides dynamic capabilities (such as reflection and runtime code modification) that are typically not available in traditional compiled languages. As of 2019, Java was one of the most popular programming languages in use according to GitHub, particularly for client–server web applications, with a reported 9 million developers."));
    }

    else if (ui->lineEdit->text() == QString("Rust") || ui->lineEdit->text() == QString("rust")) {
        ui->image->clear();
        ui->titleLabel->clear();
        ui->logo->clear();
        ui->description->setWordWrap(true);
        ui->description->setText(QString("Rust is a multi-paradigm, general-purpose programming language. Rust emphasizes performance, type safety, and concurrency. Rust enforces memory safety—that is, that all references point to valid memory—without requiring the use of a garbage collector or reference counting present in other memory-safe languages.To simultaneously enforce memory safety and prevent concurrent data races, Rust's borrow checker tracks the object lifetime and variable scope of all references in a program during compilation. Rust is popular for systems programming but also offers high-level features including functional programming constructs. Software developer Graydon Hoare created Rust as a personal project while working at Mozilla Research in 2006. Mozilla officially sponsored the project in 2009. Rust's major influences include SML, OCaml, C++, Cyclone, Haskell, and Erlang. Since the first stable release in January 2014, Rust has been adopted by companies including Amazon, Discord, Dropbox, Facebook (Meta), Google (Alphabet), and Microsoft."));
    }

    else if (ui->lineEdit->text() == QString("Python") || ui->lineEdit->text() == QString("python")) {
        ui->image->clear();
        ui->titleLabel->clear();
        ui->logo->clear();
        ui->description->setWordWrap(true);
        ui->description->setText(QString("Python is a high-level, general-purpose programming language. Its design philosophy emphasizes code readability with the use of significant indentation. Python is dynamically-typed and garbage-collected. It supports multiple programming paradigms, including structured (particularly procedural), object-oriented and functional programming. It is often described as a \"batteries included\" language due to its comprehensive standard library. Guido van Rossum began working on Python in the late 1980s as a successor to the ABC programming language and first released it in 1991 as Python 0.9.0. Python 2.0 was released in 2000 and introduced new features such as list comprehensions, cycle-detecting garbage collection, reference counting, and Unicode support. Python 3.0, released in 2008, was a major revision that is not completely backward-compatible with earlier versions. Python 2 was discontinued with version 2.7.18 in 2020. "));
    }
    ui->info_2->show();

}

void MainWindow::on_dark_mode_clicked()
{
    ui->titleLabel->setStyleSheet(QString("color: yellow;\n font-weight: 750;\n font-size: 16px;"));
    this->setStyleSheet(QString("background-color: #000000;"));
    ui->description->setStyleSheet(QString("color: white;\n font-weight: 750;"));
    ui->dark_mode->hide();
    ui->light_mode->show();
}

void MainWindow::on_light_mode_clicked() {
    this->setStyleSheet(QString("background-color: lightgreen;"));
    ui->description->setStyleSheet(QString("color: black;\n"));
    ui->titleLabel->setStyleSheet(QString("color: black;\n font-size: 16px;"));
    ui->light_mode->hide();
    ui->dark_mode->show();
}

void MainWindow::on_info_2_clicked()
{
    ui->info_2->hide();
    ui->titleLabel->setText(QString("Code Snippet"));
    ui->titleLabel->setStyleSheet(QString("font-weight: 750;\n font-size: 16px;"));
    if (!ui->dark_mode->isVisible()) {
        ui->titleLabel->setStyleSheet(QString("color: yellow;\n font-weight: 750;\n font-size: 16px;"));
    }
    ui->description->hide();
    process_langs();
    ui->info->show();
}
