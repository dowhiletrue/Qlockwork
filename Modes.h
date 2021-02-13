/******************************************************************************
Modes.h
******************************************************************************/

#ifndef MODES_H
#define MODES_H

typedef enum eMode : uint8_t
{
	STD_MODE_TIME,
	STD_MODE_AMPM,
	STD_MODE_SECONDS,
	STD_MODE_WEEKDAY,
	STD_MODE_DATE,
	STD_MODE_TITLE_TEMP,
#if defined(RTC_BACKUP) || defined(SENSOR_DHT22)
	STD_MODE_TEMP,
#endif
#ifdef SENSOR_DHT22
	STD_MODE_HUMIDITY,
#endif
#ifdef BUZZER
	STD_MODE_TITLE_ALARM,
	STD_MODE_SET_TIMER,
	STD_MODE_TIMER,
	STD_MODE_ALARM_1,
	STD_MODE_SET_ALARM_1,
	STD_MODE_ALARM_2,
	STD_MODE_SET_ALARM_2,
#endif
	STD_MODE_COUNT,
	STD_MODE_BLANK,
	EXT_MODE_START,
	EXT_MODE_TITLE_MAIN = EXT_MODE_START,
#ifdef PIN_LDR
	EXT_MODE_LDR,
#endif
	EXT_MODE_BRIGHTNESS,
	EXT_MODE_COLORCHANGE,
	EXT_MODE_MOOD_RATE,
	EXT_MODE_COLOR,
	EXT_MODE_TRANSITION,
	EXT_MODE_TIMEOUT,
	EXT_MODE_EVT,
	EXT_MODE_LANGUAGE,
	EXT_MODE_TITLE_TIME,
	EXT_MODE_TIMESET,
	EXT_MODE_IT_IS,
	EXT_MODE_DAYSET,
	EXT_MODE_MONTHSET,
	EXT_MODE_YEARSET,
	EXT_MODE_TEXT_NIGHTOFF,
	EXT_MODE_NIGHTOFF,
	EXT_MODE_TEXT_DAYON,
	EXT_MODE_DAYON,
	EXT_MODE_TITLE_TEST,
	EXT_MODE_TEST,
	EXT_MODE_COUNT
} Mode;

// Overload the ControlType++ operator.
inline Mode& operator++(Mode& eDOW, int)
{
	const uint8_t i = static_cast<uint8_t>(eDOW) + 1;
	eDOW = static_cast<Mode>((i) % EXT_MODE_COUNT);
	return eDOW;
}

enum eTransition : uint8_t
{
	TRANSITION_NORMAL,
	TRANSITION_FADE,
	TRANSITION_MATRIX,
	TRANSITION_SLIDE,
	TRANSITION_COUNT = TRANSITION_SLIDE
};

#endif
