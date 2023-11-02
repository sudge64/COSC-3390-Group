#include <iostream>
#include <string>

// Abstract Product: Report
class Report {
public:
    virtual void generate() = 0;
};

// Concrete Products: PDF Report and CSV Report
class PDFReport : public Report {
public:
    void generate() override {
        std::cout << "Generating a PDF report..." << std::endl;
        // PDF report generation logic here
    }
};

class CSVReport : public Report {
public:
    void generate() override {
        std::cout << "Generating a CSV report..." << std::endl;
        // CSV report generation logic here
    }
};

// Abstract Factory: ReportFactory
class reportFactory : public Report{
    public:
        void generate() override{
            
        }

};

// Concrete Factories: PDFReportFactory and CSVReportFactory
class PDFReportFactory : public reportFactory{
    public:
        PDFReport::generate();
};

class CSVReportFactory : public reportFactory{
    public:
        CSVReport::generate();
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
        report = new PDFReport();// instead, assign to factory a new PDFReportFactory
    } else if (reportType == "CSV") {
        report = new CSVReport();// instead, assign to factory a new PDFReportFactory
    } else {
        std::cout << "Invalid report type." << std::endl;
        return 1;
    }

	// report must receive return from method "factory->createReport()"

    // Generate the selected report
    report->generate();

    // Clean up
    delete report;
	// Also delete factory
    delete factory;
    return 0;
}
