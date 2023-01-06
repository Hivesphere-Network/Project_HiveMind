#include <iostream>
#include "HM_Logger.h"


int main()
{
    {
        HM_Logger logger;
        logger.debug("This is a debug message");
    }
    std::cout << "End Point" << std::endl;
}