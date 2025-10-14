#pragma once
#include <string>
#include <format>

#define F(str,...) std::format(str,__VA_ARGS__)
class ILogger {
public:
	virtual ~ILogger() = default;
	/// <summary>
	/// Shows a log in the console
	/// </summary>
	/// <param name="message"></param>
	virtual void Log(const std::string& message) = 0;
	/// <summary>
	/// Exits console
	/// </summary>
	virtual void Quit() = 0;
private:

};