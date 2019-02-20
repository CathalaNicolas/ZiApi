#ifndef HELLO_MODULE
# define HELLO_MODULE

#include "IModule.h"
#include "Event.h"
#include "Handler.h"
#include "HttpMessage.h"
#include <boost/config.hpp>

namespace MyModule
{
	class HelloWorldModule : public ZiApi::IModule
	{
	public:
		HelloWorldModule() {};
		HelloWorldModule(const std::string &name, const std::string &description, const std::string &version);
		~HelloWorldModule() {};

		static void	HelloWorld(std::shared_ptr<ZiApi::HttpMessage>&, std::shared_ptr<ZiApi::HttpMessage>&);
	private:
	};

	extern "C" BOOST_SYMBOL_EXPORT MyModule::HelloWorldModule module;
	MyModule::HelloWorldModule module("HelloWorldModule", "Say Hello", "0.01");
}
#endif