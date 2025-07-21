/* Multi-line *comment *** example:
*/
// Find fibonacci by co-recursion
integer f_odd(integer);
integer f_even(integer);

integer fibonacci(integer n) 
begin
    return (n % 2 == 0) ? f_even(n) : f_odd(n);
end

integer f_odd(integer n) 
begin
    if (n == 1) return 1;
    if (n < 1) return 0; // Handling negative numbers or invalid cases
    return f_even(n - 1) + f_odd(n - 2);
end

integer f_even(integer n) 
begin
    if (n == 0) return 0;
    if (n < 0) return 0; // Handling negative numbers or invalid cases
    return f_odd(n - 1) + f_even(n - 2);
end

integer main() 
begin
    const integer n = 10; // Testing keyword 'const'
    integer r;
    r = fibonacci(n);
    printStr("fibo(");
    printInt(n);
    printStr(") = ");
    printInt(r);
    printStr("\n");

    // Additional test cases
    integer m = 5; // Testing keyword 'integer' and integer const
    r = fibonacci(m);
    printStr("fibo(");
    printInt(m);
    printStr(") = ");
    printInt(r);
    printStr("\n");


    // Floating point test
    float f = 3.14;
    float f2 = 33e5;
    printStr("Floating point test: ");
    printFloat(f);
    printStr("\n");

    // Character constant test
    char c = 'ABC';
    printStr("Character constant test: ");
    printChar(c);
    printStr("\n");

    bool flag = true; // Testing keyword 'bool'
    if (flag) 
    begin
        printStr("Boolean test: true\n");
    end

    return 0;
end
