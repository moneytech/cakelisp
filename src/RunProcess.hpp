#pragma once

#include "RunProcessEnums.hpp"

#include <string>
#include <vector>

struct RunProcessArguments
{
	const char* fileToExecute;
	const char** arguments;
};

int runProcess(const RunProcessArguments& arguments, int* statusOut);

typedef void (*SubprocessOnOutputFunc)(const char* subprocessOutput);

void waitForAllProcessesClosed(SubprocessOnOutputFunc onOutput);

//
// Helpers for programmatically constructing arguments
//

struct ProcessCommandArgument
{
	ProcessCommandArgumentType type;
	std::string contents;
};

struct ProcessCommand
{
	std::string fileToExecute;
	std::vector<ProcessCommandArgument> arguments;
};

struct ProcessCommandInput
{
	ProcessCommandArgumentType type;
	const char* value;
};

void PrintProcessArguments(const char** processArguments);
const char** MakeProcessArgumentsFromCommand(ProcessCommand& command,
                                             const ProcessCommandInput* inputs, int numInputs);

extern const int maxProcessesRecommendedSpawned;
