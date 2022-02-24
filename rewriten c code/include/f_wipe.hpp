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
// DESCRIPTION:
//	Mission start screen wipe/melt, special effects.
//	
//-----------------------------------------------------------------------------


#ifndef __F_WIPE_HPP__
#define __F_WIPE_HPP__

class wipe
{
public:
    int StartScreen(int x, int	y, int width, int height);

    int EndScreen(int x, int y, int width, int	height);

    int ScreenWipe(int	wipeno, int	x, int y, int width, int height, int ticks);
};

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
