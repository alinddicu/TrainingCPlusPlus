#pragma once
#include <string>
#include "rapidxml.hpp";

using namespace std;
using namespace rapidxml;

template <typename T>
class XmlUtils
{
public:
	static T XmlUtils::GetNodeValue(xml_node<> *node, string nodeName)
	{
		xml_node<> *sibling = node->first_node();
		string currentNodeName = sibling->name();
		while (sibling != NULL && nodeName != currentNodeName)
		{
			sibling = sibling->next_sibling();
			currentNodeName = sibling->name();
		}

		return static_cast<T>(sibling->value());
	}
};

