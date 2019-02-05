#include "Event.h"
#include "Handler.h"
#include <functional>
#include "HelloWorldModule.h"

int main()
{
	ZiApi::Handler* handler = new ZiApi::Handler();

	/*Todo by User*/
	HelloWorldModule *module = new HelloWorldModule("HelloWorldModule", "Say Hello", "0.1");
	handler->setRequest("POST / HTTP/1.1\r\nHOST: localhost:8000\r\n\n-1231565325");
	std::cout << "Test :" << handler->getRequest()->getHeader().getStringField() << std::endl;
	handler->registerModule(module);
	/*------------*/

	handler->launchTypeModule(ZiApi::Event::AnchorPoint::REQUEST);
	std::cout << "Test :" << handler->getRequest()->getHeader().getStringField() << std::endl;
	delete module;
	delete handler;
	return (0);
}