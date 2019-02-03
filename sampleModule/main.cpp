#include "Event.h"
#include "Handler.h"
#include <functional>
#include "HelloWorldModule.h"

int main()
{
	ZiApi::Handler handler;

	/*Todo by User*/
	HelloWorldModule *module = new HelloWorldModule("HelloWorldModule", "Say Hello", "0.1");
	handler.setRequest("POST / HTTP/1.1\r\nHOST: localhost:8000\r\n\n-1231565325");
	module->registerEvents(handler);
	/*------------*/

	handler.launchTypeModule(ZiApi::Event::AnchorPoint::REQUEST);

	delete module;
	return (0);
}