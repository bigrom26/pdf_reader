#include "pdf_reader.h"

#include "mupdf_wrapper/context.h"
#include "mupdf_wrapper/document.h"
#include "mupdf_wrapper/matrix.h"
#include "mupdf_wrapper/pixmap.h"
#include "ui_pdf_reader.h"

#include <exception>
#include <iostream>
#include <memory>

#include <QFileDialog>

Pdf_reader::Pdf_reader(QWidget* parent)
    : QMainWindow(parent)
    , m_ui(nullptr)
    , m_label(nullptr)
    , m_stacked_layout(nullptr)
{
    m_ui = new Ui::Pdf_reader();
    m_label = new QLabel();
    m_stacked_layout = new QStackedLayout();

    m_ui->setupUi(this);
    m_ui->centralWidget->setLayout(m_stacked_layout);
    m_stacked_layout->addWidget(m_label);
}

Pdf_reader::~Pdf_reader()
{
    delete m_stacked_layout;
    m_stacked_layout = nullptr;

    delete m_label;
    m_label = nullptr;

    delete m_ui;
    m_ui = nullptr;
}

void Pdf_reader::open_file(const std::string& filename)
{
    try{
        const unsigned int page_number = 0;
        const unsigned int zoom = 100;
        const float rotation = 0;

        const auto context = std::make_shared<mupdf_wrapper::Context>();
        context->register_document_handlers();

        const auto document = std::make_shared<mupdf_wrapper::Document>(context, filename);

        const auto matrix = std::make_shared<mupdf_wrapper::Matrix>();
        matrix->set_zoom(zoom);
        matrix->set_rotation(rotation);

        const mupdf_wrapper::Pixmap pixmap(context, document, matrix, page_number);
        const auto samples = pixmap.get_samples();
        const auto width = pixmap.get_width();
        const auto height = pixmap.get_height();

        const auto image = QImage(samples, width, height, QImage::Format_RGB888, nullptr, samples);

        // Add image to UI
        m_label->setPixmap(QPixmap::fromImage(image));
        m_label->resize(m_label->sizeHint());
    }
    catch(std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void Pdf_reader::on_menu_open_file_triggered()
{
    const auto filename = QFileDialog::getOpenFileName(this, tr("Open file"), nullptr, tr("*.pdf"));

    if(!filename.isEmpty())
    {
        open_file(filename.toStdString());
    }
}
