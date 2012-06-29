//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
#ifndef __LOG_ADAPTER_H_
#define __LOG_ADAPTER_H_

using namespace System::Collections::ObjectModel;

#include <vcclr.h>
#include <APL/LogBase.h>

using namespace DNP3::Interface;

namespace DNPDotNet
{		
	class LogAdapter : public apl::ILogBase
	{
		public:

		LogAdapter(ILogHandler^ proxy);

		// logging error messages, etc
		void Log( const apl::LogEntry& arEntry );

		// updating a variable/metric in the system
		void SetVar(const std::string& aSource, const std::string& aVarName, int aValue);

		private:		
		gcroot<ILogHandler^> proxy;
	};
	
	public ref class LogAdapterWrapper
	{
		public:
		LogAdapterWrapper(ILogHandler^ proxy) : mpAdapter(new LogAdapter(proxy))
		{}

		apl::ILogBase* GetLogAdapter() { return mpAdapter; }

		~LogAdapterWrapper()
		{ delete mpAdapter; }

		private:
		LogAdapter* mpAdapter;
	};
}

#endif