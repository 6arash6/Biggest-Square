# 🔥 Last-Minute Exam Prep Guide - C00-C05 Coverage

> **Your exam will cover C00-C05** (6 projects from the first ~2 weeks)  
> With 4 weeks for 13 C projects, this timeline makes perfect sense!

**Your exam is TOMORROW - Focus on what matters most!**

## ⏰ Time Management for Tonight

**DON'T try to learn everything. Focus on:**
1. ✅ **High-frequency topics** (2 hours)
2. ✅ **Your weak spots** from first exam (1 hour)
3. ✅ **Quick practice** (1 hour)
4. ✅ **Sleep well!** (crucial for performance)

---

## 🎯 Most Likely Exam Questions (Based on 50% Pass)

### Level 0-1 (Must Master - Always Appear)
- `aff_z` / `aff_first_param` / `aff_last_param`
- `ft_strlen`
- `ft_putstr`
- `ft_swap`
- `fizzbuzz`
- `rot_13` / `rotone`
- `first_word`
- `rev_print`

### Level 2 (Very Common)
- `ft_atoi` ⭐ **Study this!**
- `ft_strcmp`
- `ft_strcpy`
- `alpha_mirror`
- `inter` / `union`
- `wdmatch`

### Level 3-4 (C05 Topics - May Appear)
- **Recursion basics:**
  - `ft_recursive_factorial`
  - `ft_recursive_power`
  - `ft_fibonacci`
  
- **Iterative versions:**
  - `ft_iterative_factorial`
  - `ft_iterative_power`

---

## 📚 C05 Quick Reference (If It Appears)

### Pattern 1: Factorial
```c
// Iterative (easier, faster to code)
int ft_iterative_factorial(int nb)
{
    int result = 1;
    
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    
    while (nb > 1)
    {
        result *= nb;
        nb--;
    }
    return (result);
}

// Recursive (what C05 asks for)
int ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (1);
    return (nb * ft_recursive_factorial(nb - 1));
}
```

**Key points:**
- Negative → return 0
- 0! = 1, 1! = 1
- n! = n × (n-1)!

---

### Pattern 2: Power
```c
// Iterative
int ft_iterative_power(int nb, int power)
{
    int result = 1;
    
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    
    while (power > 0)
    {
        result *= nb;
        power--;
    }
    return (result);
}

// Recursive
int ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    return (nb * ft_recursive_power(nb, power - 1));
}
```

**Key points:**
- Negative power → return 0
- Anything^0 = 1
- n^p = n × n^(p-1)

---

### Pattern 3: Fibonacci
```c
int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    if (index == 1)
        return (1);
    return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
```

**Sequence:** 0, 1, 1, 2, 3, 5, 8, 13, 21...
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2)

---

## ⚡ Quick Wins for Tomorrow

### 1. Memorize These Patterns

**String iteration:**
```c
int i = 0;
while (str[i])
{
    // do something
    i++;
}
```

**argc check:**
```c
if (argc == 2)      // Exactly 1 argument
if (argc > 1)       // At least 1 argument
if (argc != 2)      // Wrong number of args
    write(1, "\n", 1);
```

**Always print newline:**
```c
write(1, "\n", 1);  // At the end of main
```

**ft_putchar helper:**
```c
void ft_putchar(char c)
{
    write(1, &c, 1);
}
```

**ft_putstr:**
```c
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}
```

---

### 2. Common Mistakes to Avoid

❌ **Forgetting newline**
```c
// Wrong:
if (argc == 2)
    print_something();
// Forgot newline when argc != 2!

// Right:
if (argc == 2)
    print_something();
write(1, "\n", 1);  // Always!
```

❌ **Wrong argc check**
```c
// Wrong: accepts too many args
if (argc > 1)

// Right: exactly 1 arg
if (argc == 2)
```

❌ **Off-by-one in loops**
```c
// Wrong: skips last char
while (str[i + 1])

// Right:
while (str[i])
```

❌ **Using printf in exam**
```c
// Wrong: not allowed!
printf("%s\n", str);

// Right:
write(1, str, ft_strlen(str));
write(1, "\n", 1);
```

---

## 🎯 Practice Plan for Tonight (3-4 hours max)

### Hour 1: Review What You Missed
Go to your first exam and **understand WHY you missed those questions:**
- Was it logic error?
- Time management?
- Didn't know the pattern?

Fix those gaps NOW.

---

### Hour 2: Speed Drill These Exercises

Practice coding **from memory** (set 5-min timer each):

1. **Level 0:**
   - `aff_last_param` - Print last argument
   - `fizzbuzz` - The classic

2. **Level 1:**
   - `ft_strlen` - Count chars
   - `rot_13` - Character rotation
   - `first_word` - Print first word

3. **Level 2:**
   - `ft_atoi` - String to int ⭐ **Important!**
   - `inter` - Common characters

4. **Level 3 (if time):**
   - `ft_recursive_factorial` - Basic recursion

📁 **All these exist in your `Exams Practice/` folder!**

---

### Hour 3: Timed Mock Exam

**Do 3 exercises under exam conditions:**
1. Pick one from Level 0-1 (easy) - 10 minutes
2. Pick one from Level 2 (medium) - 15 minutes
3. Pick one from Level 3 (hard) - 20 minutes

**Rules:**
- Use only `vim`
- Compile: `gcc -Wall -Wextra -Werror`
- Test manually (no test files!)
- Fix all warnings

---

## 💡 Exam Day Strategy (Tomorrow)

### Before Starting:
1. **Read ALL available exercises first** (2 min)
2. **Pick easiest one** - get points fast
3. **Do Level 0-1 first** - build confidence

### During Exam:
1. **15 minutes per exercise** - move on if stuck
2. **Compile often** - catch errors early
3. **Test with 3 cases minimum:**
   - Normal case
   - Empty string
   - Edge case (single char, no args)

### Time Management:
```
Hour 1: Easiest exercise (Level 0-1) → Get points!
Hour 2: Medium exercise (Level 2) → Build score
Hour 3: Hard exercise (Level 3) → Extra points
Hour 4: Second easy/medium → Secure passing
```

**Pass at 50%+** - Don't aim for 100%!

---

## 🔑 Key Formulas to Remember

### ASCII Operations:
```c
'a' - 'a' = 0        // Position in alphabet
'5' - '0' = 5        // Char to int
digit + '0'          // Int to char
c + 32               // Upper to lower
c - 32               // Lower to upper
```

### Modulo Checks:
```c
i % 2 == 0           // Even
i % 2 == 1           // Odd
i & 1                // Odd (bitwise)
!(i & 1)             // Even (bitwise)
```

### Recursion Base Cases:
```c
// Factorial
if (nb < 0) return (0);
if (nb <= 1) return (1);

// Power
if (power < 0) return (0);
if (power == 0) return (1);

// Fibonacci
if (index < 0) return (-1);
if (index < 2) return (index);
```

---

## ✅ Pre-Exam Checklist

Tonight, make sure you can:
- [ ] Write `ft_strlen` from memory
- [ ] Write `ft_atoi` from memory
- [ ] Handle argc/argv correctly
- [ ] Always print newline
- [ ] Use only `write()`, not printf
- [ ] Compile with `-Wall -Wextra -Werror`
- [ ] Test 3+ cases per exercise

---

## 😴 Sleep Strategy

**STOP STUDYING by 10 PM!**

Your brain needs:
- ✅ 7-8 hours sleep
- ✅ Good breakfast tomorrow
- ✅ Hydration during exam

**Sleep > Last-minute cramming**

---

## 🚀 Quick Reference Sheet (Print This!)

```c
// ALWAYS include
#include <unistd.h>

// ft_strlen
int i = 0;
while (str[i])
    i++;
return (i);

// ft_atoi (basic)
int sign = 1;
int result = 0;

// Skip whitespace
while (*str == ' ' || (*str >= 9 && *str <= 13))
    str++;

// Handle sign
if (*str == '-' || *str == '+')
{
    if (*str == '-')
        sign = -1;
    str++;
}

// Convert digits
while (*str >= '0' && *str <= '9')
{
    result = result * 10 + (*str - '0');
    str++;
}
return (sign * result);

// Recursion template
int recursive_function(int n)
{
    // Base case
    if (n <= 1)
        return (base_value);
    
    // Recursive case
    return (operation + recursive_function(n - 1));
}
```

---

## 🎯 Final Tips

1. **Stay calm** - You already passed once!
2. **Read subjects carefully** - Don't miss requirements
3. **Start simple** - Level 0 → 1 → 2 → 3
4. **Move on if stuck** - Come back later
5. **Test everything** - Even "obvious" code

**You got this! 💪**

---

**Good luck tomorrow! 🍀**

*Remember: 50%+ is passing. Focus on getting 3-4 solid exercises done rather than attempting everything.*
