# Generate Parentheses

递归求解，递归函数``parMaker(string str, int left, int right)``

- ``left``表示目前还剩余要插入``str``的左括号的数量，若``left > 0``，则可以继续添加左括号

- ``right``表示目前还剩余要插入``str``的右括号的数量， 若``right > 0 && left < right``，则可以继续添加右括号
