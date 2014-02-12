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

#include "Object.h"

CObject::CObject()
{
	mReferences = 1;
}

CObject::~CObject()
{
}

void CObject::retain()
{
	mReferences++;
}

void CObject::release()
{
	mReferences--;
	if (mReference == 0)
	{
		delete this;
	}
}

unsigned int CObject::references()
{
	return mReferences;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */

