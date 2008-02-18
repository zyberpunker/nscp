/**************************************************************************
*   Copyright (C) 2004-2007 by Michael Medin <michael@medin.name>         *
*                                                                         *
*   This code is part of NSClient++ - http://trac.nakednuns.org/nscp      *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#pragma once

#include "NSCAThread.h"
#include <CheckMemory.h>

NSC_WRAPPERS_MAIN();
NSC_WRAPPERS_CLI();

class NSCAAgent {
private:
	CheckMemory memoryChecker;
	int processMethod_;
//	NSCAThreadImpl pdhThread;
	std::list<NSCAThreadImpl*> extra_threads;

public:

public:
	NSCAAgent();
	virtual ~NSCAAgent();
	// Module calls
	bool loadModule();
	bool unloadModule();
	std::wstring getConfigurationMeta();

	/**
	* Return the module name.
	* @return The module name
	*/
	std::wstring getModuleName() {
		return _T("NSCAAgent");
	}
	/**
	* Module version
	* @return module version
	*/
	NSCModuleWrapper::module_version getModuleVersion() {
		NSCModuleWrapper::module_version version = {0, 3, 0 };
		return version;
	}
	std::wstring getModuleDescription() {
		return _T("Various system related checks, such as CPU load, process state, service state memory usage and PDH counters.");
	}

	bool hasCommandHandler();
	bool hasMessageHandler();
	NSCAPI::nagiosReturn handleCommand(const strEx::blindstr command, const unsigned int argLen, TCHAR **char_args, std::wstring &msg, std::wstring &perf);
	int commandLineExec(const TCHAR* command, const unsigned int argLen, TCHAR** args);

	NSCAPI::nagiosReturn checkCPU(const unsigned int argLen, char **char_args, std::wstring &msg, std::wstring &perf);
	NSCAPI::nagiosReturn checkUpTime(const unsigned int argLen, char **char_args, std::wstring &msg, std::wstring &perf);
	NSCAPI::nagiosReturn checkServiceState(const unsigned int argLen, char **char_args, std::wstring &msg, std::wstring &perf);
	NSCAPI::nagiosReturn checkMem(const unsigned int argLen, char **char_args, std::wstring &msg, std::wstring &perf);
	NSCAPI::nagiosReturn checkProcState(const unsigned int argLen, char **char_args, std::wstring &msg, std::wstring &perf);
	NSCAPI::nagiosReturn checkCounter(const unsigned int argLen, char **char_args, std::wstring &msg, std::wstring &perf);

};