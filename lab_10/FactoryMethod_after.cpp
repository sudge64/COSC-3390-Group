#include <iostream>
#include <string>

// Abstract Product: Report
class Report {
public:
    virtual void generate() = 0;
    virtual std::string Operation() const = 0;
};

// Concrete Products: PDF Report 
class PDFReport : public Report {
public:
    void generate() override {
        std::cout << "Generating a PDF report..." << std::endl;
        std::cout << "PDF report generated" << std::endl;
        // PDF report generation logic here
    }
};

// Concrete Products: CSV Report
class CSVReport : public Report {
public:
    void generate() override {
        std::cout << "Generating a CSV report..." << std::endl;
        std::cout << "CSV report generated" << std::endl;
        // CSV report generation logic here
    }
};

// Abstract Factory: ReportFactory
class reportFactory : public Report{
    public:
        virtual ~reportFactory(){};
        virtual Report* createReport() const = 0;
};

// Concrete Factories: PDFReportFactory and CSVReportFactory
class PDFReportFactory : public reportFactory{
    public:
        Report* createReport() const override{
            return new PDFReportFactory();
        }
};

class CSVReportFactory : public reportFactory{
    public:
        Report* createReport() const override{
            return new CSVReportFactory();
        }
};

int main() {
    // Client code
    std::string reportType;
    Report *report;
    // Create "factory" pointer to ReportFactory
    reportFactory *factory = new reportFactory();
    
    // User input: Choose the type of report to generate
    std::cout << "Choose the type of report (PDF/CSV): ";
    std::cin >> reportType;

    if (reportType == "PDF") {
        // report = new PDFReport();// instead, assign to factory a new PDFReportFactory
        factory = new PDFReportFactory();// instead, assign to factory a new PDFReportFactory
    } else if (reportType == "CSV") {
        // report = new CSVReport();// instead, assign to factory a new PDFReportFactory
        factory = new CSVReportFactory();// instead, assign to factory a new PDFReportFactory
    } else {
        std::cout << "Invalid report type." << std::endl;
        return 1;
    }

    // report must receive return from method "factory->createReport()"
    report = factory->createReport();

    // Generate the selected report
    report->generate();

    // Clean up
    delete report;
    // Also delete factory
    delete factory;
    return 0;
}
