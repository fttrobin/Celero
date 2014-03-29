// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CELERO_INTERNAL_PIMPL_H_
#define CELERO_INTERNAL_PIMPL_H_
 
#include <memory>
 
namespace celero
{
namespace internal
{
///
/// \class pimpl
///
///	\author	Herb Sutter
///
/// Classes using this must overload the assignment operator.
/// Original code by Herb Sutter.
///
template <typename T>
class pimpl 
{
public:
    pimpl();
    template<typename ...Args> pimpl(Args&& ...args);
    ~pimpl();

    T* operator->();
    const T* operator->() const;
    T& operator*();
    const T& operator*() const;

private:
    std::unique_ptr<T> impl_;
};  // class pimpl


// Inline implementations.

template <typename T>
pimpl<T>::pimpl()
: impl_(new T())
{
}

template <typename T>
template <typename ...Args>
pimpl<T>::pimpl(Args&& ...args)
: impl_(new T(std::forward<Args>(args)...))
{
}

template <typename T>
pimpl<T>::~pimpl()
{
}

template <typename T>
T* pimpl<T>::operator->()
{
    return impl_.get();
}

template <typename T>
const T* pimpl<T>::operator->() const
{
    return impl_.get();
}

template <typename T>
T& pimpl<T>::operator*()
{
    return *impl_;
}

template <typename T>
const T& pimpl<T>::operator*() const
{
    return *impl_;
}

}  // namespace internal
}  // namespace celero

#endif  // CELERO_INTERNAL_PIMPL_H_

