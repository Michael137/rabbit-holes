```
class _LIBCPP_TEMPLATE_VIS mersenne_twister_engine
{
public:
    // types
    typedef _UIntType result_type;
private:
    result_type __x_[__n];
    size_t      __i_;
    static_assert(  0 <  __m, "mersenne_twister_engine invalid parameters");
    static_assert(__m <= __n, "mersenne_twister_engine invalid parameters");
    static _LIBCPP_CONSTEXPR const result_type _Dt = numeric_limits<result_type>::digits;
    static_assert(__w <= _Dt, "mersenne_twister_engine invalid parameters");
    static_assert(  2 <= __w, "mersenne_twister_engine invalid parameters");
    static_assert(__r <= __w, "mersenne_twister_engine invalid parameters");
    static_assert(__u <= __w, "mersenne_twister_engine invalid parameters");
    static_assert(__s <= __w, "mersenne_twister_engine invalid parameters");
    static_assert(__t <= __w, "mersenne_twister_engine invalid parameters");
    static_assert(__l <= __w, "mersenne_twister_engine invalid parameters");
public:
    static _LIBCPP_CONSTEXPR const result_type _Min = 0;
    static _LIBCPP_CONSTEXPR const result_type _Max = __w == _Dt ? result_type(~0) :
                                                      (result_type(1) << __w) - result_type(1);
    static_assert(_Min < _Max, "mersenne_twister_engine invalid parameters");
    static_assert(__a <= _Max, "mersenne_twister_engine invalid parameters");
    static_assert(__b <= _Max, "mersenne_twister_engine invalid parameters");
    static_assert(__c <= _Max, "mersenne_twister_engine invalid parameters");
    static_assert(__d <= _Max, "mersenne_twister_engine invalid parameters");
    static_assert(__f <= _Max, "mersenne_twister_engine invalid parameters");
    // engine characteristics
    static _LIBCPP_CONSTEXPR const size_t word_size = __w;
    static _LIBCPP_CONSTEXPR const size_t state_size = __n;
    static _LIBCPP_CONSTEXPR const size_t shift_size = __m;
    static _LIBCPP_CONSTEXPR const size_t mask_bits = __r;
    static _LIBCPP_CONSTEXPR const result_type xor_mask = __a;
    static _LIBCPP_CONSTEXPR const size_t tempering_u = __u;
    static _LIBCPP_CONSTEXPR const result_type tempering_d = __d;
    static _LIBCPP_CONSTEXPR const size_t tempering_s = __s;
    static _LIBCPP_CONSTEXPR const result_type tempering_b = __b;
    static _LIBCPP_CONSTEXPR const size_t tempering_t = __t;
    static _LIBCPP_CONSTEXPR const result_type tempering_c = __c;
    static _LIBCPP_CONSTEXPR const size_t tempering_l = __l;
    static _LIBCPP_CONSTEXPR const result_type initialization_multiplier = __f;
    _LIBCPP_INLINE_VISIBILITY
    static _LIBCPP_CONSTEXPR result_type min() { return _Min; }
    _LIBCPP_INLINE_VISIBILITY
    static _LIBCPP_CONSTEXPR result_type max() { return _Max; }
    static _LIBCPP_CONSTEXPR const result_type default_seed = 5489u;
    // constructors and seeding functions
    _LIBCPP_INLINE_VISIBILITY
    explicit mersenne_twister_engine(result_type __sd = default_seed)
        {seed(__sd);}
    template<class _Sseq>
        _LIBCPP_INLINE_VISIBILITY
        explicit mersenne_twister_engine(_Sseq& __q,
        typename enable_if<__is_seed_sequence<_Sseq, mersenne_twister_engine>::value>::type* = 0)
        {seed(__q);}
    void seed(result_type __sd = default_seed);
    template<class _Sseq>
        _LIBCPP_INLINE_VISIBILITY
        typename enable_if
        <
            __is_seed_sequence<_Sseq, mersenne_twister_engine>::value,
            void
        >::type
        seed(_Sseq& __q)
            {__seed(__q, integral_constant<unsigned, 1 + (__w - 1) / 32>());}
    // generating functions
    result_type operator()();
    _LIBCPP_INLINE_VISIBILITY
    void discard(unsigned long long __z) {for (; __z; --__z) operator()();}
    template <class _UInt, size_t _Wp, size_t _Np, size_t _Mp, size_t _Rp,
              _UInt _Ap, size_t _Up, _UInt _Dp, size_t _Sp,
              _UInt _Bp, size_t _Tp, _UInt _Cp, size_t _Lp, _UInt _Fp>
    friend
    bool
    operator==(const mersenne_twister_engine<_UInt, _Wp, _Np, _Mp, _Rp, _Ap, _Up, _Dp, _Sp,
                                             _Bp, _Tp, _Cp, _Lp, _Fp>& __x,
               const mersenne_twister_engine<_UInt, _Wp, _Np, _Mp, _Rp, _Ap, _Up, _Dp, _Sp,
                                             _Bp, _Tp, _Cp, _Lp, _Fp>& __y);
    template <class _UInt, size_t _Wp, size_t _Np, size_t _Mp, size_t _Rp,
              _UInt _Ap, size_t _Up, _UInt _Dp, size_t _Sp,
              _UInt _Bp, size_t _Tp, _UInt _Cp, size_t _Lp, _UInt _Fp>
    friend
    bool
    operator!=(const mersenne_twister_engine<_UInt, _Wp, _Np, _Mp, _Rp, _Ap, _Up, _Dp, _Sp,
                                             _Bp, _Tp, _Cp, _Lp, _Fp>& __x,
               const mersenne_twister_engine<_UInt, _Wp, _Np, _Mp, _Rp, _Ap, _Up, _Dp, _Sp,
                                             _Bp, _Tp, _Cp, _Lp, _Fp>& __y);
    template <class _CharT, class _Traits,
              class _UInt, size_t _Wp, size_t _Np, size_t _Mp, size_t _Rp,
              _UInt _Ap, size_t _Up, _UInt _Dp, size_t _Sp,
              _UInt _Bp, size_t _Tp, _UInt _Cp, size_t _Lp, _UInt _Fp>
    friend
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
               const mersenne_twister_engine<_UInt, _Wp, _Np, _Mp, _Rp, _Ap, _Up, _Dp, _Sp,
                                             _Bp, _Tp, _Cp, _Lp, _Fp>& __x);
    template <class _CharT, class _Traits,
              class _UInt, size_t _Wp, size_t _Np, size_t _Mp, size_t _Rp,
              _UInt _Ap, size_t _Up, _UInt _Dp, size_t _Sp,
              _UInt _Bp, size_t _Tp, _UInt _Cp, size_t _Lp, _UInt _Fp>
    friend
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __is,
               mersenne_twister_engine<_UInt, _Wp, _Np, _Mp, _Rp, _Ap, _Up, _Dp, _Sp,
                                       _Bp, _Tp, _Cp, _Lp, _Fp>& __x);
private:
    template<class _Sseq>
        void __seed(_Sseq& __q, integral_constant<unsigned, 1>);
    template<class _Sseq>
        void __seed(_Sseq& __q, integral_constant<unsigned, 2>);
    template <size_t __count>
        _LIBCPP_INLINE_VISIBILITY
        static
        typename enable_if
        <
            __count < __w,
            result_type
        >::type
        __lshift(result_type __x) {return (__x << __count) & _Max;}
    template <size_t __count>
        _LIBCPP_INLINE_VISIBILITY
        static
        typename enable_if
        <
            (__count >= __w),
            result_type
        >::type
        __lshift(result_type) {return result_type(0);}
    template <size_t __count>
        _LIBCPP_INLINE_VISIBILITY
        static
        typename enable_if
        <
            __count < _Dt,
            result_type
        >::type
        __rshift(result_type __x) {return __x >> __count;}
    template <size_t __count>
        _LIBCPP_INLINE_VISIBILITY
        static
        typename enable_if
        <
            (__count >= _Dt),
            result_type
        >::type
        __rshift(result_type) {return result_type(0);}
};

template <class _UIntType, size_t __w, size_t __n, size_t __m, size_t __r,
          _UIntType __a, size_t __u, _UIntType __d, size_t __s,
          _UIntType __b, size_t __t, _UIntType __c, size_t __l, _UIntType __f>
_UIntType
mersenne_twister_engine<_UIntType, __w, __n, __m, __r, __a, __u, __d, __s, __b,
    __t, __c, __l, __f>::operator()()
{
    const size_t __j = (__i_ + 1) % __n;
    const result_type __mask = __r == _Dt ? result_type(~0) :
                                       (result_type(1) << __r) - result_type(1);
    const result_type _Yp = (__x_[__i_] & ~__mask) | (__x_[__j] & __mask);
    const size_t __k = (__i_ + __m) % __n;
    __x_[__i_] = __x_[__k] ^ __rshift<1>(_Yp) ^ (__a * (_Yp & 1));
    result_type __z = __x_[__i_] ^ (__rshift<__u>(__x_[__i_]) & __d);
    __i_ = __j;
    __z ^= __lshift<__s>(__z) & __b;
    __z ^= __lshift<__t>(__z) & __c;
    return __z ^ __rshift<__l>(__z);
}

class _LIBCPP_TEMPLATE_VIS uniform_real_distribution
{
public:
    // types
    typedef _RealType result_type;
    class _LIBCPP_TEMPLATE_VIS param_type
    {
        result_type __a_;
        result_type __b_;
    public:
        typedef uniform_real_distribution distribution_type;
        _LIBCPP_INLINE_VISIBILITY
        explicit param_type(result_type __a = 0,
                            result_type __b = 1)
            : __a_(__a), __b_(__b) {}
        _LIBCPP_INLINE_VISIBILITY
        result_type a() const {return __a_;}
        _LIBCPP_INLINE_VISIBILITY
        result_type b() const {return __b_;}
        friend _LIBCPP_INLINE_VISIBILITY
        bool operator==(const param_type& __x, const param_type& __y)
            {return __x.__a_ == __y.__a_ && __x.__b_ == __y.__b_;}
        friend _LIBCPP_INLINE_VISIBILITY
        bool operator!=(const param_type& __x, const param_type& __y)
            {return !(__x == __y);}
    };
private:
    param_type __p_;
public:
    // constructors and reset functions
    _LIBCPP_INLINE_VISIBILITY
    explicit uniform_real_distribution(result_type __a = 0, result_type __b = 1)
        : __p_(param_type(__a, __b)) {}
    _LIBCPP_INLINE_VISIBILITY
    explicit uniform_real_distribution(const param_type& __p) : __p_(__p) {}
    _LIBCPP_INLINE_VISIBILITY
    void reset() {}
    // generating functions
    template<class _URNG>
        _LIBCPP_INLINE_VISIBILITY
        result_type operator()(_URNG& __g)
        {return (*this)(__g, __p_);}
    template<class _URNG> _LIBCPP_INLINE_VISIBILITY result_type operator()(_URNG& __g, const param_type& __p);
    // property functions
    _LIBCPP_INLINE_VISIBILITY
    result_type a() const {return __p_.a();}
    _LIBCPP_INLINE_VISIBILITY
    result_type b() const {return __p_.b();}
    _LIBCPP_INLINE_VISIBILITY
    param_type param() const {return __p_;}
    _LIBCPP_INLINE_VISIBILITY
    void param(const param_type& __p) {__p_ = __p;}
    _LIBCPP_INLINE_VISIBILITY
    result_type min() const {return a();}
    _LIBCPP_INLINE_VISIBILITY
    result_type max() const {return b();}
    friend _LIBCPP_INLINE_VISIBILITY
        bool operator==(const uniform_real_distribution& __x,
                        const uniform_real_distribution& __y)
        {return __x.__p_ == __y.__p_;}
    friend _LIBCPP_INLINE_VISIBILITY
        bool operator!=(const uniform_real_distribution& __x,
                        const uniform_real_distribution& __y)
        {return !(__x == __y);}
};

template<class _RealType>
template<class _URNG>
inline
typename uniform_real_distribution<_RealType>::result_type
uniform_real_distribution<_RealType>::operator()(_URNG& __g, const param_type& __p)
{
    return (__p.b() - __p.a())
        * _VSTD::generate_canonical<_RealType, numeric_limits<_RealType>::digits>(__g)
        + __p.a();
}

template<class _RealType, size_t __bits, class _URNG>
_RealType
generate_canonical(_URNG& __g)
{
    const size_t _Dt = numeric_limits<_RealType>::digits;
    const size_t __b = _Dt < __bits ? _Dt : __bits;
#ifdef _LIBCPP_CXX03_LANG
    const size_t __logR = __log2<uint64_t, _URNG::_Max - _URNG::_Min + uint64_t(1)>::value;
#else
    const size_t __logR = __log2<uint64_t, _URNG::max() - _URNG::min() + uint64_t(1)>::value;
#endif
    const size_t __k = __b / __logR + (__b % __logR != 0) + (__b == 0);
    const _RealType _Rp = static_cast<_RealType>(_URNG::max() - _URNG::min()) + _RealType(1);
    _RealType __base = _Rp;
    _RealType _Sp = __g() - _URNG::min();
    for (size_t __i = 1; __i < __k; ++__i, __base *= _Rp)
        _Sp += (__g() - _URNG::min()) * __base;
    return _Sp / __base;
}
```
