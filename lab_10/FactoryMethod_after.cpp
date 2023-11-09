#include <iostream>
#include <string>

// Abstract Product: Report
class Report {
public:
    virtual void generate() = 0;
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

// Abstract Factory: ReportFactory, with virtual method getReport()
class reportFactory{
    public:
        //virtual ~reportFactory(){};
        virtual Report* getReport() = 0;
};

// Concrete Factories: PDFReportFactory and CSVReportFactory, with implementation of getReport()
class PDFReportFactory : public reportFactory{
    public:
        Report* getReport() override{
            return new PDFReport();
        }
};

class CSVReportFactory : public reportFactory{
    public:
        Report* getReport() override{
            return new CSVReport();
        }

};

int main() {
    // Client code
    std::string reportType;
    Report* report;
    // Create "factory" pointer to ReportFactory
    reportFactory* factory;
    
    // User input: Choose the type of report to generate
    std::cout << "Choose the type of report (PDF/CSV): ";
    std::cin >> reportType;

    if (reportType == "PDF") {
        // instead, assign to factory a new PDFReportFactory
        factory = new PDFReportFactory();
    } else if (reportType == "CSV") {
        // instead, assign to factory a new CSVReportFactory
        factory = new CSVReportFactory();
    } else {
        std::cout << "Invalid report type." << std::endl;
        return 1;
    }

    // report must receive return from method "factory->createReports()"
    report = factory->getReport();

    // Generate the selected report
    report->generate();

    // Clean up
    delete report;
    // Also delete factory
    delete factory;
    return 0;
}
