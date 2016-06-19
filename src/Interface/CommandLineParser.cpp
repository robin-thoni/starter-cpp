//
// Created by robin on 8/8/15.
//

#include <getopt.h>
#include <iostream>
#include "CommandLineParser.h"

CommandLineParser::CommandLineParser(int argc, char **argv)
    : _argc(argc)
    , _argv(argv)
{
}

bool CommandLineParser::parse()
{
    std::string shortOpts;
    option opts[_options.size() + 1];
    for (unsigned i = 0; i < _options.size(); ++i)
    {
        auto opt = _options[i];
        shortOpts += opt->getShortName();
        if (opt->hasValue())
            shortOpts += ":";
        opts[i].name = opt->getLongName().c_str();
        opts[i].has_arg = opt->hasValue();
        opts[i].flag = 0;
        opts[i].val = opt->getShortName();
    }
    opts[_options.size()] = {0, 0, 0, 0};
    int option;
    extern int optind;
    extern char* optarg;
    bool valid = true;
    while ((option = getopt_long(_argc, _argv, shortOpts.c_str(), opts, 0)) != -1)
    {
        bool optValid = false;
        for (unsigned i = 0; i < _options.size(); ++i)
        {
            auto opt = _options[i];
            if (opt->getShortName() == option)
            {
                optValid = true;
                opt->setIsSet(true);
                if (opt->hasValue())
                    opt->addValue(optarg);
            }
        }
        if (!optValid)
            valid = false;
    }
    return optind == _argc && valid;
}

void CommandLineParser::addOption(CommandLineOption* opt)
{
    _options.push_back(opt);
}

int CommandLineParser::showHelp(int status, bool stdErr)
{
    auto& out = stdErr ? std::cerr : std::cout;
    out << "Options:" << std::endl;
    for (auto opt : _options)
    {
        out << "  -" << opt->getShortName() << ", --" << opt->getLongName();
        if (opt->hasValue())
        {
            out << " <" << opt->getValueName() << "=" << opt->getDefaultValue() << ">";
        }
        out << " " << opt->getDescription() << std::endl;
    }
    return status;
}
