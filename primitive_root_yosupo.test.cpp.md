---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Misc/debug.hpp
    title: Misc/debug.hpp
  - icon: ':x:'
    path: Misc/faster_io.hpp
    title: Misc/faster_io.hpp
  - icon: ':question:'
    path: Misc/marco.hpp
    title: Misc/marco.hpp
  - icon: ':x:'
    path: Mod/Primitive_root.hpp
    title: Mod/Primitive_root.hpp
  - icon: ':x:'
    path: Mod/mod_inv.hpp
    title: Mod/mod_inv.hpp
  - icon: ':x:'
    path: Modint/Barrett_2.hpp
    title: Modint/Barrett_2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primitive_root
    links:
    - https://judge.yosupo.jp/problem/primitive_root
  bundledCode: "#line 1 \"primitive_root_yosupo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\
    \n#line 2 \"Misc/marco.hpp\"\n// Judges with GCC >= 12 only needs Ofast\n// #pragma\
    \ GCC optimize(\"O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize\"\
    )\n// MLE optimization\n// #pragma GCC optimize(\"conserve-stack\")\n// Old judges\n\
    // #pragma GCC target(\"sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2\")\n// New judges.\
    \ Test with assert(__builtin_cpu_supports(\"avx2\"));\n// #pragma GCC target(\"\
    avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native\")\n// Atcoder\n// #pragma GCC\
    \ target(\"avx2,popcnt,lzcnt,abm,bmi,bmi2,fma\")\n/*\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\ntypedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>\
    \ ods;\n- insert(x),erase(x)\n- find_by_order(k): return iterator to the k-th\
    \ smallest element\n- order_of_key(x): the number of elements that are strictly\
    \ smaller\n*/\n#include<bits/stdc++.h>\nusing namespace std;\n\nusing ld = long\
    \ double;\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n \n \n#define pii pair<int,int>\n#define pll pair<ll,ll>\n \n\
    #define all(x) (x).begin(),(x).end()\n#define rall(x) (x).rbegin(),(x).rend()\n\
    #define ars(x) (x),(x+n)\n \n#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)\n\
    \ \n#define For(i,a,b) for (int i=(a); i<(b); i++)\n#define rep(i,a) For(i,0,a)\n\
    #define rev(i,a,b) for (int i=(a); i>(b); i--)\n#define FOR(i,a,b) for (int i=(a);\
    \ i<=(b); i++)\n#define REP(i,a) FOR(i,1,a)\n#define REV(i,a,b) for (int i=(a);\
    \ i>=(b); i--)\n \n#define pb push_back\n#define eb emplace_back\n#define mp make_pair\n\
    #define fi first\n#define se second\n#define FT ios_base::sync_with_stdio(false);\
    \ cin.tie(nullptr);\n \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nusing vi=vector<int>;\nusing vll = vector<ll>;\ntemplate <class T>\nusing vc\
    \ = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n \n//template <class T>\n//using ods =\n//   tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n \ntemplate\
    \ <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}\ntemplate <typename\
    \ T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}\n \ntemplate<class T> using pq\
    \ = priority_queue<T>;\ntemplate<class T> using pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n#line 1 \"Misc/debug.hpp\"\nvoid __print(int x) {cerr << x;}\n\
    void __print(long x) {cerr << x;}\nvoid __print(long long x) {cerr << x;}\nvoid\
    \ __print(unsigned x) {cerr << x;}\nvoid __print(unsigned long x) {cerr << x;}\n\
    void __print(unsigned long long x) {cerr << x;}\nvoid __print(float x) {cerr <<\
    \ x;}\nvoid __print(double x) {cerr << x;}\nvoid __print(long double x) {cerr\
    \ << x;}\nvoid __print(char x) {cerr << '\\'' << x << '\\'';}\nvoid __print(const\
    \ char *x) {cerr << '\\\"' << x << '\\\"';}\nvoid __print(const string &x) {cerr\
    \ << '\\\"' << x << '\\\"';}\nvoid __print(bool x) {cerr << (x ? \"true\" : \"\
    false\");}\n\ntemplate<typename T, typename V>\nvoid __print(const pair<T, V>\
    \ &x) {cerr << '{'; __print(x.first); cerr << \", \"; __print(x.second); cerr\
    \ << '}';}\ntemplate<typename T>\nvoid __print(const T &x) {int f = 0; cerr <<\
    \ '{'; for (auto &i: x) cerr << (f++ ? \", \" : \"\"), __print(i); cerr << \"\
    }\";}\ntemplate<>\nvoid __print(const vector<bool> &x) {int f = 0; cerr << '{';\
    \ for (size_t i = 0; i < x.size(); ++i) cerr << (f++ ? \", \" : \"\"), __print(x[i]);\
    \ cerr << \"}\";}\nvoid _print() {cerr << \"]\\n\";}\ntemplate <typename T, typename...\
    \ V>\nvoid _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << \", \";\
    \ _print(v...);}\n\nvoid dbg_out() { cerr << endl; }\ntemplate<typename Head,\
    \ typename... Tail> void dbg_out(Head H, Tail... T) { __print(H); if (sizeof...(T))\
    \ cerr << \", \"; dbg_out(T...); }\n#define dbg(...) cerr << \"[\" << #__VA_ARGS__\
    \ << \"]:\"; dbg_out(__VA_ARGS__);\n#line 2 \"Misc/faster_io.hpp\"\n\n#include\
    \ <unistd.h>\n#line 11 \"Misc/faster_io.hpp\"\n#include <type_traits>\n#line 13\
    \ \"Misc/faster_io.hpp\"\n#include <bit>\n#line 18 \"Misc/faster_io.hpp\"\n\n\
    namespace yosupo {\n\nnamespace internal {\n\ntemplate <class T>\nusing is_signed_int128\
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
    \ namespace yosupo;\nScanner sc(stdin);\nPrinter pr(stdout);\n#line 5 \"primitive_root_yosupo.test.cpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#line 2 \"Mod/mod_inv.hpp\"\n\n#line 5 \"Mod/mod_inv.hpp\"\
    \nusing namespace std;\n\n// gcd(a, m) != 1 return -1 \ntemplate <typename T>\n\
    T inv_mod(T a, T m) {\n  if (m == 1) return 0;\n  if (a >= m) a %= m;\n  if (a\
    \ < 0) a += m;\n  if(__gcd(a,m)!=1) return -1;\n  T b = m, s = 1, t = 0;\n  while\
    \ (true) {\n    if (a == 1) return s;\n    t -= b / a * s;\n    b %= a;\n    if\
    \ (b == 1) return t + m;\n    s -= a / b * t;\n    a %= b;\n  }\n}\n#line 3 \"\
    Modint/Barrett_2.hpp\"\nstruct Barrett_u32 {\n    u64 m, m2, im;\n    u64 div,\
    \ rem;\n\n    void set(u64 mod) {\n        m = mod;\n        m2 = mod << 1;\n\
    \        im = ((((u128)(1ull) << 64)) + mod - 1) / mod;\n        div = 0;\n  \
    \      rem = 0;\n    }\n\n    void reduce(u64 a) {\n        u64 x = (u64)(((u128)(a)\
    \ * im) >> 64);\n        u64 y = x * m;\n        unsigned long long z;\n     \
    \   u32 w = __builtin_usubll_overflow(a, y, &z) ? m : 0;\n        div = x;\n \
    \       rem = z + w;\n    }\n\n    u32 add(u32 a, u32 b) {\n        a += b;\n\
    \        a -= (a >= (u32)m ? (u32)m : 0);\n        return a;\n    }\n\n    u32\
    \ sub(u32 a, u32 b) {\n        a += (a < b ? (u32)m : 0);\n        a -= b;\n \
    \       return a;\n    }\n\n    u32 min(u32 a) {\n        return sub(0, a);\n\
    \    }\n\n    u32 shl(u32 a) {\n        return (a <<= 1) >= m ? a - m : a;\n \
    \   }\n\n    u32 shr(u32 a) {\n        return (a & 1) ? ((a >> 1) + (m >> 1) +\
    \ 1) : (a >> 1);\n    }\n};\n\nstruct Barrett_u64 {\n    u128 m, m2, im;\n   \
    \ u128 div, rem;\n\n    void set(u128 mod) {\n        m = mod;\n        m2 = mod\
    \ << 1;\n        im = (~((u128)0ull)) / mod;\n        div = 0;\n        rem =\
    \ 0;\n    }\n\n    void reduce(u128 x) {\n        if (m == 1) {\n            div\
    \ = x;\n            rem = 0;\n            return;\n        }\n        uint8_t\
    \  f;\n        u128 a = x >> 64;\n        u128 b = x & 0xffffffffffffffffull;\n\
    \        u128 c = im >> 64;\n        u128 d = im & 0xffffffffffffffffull;\n  \
    \      u128 ac = a * c;\n        u128 bd = (b * d) >> 64;\n        u128 ad = a\
    \ * d;\n        u128 bc = b * c;\n        f = (ad > ((u128)((i128)(-1L)) - bd));\n\
    \        bd += ad;\n        ac += f;\n        f = (bc > ((u128)((i128)(-1L)) -\
    \ bd));\n        bd += bc;\n        ac += f;\n        u128 q = ac + (bd >> 64);\n\
    \        u128 r = x - q * m;\n        if (m <= r) {\n            r -= m;\n   \
    \         q += 1;\n        }\n        div = q;\n        rem = r;\n    }\n\n  \
    \  u64 add(u64 a, u64 b) {\n        a += b;\n        a -= (a >= (u64)m ? (u64)m\
    \ : 0);\n        return a;\n    }\n\n    u64 sub(u64 a, u64 b) {\n        a +=\
    \ (a < b ? (u64)m : 0);\n        a -= b;\n        return a;\n    }\n\n    u64\
    \ min(u64 a) {\n        return sub(0, a);\n    }\n\n    u64 shl(u64 a) {\n   \
    \     return (a <<= 1) >= m ? a - m : a;\n    }\n\n    u64 shr(u64 a) {\n    \
    \    return (a & 1) ? ((a >> 1) + (m >> 1) + 1) : (a >> 1);\n    }\n};\n// Barrett\
    \ reduction - 32-bit\nu32 mul_b32(struct Barrett_u32 *b, u32 a, u32 x) {\n   \
    \ b->reduce((u64)a * x);\n    return (u32)b->rem;\n}\n\nu32 div_b32(struct Barrett_u32\
    \ *b, u32 a, u32 x) {\n    b->reduce((u64)a << 32);\n    return (u32)(b->div *\
    \ inv_mod(x,(u32)b->m));\n}\n\nu32 pow_b32(struct Barrett_u32 *b, u32 a, u64 k)\
    \ {\n    u32 ret = 1u;\n    u64 deg = k;\n    while (deg > 0) {\n        if (deg\
    \ & 1) {\n            ret = mul_b32(b, ret, a);\n        }\n        a = mul_b32(b,\
    \ a, a);\n        deg >>= 1;\n    }\n    return ret;\n}\n\n// Barrett reduction\
    \ - 64-bit\nu64 mul_b64(struct Barrett_u64 *b, u64 a, u64 x) {\n    b->reduce((u128)a\
    \ * x);\n    return (u64)b->rem;\n}\n\nu64 div_b64(struct Barrett_u64 *b, u64\
    \ a, u64 x) {\n    b->reduce((u128)a << 64);\n    return (u64)(b->div * inv_mod(x,(u64)b->m));\n\
    }\n\nu64 pow_b64(struct Barrett_u64 *b, u64 a, u64 k) {\n    u64 ret = 1ull, deg\
    \ = k;\n    while (deg > 0) {\n        if (deg & 1) {\n            ret = mul_b64(b,\
    \ ret, a);\n        }\n        a = mul_b64(b, a, a);\n        deg >>= 1;\n   \
    \ }\n    return ret;\n}\n#line 3 \"Mod/Primitive_root.hpp\"\nu64 primitive_root\
    \ (u64 p) {\n    if(p==2) return 1;\n    vector<u64> fact;\n    Barrett_u64 br;\n\
    \    br.set(p);\n    u64 phi = p-1,  n = phi;\n    for (int i=2; i*i<=n; ++i)\n\
    \        if (n % i == 0) {\n            fact.push_back (i);\n            while\
    \ (n % i == 0)\n                n /= i;\n        }\n    if (n > 1)\n        fact.push_back\
    \ (n);\n    for (int res=2; res<=p; ++res) {\n        bool ok = true;\n      \
    \  for (size_t i=0; i<fact.size() && ok; ++i)\n            ok &= pow_b64(&br,res,\
    \ phi / fact[i]) != 1;\n        if (ok)  return res;\n    }\n    return -1;\n\
    }\n#line 9 \"primitive_root_yosupo.test.cpp\"\nvoid solve()\n{\n   u64 n; sc.read(n);\n\
    \   pr.writeln(primitive_root(n));\n}\n\nint main(){\nFT;\nint t; sc.read(t);\
    \ int tc=0;\nwhile(t--)\n{\n//tc++;\n//cout << \"Case #\" << tc << \": \";\nsolve();\n\
    // cerr << \"Time elapsed: \" << TIME << \" s.\\n\";\n}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primitive_root\"\n#include\
    \ \"Misc/marco.hpp\"\n#include \"Misc/debug.hpp\"\n#include \"Misc/faster_io.hpp\"\
    \nconst int INF=1e9;\nconst ll INFI=1e15;\n//----------Author: Nguyen Ho Nam,UIT,\
    \ Saigon-----------------\n#include \"Mod/Primitive_root.hpp\"\nvoid solve()\n\
    {\n   u64 n; sc.read(n);\n   pr.writeln(primitive_root(n));\n}\n\nint main(){\n\
    FT;\nint t; sc.read(t); int tc=0;\nwhile(t--)\n{\n//tc++;\n//cout << \"Case #\"\
    \ << tc << \": \";\nsolve();\n// cerr << \"Time elapsed: \" << TIME << \" s.\\\
    n\";\n}\n}\n"
  dependsOn:
  - Misc/marco.hpp
  - Misc/debug.hpp
  - Misc/faster_io.hpp
  - Mod/Primitive_root.hpp
  - Modint/Barrett_2.hpp
  - Mod/mod_inv.hpp
  isVerificationFile: true
  path: primitive_root_yosupo.test.cpp
  requiredBy: []
  timestamp: '2024-06-03 13:52:17+07:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: primitive_root_yosupo.test.cpp
layout: document
redirect_from:
- /verify/primitive_root_yosupo.test.cpp
- /verify/primitive_root_yosupo.test.cpp.html
title: primitive_root_yosupo.test.cpp
---
