#ifndef PALCHECK_H
#define PALCHECK_H
#include <string>

class palCheck
{
private:
    std::string a;
public:
    palCheck(std::string& aa);
    void operator()(std::string& aa);

};

#endif // PALCHECK_H
