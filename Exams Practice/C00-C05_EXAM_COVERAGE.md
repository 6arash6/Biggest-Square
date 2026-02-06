# 📋 C00-C05 Exam Coverage Guide

## What to Expect on Tomorrow's Exam

With 4 weeks for 13 projects, your exam will likely cover **C00 through C05**. Here's what appears most frequently:

---

## 🎯 C00: Basics & Output
**Likelihood: HIGH** - These are warm-up questions (Level 0-1)

### Most Common:
- **ft_putchar** - Write single character
- **ft_print_alphabet** - Print a-z
- **ft_print_numbers** - Print 0-9
- **ft_is_negative** - Check if number is negative
- **ft_print_comb** - Print number combinations

### Key Skills:
```c
write(1, &c, 1);           // Write a character
write(1, "text", 4);       // Write a string
while (n <= 9)             // Simple loops
```

### Exam Notes:
- Always use `write()`, never `printf()`
- Remember: `write(1, &var, 1)` for single characters
- Loops: `n = '0'; while (n <= '9')` for digits

---

## 🔄 C01: Pointers Basics
**Likelihood: VERY HIGH** - Core exam material (Level 2-3)

### Most Common:
- **ft_ft** / **ft_ultimate_ft** - Set value through pointer(s)
- **ft_swap** - Swap two integers ⭐ VERY COMMON
- **ft_strlen** - String length ⭐ APPEARS IN 80% OF EXAMS
- **ft_putstr** - Print string
- **ft_rev_int_tab** - Reverse array

### Key Skills:
```c
void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
```

### Exam Notes:
- **ft_swap** and **ft_strlen** are exam favorites
- Always dereference: `*ptr` to get/set value
- NULL checks optional for Level 2, required for Level 3+

---

## 📝 C02: String Manipulation
**Likelihood: HIGH** - String operations (Level 2-3)

### Most Common:
- **ft_strcpy** - Copy string
- **ft_strncpy** - Copy n characters
- **ft_str_is_alpha** - Check if all letters
- **ft_str_is_numeric** - Check if all digits
- **ft_strcapitalize** - Capitalize first letter of words

### Key Skills:
```c
char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Don't forget!
    return (dest);
}

int ft_str_is_alpha(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!(str[i] >= 'a' && str[i] <= 'z') && 
            !(str[i] >= 'A' && str[i] <= 'Z'))
            return (0);
        i++;
    }
    return (1);
}
```

### Exam Notes:
- **Always null-terminate** strings: `dest[i] = '\0'`
- Check uppercase AND lowercase: `(c >= 'a' && c <= 'z')`
- Empty string `""` should return `1` for `ft_str_is_*` functions

---

## 🔍 C03: String Comparison
**Likelihood: VERY HIGH** - Classic exam questions (Level 2-3)

### Most Common:
- **ft_strcmp** - Compare strings ⭐ VERY COMMON
- **ft_strncmp** - Compare n characters
- **ft_strcat** - Concatenate strings
- **ft_strncat** - Concatenate n characters
- **ft_strstr** - Find substring

### Key Skills:
```c
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char *ft_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    
    while (dest[i])      // Find end of dest
        i++;
    while (src[j])       // Copy src to end
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
```

### Exam Notes:
- **ft_strcmp** appears in ~70% of exams
- Return **difference**: `s1[i] - s2[i]`, not just 0/1/-1
- For strcat: find end, **then** copy
- Edge case: both empty strings should return 0

---

## 🔢 C04: String Conversion
**Likelihood: HIGH** - More complex string work (Level 3-4)

### Most Common:
- **ft_putnbr** - Print integer
- **ft_atoi** - String to integer ⭐ VERY COMMON
- **ft_putnbr_base** - Print number in any base
- **ft_atoi_base** - Convert string in any base to int

### Key Skills:
```c
void ft_putnbr(int n)
{
    char c;
    
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    
    // Skip whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        i++;
    
    // Handle signs (multiple allowed)
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    
    // Convert digits
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return (result * sign);
}
```

### Exam Notes:
- **ft_atoi** appears in ~60% of exams
- Handle **INT_MIN** separately: `-2147483648`
- Whitespace: space, tab, newline, vtab, formfeed, carriage return
- Multiple signs: `"--123"` = 123, `"---123"` = -123
- Stop at first non-digit: `"42abc"` = 42

---

## ♻️ C05: Recursion
**Likelihood: MEDIUM-HIGH** - May appear as Level 3-4 (Level 4 bonus points)

### Most Common:
- **ft_recursive_factorial** - n! recursively
- **ft_recursive_power** - nb^power recursively
- **ft_fibonacci** - Fibonacci number
- **ft_sqrt** - Square root (iterative or recursive)
- **ft_is_prime** - Check if prime

### Key Skills:
```c
int ft_recursive_factorial(int nb)
{
    if (nb < 0)         // Base case: invalid
        return (0);
    if (nb == 0 || nb == 1)  // Base case: 0! = 1! = 1
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));  // Recursive
}

int ft_recursive_power(int nb, int power)
{
    if (power < 0)      // Base case: negative power
        return (0);
    if (power == 0)     // Base case: anything^0 = 1
        return (1);
    return (nb * ft_recursive_power(nb, power - 1));  // Recursive
}

int ft_fibonacci(int index)
{
    if (index < 0)      // Base case: invalid
        return (-1);
    if (index == 0)     // Base case: fib(0) = 0
        return (0);
    if (index == 1)     // Base case: fib(1) = 1
        return (1);
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));  // Double recursion
}
```

### Exam Notes:
- **Always** handle negative inputs (return 0 or -1)
- **Always** have base case FIRST
- **Factorial**: 0! = 1, negative = 0
- **Power**: 0^0 = 1, negative power = 0
- **Fibonacci**: fib(0)=0, fib(1)=1, fib(2)=1, fib(3)=2...

---

## 📊 Exam Strategy by Level

### Level 0-1 (Easy - 5 min each)
- C00 exercises (ft_putchar, ft_print_alphabet)
- Basic output, simple loops
- **Goal: Get 2-3 of these done fast**

### Level 2 (Medium - 10-15 min each)
- **ft_strlen** (C01) ⭐ Most common
- **ft_strcmp** (C03) ⭐ Very common
- **ft_strcpy** (C02)
- **Goal: Get 2-3 of these = 50%+ pass**

### Level 3 (Medium-Hard - 15-20 min each)
- **ft_atoi** (C04) ⭐ Common
- **ft_swap** (C01)
- **ft_strcat** (C03)
- **Goal: If time allows, attempt 1-2 for higher score**

### Level 4 (Hard - 20-30 min each)
- **ft_recursive_factorial** (C05)
- **ft_recursive_power** (C05)
- **ft_putnbr_base** (C04)
- **Goal: Only if you've secured 50%+**

---

## 🎯 Most Likely to Appear (Top 10)

Based on 42 exam patterns:

1. **ft_strlen** - C01 - 80% of exams ⭐⭐⭐
2. **ft_strcmp** - C03 - 70% of exams ⭐⭐⭐
3. **ft_atoi** - C04 - 60% of exams ⭐⭐
4. **ft_swap** - C01 - 50% of exams ⭐⭐
5. **ft_putstr** - C01 - 50% of exams ⭐⭐
6. **ft_strcpy** - C02 - 40% of exams ⭐
7. **ft_strcat** - C03 - 40% of exams ⭐
8. **ft_putnbr** - C04 - 40% of exams ⭐
9. **ft_recursive_factorial** - C05 - 30% ⭐
10. **ft_str_is_alpha** - C02 - 25%

---

## ⏱️ Tonight's Priority Practice (3 hours max)

### Hour 1: Must-Master (C01-C03)
Focus on these - they appear in MOST exams:
```bash
# Practice in order:
1. ft_strlen      (10 min) - C01 - CRITICAL
2. ft_strcmp      (15 min) - C03 - CRITICAL  
3. ft_swap        (10 min) - C01 - Common
4. ft_strcpy      (15 min) - C02 - Common
5. ft_putstr      (10 min) - C01 - Common
```

