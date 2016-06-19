//
// Created by robin on 8/8/15.
//

#ifndef PDNS_SLAVE_COMMANDLINEOPTION_H
#define PDNS_SLAVE_COMMANDLINEOPTION_H

# include <string>
# include <vector>

class CommandLineOption
{
public:
    CommandLineOption(const std::string& longName, char shortName, const std::string& description,
                      const std::string& valueName = "", const std::string& defaultValue = "");

    const std::string &getLongName() const;

    void setLongName(const std::string &longName);

    char getShortName() const;

    void setShortName(char shortName);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getValueName() const;

    void setValueName(const std::string &valueName);

    const std::string &getDefaultValue() const;

    void setDefaultValue(const std::string &defaultValue);

    const std::vector<std::string> &getValues() const;

    const std::string &getValue() const;

    void addValue(const std::string &value);

    bool isSet() const;

    void setIsSet(bool isSet);

    bool hasValue() const;

private:
    std::string _longName;

    char _shortName;

    std::string _description;

    std::string _valueName;

    std::string _defaultValue;

    std::vector<std::string> _values;

    bool _isSet;
};


#endif //PDNS_SLAVE_COMMANDLINEOPTION_H
