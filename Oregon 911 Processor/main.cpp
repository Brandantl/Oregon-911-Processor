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
#include <fstream>
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

    const std::string WCCCA_STR = util::tidyHTML(GET_WCCCA_DATA());

    vector<struct WCCCA_JSON> gpsData;
    if (util::isWCCCAHTMLValid(WCCCA_STR)) {
        
        gpsData = util::getWCCCAGPSFromHTML(WCCCA_STR);

        // If theres GPS data then it's highly likely theres call data too!
        if (gpsData.size() > 0) {
            try
            {
                Poco::XML::DOMParser parser;
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACES, true);
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
                Poco::XML::AutoPtr<Poco::XML::Document> pDoc = parser.parseString(WCCCA_STR);

                //Iterate over every child node (non-recursively)
                for (Poco::XML::Node *pNode = pDoc->getNodeByPath("html/body/form/"); pNode != 0; pNode = pNode->nextSibling()) {
                    auto pElem = dynamic_cast<Poco::XML::Element*>(pNode);

                    if (pElem) {

                        if (pElem->getAttribute("id") == "wccca-incidents") {
                            cout << "Yes!";
                        }

                       /* for (Poco::XML::Node *pNode2 = pDoc->getNodeByPath("html/body/form/div/div"); pNode2 != 0; pNode2 = pNode->nextSibling()) {
                            auto pElem2 = dynamic_cast<Poco::XML::Element*>(pNode2);
                        }*/

                        //std::cout << "Node: " << pElem->tagName() << " " << pElem->innerText() << " Value: " << pElem->nodeValue() << endl;
                        //std::cout << "\n";
                    }
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
