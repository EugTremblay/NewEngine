#pragma once
#include "ILogger.h"
#include <iostream>

using namespace std;

class SDLlogger final : public ILogger {
public:
	SDLlogger();
	virtual ~SDLlogger() = default;
	virtual void Log(const std::string& message) override;
	virtual void Quit() override;

private:
	void* m_Hconsole;

};