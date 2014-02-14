/***************************************************************************
 * 
 * Copyright (c) 2010 baimashi.com, Inc. All Rights Reserved
 * $Id$
 * 
 **************************************************************************/

/**
 * @file $HeadURL$
 * @author $Author$(hoping@baimashi.com)
 * @date $Date$
 * @version $Revision$
 * @brief 
 *  
 **/

#include "Document.h"
#include <iostream>
#include <fstream>
#include "Node.h"

int main()
{
	try
	{
		CDocument d;

		std::ifstream in("new.html", std::ios::in | std::ios::binary);
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
		CSelection c = d.find("div.left-mods-txt");
		for (unsigned int i = 0; i < c.nodeNum(); i++)
		{
			CNode n = c.nodeAt(i);
			CNode a = n.childAt(0);
			std::cout << a.attribute("href") << a.text() << std::endl;
		}
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
