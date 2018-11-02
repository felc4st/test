#include <iostream>
#include <string>




int main()
{
    std::string a;
    std::string b;

    std::cin >> a;
    std::cout<<std::endl<<a;
     std::cout<<std::endl<<a.size();

    std::copy(a.crbegin(), a.crend(), std::back_inserter(b));

    std::cout<<std::endl<<b;
     std::cout<<std::endl<<b.size();
    std::cout<<std::endl;

    if(a==b)
    {
        std::cout<<"palindrom"<<std::endl;
    }
    else
    {
         std::cout<<"not a palindrom"<<std::endl;
    }

    system("pause");
    return 0;
}
