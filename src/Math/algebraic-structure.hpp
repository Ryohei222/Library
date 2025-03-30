#pragma once

#include <numeric>
#include <concepts>

template <typename T>
concept inner_type = requires() {
    typename T::S;
};

template <typename T>
concept identity = requires() {
    { T::e() } -> std::same_as<typename T::S>; // 単位元
};

template <typename T>
concept inverse = requires() {
    { T::inv(std::declval<typename T::S>()) } -> std::same_as<typename T::S>; // 逆元
};

template <typename T>
concept binary_operation = requires() {
    { T::op(std::declval<typename T::S>(), std::declval<typename T::S>()) } -> std::same_as<typename T::S>; // 二項演算
};

template <class T>
concept MonoidConcept = inner_type<T> && identity<T> && binary_operation<T>;

template <class T>
concept GroupConcept = MonoidConcept<T> && inverse<T>;

template <std::integral T>
struct MinMonoid {
    using S = T;
    static constexpr S e() { return std::numeric_limits<S>::max(); }
    static constexpr S op(const S &a, const S &b) { return std::min(a, b); }
};

template <std::integral T>
struct MaxMonoid {
    using S = T;
    static constexpr S e() { return std::numeric_limits<S>::min(); }
    static constexpr S op(const S &a, const S &b) { return std::max(a, b); }
};

template <typename T>
struct MultiplicativeMonoid {
    using S = T;
    static constexpr S e() { return S(1); }
    static constexpr S op(const S &a, const S &b) { return a * b; }
};

template <typename T>
struct AdditiveGroup {
    using S = T;
    static constexpr S e() { return S(); }
    static constexpr S op(const S &a, const S &b) { return a + b; }
    static constexpr S inv(const S &a) { return -a; }
};

template <typename T>
struct XORGroup {
    using S = T;
    static constexpr S e() { return S(); }
    static constexpr S op(const S &a, const S &b) { return a ^ b; }
    static constexpr S inv(const S &a) { return a; }
};