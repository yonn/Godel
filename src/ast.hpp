#ifndef GODEL_AST_HPP
#define GODEL_AST_HPP

#include <string>

#include "error.hpp"

namespace godel {

	/**
	 * A polymorphic class to represent an mathematical expression that can return a value
	 */
	class Expression {
	public:
		/**
		 * Construct an expression
		 */
		Expression();
		
		size_t gc_tag;
	};

	class Variable: public Expression {
	public:
		/**
		 * Construct a Variable that by the name of `name`, and which holds an expression
		 */
		Variable(std::string name, Expression* value);

		/**
		 * The variable's name
		 */
		std::string name;
		/**
		 * The variable's value
		 */
		Expression* value;
	};

	/**
	 * A polymorphic class that represents an actual number, whether it be an integer, rational, complex...
	 */
	class Number: public Expression {
	public:
		Number();
	};

	/**
	 * A class to hold a signed integer number
	 */
	class Integer: public Number {
	public:
		/**
		 * Construct an Integer with an initial value
		 */
		Integer(long long int value);

		/**
		 * Value that the Integer holds
		 */
		long long int value;
	};

	/**
	 * Polymorphic class representing an operation, unary or binary
	 */
	class Operator: public Expression {
	public:
		Operator();
	};

	/**
	 * Polymorphic class representing a operator with one argument
	 */
	class UnaryOperator: public Operator {
	public:
		/**
		 * Constructs a unary operator with one expression
		 */
		UnaryOperator(Expression* expr);

		/**
		 * Expression that the operator acts upon
		 */
		Expression* expr;
	};

	/**
	 * Polymorphic class representing a operator with one argument
	 */
	class BinaryOperator: public Operator {
	public:
		/**
		 * Constructs a unary operator with one expression
		 */
		BinaryOperator(Expression* lexpr, Expression* rexpr);
		
		/**
		 * Left side of the expression that the operator acts upon
		 */
		Expression* lexpr;
		/**
		 * Right side of the expression that the operator acts upon
		 */
		Expression* rexpr;
	};

}

#endif /*GODEL_AST_HPP*/
