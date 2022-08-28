// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2019 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <bit>
// #include <compare>
// #include <span>
// #include <syncstream>
#include <version>
#endif

#ifdef lolainta

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N

#define macro_dispatcher(macro,...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro,nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro,nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro,nargs) macro ## nargs

#define INDENT "            " // 12 space
#define DBN(...)        macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
#define DBN1(a)         cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<"\n"<<flush;
#define DBN2(a,b)       cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<",\n"<<INDENT<<#b<<"="<<(b)<<"\n"<<flush;
#define DBN3(a,b,c)     cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<",\n"<<INDENT<<#b<<"="<<(b)<<",\n"<<INDENT<<#c<<"="<<(c)<<"\n"<<flush;
#define DBN4(a,b,c,d)   cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<",\n"<<INDENT<<#b<<"="<<(b)<<",\n"<<INDENT<<#c<<"="<<(c)<<",\n"<<INDENT<<#d<<"="<<(d)<<"\n"<<flush;
#define DBN5(a,b,c,d,e) cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<",\n"<<INDENT<<#b<<"="<<(b)<<",\n"<<INDENT<<#c<<"="<<(c)<<",\n"<<INDENT<<#d<<"="<<(d)<<",\n"<<INDENT<<#e<<"="<<(e)<<"\n"<<flush;
#define DBN1D(x) cerr<<"LINE"<<setw(4)<<__LINE__<<" -> "<<#x<<"\n"<<INDENT;for(auto _:x){cerr<<_<<" ";}cerr<<"\n"<<flush;
#define DBN2D(x) cerr<<"LINE"<<setw(4)<<__LINE__<<" -> "<<#x<<"\n";for(auto _:x){cerr<<INDENT;for(auto __:_){cerr<<__<<" ";}cerr<<"\n"<<flush;};

#define dbn(...)        macro_dispatcher(dbn, __VA_ARGS__)(__VA_ARGS__)
#define dbn1(a)         cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<"\n"<<flush;
#define dbn2(a,b)       cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"<<flush;
#define dbn3(a,b,c)     cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"<<flush;
#define dbn4(a,b,c,d)   cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"<<flush;
#define dbn5(a,b,c,d,e) cerr<<"LINE"<<setw(4)<<__LINE__<<" -> ",cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"<<flush;

template<typename T1, typename T2>
std::ostream&operator<<(std::ostream&os,std::pair<T1,T2>&p){
    return os<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
std::ostream&operator<<(std::ostream&os,std::vector<T>&_){
    int f=0;
    os<<"[";
    for(auto&__:_)
        os<<(f++?",":"")<<__;
    os<<"]";
    return os;
}
#endif
