/**
 * @brief oj-template(old)
 * @docs docs/oj-template.md
 */

<%!
    import onlinejudge_template.generator.cplusplus as cplusplus
    import onlinejudge_template.generator.about as about
%>\
<%
    data['config']['indent'] = '\t'
    data['config']['scanner'] = 'cin'
    data['config']['printer'] = 'cout'
%>\

#include <bits/stdc++.h>
using namespace std;

/*
#include <atcoder/all>
using namespace atcoder;
*/

#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) std::begin(x), std::end(x)
#define uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define sum(...) accumulate(all(__VA_ARGS__),0LL)

template <class T> auto min(const T& a){ return *min_element(all(a)); }
template <class T> auto max(const T& a){ return *max_element(all(a)); }
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
 
using i64 = long long;
using P = pair<i64, i64>;

// generated by ${about.title} ${about.version} (${about.url})

${cplusplus.declare_constants(data)}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ${cplusplus.declare_constants(data)}
    ${cplusplus.read_input(data)}
}