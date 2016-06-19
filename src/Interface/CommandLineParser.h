//
// Created by robin on 8/8/15.
//

#ifndef PDNS_SLAVE_COMMANDLINEPARSER_H
#define PDNS_SLAVE_COMMANDLINEPARSER_H

# include "DBO/CommandLineOption.h"

class CommandLineParser
{
public:
    CommandLineParser(int argc, char** argv);

    bool parse();

    int showHelp(int status = 0, bool stdErr = true);

    void addOption(CommandLineOption* opt);

private:
    int _argc;

    char** _argv;

    std::vector<CommandLineOption*> _options;
};


#endif //PDNS_SLAVE_COMMANDLINEPARSER_H
