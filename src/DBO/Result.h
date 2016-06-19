//
// Created by robin on 8/9/15.
//

#ifndef RESULT_H
#define RESULT_H

# include <string>
# include <vector>
# include <iostream>

template <class T> class Result
{
public:
    static const Result<T> ok(const T& data);
    static const Result<T> strerror();
    static const Result<T> error(const std::string& error);
    template <class U> static const Result<T> error(const Result<U>& other);

    T& getData();
    const bool isSuccess() const;
    const std::string& getError() const;

    bool operator !() const;
    operator bool() const;

    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Result<U>& res);

    const Result<T>& print() const;

private:
    Result();

    T _data;

    std::string _error;

    bool _success;
};

typedef Result<bool> ResultBool;

typedef Result<int> ResultInt;

typedef Result<long> ResultLong;

typedef Result<float> ResultFloat;

typedef Result<double> ResultDouble;

typedef Result<char> ResultChar;

typedef Result<std::string> ResultString;

# include "DBO/Result.hxx"

#endif //RESULT_H