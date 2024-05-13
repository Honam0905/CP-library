---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: PARS_yosupo.test.cpp
    title: PARS_yosupo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fast_io.hpp\"\n\n#include <unistd.h>\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <cctype>\n#include <cstring>\n\
    #include <sstream>\n#include <string>\n#include <type_traits>\n#include <vector>\n\
    #include <bit>\n#include <cstdint>\n#line 16 \"fast_io.hpp\"\n#include <numeric>\n\
    #line 18 \"fast_io.hpp\"\n\nnamespace yosupo {\n\nnamespace internal {\n\ntemplate\
    \ <class T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ =\n    typename std::conditional<std::is_integral<T>::value ||\n           \
    \                       internal::is_signed_int128<T>::value ||\n            \
    \                      internal::is_unsigned_int128<T>::value,\n             \
    \                 std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_signed_int = typename std::conditional<(is_integral<T>::value\
    \ &&\n                                                 std::is_signed<T>::value)\
    \ ||\n                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\ntemplate <class T>\nusing is_integral_t\
    \ = std::enable_if_t<is_integral<T>::value>;\n\ntemplate <class T>\nusing is_signed_int_t\
    \ = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate <class T>\nusing is_unsigned_int_t\
    \ = std::enable_if_t<is_unsigned_int<T>::value>;\n\ntemplate <class T> using to_unsigned_t\
    \ = typename to_unsigned<T>::type;\n\n}  // namespace internal\n\n}  // namespace\
    \ yosupo\n\nnamespace yosupo {\n\nstruct Scanner {\n  public:\n    Scanner(const\
    \ Scanner&) = delete;\n    Scanner& operator=(const Scanner&) = delete;\n\n  \
    \  Scanner(FILE* fp) : fd(fileno(fp)) { line[0] = 127; }\n\n    void read() {}\n\
    \    template <class H, class... T> void read(H& h, T&... t) {\n        bool f\
    \ = read_single(h);\n        assert(f);\n        read(t...);\n    }\n\n    int\
    \ read_unsafe() { return 0; }\n    template <class H, class... T> int read_unsafe(H&\
    \ h, T&... t) {\n        bool f = read_single(h);\n        if (!f) return 0;\n\
    \        return 1 + read_unsafe(t...);\n    }\n\n    int close() { return ::close(fd);\
    \ }\n\n  private:\n    static constexpr int SIZE = 1 << 15;\n\n    int fd = -1;\n\
    \    std::array<char, SIZE + 1> line;\n    int st = 0, ed = 0;\n    bool eof =\
    \ false;\n\n    bool read_single(std::string& ref) {\n        if (!skip_space())\
    \ return false;\n        ref = \"\";\n        while (true) {\n            char\
    \ c = top();\n            if (c <= ' ') break;\n            ref += c;\n      \
    \      st++;\n        }\n        return true;\n    }\n    bool read_single(double&\
    \ ref) {\n        std::string s;\n        if (!read_single(s)) return false;\n\
    \        ref = std::stod(s);\n        return true;\n    }\n\n    template <class\
    \ T,\n              std::enable_if_t<std::is_same<T, char>::value>* = nullptr>\n\
    \    bool read_single(T& ref) {\n        if (!skip_space<50>()) return false;\n\
    \        ref = top();\n        st++;\n        return true;\n    }\n\n    template\
    \ <class T,\n              internal::is_signed_int_t<T>* = nullptr,\n        \
    \      std::enable_if_t<!std::is_same<T, char>::value>* = nullptr>\n    bool read_single(T&\
    \ sref) {\n        using U = internal::to_unsigned_t<T>;\n        if (!skip_space<50>())\
    \ return false;\n        bool neg = false;\n        if (line[st] == '-') {\n \
    \           neg = true;\n            st++;\n        }\n        U ref = 0;\n  \
    \      do {\n            ref = 10 * ref + (line[st++] & 0x0f);\n        } while\
    \ (line[st] >= '0');\n        sref = neg ? -ref : ref;\n        return true;\n\
    \    }\n    template <class U,\n              internal::is_unsigned_int_t<U>*\
    \ = nullptr,\n              std::enable_if_t<!std::is_same<U, char>::value>* =\
    \ nullptr>\n    bool read_single(U& ref) {\n        if (!skip_space<50>()) return\
    \ false;\n        ref = 0;\n        do {\n            ref = 10 * ref + (line[st++]\
    \ & 0x0f);\n        } while (line[st] >= '0');\n        return true;\n    }\n\n\
    \    bool reread() {\n        if (ed - st >= 50) return true;\n        if (st\
    \ > SIZE / 2) {\n            std::memmove(line.data(), line.data() + st, ed -\
    \ st);\n            ed -= st;\n            st = 0;\n        }\n        if (eof)\
    \ return false;\n        auto u = ::read(fd, line.data() + ed, SIZE - ed);\n \
    \       if (u == 0) {\n            eof = true;\n            line[ed] = '\\0';\n\
    \            u = 1;\n        }\n        ed += int(u);\n        line[ed] = char(127);\n\
    \        return true;\n    }\n\n    char top() {\n        if (st == ed) {\n  \
    \          bool f = reread();\n            assert(f);\n        }\n        return\
    \ line[st];\n    }\n\n    template <int TOKEN_LEN = 0> bool skip_space() {\n \
    \       while (true) {\n            while (line[st] <= ' ') st++;\n          \
    \  if (ed - st > TOKEN_LEN) return true;\n            if (st > ed) st = ed;\n\
    \            for (auto i = st; i < ed; i++) {\n                if (line[i] <=\
    \ ' ') return true;\n            }\n            if (!reread()) return false;\n\
    \        }\n    }\n};\n\nstruct Printer {\n  public:\n    template <char sep =\
    \ ' ', bool F = false> void write() {}\n    template <char sep = ' ', bool F =\
    \ false, class H, class... T>\n    void write(const H& h, const T&... t) {\n \
    \       if (F) write_single(sep);\n        write_single(h);\n        write<true>(t...);\n\
    \    }\n    template <char sep = ' ', class... T> void writeln(const T&... t)\
    \ {\n        write<sep>(t...);\n        write_single('\\n');\n    }\n\n    Printer(FILE*\
    \ _fp) : fd(fileno(_fp)) {}\n    ~Printer() { flush(); }\n\n    int close() {\n\
    \        flush();\n        return ::close(fd);\n    }\n\n    void flush() {\n\
    \        if (pos) {\n            auto res = ::write(fd, line.data(), pos);\n \
    \           assert(res != -1);\n            pos = 0;\n        }\n    }\n\n  private:\n\
    \    static std::array<std::array<char, 2>, 100> small;\n    static std::array<unsigned\
    \ long long, 20> tens;\n\n    static constexpr size_t SIZE = 1 << 15;\n    int\
    \ fd;\n    std::array<char, SIZE> line;\n    size_t pos = 0;\n    std::stringstream\
    \ ss;\n\n    template <class T,\n              std::enable_if_t<std::is_same<char,\
    \ T>::value>* = nullptr>\n    void write_single(const T& val) {\n        if (pos\
    \ == SIZE) flush();\n        line[pos++] = val;\n    }\n\n    template <class\
    \ T,\n              internal::is_signed_int_t<T>* = nullptr,\n              std::enable_if_t<!std::is_same<char,\
    \ T>::value>* = nullptr>\n    void write_single(const T& val) {\n        using\
    \ U = internal::to_unsigned_t<T>;\n        if (val == 0) {\n            write_single('0');\n\
    \            return;\n        }\n        if (pos > SIZE - 50) flush();\n     \
    \   U uval = val;\n        if (val < 0) {\n            write_single('-');\n  \
    \          uval = -uval;\n        }\n        write_unsigned(uval);\n    }\n\n\
    \    template <class U, internal::is_unsigned_int_t<U>* = nullptr>\n    void write_single(U\
    \ uval) {\n        if (uval == 0) {\n            write_single('0');\n        \
    \    return;\n        }\n        if (pos > SIZE - 50) flush();\n\n        write_unsigned(uval);\n\
    \    }\n\n    static int calc_len(uint64_t x) {\n        int i = ((63 - std::countl_zero(x))\
    \ * 3 + 3) / 10;\n        if (x < tens[i])\n            return i;\n        else\n\
    \            return i + 1;\n    }\n\n    template <class U,\n              internal::is_unsigned_int_t<U>*\
    \ = nullptr,\n              std::enable_if_t<2 >= sizeof(U)>* = nullptr>\n   \
    \ void write_unsigned(U uval) {\n        size_t len = calc_len(uval);\n      \
    \  pos += len;\n\n        char* ptr = line.data() + pos;\n        while (uval\
    \ >= 100) {\n            ptr -= 2;\n            memcpy(ptr, small[uval % 100].data(),\
    \ 2);\n            uval /= 100;\n        }\n        if (uval >= 10) {\n      \
    \      memcpy(ptr - 2, small[uval].data(), 2);\n        } else {\n           \
    \ *(ptr - 1) = char('0' + uval);\n        }\n    }\n\n    template <class U,\n\
    \              internal::is_unsigned_int_t<U>* = nullptr,\n              std::enable_if_t<4\
    \ == sizeof(U)>* = nullptr>\n    void write_unsigned(U uval) {\n        std::array<char,\
    \ 8> buf;\n        memcpy(buf.data() + 6, small[uval % 100].data(), 2);\n    \
    \    memcpy(buf.data() + 4, small[uval / 100 % 100].data(), 2);\n        memcpy(buf.data()\
    \ + 2, small[uval / 10000 % 100].data(), 2);\n        memcpy(buf.data() + 0, small[uval\
    \ / 1000000 % 100].data(), 2);\n\n        if (uval >= 100000000) {\n         \
    \   if (uval >= 1000000000) {\n                memcpy(line.data() + pos, small[uval\
    \ / 100000000 % 100].data(),\n                       2);\n                pos\
    \ += 2;\n            } else {\n                line[pos] = char('0' + uval / 100000000);\n\
    \                pos++;\n            }\n            memcpy(line.data() + pos,\
    \ buf.data(), 8);\n            pos += 8;\n        } else {\n            size_t\
    \ len = calc_len(uval);\n            memcpy(line.data() + pos, buf.data() + (8\
    \ - len), len);\n            pos += len;\n        }\n    }\n\n    template <class\
    \ U,\n              internal::is_unsigned_int_t<U>* = nullptr,\n             \
    \ std::enable_if_t<8 == sizeof(U)>* = nullptr>\n    void write_unsigned(U uval)\
    \ {\n        size_t len = calc_len(uval);\n        pos += len;\n\n        char*\
    \ ptr = line.data() + pos;\n        while (uval >= 100) {\n            ptr -=\
    \ 2;\n            memcpy(ptr, small[uval % 100].data(), 2);\n            uval\
    \ /= 100;\n        }\n        if (uval >= 10) {\n            memcpy(ptr - 2, small[uval].data(),\
    \ 2);\n        } else {\n            *(ptr - 1) = char('0' + uval);\n        }\n\
    \    }\n\n    template <\n        class U,\n        std::enable_if_t<internal::is_unsigned_int128<U>::value>*\
    \ = nullptr>\n    void write_unsigned(U uval) {\n        static std::array<char,\
    \ 50> buf;\n        size_t len = 0;\n        while (uval > 0) {\n            buf[len++]\
    \ = char((uval % 10) + '0');\n            uval /= 10;\n        }\n        std::reverse(buf.begin(),\
    \ buf.begin() + len);\n        memcpy(line.data() + pos, buf.data(), len);\n \
    \       pos += len;\n    }\n\n    void write_single(const std::string& s) {\n\
    \        for (char c : s) write_single(c);\n    }\n    void write_single(const\
    \ char* s) {\n        size_t len = strlen(s);\n        for (size_t i = 0; i <\
    \ len; i++) write_single(s[i]);\n    }\n    template <class T> void write_single(const\
    \ std::vector<T>& val) {\n        auto n = val.size();\n        for (size_t i\
    \ = 0; i < n; i++) {\n            if (i) write_single(' ');\n            write_single(val[i]);\n\
    \        }\n    }\n};\n\nstd::array<std::array<char, 2>, 100> Printer::small =\
    \ [] {\n    std::array<std::array<char, 2>, 100> table;\n    for (int i = 0; i\
    \ <= 99; i++) {\n        table[i][1] = char('0' + (i % 10));\n        table[i][0]\
    \ = char('0' + (i / 10 % 10));\n    }\n    return table;\n}();\nstd::array<unsigned\
    \ long long, 20> Printer::tens = [] {\n    std::array<unsigned long long, 20>\
    \ table;\n    for (int i = 0; i < 20; i++) {\n        table[i] = 1;\n        for\
    \ (int j = 0; j < i; j++) {\n            table[i] *= 10;\n        }\n    }\n \
    \   return table;\n}();\n\n}  // namespace yosupo\n//sc.read(type) to enter input\n\
    //sc.write(type) to print out answer\n//sc.writeln() to go break the line\nusing\
    \ namespace yosupo;\nScanner sc(stdin);\nPrinter pr(stdout);\n"
  code: "#pragma once\n\n#include <unistd.h>\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <cctype>\n#include <cstring>\n#include <sstream>\n\
    #include <string>\n#include <type_traits>\n#include <vector>\n#include <bit>\n\
    #include <cstdint>\n#include <cassert>\n#include <numeric>\n#include <type_traits>\n\
    \nnamespace yosupo {\n\nnamespace internal {\n\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral =\n    typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                  internal::is_signed_int128<T>::value ||\n\
    \                                  internal::is_unsigned_int128<T>::value,\n \
    \                             std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_signed_int = typename std::conditional<(is_integral<T>::value\
    \ &&\n                                                 std::is_signed<T>::value)\
    \ ||\n                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\ntemplate <class T>\nusing is_integral_t\
    \ = std::enable_if_t<is_integral<T>::value>;\n\ntemplate <class T>\nusing is_signed_int_t\
    \ = std::enable_if_t<is_signed_int<T>::value>;\n\ntemplate <class T>\nusing is_unsigned_int_t\
    \ = std::enable_if_t<is_unsigned_int<T>::value>;\n\ntemplate <class T> using to_unsigned_t\
    \ = typename to_unsigned<T>::type;\n\n}  // namespace internal\n\n}  // namespace\
    \ yosupo\n\nnamespace yosupo {\n\nstruct Scanner {\n  public:\n    Scanner(const\
    \ Scanner&) = delete;\n    Scanner& operator=(const Scanner&) = delete;\n\n  \
    \  Scanner(FILE* fp) : fd(fileno(fp)) { line[0] = 127; }\n\n    void read() {}\n\
    \    template <class H, class... T> void read(H& h, T&... t) {\n        bool f\
    \ = read_single(h);\n        assert(f);\n        read(t...);\n    }\n\n    int\
    \ read_unsafe() { return 0; }\n    template <class H, class... T> int read_unsafe(H&\
    \ h, T&... t) {\n        bool f = read_single(h);\n        if (!f) return 0;\n\
    \        return 1 + read_unsafe(t...);\n    }\n\n    int close() { return ::close(fd);\
    \ }\n\n  private:\n    static constexpr int SIZE = 1 << 15;\n\n    int fd = -1;\n\
    \    std::array<char, SIZE + 1> line;\n    int st = 0, ed = 0;\n    bool eof =\
    \ false;\n\n    bool read_single(std::string& ref) {\n        if (!skip_space())\
    \ return false;\n        ref = \"\";\n        while (true) {\n            char\
    \ c = top();\n            if (c <= ' ') break;\n            ref += c;\n      \
    \      st++;\n        }\n        return true;\n    }\n    bool read_single(double&\
    \ ref) {\n        std::string s;\n        if (!read_single(s)) return false;\n\
    \        ref = std::stod(s);\n        return true;\n    }\n\n    template <class\
    \ T,\n              std::enable_if_t<std::is_same<T, char>::value>* = nullptr>\n\
    \    bool read_single(T& ref) {\n        if (!skip_space<50>()) return false;\n\
    \        ref = top();\n        st++;\n        return true;\n    }\n\n    template\
    \ <class T,\n              internal::is_signed_int_t<T>* = nullptr,\n        \
    \      std::enable_if_t<!std::is_same<T, char>::value>* = nullptr>\n    bool read_single(T&\
    \ sref) {\n        using U = internal::to_unsigned_t<T>;\n        if (!skip_space<50>())\
    \ return false;\n        bool neg = false;\n        if (line[st] == '-') {\n \
    \           neg = true;\n            st++;\n        }\n        U ref = 0;\n  \
    \      do {\n            ref = 10 * ref + (line[st++] & 0x0f);\n        } while\
    \ (line[st] >= '0');\n        sref = neg ? -ref : ref;\n        return true;\n\
    \    }\n    template <class U,\n              internal::is_unsigned_int_t<U>*\
    \ = nullptr,\n              std::enable_if_t<!std::is_same<U, char>::value>* =\
    \ nullptr>\n    bool read_single(U& ref) {\n        if (!skip_space<50>()) return\
    \ false;\n        ref = 0;\n        do {\n            ref = 10 * ref + (line[st++]\
    \ & 0x0f);\n        } while (line[st] >= '0');\n        return true;\n    }\n\n\
    \    bool reread() {\n        if (ed - st >= 50) return true;\n        if (st\
    \ > SIZE / 2) {\n            std::memmove(line.data(), line.data() + st, ed -\
    \ st);\n            ed -= st;\n            st = 0;\n        }\n        if (eof)\
    \ return false;\n        auto u = ::read(fd, line.data() + ed, SIZE - ed);\n \
    \       if (u == 0) {\n            eof = true;\n            line[ed] = '\\0';\n\
    \            u = 1;\n        }\n        ed += int(u);\n        line[ed] = char(127);\n\
    \        return true;\n    }\n\n    char top() {\n        if (st == ed) {\n  \
    \          bool f = reread();\n            assert(f);\n        }\n        return\
    \ line[st];\n    }\n\n    template <int TOKEN_LEN = 0> bool skip_space() {\n \
    \       while (true) {\n            while (line[st] <= ' ') st++;\n          \
    \  if (ed - st > TOKEN_LEN) return true;\n            if (st > ed) st = ed;\n\
    \            for (auto i = st; i < ed; i++) {\n                if (line[i] <=\
    \ ' ') return true;\n            }\n            if (!reread()) return false;\n\
    \        }\n    }\n};\n\nstruct Printer {\n  public:\n    template <char sep =\
    \ ' ', bool F = false> void write() {}\n    template <char sep = ' ', bool F =\
    \ false, class H, class... T>\n    void write(const H& h, const T&... t) {\n \
    \       if (F) write_single(sep);\n        write_single(h);\n        write<true>(t...);\n\
    \    }\n    template <char sep = ' ', class... T> void writeln(const T&... t)\
    \ {\n        write<sep>(t...);\n        write_single('\\n');\n    }\n\n    Printer(FILE*\
    \ _fp) : fd(fileno(_fp)) {}\n    ~Printer() { flush(); }\n\n    int close() {\n\
    \        flush();\n        return ::close(fd);\n    }\n\n    void flush() {\n\
    \        if (pos) {\n            auto res = ::write(fd, line.data(), pos);\n \
    \           assert(res != -1);\n            pos = 0;\n        }\n    }\n\n  private:\n\
    \    static std::array<std::array<char, 2>, 100> small;\n    static std::array<unsigned\
    \ long long, 20> tens;\n\n    static constexpr size_t SIZE = 1 << 15;\n    int\
    \ fd;\n    std::array<char, SIZE> line;\n    size_t pos = 0;\n    std::stringstream\
    \ ss;\n\n    template <class T,\n              std::enable_if_t<std::is_same<char,\
    \ T>::value>* = nullptr>\n    void write_single(const T& val) {\n        if (pos\
    \ == SIZE) flush();\n        line[pos++] = val;\n    }\n\n    template <class\
    \ T,\n              internal::is_signed_int_t<T>* = nullptr,\n              std::enable_if_t<!std::is_same<char,\
    \ T>::value>* = nullptr>\n    void write_single(const T& val) {\n        using\
    \ U = internal::to_unsigned_t<T>;\n        if (val == 0) {\n            write_single('0');\n\
    \            return;\n        }\n        if (pos > SIZE - 50) flush();\n     \
    \   U uval = val;\n        if (val < 0) {\n            write_single('-');\n  \
    \          uval = -uval;\n        }\n        write_unsigned(uval);\n    }\n\n\
    \    template <class U, internal::is_unsigned_int_t<U>* = nullptr>\n    void write_single(U\
    \ uval) {\n        if (uval == 0) {\n            write_single('0');\n        \
    \    return;\n        }\n        if (pos > SIZE - 50) flush();\n\n        write_unsigned(uval);\n\
    \    }\n\n    static int calc_len(uint64_t x) {\n        int i = ((63 - std::countl_zero(x))\
    \ * 3 + 3) / 10;\n        if (x < tens[i])\n            return i;\n        else\n\
    \            return i + 1;\n    }\n\n    template <class U,\n              internal::is_unsigned_int_t<U>*\
    \ = nullptr,\n              std::enable_if_t<2 >= sizeof(U)>* = nullptr>\n   \
    \ void write_unsigned(U uval) {\n        size_t len = calc_len(uval);\n      \
    \  pos += len;\n\n        char* ptr = line.data() + pos;\n        while (uval\
    \ >= 100) {\n            ptr -= 2;\n            memcpy(ptr, small[uval % 100].data(),\
    \ 2);\n            uval /= 100;\n        }\n        if (uval >= 10) {\n      \
    \      memcpy(ptr - 2, small[uval].data(), 2);\n        } else {\n           \
    \ *(ptr - 1) = char('0' + uval);\n        }\n    }\n\n    template <class U,\n\
    \              internal::is_unsigned_int_t<U>* = nullptr,\n              std::enable_if_t<4\
    \ == sizeof(U)>* = nullptr>\n    void write_unsigned(U uval) {\n        std::array<char,\
    \ 8> buf;\n        memcpy(buf.data() + 6, small[uval % 100].data(), 2);\n    \
    \    memcpy(buf.data() + 4, small[uval / 100 % 100].data(), 2);\n        memcpy(buf.data()\
    \ + 2, small[uval / 10000 % 100].data(), 2);\n        memcpy(buf.data() + 0, small[uval\
    \ / 1000000 % 100].data(), 2);\n\n        if (uval >= 100000000) {\n         \
    \   if (uval >= 1000000000) {\n                memcpy(line.data() + pos, small[uval\
    \ / 100000000 % 100].data(),\n                       2);\n                pos\
    \ += 2;\n            } else {\n                line[pos] = char('0' + uval / 100000000);\n\
    \                pos++;\n            }\n            memcpy(line.data() + pos,\
    \ buf.data(), 8);\n            pos += 8;\n        } else {\n            size_t\
    \ len = calc_len(uval);\n            memcpy(line.data() + pos, buf.data() + (8\
    \ - len), len);\n            pos += len;\n        }\n    }\n\n    template <class\
    \ U,\n              internal::is_unsigned_int_t<U>* = nullptr,\n             \
    \ std::enable_if_t<8 == sizeof(U)>* = nullptr>\n    void write_unsigned(U uval)\
    \ {\n        size_t len = calc_len(uval);\n        pos += len;\n\n        char*\
    \ ptr = line.data() + pos;\n        while (uval >= 100) {\n            ptr -=\
    \ 2;\n            memcpy(ptr, small[uval % 100].data(), 2);\n            uval\
    \ /= 100;\n        }\n        if (uval >= 10) {\n            memcpy(ptr - 2, small[uval].data(),\
    \ 2);\n        } else {\n            *(ptr - 1) = char('0' + uval);\n        }\n\
    \    }\n\n    template <\n        class U,\n        std::enable_if_t<internal::is_unsigned_int128<U>::value>*\
    \ = nullptr>\n    void write_unsigned(U uval) {\n        static std::array<char,\
    \ 50> buf;\n        size_t len = 0;\n        while (uval > 0) {\n            buf[len++]\
    \ = char((uval % 10) + '0');\n            uval /= 10;\n        }\n        std::reverse(buf.begin(),\
    \ buf.begin() + len);\n        memcpy(line.data() + pos, buf.data(), len);\n \
    \       pos += len;\n    }\n\n    void write_single(const std::string& s) {\n\
    \        for (char c : s) write_single(c);\n    }\n    void write_single(const\
    \ char* s) {\n        size_t len = strlen(s);\n        for (size_t i = 0; i <\
    \ len; i++) write_single(s[i]);\n    }\n    template <class T> void write_single(const\
    \ std::vector<T>& val) {\n        auto n = val.size();\n        for (size_t i\
    \ = 0; i < n; i++) {\n            if (i) write_single(' ');\n            write_single(val[i]);\n\
    \        }\n    }\n};\n\nstd::array<std::array<char, 2>, 100> Printer::small =\
    \ [] {\n    std::array<std::array<char, 2>, 100> table;\n    for (int i = 0; i\
    \ <= 99; i++) {\n        table[i][1] = char('0' + (i % 10));\n        table[i][0]\
    \ = char('0' + (i / 10 % 10));\n    }\n    return table;\n}();\nstd::array<unsigned\
    \ long long, 20> Printer::tens = [] {\n    std::array<unsigned long long, 20>\
    \ table;\n    for (int i = 0; i < 20; i++) {\n        table[i] = 1;\n        for\
    \ (int j = 0; j < i; j++) {\n            table[i] *= 10;\n        }\n    }\n \
    \   return table;\n}();\n\n}  // namespace yosupo\n//sc.read(type) to enter input\n\
    //sc.write(type) to print out answer\n//sc.writeln() to go break the line\nusing\
    \ namespace yosupo;\nScanner sc(stdin);\nPrinter pr(stdout);\n"
  dependsOn: []
  isVerificationFile: false
  path: fast_io.hpp
  requiredBy: []
  timestamp: '2024-05-13 07:56:20+07:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - PARS_yosupo.test.cpp
documentation_of: fast_io.hpp
layout: document
redirect_from:
- /library/fast_io.hpp
- /library/fast_io.hpp.html
title: fast_io.hpp
---
