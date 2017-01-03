#include "ast.hpp"

namespace godel {

	Expression::Expression()
	{
		this->gc_tag = 0;
	}
	
	Variable::Variable(std::string name, Expression* value): Expression()
	{
		this->name = name;
		this->value = value;
	}

	Number::Number(): Expression() { }

	Integer::Integer(long long int value): Number()
	{
		this->value = value;
	}

	Operator::Operator(): Expression() { }

	UnaryOperator::UnaryOperator(Expression* expr): Operator()
	{
		this->expr = expr;
	}

	BinaryOperator::BinaryOperator(Expression* lexpr, Expression* rexpr): Operator()
	{
		this->lexpr = lexpr;
		this->rexpr = rexpr;
	}
}
