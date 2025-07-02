#pragma once

#include "RE/T/TESGlobal.h"

namespace RE
{
	class GameCalendar
	{
	public:
		static GameCalendar* GetSingleton()
		{
			static REL::Relocation<GameCalendar*> singleton{ ID::GameCalendar::Singleton };
			return singleton.get();
		}

		[[nodiscard]] float GetGameYear() const { return gameYear->value; }
		[[nodiscard]] float GetGameWeek() const { return gameWeek->value; }
		[[nodiscard]] float GetGameDay() const { return gameDay->value; }
		[[nodiscard]] float GetGameHour() const { return gameHour->value; }
		[[nodiscard]] float GetGameDaysPassed() const { return gameDaysPassed->value; }
		[[nodiscard]] float GetTimeScale() const { return timeScale->value; }

		[[nodiscard]] float GetCurrentGameTime() const { return gameDaysPassed->value + (gameHour->value / 24.0f); }  // Like Skyrim's GameDaysPassed (Oblivion's is truncated).

		void SetTimeScale(float a_value) { timeScale->value = a_value; }

		TESGlobal* gameYear;
		TESGlobal* gameWeek;
		TESGlobal* gameDay;
		TESGlobal* gameHour;
		TESGlobal* gameDaysPassed;
		TESGlobal* timeScale;
	};
}
