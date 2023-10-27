# BigNumber
BigNumber is a class which simulates a number that exceeds C++'s capabilities to store integers. It is capable of handling the same operations as regular ints / long longs, such as arithmetical or logical operations, but some operations, such as multiplication or division, might be slow due to the poor implementation but also due to the large size of the numbers.
## Supported operations
- Initialization (from a small number, from string, from another big number)
- Assignment (from a small number, from a big number)
- Comparison (==, !=, <, >, <=, >=)
- Arithmetic operations (+, -, *, /, %)
- Arithmetic assignment (+=, -=, *=, /=, %=)
- Increment / decrement (++, --, both prefix and postfix)
- Stream extraction & insertion (istream>>, ostream<<)
- Destructor
