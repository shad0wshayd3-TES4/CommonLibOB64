#include "UE/U/UObject.h"

#include "UE/U/UClass.h"

namespace UE
{
	UFunction* UObject::FindFunction(FName a_name) const
	{
		return GetClass()->FindFunctionByName(a_name);
	}

	UFunction* UObject::FindFunctionChecked(FName a_name) const
	{
		// TODO: check?
		return FindFunction(a_name);
	}
}
