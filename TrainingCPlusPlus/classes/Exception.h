#pragma once

#include <string>

using namespace std;

class Exception : public std::exception
{
public:

	Exception(const char* message) :
		msg_(message)
	{
	}

	Exception(const std::string& message) :
		msg_(message)
	{
	}

	virtual ~Exception() throw () 
	{
	}

	virtual const char* what() const throw () 
	{
		return msg_.c_str();
	}

protected:
	string msg_;
};

