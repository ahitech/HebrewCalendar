#ifndef __HEBREW_CALENDAR_H__
#define __HEBREW_CALENDAR_H__

#include "TimeRepresentation.h"
#include "CalendarModule.h"

class CalendarModule;

/**
 *	\class	HebrewCalendar
 *
 *	\brief	This class implements Hebrew Calendar module.
 *
 *			It makes heavy usage of the HDATE library (https://sourceforge.net/p/libhdate/wiki/Home/)
 */
class HebrewCalendar : 
	public CalendarModule
{
private:	// Constants for the calendar calculation
	unsigned char	fDaysInWeek;			//!< In Hebrew Calendar, it's 7.
	map<int, DoubleNames> fMonthsNames;		//!< Names of the months, localized, in short and long form.
	map<int, BString> fDaysNames;			//!< Names of the days, localized.
	map<uint32, DoubleNames> fWeekdaysNames;	//!< Names of the weekdays, localized, in short and long form.
	BString id;								//!< Identifier of the module.
	unsigned char	fDaysInLongestMonth;	//!< How many days the longest month has?

public:
		//! These functions translate the times from one format to another.
	virtual TimeRepresentation FromLocalCalendarToGregorian(const TimeRepresentation& timeIn);
	virtual TimeRepresentation FromGregorianCalendarToLocal(TimeRepresentation& timeIn);
	virtual time_t FromLocalCalendarToTimeT(const TimeRepresentation& timeIn);
	virtual TimeRepresentation FromTimeTToLocalCalendar(const time_t timeIn);

	//! These functions translate the years to and from the local calendar.
	virtual int FromLocalToGregorianYear(int year);
	virtual int FromGregorianToLocalYear(int year);
	
	//! These functions return the names of the months in given year.
	virtual map<int, DoubleNames> GetMonthNamesForGregorianYear(int gregorianYear);
	virtual map<int, DoubleNames> GetMonthNamesForLocalYear(int localYear);

	//! These functions return the localized names of the days in given year and month.
	virtual map<int, BString> GetDayNamesForGregorianYearMonth(int gregoryanYear, int month);
	virtual map<int, BString> GetDayNamesForLocalYearMonth(int localYear, int month);

	/*! The following function returns map where each weekday's name is mapped to corresponding
	 *	int from the enum WEEKDAYS.
	 */
	virtual map<uint32, DoubleNames> GetWeekdayNames(void);

	/*!	\brief	This way the caller can place a given date at a specific place in the grid.
	 */
	virtual uint32 GetWeekDayForLocalDate(const TimeRepresentation& date, int *wday = NULL);
	virtual int GetWeekDayForLocalDateAsInt(const TimeRepresentation& date);
	virtual int GetWeekDayForLocalDateAsInt(const uint32 in);
	virtual int DayFromBeginningOfTheYear(TimeRepresentation& date);

	//! Identification
	virtual const BString Identify(void);	
	
	//! Construction and destruction
	HebrewCalendar();
	HebrewCalendar(const CalendarModule& in);

	virtual ~HebrewCalendar(void);

	//! Date legality verification.
	virtual TimeRepresentation NormalizeDate(const TimeRepresentation &in);
	/*! \brief	This function accepts a date and answers the question if it's valid or not.
	 *			It's the caller's responcibility to call this function only when 
	 *			the constructed struct tm represents really a date.
	 */
	virtual bool IsDateValid(TimeRepresentation& in);

	/*! \brief	This function calculates time difference between two dates.
	 */
	virtual TimeRepresentation GetDifference(const TimeRepresentation& op1, const TimeRepresentation& op2, bool daysOnly = false);

	//! Date manipulation routines
	virtual TimeRepresentation AddTime(const TimeRepresentation &op1, const TimeRepresentation &op2);
	virtual TimeRepresentation& AddTimeTo1stOperand(TimeRepresentation &op1, const TimeRepresentation &op2);
/*	virtual TimeRepresentation SubTime(const TimeRepresentation &op1, const TimeRepresentation &op2);
	virtual TimeRepresentation& SubTimeFrom1stOperand(TimeRepresentation &op1, const TimeRepresentation &op2);
*/	
	//! To ease the calculation of the rectangle to display the month
	virtual void SetLongestMonthLength(const unsigned char length);
	virtual unsigned char GetLongestMonthLength(void) const;
	virtual void SetDaysInWeek(const unsigned char length);
	virtual unsigned char GetDaysInWeek(void) const;
	
	virtual BList* GetDefaultWeekend( void ) const;
	virtual uint32	GetDefaultStartingDayOfWeek( void ) const;
};

#endif	// __HEBREW_CALENDAR_H__