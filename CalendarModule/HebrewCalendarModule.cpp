#include <map>
#include <stdlib.h>
#include <stdio.h>

#include "HebrewCalendarModule.h"
#include "CalendarModule.h"
#include "TimeRepresentation.h"

class CalendarModule;

/// Default constructor
HebrewCalendar::HebrewCalendar (void)
{
	int i;
	this->id.SetTo("Hebrew");
	this->fDaysInLongestMonth = 31;
	this->fDaysInWeek = 7;
	
	// Fill in the days of the month
	for (i = 1; i < 32; i++)
	{
		if (i < 10)
		{

		}
		else 
		{
			
		}
	}

	// Fill in the names of the months


	// Fill in the names of the weekdays
}



HebrewCalendar::HebrewCalendar (const HebrewCalendar& in)
{ 
	this->fDaysInWeek = in.fDaysInWeek;
	this->fDaysNames = in.fDaysNames;
	this->fMonthsNames = in.fMonthsNames;
	this->fWeekdaysNames = in.fWeekdaysNames;
	this->id.SetTo(in.id);
}
