/*!	\file
 *
 *	\brief	The class that draws the Moon and its phase according to the input.
 *
 *	A shared library that provides the interface for drawing the picture of
 *	the Moon and optoinally covers it with shadow.
 *
 *	\author Alexey "Hitech" Burshtein
 *	\copyright	GNU Public License
 */


#ifndef MOONPHASE_H
#define MOONPHASE_H

#include <Message.h>
#include <Rect.h>
#include <View.h>


class MoonPhase :
	public BView
{
	public:
		/// Constructors and destructor
		MoonPhase  (BRect frame,
					const char* name);
		MoonPhase (BMessage* archive);
		virtual	~MoonPhase();
		
		/// Hook functions
		virtual void	AttachedToWindow (void);
		virtual void	ResizeToPreferred (void);
		virtual void	GetPreferredSize (float *width, float *height);
	
	private:
		BBitmap* moonBitmap;
	
};

#endif	// MOONPHASE_H
