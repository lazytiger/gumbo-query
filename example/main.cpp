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

int main()
{
	try
	{
		CDocument d;
		d.parse("<html><head></head><body>test</body></html>");
		CSelection* c = d.find("body > a");
		std::cout << c->nodes().size() << std::endl;
		c->release();
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
