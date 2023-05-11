# Scientific Calculator


## How it works:

This program takes an infix expression and converts it into postfix notation, and then evaluates the postfix expression. It uses two stacks: one to store operators during the conversion to postfix, and another to evaluate the postfix expression.

To convert an infix expression to postfix, the program iterates through the input expression and pushes each number onto the output stack. When it encounters an operator or a parenthesis, the program uses the stack to keep track of the order of operations to output the postfix expression.

Once the program has the postfix expression, it evaluates it by iterating through the expression and pushing operands onto the stack, and when it encounters an operator, it pops the two most recent operands, performs the operation, and pushes the result back onto the stack.
