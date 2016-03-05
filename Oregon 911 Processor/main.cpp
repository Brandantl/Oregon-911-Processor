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
#include <Poco/DOM/NamedNodeMap.h>
#include <Poco/String.h>

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n\n";

    const std::string WCCCA_STR = util::tidyHTML(GET_WCCCA_DATA());

    ofstream myfile;
    myfile.open("wccca.html");
    myfile << WCCCA_STR;
    myfile.close();

    std::string WCCCA_DATA;

    vector<struct WCCCA_JSON> gpsData;
    if (util::isWCCCAHTMLValid(WCCCA_STR)) {

        gpsData = util::getWCCCAGPSFromHTML(WCCCA_STR);

        // If theres GPS data then it's highly likely theres call data too!
        if (gpsData.size() > 0) {
            try
            {
                // HTML Parser
                Poco::XML::DOMParser parser;
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACES, true);
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
                Poco::XML::AutoPtr<Poco::XML::Document> pDoc = parser.parseString(WCCCA_STR);
                Poco::XML::NodeIterator it(pDoc->getNodeByPath("html/body/form/div"), Poco::XML::NodeFilter::SHOW_ALL);
                Poco::XML::Node* pNode = it.nextNode();

                Poco::XML::NamedNodeMap* attributes = NULL;
                Poco::XML::Node* attribute = NULL;

                string nName;
                string nValue;
                string timeTemp;

                std::vector<string>     callNumbers;
                std::vector<char>       counties;
                std::vector<string>     callSummeries;
                std::vector<string>     addresses;
                std::vector<string>     callTime[4];
                std::vector<string>     agency;
                std::vector<string>     station;

                while (pNode)
                {
                    if (pNode->hasAttributes()) {
                        attributes = pNode->attributes();
                        bool found = false;
                        for (unsigned int i = 0; i < attributes->length(); i++)
                        {
                            attribute = attributes->item(i);
                            nName = attribute->nodeName();
                            nValue = attribute->getNodeValue();


                            if (nName == "id" && nValue.find("CallNo") != std::string::npos) {
                                // We found a call number!
                                callNumbers.push_back(pNode->innerText());
                                if (nValue.find("CCOM") != std::string::npos) {
                                    counties.push_back('C');
                                }
                                else {
                                    counties.push_back('W');
                                }
                            }
                            else  if (nName == "id" && nValue.find("CallType") != std::string::npos) {
                                callSummeries.push_back(Poco::toUpper(pNode->innerText()));
                            }
                            else  if (nName == "class" && nValue.find("address") != std::string::npos) {
                                addresses.push_back(Poco::toUpper(pNode->innerText()));
                            }
                            else  if (nName == "title" && nValue == "Call Entry Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    callTime[0].push_back(timeTemp);
                                }
                            }
                            else  if (nName == "title" && nValue == "Dispatch Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    callTime[1].push_back(timeTemp);
                                }
                            }
                            else  if (nName == "title" && nValue == "En Route Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    callTime[2].push_back(timeTemp);
                                }
                            }
                            else  if (nName == "title" && nValue == "On Scene Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    callTime[3].push_back(timeTemp);
                                }
                            }
                            else  if (nName == "class" && nValue == "units") {
                                // These skips are required because agency cannot be found
                                // by name and value as the value constantly changes.

                                // Skip node
                                pNode = it.nextNode();
                                agency.push_back(pNode->innerText());

                                // Skip node
                                pNode = it.nextNode(); // Skip past Agency node
                                pNode = it.nextNode(); // Skip past a / 
                                pNode = it.nextNode(); // ???
                                station.push_back(pNode->innerText()); // It works.
                            }
                        }
                    }
                    pNode = it.nextNode();
                }
            }
            catch (Poco::Exception& e)
            {
                std::cerr << e.displayText() << std::endl;
            }

            cout << WCCCA_DATA;

        }
    }

    delete DataCache;
    return 0;
}
