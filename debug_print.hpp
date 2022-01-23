#ifndef DEBUG_PRINT_HPP
#define DEBUG_PRINT_HPP

#include <bits/stdc++.h>
using namespace std;

namespace debug_print {
  ostream& os = cerr;

  template <class Tp> auto has_cbegin(int)     -> decltype(cbegin(declval<Tp>()), true_type {});
  template <class Tp> auto has_cbegin(...)     -> false_type;
  template <class Tp> auto has_value_type(int) -> decltype(declval<typename Tp::value_type>(), true_type {});
  template <class Tp> auto has_value_type(...) -> false_type;

  template <class Tp>[[maybe_unused]] constexpr bool is_iteratable_container_v = decltype(has_cbegin<Tp>(int {}))::value;
  template <class Tp>[[maybe_unused]] constexpr bool is_container_v            = decltype(has_value_type<Tp>(int {}))::value
                                                                                 || is_iteratable_container_v<Tp>;

  template <>        [[maybe_unused]] constexpr bool is_iteratable_container_v<string_view> = false;
  template <>        [[maybe_unused]] constexpr bool is_container_v<string_view>            = false;
#if (defined _GLIBCXX_STRING) || (defined _LIBCPP_STRING)
  template <>        [[maybe_unused]] constexpr bool is_iteratable_container_v<string>      = false;
  template <>        [[maybe_unused]] constexpr bool is_container_v<string>                 = false;
#endif

  template <class Tp, class... Ts> struct first_element { using type = Tp; };
  template <class... Ts> using first_t = typename first_element<Ts...>::type;

  template <class Tp, enable_if_t<!decltype(has_value_type<Tp>(int {}))::value, nullptr_t> = nullptr>
    auto check_elem(int) -> decltype(*cbegin(declval<Tp>()));
  template <class Tp, enable_if_t<decltype(has_value_type<Tp>(int {}))::value, nullptr_t> = nullptr>
    auto check_elem(int) -> typename Tp::value_type;
  template <class Tp>
    auto check_elem(...) -> void;

  template <class Tp> using elem_t = decltype(check_elem<Tp>(int {}));

  template <class Tp> [[maybe_unused]] constexpr bool is_multidim_container_v = is_container_v<Tp>
                                                                                && is_container_v<elem_t<Tp>>;

  template <class Tp> enable_if_t<!is_container_v<Tp>> out(const Tp&);
  void out(const char&);
  void out(const char*);
  void out(const string_view&);

#if (defined _GLIBCXX_STRING) || (defined _LIBCPP_STRING)
  void out(const string&);
#endif

#ifdef __SIZEOF_INT128__
  void out(const __int128&);
  void out(const unsigned __int128&);
#endif

  template <class Tp1, class Tp2> void out(const pair<Tp1, Tp2>&);

#if (defined _GLIBCXX_TUPLE) || (defined _LIBCPP_TUPLE)
  template <class... Ts> void out(const tuple<Ts...>&);
#endif

#if (defined _GLIBCXX_STACK) || (defined _LIBCPP_STACK)
  template <class... Ts> void out(stack<Ts...>);
#endif

#if (defined _GLIBCXX_QUEUE) || (defined _LIBCPP_QUEUE)
  template <class... Ts> void out(queue<Ts...>);
  template <class... Ts> void out(priority_queue<Ts...>);
#endif

  template <class C>
  enable_if_t<is_iteratable_container_v<C>> out(const C&);

  template <class Tp> enable_if_t<!is_container_v<Tp>> out(const Tp& arg) {
    os << arg;
  }

  void out(const char& arg) {
    os << '\'' << arg << '\'';
  }

  void out(const char* arg) {
    os << '\"' << arg << '\"';
  }

  void out(const string_view& arg) {
    os << '\"' << arg << '\"';
  }

#if (defined _GLIBCXX_STRING) || (defined _LIBCPP_STRING)
  void out(const string& arg) {
    os << '\"' << arg << '\"';
  }
#endif

#ifdef __SIZEOF_INT128__
  void out(const __int128& arg) {
    int sign = (arg < 0) ? (-1) : 1;
    if (sign == -1)
      os << '-';
    __int128 base = sign;
    while (sign * arg >= sign * base * 10)
      base *= 10;
    while (base) {
      os << static_cast<char>('0' + (arg / base % 10));
      base /= 10;
    }
  }

  void out(const unsigned __int128& arg) {
    unsigned __int128 base = 1;
    while (arg >= base * 10)
      base *= 10;
    while (base) {
      os << static_cast<char>('0' + (arg / base % 10));
      base /= 10;
    }
  }
#endif

