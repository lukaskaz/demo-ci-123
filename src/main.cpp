#include "Formula.h"
#include <iostream>

int main()
{
    std::cout << "Bla: " << Formula::bla(2) << std::endl;

    std::shared_ptr<FormulaFactory> factoryPtr =
        std::make_shared<FormulaFactory>();

    Control control(factoryPtr, 1012);

    std::cout << "Limit: " << control.read() << std::endl;

    return 0;
}

