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

#include "QueryUtil.h"

std::string CQueryUtil::tolower(std::string s)
{
	for (unsigned int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c >= 'A' && c <= 'Z')
		{
			c = 'a' + c - 'A';
			s[i] = c;
		}
	}

	return s;
}

std::vector<GumboNode*> CQueryUtil::unionNodes(std::vector<GumboNode*> aNodes1,
		std::vector<GumboNode*> aNodes2)
{
	for (std::vector<GumboNode*>::iterator it = aNodes2.begin(); it != aNodes2.end(); it++)
	{
		GumboNode* pNode = *it;
		if (nodeExists(aNodes1, pNode))
		{
			continue;
		}

		aNodes1.push_back(pNode);
	}

	return aNodes1;
}

bool CQueryUtil::nodeExists(std::vector<GumboNode*> aNodes, GumboNode* apNode)
{
	for (std::vector<GumboNode*>::iterator it = aNodes.begin(); it != aNodes.end(); it++)
	{
		GumboNode* pNode = *it;
		if (pNode == apNode)
		{
			return true;
		}
	}
	return false;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */

