#pragma once

#include "UE/T/TWeakObjectPtr.h"

namespace UE
{
	class UPackage;
	class UStruct;

	class FStructOnScope
	{
	public:
		// add
		virtual void                Initialize();                     // 001
		virtual bool                OwnsStructMemory() const;         // 002
		virtual std::uint8_t*       GetStructMemory();                // 003
		virtual const std::uint8_t* GetStructMemory() const;          // 004
		virtual const UStruct*      GetStruct() const;                // 005
		virtual UPackage*           GetPackage() const;               // 006
		virtual void                SetPackage(UPackage* a_package);  // 007
		virtual bool                IsValid() const;                  // 008
		virtual void                Destroy();                        // 009
		virtual void                Reset();                          // 00A
		virtual ~FStructOnScope();                                    // 00B

		// members
		TWeakObjectPtr<const UStruct> scriptStruct;        // 008
		std::uint8_t*                 sampleStructMemory;  // 010
		TWeakObjectPtr<UPackage>      package;             // 018
		bool                          ownsMemory;          // 020
	};
	static_assert(sizeof(FStructOnScope) == 0x28);
}
