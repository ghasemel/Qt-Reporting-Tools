#include "reportpp/types/PageFormat.hpp"
#include "reportpp/types/ReportFormat.hpp"

#include <ostream>

std::ostream& operator<<(std::ostream &os, const reportpp::types::PageFormat &obj) {
    switch (obj) {
        case reportpp::types::PageFormat::letter:    os << "reportpp::types::PageFormat::letter"; break;
        case reportpp::types::PageFormat::legal:     os << "reportpp::types::PageFormat::legal"; break;
        case reportpp::types::PageFormat::a3:        os << "reportpp::types::PageFormat::a3"; break;
        case reportpp::types::PageFormat::a4:        os << "reportpp::types::PageFormat::a4"; break;
        case reportpp::types::PageFormat::a5:        os << "reportpp::types::PageFormat::a5"; break;
        case reportpp::types::PageFormat::b4:        os << "reportpp::types::PageFormat::b4"; break;
        case reportpp::types::PageFormat::b5:        os << "reportpp::types::PageFormat::b5"; break;
        case reportpp::types::PageFormat::executive: os << "reportpp::types::PageFormat::executive"; break;
        case reportpp::types::PageFormat::us4x6:     os << "reportpp::types::PageFormat::us4x6"; break;
        case reportpp::types::PageFormat::us4x8:     os << "reportpp::types::PageFormat::us4x8"; break;
        case reportpp::types::PageFormat::us5x7:     os << "reportpp::types::PageFormat::us5x7"; break;
        case reportpp::types::PageFormat::comm10:    os << "reportpp::types::PageFormat::comm10"; break;
        default: os << "UNKNOWN!"; break;
    }
   return os;
}

std::ostream& operator<<(std::ostream &os, const reportpp::types::ReportFormat &obj) {
    os << "ReportPage{format=" << obj.getFormat();
    os << ", margins(TBLR)=[" << obj.getMarginTop() << ", " << obj.getMarginBottom();
    os << ", " << obj.getMarginLeft() << ", " << obj.getMarginRight() << "]}";
   return os;
}
