
/*#include <stdio.h>
#include <string>
#include "tinyxml2.h"

using namespace tinyxml2;

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int main()
{
	
	// Create XML File
	XMLDocument xmlDoc;
	XMLNode * pRoot = xmlDoc.NewElement("Root");
	xmlDoc.InsertFirstChild(pRoot);

	// premier élément création avec pointeur
	XMLElement * pElement = xmlDoc.NewElement("IntValue");
	pElement->SetText(10);  // valeur du champ
	pRoot->InsertEndChild(pElement);
	//
	pElement = xmlDoc.NewElement("FloatValue");
	pElement->SetText(0.5f);   // valeur du champ
	pRoot->InsertEndChild(pElement);
	//
	pElement = xmlDoc.NewElement("Date");
	pElement->SetAttribute("day", 26);
	pElement->SetAttribute("month", "April");
	pElement->SetAttribute("year", 2014);
	pElement->SetAttribute("dateFormat", "26/04/2014");
	pRoot->InsertEndChild(pElement);
	//
	
	XMLError returncode_savexml = xmlDoc.SaveFile("SavedData.xml");
	XMLCheckResult(returncode_savexml);

	/*______________________________________________________________________________
	
	//  Load XML File into DOM
	XMLDocument xmlDoc2; 
 	XMLError returncode_loadxml = xmlDoc2.LoadFile("SavedData.xml");
	XMLCheckResult(returncode_loadxml);

	XMLNode * pRoot_in = xmlDoc2.FirstChild();
		if(pRoot_in == nullptr) return XML_ERROR_FILE_READ_ERROR;

	XMLElement * pElement_in = pRoot_in->FirstChildElement("IntValue");
		if (pElement_in == nullptr) return XML_ERROR_PARSING_ELEMENT;

		int iOutInt;  //variable pour recevoir le contenu de type int
		returncode_loadxml = pElement->QueryIntText(&iOutInt);
		XMLCheckResult(returncode_loadxml);

	pElement_in = pRoot_in->FirstChildElement("FloatValue");
		if (pElement_in == nullptr) return XML_ERROR_PARSING_ELEMENT;

		float fOutFloat;  //variable pour recevoir le contenu de type float
		returncode_loadxml = pElement_in->QueryFloatText(&fOutFloat);
		XMLCheckResult(returncode_loadxml);

	pElement_in = pRoot_in->FirstChildElement("Date");
		if (pElement_in == nullptr) return XML_ERROR_PARSING_ELEMENT;

		// éléments numérique
		int iOutDay;
		returncode_loadxml = pElement_in->QueryIntAttribute("day", &iOutDay);
		XMLCheckResult(returncode_loadxml);

		int iOutYear;
		returncode_loadxml = pElement_in->QueryIntAttribute("year", &iOutYear);
		XMLCheckResult(returncode_loadxml);

		// éléments en format texte
		const char * szAttributeText = nullptr;
		szAttributeText = pElement_in->Attribute("month");
			if (szAttributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
		std::string strOutMonth = szAttributeText;

		szAttributeText = pElement_in->Attribute("dateFormat");
			if (szAttributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
		std::string strOutFormat = szAttributeText;


	return 0;
}*/
