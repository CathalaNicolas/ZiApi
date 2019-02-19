#include "Event.h"
#include "Handler.h"
#include <functional>
#include "HelloWorldModule.h"

int main()
{
	//Init the Handler and its request / response
	std::shared_ptr<ZiApi::Handler> handler = std::make_shared<ZiApi::Handler>();
	handler->setRequest("POST / HTTP/1.1\r\nHOST: localhost:8000\r\n\r\n-1231565325\r\n");
	handler->setResponse("");

	// /!\ Test example the module most be loaded from dll/.so at run-time.
	//Creation of the example module
	std::shared_ptr<HelloWorldModule> module = std::make_shared<HelloWorldModule>("HelloWorldModule", "Say Hello", "0.1");

	//Register the module in the handler list of modules
	handler->registerModule(module);

	//Launch all module for the anchorPoint Request
	handler->launchTypeModule(ZiApi::Event::AnchorPoint::REQUEST);
	return (0);
}