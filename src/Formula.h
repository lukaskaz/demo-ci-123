#ifndef EXAMPLEPROJECT_FORMULA_H
#define EXAMPLEPROJECT_FORMULA_H

#include <memory>

class FormulaIf
{
  public:
    virtual ~FormulaIf(){};
    virtual void update(int) = 0;
    virtual int getLimit() = 0;
};

class Formula : public FormulaIf
{
  public:
    ~Formula(){};
    Formula() = delete;
    Formula(int lim) : limit{lim}
    {}

    static int bla(int arg1);

    void update(int val)
    {
        limit = val;
    }

    int getLimit()
    {
        return limit;
    }

  private:
    int limit;
};

class FormulaFactoryIf
{
  public:
    virtual std::shared_ptr<FormulaIf> create(int) = 0;
};

class FormulaFactory : public FormulaFactoryIf
{
  public:
    virtual std::shared_ptr<FormulaIf> create(int val)
    {
        return std::make_shared<Formula>(val);
    }
};

class Control
{
  public:
    ~Control()
    {}
    Control() = delete;
    Control(std::shared_ptr<FormulaFactoryIf> formulaFactoryPtr, int val)
    {
        if (formulaFactoryPtr)
            formulaPtr = formulaFactoryPtr->create(val);
    }

    void write(int val)
    {
        if (formulaPtr)
            formulaPtr->update(val);
    }

    int read()
    {
        return formulaPtr == nullptr ? -1 : formulaPtr->getLimit();
    }

  private:
    std::shared_ptr<FormulaIf> formulaPtr;
};

#endif // EXAMPLEPROJECT_FORMULA_H

