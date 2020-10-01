# Hollow Rhombus Pattern

- Input:
  - `int n;`
  - `(n % 2) == 0`
  - `0 < N < 10`
- Output: draw a diamon shape like below with simple output

  ```bash
    * * * * *    * * * * * * *
    * *   * *    * * *   * * *
    *       *    * *       * *
    * *   * *    *           *
    * * * * *    * *       * *
                 * * *   * * *
                 * * * * * * *
  ```

- To compile, please use [makefile](/makefile). If you want to do that manually for practicing purpose, please ensure to build that on C++20 standard.


## References

- Learn more about [`.editorconfig`][edicon].
- Learn more about Makefile:
  - [For C++ developers][mk-cpp]
  - [For web developers][mk-dev]


[lnk]: https://github.com/akshitagit/JavaScript/issues/42
[mk-cpp]: https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
[mk-dev]: https://nicwortel.nl/blog/2019/01/29/building-web-applications-with-make
[edicon]: https://editorconfig.org