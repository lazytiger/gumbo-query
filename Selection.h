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

#ifndef SELECTION_H_
#define SELECTION_H_

#include <vector>
#include "Object.h"

class CSelection: public CObject
{
	public:

		CSelection(GumboNode* apNode);

		CSelection(std::vector<GumboNode*> apNodes);

		virtual ~CSelection();

	public:

		CSelection* find(std::string aSelector);

		std::vector<GumboNode*> nodes();

	protected:

		std::vector<GumboNode*> mpNodes;
};

#endif /* SELECTION_H_ */

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
