#include "notimplementedexception.h"

NotImplementedException::NotImplementedException()
    :
    std::runtime_error("The author was to lazy to implement this function yet...")
{
}
