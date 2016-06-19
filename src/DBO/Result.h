//
// Created by robin on 8/9/15.
//

#ifndef PDNS_SLAVE_RESULT_H
#define PDNS_SLAVE_RESULT_H

# include <string>
# include <vector>

template <class T> class Result
{
public:
    Result();

    Result(const T& data);

    virtual ~Result();

    Result<T>& ok(const T& data);

    T& getData();

    bool isSuccess() const;

    Result<T>& addWarning(const std::string& warning);

    const std::vector<std::string>& getWarnings() const;

    Result<T>& error(const std::string& error);

    const std::string& getError() const;

    bool operator !() const;

    operator bool() const;

    const Result<T>& print() const;

private:
    T _data;

    std::vector<std::string> _warnings;

    std::string _error;
};

typedef Result<bool> BResult;

# include "DBO/Result.hxx"

#endif //PDNS_SLAVE_RESULT_H
