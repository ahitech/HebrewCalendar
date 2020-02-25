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

	names.longName = BString ("Kislev");
	names.shortName = BString ("Kislev");
	this->fMonthNames[3] = names;
	
	names.longName = BString("Tevet");
	names.shortName = BString ("Tevet");
	this->fMonthNames[4] = names;
	
	names.longName = BString("Shevat");
	names.shortName = BString ("Shevat");
	this->fMonthNames[5] = names;
	
	// Actually, the Adar should be omitted; libhdate should never
	// return 6, returning 13 or 14 instead (see below).
	// I leave it here because holes in arrays are bad practice.
	names.longName = BString("Adar")
	names.shortName = BString ("Adar");
	this->fMonthNames[6] = names;
	
	names.longName = BString("Nisan");
	names.shortName = BString("Nisan");
	this->fMonthNames[7] = names;
	
	names.longName = BString("Iyar");
	names.shortName = BString("Iyar");
	this->fMonthNames[8] = names;
	
	names.longName = BString ("Sivan");
	names.shortName = BString ("Sivan");
	this->fMonthNames[9] = names;
	
	names.longName = BString ("Tammuz");
	names.shortName = BString ("Tammuz");
	this->fMonthNames[10] = names;
	
	names.longName = BString ("Av");
	names.shortName = BString ("Av");
	this->fMonthNames[11] = names;
	
	names.longName = BString ("Elul");
	names.shortName = BString ("Elul");
	this->fMonthNames[12] = names;
	
	names.longName = BString("Adar")
	names.shortName = BString ("Adar");
	this->fMonthNames[13] = names;
	
	names.longName = BString("Adar B")
	names.shortName = BString ("Adar B");
	this->fMonthNames[14] = names;
	
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
