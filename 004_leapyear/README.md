# 004 Leap Year

## 3 Laws of TDD
> 1. You are not allowed to write any production code unless it is to make a failing unit test pass.
> 1. You are not allowed to write any more of a unit test than is sufficient to fail; and compilation failures are failures.
> 1. You are not allowed to write any more production code than is sufficient to pass the one failing unit test.

― Robert "Uncle Bob" C. Martin, http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd

## New Elements
- Research your requirements (in this case, for example, first research the rules for leap years).
- Use `<assert.h>` to get access to the `assert()` macro.
- Use `<stdbool.h>` to get access to the `bool` type and the `true` and `false` constants.
- Use the `assert()` macro to verify assumptions about the behavior of code.
- First define your assumptions, verify them, and then implement them.
  That is called TDD - Test-Driven Development

## References
- ISO/IEC 9899:yyyy http://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf
  - 7.2 Diagnostics `<assert.h>`
