/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
*/
#include "or911.h"
#include "structs.h"
#include "data.h"
#include "Unit.h"
#include "Call.h"
#include "Utils.h"
#include "DataMaps.h"
#include <iostream>
#include <string>
using namespace std;

#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/SAX/InputSource.h>

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n\n";

    const std::string WCCCA_STR = GET_WCCCA_DATA();

    vector<struct WCCCA_JSON> gpsData;
    if (util::isWCCCAHTMLValid(WCCCA_STR)) {
        
        gpsData = util::getWCCCAGPSFromHTML(WCCCA_STR);

        // If theres GPS data then it's highly likely theres call data too!
        if (gpsData.size() > 0) {
            // Convert HTML to XHTML so Poco can read it.
            std::string tidyResult = util::tidyHTML(WCCCA_STR);

            try
            {
                Poco::XML::DOMParser parser;
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACES, true);
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
                Poco::XML::AutoPtr<Poco::XML::Document> pDoc = parser.parseString(tidyResult);

                Poco::XML::NodeIterator it(pDoc, Poco::XML::NodeFilter::SHOW_TEXT);
                Poco::XML::Node* pNode = it.nextNode();
                while (pNode)
                {
                    std::cout << pNode->nodeType() << ":" << pNode->nodeValue() << std::endl;
                    pNode = it.nextNode();
                }


            }
            catch (Poco::Exception& e)
            {
                std::cerr << e.displayText() << std::endl;
            }

        }

    }

    delete DataCache;
    return 0;
}
