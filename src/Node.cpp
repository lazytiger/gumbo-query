/***************************************************************************
 * 
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

#include "Node.h"
#include "Selection.h"
#include "QueryUtil.h"

CNode::CNode(GumboNode* apNode)
{
	mpNode = apNode;
}

CNode::~CNode()
{
}

CNode CNode::parent()
{
	return CNode(mpNode->parent);
}

CNode CNode::nextSibling()
{
	return parent().childAt(mpNode->index_within_parent + 1);
}

CNode CNode::prevSibling()
{
	return parent().childAt(mpNode->index_within_parent - 1);
}

unsigned int CNode::childNum()
{
	if (mpNode->type != GUMBO_NODE_ELEMENT)
	{
		return 0;
	}

	return mpNode->v.element.children.length;

}

bool CNode::valid()
{
	return mpNode != NULL;
}

CNode CNode::childAt(unsigned int i)
{
	if (mpNode->type != GUMBO_NODE_ELEMENT || i >= mpNode->v.element.children.length)
	{
		return CNode();
	}

	return CNode((GumboNode*) mpNode->v.element.children.data[i]);
}

std::string CNode::attribute(std::string key)
{
	if (mpNode->type != GUMBO_NODE_ELEMENT)
	{
		return "";
	}

	GumboVector attributes = mpNode->v.element.attributes;
	for (unsigned int i = 0; i < attributes.length; i++)
	{
		GumboAttribute* attr = (GumboAttribute*) attributes.data[i];
		if (key == attr->name)
		{
			return attr->value;
		}
	}

	return "";
}

std::string CNode::text()
{
	return CQueryUtil::nodeText(mpNode);
}

std::string CNode::ownText()
{
	return CQueryUtil::nodeOwnText(mpNode);
}

std::string CNode::tag()
{
	if (mpNode->type != GUMBO_NODE_ELEMENT)
	{
		return "";
	}

	return gumbo_normalized_tagname(mpNode->v.element.tag);
}

CSelection CNode::find(std::string aSelector)
{
	CSelection c(mpNode);
	return c.find(aSelector);
}
/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
