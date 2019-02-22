#include "HttpField.h"
#include <iostream>

ZiApi::HttpField::HttpField(const std::string &field)
	: field(field)
{
	mapStringField(field);
}

ZiApi::HttpField::~HttpField()
{
}

void									ZiApi::HttpField::mapMethodValue(const std::string &value)
{
	std::vector<std::string>			parts;

	boost::split(parts, value, [](char c) {return c == ' '; });
	if (parts.size() < 2)
		return;
	mapField.insert(std::pair<std::string, std::string>(std::string("REQUEST_METHOD"), parts[0]));
	mapField.insert(std::pair<std::string, std::string>(std::string("REQUEST_RESSOURCE"), parts[1]));
	mapField.insert(std::pair<std::string, std::string>(std::string("REQUEST_HTTP_VERSION"), parts[2]));
}

void									ZiApi::HttpField::mapStringField(const std::string &field)
{
	std::vector<std::string>			parts;
	std::string							delemiters("\r\n");

	boost::split(parts, field, boost::is_any_of(delemiters));
	if (parts.size() > 0 && parts[0] != "")
	{
		mapMethodValue(parts[0]);
		for (auto &&it = parts.begin() + 1; it != parts.end(); it++)
		{
			std::vector<std::string>		keyAndValue;
			std::string						key;
			std::string						value;

			boost::split(keyAndValue, (*it), [](char c) { return c == ':'; });
			for (auto &&it = keyAndValue.begin(); it != keyAndValue.end(); it++)
			{
				if (it == keyAndValue.begin()) {
					key = (*it);
				}
				else {
					value += (*it);
				}
			}
			mapField.insert(std::pair<std::string, std::string>(key, value));
		}
	}
}

std::map<std::string, std::string>		ZiApi::HttpField::getField()const
{
	return (mapField);
}

std::string								ZiApi::HttpField::getValueFromMapField(const std::string &key)const
{
	return (mapField.at(key));
}

void									ZiApi::HttpField::setField(const std::string &field)
{
	this->field = std::string(field);
	mapStringField(this->field);
}