#include "HelloWorldModule.h"

HelloWorldModule::HelloWorldModule(const std::string &name, const std::string &description, const std::string &version)
	:	ZiApi::IModule(name, description, version)
{
}

void	HelloWorldModule::registerEvents(ZiApi::Handler &handler)
{
	std::string name("toto");
	ZiApi::Event::EventPriority t = ZiApi::Event::EventPriority::FIRST;
	ZiApi::Event::AnchorPoint point = ZiApi::Event::AnchorPoint::REQUEST;
	int nb = 14;

	std::function<void(ZiApi::HttpMessage&, ZiApi::HttpMessage&)> function = std::bind(this->HelloWorld, handler.getRequest(), handler.getResponse());

	ZiApi::Event event(name, function, t, point);

	this->addEvent(event);
	handler.registerModule(this);
}

void	HelloWorldModule::HelloWorld(ZiApi::HttpMessage& request, ZiApi::HttpMessage& response)
{
	std::cout << "Hello" << " header:\n" << request.getHeader().getStringField() << "body: \n" << request.getBody().getStringField() << std::endl;
}
