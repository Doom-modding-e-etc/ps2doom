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
//      Zone Memory Allocation, perhaps NeXT ObjectiveC inspired.
//	Remark: this was the only stuff that, according
//	 to John Carmack, might have been useful for
//	 Quake.
//
//---------------------------------------------------------------------


/*****************************************************
******************************************************
** This header file has some problems with z aclloc **
******************************************************
******************************************************/

#ifndef __Z_ZONE__HPP
#define __Z_ZONE__HPP

#include <stdio.h>
#include "doomtype.hpp"
//
// ZONE MEMORY
// PU - purge tags.
// Tags < 100 are not overwritten until freed.
#define PU_STATIC 1	// static entire execution time
#define PU_SOUND		2	// static while playing
#define PU_MUSIC		3	// static while playing
#define PU_DAVE		4	// anything else Dave wants static
#define PU_LEVEL		50	// static until level exited
#define PU_LEVSPEC		51      // a special thinker in a level
// Tags >= 100 are purgable whenever needed.
#define PU_PURGELEVEL	100
#define PU_CACHE		101

// cosmito from lsdldoom
void *(Z_Calloc)(size_t n, size_t n2, int tag, void **user, const char *, int);
#define Z_Calloc(a,b,c,d)  (Z_Calloc)   (a,b,c,d, __FILE__, __LINE__)
#define calloc(n1,n2)      Z_Calloc(n1,n2,PU_STATIC,0)

class Z
{
  public:
    void	Init (void);
    void*	Malloc (int size, int tag, void *ptr);
    void    Free (void *ptr);
    void    FreeTags (int lowtag, int hightag);
    void    DumpHeap (int lowtag, int hightag);
    void    FileDumpHeap (FILE *f);
    void    CheckHeap (void);
    void    ChangeTag2 (void *ptr, int tag);
    int     FreeMemory (void);
  protected:
    typedef struct memblock_s
    {
     int			size;	// including the header and possibly tiny fragments
     void**		user;	// NULL if a free block
     int			tag;	// purgelevel
     int			id;	// should be ZONEID
     memblock_s*	next;
     memblock_s*	prev;
    } memblock_t;
};

// This is used to get the local FILE:LINE info from CPP
// prior to really call the function in question.
//
#define Z_ChangeTag(p,t) \
{ \
      if (( (Z::memblock_t *)( (byte *)(p) - sizeof(Z::memblock_t)))->id!=0x1d4a11) \
	  //todo:
      //I_Error("Z_CT at "__FILE__":%i",__LINE__); \
Z_ChangeTag2(p,t); \
};


#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------