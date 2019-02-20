#include "Event.h"
#include "Handler.h"
#include <functional>
#include <boost/dll/import.hpp>

template<typename T>
boost::shared_ptr<T> make_shared_ptr(std::shared_ptr<T>& ptr)
{
	return boost::shared_ptr<T>(ptr.get(), [ptr](T*) mutable {ptr.reset(); });
}

template<typename T>
std::shared_ptr<T> make_shared_ptr(boost::shared_ptr<T> &ptr)
{
	return std::shared_ptr<T>(ptr.get(), [ptr](T*) mutable {ptr.reset(); });
}

void								loadModule(char *path)
{
	//Init the Handler and its request / response
	std::shared_ptr<ZiApi::Handler> handler = std::make_shared<ZiApi::Handler>();
	handler->setRequest("POST / HTTP/1.1\r\nHOST: localhost:8000\r\n\r\n-1231565325\r\n");
	handler->setResponse("");

	//Init Boost to load dll or .so
	boost::filesystem::path			lib_path(path);				//Path to the library
	std::shared_ptr<ZiApi::IModule>	plugin;						//Smart ptr that will contain a pointer to our new module


	auto/*boost::shared_ptr<ZiApi::IModule>*/ tmp = boost::dll::import<ZiApi::IModule>(lib_path,		//Path to the library / "name of the dll"
																					"module");			//Name of the symbol to import, see HelloWorldModule.h lign:23
	
	plugin = make_shared_ptr(tmp);					//Convert the temporary pointer 

	//We got our new module now we can add it to the handler list
	handler->registerModule(plugin);			//Register the module in the handler's list of module.

	//Launch all module for the anchorPoint Request
	handler->launchTypeModule(ZiApi::Event::AnchorPoint::REQUEST);

	//We can remove the module from the list of the handler
	handler->removeModule(plugin);			//Remove the module from the handler's list of module)
	return;
}

int main(int argc, char *argv[])
{
	loadModule(argv[1]);
	return (0);
}