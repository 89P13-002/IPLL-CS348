// Global declaration with init
float pi = 3.14;
void print();
// Function with parameters and body
integer sum(integer a, integer b)
begin
    integer result;
    result = a + b;
    return result;
end

// Function with pointer, array, call, if, for, return
void main()
begin
    integer x = 0;
    integer y = 5;
    integer z;
    integer *ptr;
    char name[10];

    ptr = &x;
    name[3] = 'A';

    z = sum(x, y);

    if (z > 5 && name[3] == 'A')
    begin
    float b;
    continue;
        print("Z is large\n");
    end
    else
        print("Z is small\n");

    for (x = 0; x < 5; x = x + 1)
    begin
        y = y + x;
        break;
        end

    obj->value = 10;   // Postfix pointer access

    return;
end

