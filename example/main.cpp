/***************************************************************************
 * 
 * Copyright (c) 2010 babeltime.com, Inc. All Rights Reserved
 * $Id$
 * 
 **************************************************************************/

/**
 * @file $HeadURL$
 * @author $Author$(hoping@babeltime.com)
 * @date $Date$
 * @version $Revision$
 * @brief 
 *  
 **/

#include "Document.h"
#include <iostream>
#include <fstream>

int main()
{
	try
	{
		CDocument d;

		std::ifstream in("test.html", std::ios::in | std::ios::binary);
		if (!in)
		{
			std::cout << "File test.html not found!\n";
			return 1;
		}

		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();

		d.parse(contents.c_str());
		CSelection c = d.find(".sep");
		std::cout << c.nodeNum() << std::endl;
	}
	catch (const char* message)
	{
		std::cout << message << std::endl;
	}
	catch (std::string message)
	{
		std::cout << message << std::endl;
	}

	return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
