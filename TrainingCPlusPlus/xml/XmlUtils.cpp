#include "stdafx.h"
#include "XmlUtils.h"

string XmlUtils::GetNodeValue(xml_node<> *node, string nodeName)
{
	xml_node<> *sibling = node->first_node();
	string currentNodeName = sibling->name();
	while (sibling != NULL && nodeName != currentNodeName)
	{
		sibling = sibling->next_sibling();
		currentNodeName = sibling->name();
	}

	return sibling->value();
}
