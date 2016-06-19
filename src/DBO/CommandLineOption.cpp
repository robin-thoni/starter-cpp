//
// Created by robin on 8/8/15.
//

#include "CommandLineOption.h"

CommandLineOption::CommandLineOption(const std::string &longName, char shortName, const std::string &description,
                                     const std::string &valueName, const std::string &defaultValue)
    : _longName(longName)
    , _shortName(shortName)
    , _description(description)
    , _valueName(valueName)
    , _defaultValue(defaultValue)
    , _isSet(false)
{
}

const std::string &CommandLineOption::getLongName() const
{
    return _longName;
}

void CommandLineOption::setLongName(const std::string &longName)
{
    _longName = longName;
}

char CommandLineOption::getShortName() const
{
    return _shortName;
}

void CommandLineOption::setShortName(char shortName)
{
    _shortName = shortName;
}

const std::string &CommandLineOption::getDescription() const
{
    return _description;
}

void CommandLineOption::setDescription(const std::string &description)
{
    _description = description;
}

const std::string &CommandLineOption::getValueName() const
{
    return _valueName;
}

void CommandLineOption::setValueName(const std::string &valueName)
{
    _valueName = valueName;
}

const std::string &CommandLineOption::getDefaultValue() const
{
    return _defaultValue;
}

void CommandLineOption::setDefaultValue(const std::string &defaultValue)
{
    _defaultValue = defaultValue;
}

const std::vector<std::string> &CommandLineOption::getValues() const
{
    return _values;
}

void CommandLineOption::addValue(const std::string &value)
{
    _values.push_back(value);
}

bool CommandLineOption::isSet() const
{
    return _isSet;
}

void CommandLineOption::setIsSet(bool isSet)
{
    _isSet = isSet;
}

bool CommandLineOption::hasValue() const
{
    return !_valueName.empty();
}

const std::string &CommandLineOption::getValue() const
{
    if (_values.empty())
        return _defaultValue;
    return _values[_values.size() - 1];
}
