/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#ifndef INLINE
#define INLINE inline __attribute__((always_inline))
#endif

template<typename T, auto MinVal, auto MaxVal>
class alignas(T) TClampedVariable final
{
    static_assert(std::is_trivial_v<T>);
    static_assert(MaxVal > MinVal);
public:

    INLINE explicit TClampedVariable(const T InitValue)
    {
        operator=(InitValue);
    }

    // just to make UE happy
    TClampedVariable()
    {
        operator=(static_cast<T>(0));
    }

    ~TClampedVariable() = default;

    //returns a copy of this variable
    INLINE T GetVariable() const
    {
        return Variable;
    }

    //returns a copy of this variable
    INLINE T operator*() const
    {
        return Variable;
    }

    INLINE TClampedVariable& operator=(const T NewValue)
    {
        Variable = NewValue < MinVal ? MinVal : NewValue < MaxVal ? NewValue : MaxVal;
        return *this;
    }

    INLINE TClampedVariable& operator+=(const T Other)
    {
        return operator=(Variable + Other);
    }

    INLINE TClampedVariable& operator-=(const T Other)
    {
        return operator=(Variable - Other);
    }

    INLINE TClampedVariable& operator*=(const T Other)
    {
        return operator=(Variable * Other);
    }

    INLINE TClampedVariable& operator/=(const T Other)
    {
        return operator=(Variable / Other);
    }

    INLINE T operator+(const T Other) const
    {
        return Variable + Other;
    }

    INLINE T operator-(const T Other) const
    {
        return Variable - Other;
    }

    INLINE T operator*(const T Other) const
    {
        return Variable * Other;
    }

    INLINE T operator/(const T Other) const
    {
        return Variable / Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE TClampedVariable& operator+=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return operator=(Variable + Other.Variable);
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE TClampedVariable& operator-=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return operator=(Variable - Other.Variable);
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE TClampedVariable& operator*=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return operator=(Variable * Other.Variable);
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE TClampedVariable& operator/=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return operator=(Variable / Other.Variable);
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator+(const TClampedVariable<OtherT, OtherMin, OtherMax> Other) const
    {
        return Variable + Other.Variable;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator-(const TClampedVariable<OtherT, OtherMin, OtherMax> Other) const
    {
        return Variable - Other.Variable;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator*(const TClampedVariable<OtherT, OtherMin, OtherMax> Other) const
    {
        return Variable * Other.Variable;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator/(const TClampedVariable<OtherT, OtherMin, OtherMax> Other) const
    {
        return Variable / Other.Variable;
    }

    INLINE bool operator==(const T Other) const
    {
        return Variable == Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator==(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return Variable == Other.Variable;
    }

    INLINE bool operator!=(const T Other) const
    {
        return Variable != Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator!=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return Variable != Other.Variable;
    }

    INLINE bool operator<=(const T Other) const
    {
        return Variable <= Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator<=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return Variable <= Other.Variable;
    }

    INLINE bool operator>=(const T Other) const
    {
        return Variable >= Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator>=(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return Variable >= Other.Variable;
    }

    INLINE bool operator>(const T Other) const
    {
        return Variable > Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator>(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return Variable > Other.Variable;
    }

    INLINE bool operator<(const T Other) const
    {
        return Variable < Other;
    }

    template<typename OtherT, auto OtherMin, auto OtherMax>
    INLINE T operator<(const TClampedVariable<OtherT, OtherMin, OtherMax> Other)
    {
        return Variable < Other.Variable;
    }

private:

    T Variable;
};
