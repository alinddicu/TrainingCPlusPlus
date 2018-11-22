#pragma once
#include <string>
#include "rapidxml.hpp";

using namespace std;
using namespace rapidxml;

class XmlUtils
{
public:
	static string XmlUtils::GetNodeValue(xml_node<> *node, string nodeName);
};

