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

#include "Selection.h"
#include "Parser.h"
#include "QueryUtil.h"

CSelection::CSelection(GumboNode* apNode)
{
	mpNodes.push_back(apNode);
}

CSelection::CSelection(std::vector<GumboNode*> apNodes)
{
	mpNodes = apNodes;
}

CSelection::~CSelection()
{
}

CSelection* CSelection::find(std::string aSelector)
{
	CSelector* sel = CParser::create(aSelector);
	std::vector<GumboNode*> ret;
	for (std::vector<GumboNode*>::iterator it = mpNodes.begin(); it != mpNodes.end(); it++)
	{
		GumboNode* pNode = *it;
		std::vector<GumboNode*> matched = sel->matchAll(pNode);
		ret = CQueryUtil::unionNodes(ret, matched);
	}
	sel->release();
	return new CSelection(ret);
}

std::vector<GumboNode*> CSelection::nodes()
{
	return mpNodes;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */

