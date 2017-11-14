// Copyright 2017 John T. Foster

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef PUFFRS_TYPES_H_
#define PUFFRS_TYPES_H_
#include <array>
#include <vector>

namespace puffrs {
namespace types {

// Standard puffrs types
typedef int PuffrsInt;
typedef std::size_t PuffrsUnsignedInt;
typedef double PuffrsReal;
typedef PuffrsInt PuffrsComm;

// Templated types from standard library;
template <typename T>
using PuffrsVector = std::vector<T>;

template <typename T, PuffrsUnsignedInt S>
using PuffrsArray = std::array<T, S>;

template <PuffrsUnsignedInt S>
using PuffrsIntArray = PuffrsArray<PuffrsInt, S>;

template <PuffrsUnsignedInt S>
using PuffrsRealArray = PuffrsArray<PuffrsReal, S>;

typedef PuffrsVector<PuffrsInt> PuffrsIntVector;
typedef PuffrsVector<PuffrsReal> PuffrsRealVector;
}
}
#endif
