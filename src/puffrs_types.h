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

/**
 * puffrs namespace description. Detailed description.
 */
namespace puffrs {

/**
 * types namespace description. Detailed description.
 */
namespace types {

// Standard Puffrs types

/**
 * Defines a Puffrs integer.
 */
typedef int PuffrsInt;
/**
 * Defines a Puffrs unsigned integer.
 */
typedef std::size_t PuffrsUnsignedInt;
/**
 * Defines a Puffrs real double.
 */
typedef double PuffrsReal;
/**
 * Defines a Puffrs communicator.
 */
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

/**
 * Defines a Puffrs vector of integers.
 */
typedef PuffrsVector<PuffrsInt> PuffrsIntVector;
/**
 * Defines a Puffrs vector of real doubles.
 */
typedef PuffrsVector<PuffrsReal> PuffrsRealVector;
}
}
#endif
