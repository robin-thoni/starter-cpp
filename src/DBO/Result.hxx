//
// Created by robin on 8/9/15.
//

#include <iostream>
#include "Result.h"

template<class T>
Result<T>::Result()
{
}

template<class T>
Result<T>::Result(const T &data)
        : _data(data)
{
}

template<class T>
Result<T>::~Result()
{
}

template<class T>
Result<T> &Result<T>::ok(const T &data)
{
    _data = data;
    return *this;
}

template<class T>
T &Result<T>::getData()
{
    return _data;
}

template<class T>
bool Result<T>::isSuccess() const
{
    return _error.empty();
}

template<class T>
const std::vector<std::string>& Result<T>::getWarnings() const
{
    return _warnings;
}

template<class T>
Result<T>& Result<T>::addWarning(const std::string &warning)
{
    _warnings.push_back(warning);
    return *this;
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
Result<T> &Result<T>::error(const std::string &error)
{
    _error = error;
    return *this;
}

template<class T>
const std::string &Result<T>::getError() const
{
    return _error;
}

template<class T>
const Result<T>& Result<T>::print() const
{
    for (auto warning : _warnings)
        std::cerr << "WARNING: " << warning << std::endl;
    if (!isSuccess())
        std::cerr << "ERROR: " << _error << std::endl;
    return *this;
}
