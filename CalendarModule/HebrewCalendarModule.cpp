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
	BString builder;
	
	// Fill in the days of the month
	for (i = 1; i < 32; i++)
	{
		builder << (uint32)i;
		this->fDaysNames[i] = builder;
		builder.Truncate(0);		// Clear the string
	}

	// Fill in the names of the months
	struct DoubleNames names;
	
	names.longName = BString("Tishrei");
	names.shortName = BString("Tishrei");
	this->fMonthNames[1] = names;
	
	names.longName = BString("Kheshvan");
	names.shortName = BString("Kheshvan");
	this->fMonthNames[2] = names;


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
