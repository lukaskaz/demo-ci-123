#include "Formula.h"
#include "gmock/gmock.h"

class FormulaMock : public FormulaIf
{
public:
    MOCK_METHOD(void, update, (int), (override));
    MOCK_METHOD(int, getLimit, (), (override));
};

class FormulaFactoryMock : public FormulaFactoryIf
{
public:
    MOCK_METHOD(std::shared_ptr<FormulaIf>, create, (int), (override));
};

