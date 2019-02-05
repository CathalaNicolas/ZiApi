#include "HttpMessage.h"

ZiApi::HttpMessage::HttpMessage(const ZiApi::HttpField &header, const ZiApi::HttpField &body)
	: header(header), body(body)
{
}

ZiApi::HttpMessage::HttpMessage(const std::string &header, const std::string &body)
{
	setHeader(header);
	setBody(body);
}

ZiApi::HttpMessage::HttpMessage(const std::string &message)
{
	std::vector<std::string> result;
	std::string header;
	std::string body;

	boost::split(result, message, [](const char c) {return c == '\r'; });

	auto &&it = result.begin();
	for (; it != result.end() && (*it) != "\n"; it++)
		header += (*it);
	for (; it != result.end(); it++)
		body += (*it);

	this->header.setField(header);
	this->body.setField(body);
}

ZiApi::HttpMessage::~HttpMessage()
{

}

ZiApi::HttpField		ZiApi::HttpMessage::getHeader()const
{
	return (header);
}

ZiApi::HttpField			ZiApi::HttpMessage::getBody()const
{
	return (body);
}

void		ZiApi::HttpMessage::setHeader(const std::string &header)
{
	this->header.setField(header);
}

void		ZiApi::HttpMessage::setBody(const std::string &body)
{
	this->body.setField(body);
}