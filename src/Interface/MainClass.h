//
// Created by robin on 8/8/15.
//

#ifndef PDNS_SLAVE_MAINCLASS_H
#define PDNS_SLAVE_MAINCLASS_H


class MainClass {
public:
    MainClass(int argc, char* argv[]);

    int main();

private:
    int _argc;

    char** _argv;

};


#endif //PDNS_SLAVE_MAINCLASS_H
