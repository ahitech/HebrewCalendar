#include <File.h>

#include "MoonPhase.h"




MoonPhase (BRect frame, const char *name)
	: BView (frame, name, B_FOLLOW_ALL_SIDES,
			 B_WILL_DRAW | B_FRAME_EVENTS | B_FULL_UPDATE_ON_RESIZE)
{
	
	
}




void MoonPhase::AttachedToWindow ()
{
	BView* parent = Parent();
	if (parent)
	{
		SetViewColor (parent->ViewColor());
	}
	BView::AttachedToWindow();
	ResizeToPreferred();
}
