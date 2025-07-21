---------------------------------------------------------------------------------------------------------------------------------
File size is limited so not uploading all file need to first make then only run the code
---------------------------------------------------------------------------------------------------------------------------------

To run the code run this command after going to corresponding directry
1 $make clean (if want to clear earlier created file)
2 $make (to run the code)
3 $ ./compiler < a9_220101002_test.mc > a9_220101002_quad.out

---------------------------------------------------------------------------------------------------------------------------------
Explanation of the changed grammer rule I have augmented grammer for these things according to the assignment(A7 and A9)
----------------------------------------------------------------------------------------------------------------------------------
1. M and N :

M : To create a marker for the current instruction position miainly used for backpatching (conditionals and loop iteration)
N : For creating a goto instruction and returns its location for future backpatching (typically used in control flow)

2. Also included floating point const and bitwise operation (from A7 and A9 instructions)

3. Also at places where we have rules like
    S -> (E)
    E -> T|epsilon
    For that kind of rule at all places I am using 2 rule one directly like its parent
    S->(T)|()

4. In unary_expression have included for the operations like ++,--,~ similar to earlier uniary operator

5. Shift Expressions (left and right) : int<<int i.e only for int 
    For this I have added the rule similarly as we have written rule for additive_expression
    shift_expression : additive_expression
                       shift_expression << additive_expression
                       shift_expression >> additive_expression
    so all the grammer rule after this is based on this

6. Also added for all the XOR OR AND operation similar to logical AND OR XOR for boolean values 
    (as asked in assignment that need to augment rule for boolean val also )
7. In the declarator I have adjusted rule for the declaration like int a,b; type  earlier rule can declare at max of one var at a timee
8. Also added the float type_specifier for floating point num
9. Similar to for loop I have added for while and do while loop rule
10. Also in jump_statement I have added rule for the break and goto a/c to assignment similarly
    jump_statement : break;|goto location

11. Added rule so that multiple function defination can happen other then just main fun. For this added recursive rule 
    translation_unit: external_declaration | translation_unit external_declaration 
12. Also added for the case that we can declare fun before main and call it later for that add another rule for fun 
    function_definition : function_prototype compound_statement
13. And fun protype is same as its return type

For all these modifiction rule are added at corresponding position in yacc file