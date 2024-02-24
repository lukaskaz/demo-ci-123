#include "Formula-mock.h"
#include "Formula.h"
#include "gtest/gtest.h"

class TestFormula : public testing::Test
{
public:
    std::shared_ptr<FormulaMock> formulaPtr_ =
        std::make_shared<testing::NiceMock<FormulaMock>>();

    std::shared_ptr<FormulaFactoryMock> factoryPtr_ =
        std::make_shared<testing::NiceMock<FormulaFactoryMock>>();
};

TEST_F(TestFormula, testBla)
{
    //arrange
    //act
    //assert
    EXPECT_EQ(Formula::bla(0), 0);
    EXPECT_EQ(Formula::bla(10), 20);
    EXPECT_EQ(Formula::bla(50), 100);
}

TEST_F(TestFormula, testUpdate)
{
    int initValue = 2123;
    int newValue = 768;

    ON_CALL(*factoryPtr_, create(initValue))
        .WillByDefault(testing::Return(formulaPtr_));
    EXPECT_CALL(*formulaPtr_, update(newValue)).Times(1);
    Control control(factoryPtr_, initValue);
    control.write(newValue);

    ON_CALL(*formulaPtr_, getLimit()).WillByDefault(testing::Return(newValue));
    EXPECT_CALL(*formulaPtr_, getLimit()).Times(1);
    EXPECT_EQ(control.read(), newValue);
}

