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

	static void	HelloWorld(std::shared_ptr<ZiApi::HttpMessage>&, std::shared_ptr<ZiApi::HttpMessage>&);
private:
};
