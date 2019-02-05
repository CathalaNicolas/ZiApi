#include "HelloWorldModule.h"

HelloWorldModule::HelloWorldModule(const std::string &name, const std::string &description, const std::string &version)
	:	ZiApi::IModule(name, description, version)
{
	std::string _name("toto");
	ZiApi::Event::EventPriority t = ZiApi::Event::EventPriority::FIRST;
	ZiApi::Event::AnchorPoint point = ZiApi::Event::AnchorPoint::REQUEST;

	ZiApi::EventFunction function = std::bind(this->HelloWorld, std::placeholders::_1, std::placeholders::_2);

	ZiApi::Event event(_name, function, t, point);

	this->addEvent(event);
}

void	HelloWorldModule::HelloWorld(ZiApi::HttpMessage* request, ZiApi::HttpMessage* response)
{
	std::string test("THIS IS THE NEW REQUEST !");
	std::cout << "Hello" << " header:\n" << request->getHeader().getStringField() << "body: \n" << request->getBody().getStringField() << std::endl;
	request->getHeader().setField(test);
	std::cout << "REquest !! : " << request->getHeader().getStringField() << std::endl;
}