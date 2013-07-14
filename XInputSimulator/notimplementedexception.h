#ifndef NOTIMPLEMENTEDEXCEPTION_H
#define NOTIMPLEMENTEDEXCEPTION_H

#include <stdexcept>

class NotImplementedException : public std::runtime_error
{
public:
    NotImplementedException();
};

#endif // NOTIMPLEMENTEDEXCEPTION_H
