#pragma once

#include "IModule.h"
#include "Event.h"
#include "Handler.h"
#include "HttpMessage.h"

class HelloWorldModule : public ZiApi::IModule
{
public:
	HelloWorldModule(const std::string &name, const std::string &description, const std::string &version);
	~HelloWorldModule() {};

	static void	HelloWorld(ZiApi::HttpMessage*, ZiApi::HttpMessage*);
private:
};
