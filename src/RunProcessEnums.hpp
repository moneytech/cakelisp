#pragma once

enum ProcessCommandArgumentType
{
	ProcessCommandArgumentType_String,

	ProcessCommandArgumentType_SourceInput,
	ProcessCommandArgumentType_ObjectOutput,
	ProcessCommandArgumentType_CakelispHeadersInclude,

	ProcessCommandArgumentType_ObjectInput,
	ProcessCommandArgumentType_DynamicLibraryOutput,
};
