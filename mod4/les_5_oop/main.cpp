#include <iostream>

#include <iostream>
#include <string>

using namespace std;

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const *number) = 0;

    virtual void visitBinaryOperation(BinaryOperation const *binary) = 0;

    virtual ~Visitor() {}
};

struct Expression {
    virtual double evaluate() const = 0;

    virtual void visit(Visitor *v) const = 0;

    virtual ~Expression() {};
};

struct Number : Expression {
    Number(double value)
            : value(value) {}

    ~Number() {
        delete &value;
    }

    double evaluate() const {
        return value;
    }

    double get_value() const {
        return value;
    };

    void visit(Visitor *v) const {
        v->visitNumber(this);
    };

private:
    double value;
};

struct BinaryOperation : Expression {
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
            : left(left), op(op), right(right) {}

    ~BinaryOperation() {
        delete &left;
        delete &right;
        delete &op;
    }

    double evaluate() const {

        double result = 0;

        switch (op) {
            case '+':
                result = left->evaluate() + right->evaluate();
                break;
            case '-':
                result = left->evaluate() - right->evaluate();
                break;
            case '*':
                result = left->evaluate() * right->evaluate();
                break;
            default:
                result = left->evaluate() / right->evaluate();
                break;
        }

        return result;
    }

    void visit(Visitor *v) const {
        v->visitBinaryOperation(this);
    };

    Expression const *get_left() const { return left; }

    Expression const *get_right() const { return right; }

    char get_op() const { return op; }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

struct PrintBinaryOperationVisitor : Visitor {
    virtual void visitNumber(Number const *number) {};

    virtual void visitBinaryOperation(BinaryOperation const *binary) {
        binary->get_left()->visit(this);
        cout << binary->get_op() << endl;
        binary->get_right()->visit(this);
    };
};

struct PrintVisitor : Visitor {
    void visitNumber(Number const *number) {
        cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const *bop) {
        cout << "(";
        bop->get_left()->visit(this);
        cout << bop->get_op();
        bop->get_right()->visit(this);
        cout << ")";
    }
};

int main() {

    // (1 + 4) * (2 + 3)

    Expression * onePlusFour = new BinaryOperation(new Number(1), '+', new Number(4));
    Expression * twoPlusThree = new BinaryOperation(new Number(2), '+', new Number(3));
    Expression * firstMulSecond = new BinaryOperation(onePlusFour, '*', twoPlusThree);

    Expression *sube = new BinaryOperation(new Number(12), '+', new Number(5));
    Expression *sube1 = new BinaryOperation(sube, '*', new Number(5));

//    cout << sube->evaluate() << endl;

    PrintBinaryOperationVisitor bov;
    sube1->visit(&bov);

    PrintVisitor pov;
    firstMulSecond->visit(&pov);

    return 0;
}