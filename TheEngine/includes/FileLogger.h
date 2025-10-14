#pragma once
#include "ILogger.h"
#include <iostream>
#include <fstream>
using namespace std;

class FileLogger final : public ILogger {
public:
	FileLogger();
	virtual ~FileLogger() = default;
	/// <summary>
	/// Takes a string and show it in the console
	/// </summary>
	/// <param name="message"></param>
	virtual void Log(const std::string& message) override;
	/// <summary>
	/// Quits the console
	/// </summary>
	virtual void Quit() override;

private:
	ofstream m_LogFile;
};