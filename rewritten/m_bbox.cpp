// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Main loop menu stuff.
//	Random number LUT.
//	Default Config File.
//	PCX Screenshots.
// 
// static const char rcsid[] = "$Id: m_bbox.c,v 1.1 1997/02/03 22:45:10 b1 Exp $";
//-----------------------------------------------------------------------------




#ifdef __GNUG__
#pragma implementation "include/m_bbox.hpp"
#endif
#include "include/m_bbox.hpp"

void Bbox::ClearBox(fixed_t*	box)
{
    box[BOX::TOP] = box[BOX::RIGHT] = MININT;
    box[BOX::BOTTOM] = box[BOX::LEFT] = MAXINT;
}

void Bbox::AddToBox(fixed_t* box, fixed_t x, fixed_t y)
{
    if (x<box[BOX::LEFT])
	box[BOX::LEFT] = x;
    else if (x>box[BOX::RIGHT])
	box[BOX::RIGHT] = x;
    if (y<box[BOX::BOTTOM])
	box[BOX::BOTTOM] = y;
    else if (y>box[BOX::TOP])
	box[BOX::TOP] = y;
}

int main(int argc, char* argv[]){}