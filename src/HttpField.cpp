#include "HttpField.h"

void									ZiApi::HttpField::mapStringField(const std::string &field)
{
	std::vector<std::string>			parts;
	std::string							delemiters("\r\n");

	boost::split(parts, field, boost::is_any_of(delemiters));
	for (auto &&it = parts.begin(); it != parts.end(); it++)
	{
		std::vector<std::string>		keyAndValue;
		std::string						key;
		std::string						value;

		boost::split(keyAndValue, (*it), [](char c) { return c == ':'; });


		for (auto &&it = keyAndValue.begin(); it != keyAndValue.end(); it++)
		{
			if (it == keyAndValue.begin())
				key = (*it);
			else
				value += (*it);
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
void								ZiApi::HttpField::setField(const std::string &field)
{
	this->field = field;
	mapStringField(this->field);
}

ZiApi::HttpField::HttpField(const std::string &field)
	: field(field)
{
	mapStringField(field);
}

ZiApi::HttpField::~HttpField()
{
}