  template <class Tp1, class Tp2> void out(const pair<Tp1, Tp2>& arg) {
    os << '(';
    out(arg.first);
    os << ", ";
    out(arg.second);
    os << ')';
  }

#if (defined _GLIBCXX_TUPLE) || (defined _LIBCPP_TUPLE)
  template <class T, size_t... Is> void print_tuple(const T& arg, index_sequence<Is...>) {
    static_cast<void>(((os << (Is == 0 ? "" : ", "), out(get<Is>(arg))), ...));
  }

  template <class... Ts> void out(const tuple<Ts...>& arg) {
    os << '(';
    print_tuple(arg, make_index_sequence<sizeof...(Ts)>());
    os << ')';
  }
#endif

#if (defined _GLIBCXX_STACK) || (defined _LIBCPP_STACK)
  template <class... Ts> void out(stack<Ts...> arg) {
    if (arg.empty()) {
      os << "<empty stack>";
      return;
    }
    os << "[ ";
    while (!arg.empty()) {
      out(arg.top());
      os << ' ';
      arg.pop();
    }
    os << ']';
  }
#endif

#if (defined _GLIBCXX_QUEUE) || (defined _LIBCPP_QUEUE)
  template <class... Ts> void out(queue<Ts...> arg) {
    if (arg.empty()) {
      os << "<empty queue>";
      return;
    }
    os << "[ ";
    while (!arg.empty()) {
      out(arg.front());
      os << ' ';
      arg.pop();
    }
    os << ']';
  }
  template <class... Ts> void out(priority_queue<Ts...> arg) {
    if (arg.empty()) {
      os << "<empty priority_queue>";
      return;
    }
    os << "[ ";
    while (!arg.empty()) {
      out(arg.top());
      os << ' ';
      arg.pop();
    }
    os << ']';
  }
#endif

  template <class Container>
  enable_if_t<is_iteratable_container_v<Container>> out(const Container& arg) {
    if (distance(cbegin(arg), cend(arg)) == 0) {
      os << "<empty container>";
      return;
    }
    os << "[ ";
    for_each(cbegin(arg), cend(arg), [](const elem_t<Container>& elem) {
      out(elem);
      os << ' ';
    });
    os << ']';
  }

  template <class Tp> enable_if_t<!is_multidim_container_v<Tp>>
  print(string_view name, const Tp& arg) {
    os << name << ": ";
    out(arg);
    if constexpr (is_container_v<Tp>)
      os << '\n';
  }

  template <class Tp> enable_if_t<is_multidim_container_v<Tp>>
  print(string_view name, const Tp& arg) {
    os << name << ": ";
    if (distance(cbegin(arg), cend(arg)) == 0) {
      os << "<empty multidimensional container>\n";
      return;
    }
    for_each(cbegin(arg), cend(arg),
      [&name, is_first_elem = true](const elem_t<Tp>& elem) mutable {
        if (is_first_elem)
          is_first_elem = false;
        else
          for (size_t i = 0; i < name.length() + 2; i++)
            os << ' ';
        out(elem);
        os << '\n';
    });
  }

  template <class Tp, class... Ts> void multi_print(string_view names, const Tp& arg, const Ts&... args) {
    if constexpr (sizeof...(Ts) == 0) {
      names.remove_suffix(
        distance(
          names.crbegin(),
          find_if_not(names.crbegin(), names.crend(),
                           [](const char c) { return isspace(c); })
        )
      );
      print(names, arg);
      if constexpr (!is_container_v<Tp>)
        os << '\n';
    } else {
      size_t comma_pos = 0;

      for (size_t i = 0, paren_depth = 0, inside_quote = false; i < names.length(); i++) {
        if (!inside_quote && paren_depth == 0 && i > 0 && names[i - 1] != '\'' && names[i] == ',') {
          comma_pos = i;
          break;
        }
        if (names[i] == '\"') {
          if (i > 0 && names[i - 1] == '\\') continue;
          inside_quote ^= true;
        }
        if (!inside_quote && names[i] == '(' && (i == 0 || names[i - 1] != '\''))
          paren_depth++;
        if (!inside_quote && names[i] == ')' && (i == 0 || names[i - 1] != '\''))
          paren_depth--;
      }

      const size_t first_varname_length = comma_pos - distance(
        names.crend() - comma_pos,
        find_if_not(
          names.crend() - comma_pos, names.crend(),
          [](const char c) { return isspace(c); }
        )
      );
      print(names.substr(0, first_varname_length), arg);

      if constexpr (!is_container_v<Tp>) {
        if constexpr (is_container_v<first_t<Ts...>>)
          os << '\n';
        else
          os << " | ";
      }

      const size_t next_varname_begins_at = distance(
        names.cbegin(),
        find_if_not(
          names.cbegin() + comma_pos + 1, names.cend(),
          [](const char c) { return isspace(c); }
        )
      );
      names.remove_prefix(next_varname_begins_at);

      multi_print(names, args...);
    }
  }
}  // namespace debug_print

#endif  // DEBUG_PRINT_HPP