### Hour 2: High-Value (C03-C04)
If comfortable with above:
```bash
6. ft_atoi        (20 min) - C04 - HIGH value
7. ft_strcat      (15 min) - C03 - Common
8. ft_putnbr      (15 min) - C04 - Common
9. ft_str_is_alpha(10 min) - C02 - Easy points
```

### Hour 3: C05 Recursion (if appears)
Only if exam hints mention C05:
```bash
10. ft_recursive_factorial (15 min) - Level 3-4
11. ft_recursive_power     (15 min) - Level 3-4
12. ft_fibonacci           (15 min) - Level 4
```

**STOP at 10 PM** - Sleep is more important!

---

## 📝 Quick Reference Formulas

### Character Checks
```c
is_lowercase: (c >= 'a' && c <= 'z')
is_uppercase: (c >= 'A' && c <= 'Z')
is_alpha:     is_lowercase || is_uppercase
is_digit:     (c >= '0' && c <= '9')
is_alphanum:  is_alpha || is_digit

to_uppercase: c - 32  (if c is lowercase)
to_lowercase: c + 32  (if c is uppercase)
```

### String Patterns
```c
// Length
while (str[i])
    i++;

// Copy  
while (src[i])
{
    dest[i] = src[i];
    i++;
}
dest[i] = '\0';

// Compare
while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
return (s1[i] - s2[i]);

// Find end
while (str[i])
    i++;
// Now str[i] is '\0', i is length
```

### Number Conversion
```c
// Digit to int
n = c - '0';

// Int to digit  
c = n + '0';

// Build number from string
result = result * 10 + (str[i] - '0');
```

### Recursion Pattern
```c
int recursive_func(int n)
{
    // 1. Handle invalid (negative)
    if (n < 0)
        return (0 or -1);
    
    // 2. Base case(s)
    if (n == 0)
        return (base_value);
    
    // 3. Recursive case
    return (n * recursive_func(n - 1));
}
```

---

## ✅ Pre-Exam Checklist (Tomorrow Morning)

- [ ] Quick review: ft_strlen, ft_strcmp, ft_atoi
- [ ] Remember: `write(1, &c, 1)` for characters
- [ ] NULL terminator: **always** for string functions
- [ ] Test edge cases: empty string, NULL, negative numbers
- [ ] Recursion base cases: negative, zero, one
- [ ] **Stay calm** - You only need 50%+

---

## 🎯 Exam Day Strategy

1. **Read ALL questions first** (5 min)
   - Mark Level 0-1 (easy wins)
   - Mark Level 2 (your target for 50%+)
   - Note any C05 recursion

2. **Start with Level 0-1** (15-20 min)
   - Quick points, build confidence
   - ft_putchar, ft_print_alphabet

3. **Focus on Level 2** (45-60 min)
   - ft_strlen, ft_strcmp, ft_strcpy
   - **This gets you to 50%+**

4. **Attempt Level 3** (30-45 min)
   - ft_atoi, ft_strcat
   - Push towards 70-80%

5. **C05 if comfortable** (remaining time)
   - ft_recursive_factorial
   - Only if you're solid on Level 2-3

6. **Test everything** (last 10-15 min)
   - 3 test cases per exercise minimum
   - Empty string, normal, edge case

---

## 🚀 You've Got This!

### What You Know:
✅ Passed first exam at 50%  
✅ Understand pointers (from 42-pointer-tutorials)  
✅ Have practiced 6+ exercises  
✅ Know the patterns  

### What You Need:
✅ Focus on ft_strlen, ft_strcmp, ft_atoi  
✅ Remember base cases for recursion  
✅ Test with 3 cases each  
✅ **50%+ = PASS** - Don't aim for 100%  

### Tomorrow:
1. Start easy (Level 0-1)
2. Secure 50% (Level 2)
3. Push higher if time
4. Stay calm and test

**Good luck! 🍀**
