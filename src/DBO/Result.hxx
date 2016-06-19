//
// Created by robin on 8/9/15.
//

#include "Result.h"
#include <errno.h>
#include <string.h>

template<class T>
Result<T>::Result()
{
}

template<class T>
const Result<T> Result<T>::ok(const T& data)
{
    Result<T> r;
    r._success = true;
    r._data = data;
    return r;
}

template<class T>
const Result<T> Result<T>::strerror()
{
    Result<T> r;
    r._success = false;
    r._error = ::strerror(errno);
    return r;
}

template<class T>
const Result<T> Result<T>::error(const std::string& error)
{
    Result<T> r;
    r._success = false;
    r._error = error;
    return r;
}

template<class T>
template<class U>
const Result<T> Result<T>::error(const Result<U>& other)
{
    Result<T> r;
    r._success = false;
    r.error(other.getError());
    return r;
}

template<class T>
T &Result<T>::getData()
{
    return _data;
}

template<class T>
const bool Result<T>::isSuccess() const
{
    return _success;
}

template<class T>
bool Result<T>::operator!() const
{
    return !isSuccess();
}

template<class T>
Result<T>::operator bool() const
{
    return isSuccess();
}

template<class T>
const std::string &Result<T>::getError() const
{
    return _error;
}

template<class U>
std::ostream& operator<<(std::ostream& os, const Result<U>& res)
{
    if (res._success) {
        os << "Success";// << res._data;
    }
    else {
        os << "Error: " << (res._error.empty() ? "Unknown error" : res._error);
    }
    return os;
}

template<class T>
const Result<T>& Result<T>::print() const
{
    (_success ? std::cout : std::cerr) << *this << std::endl;
    return *this;
}