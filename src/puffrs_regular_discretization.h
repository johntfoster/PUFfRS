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
#ifndef PUFFRS_REGULAR_DISCRETIZATION_H_
#define PUFFRS_REGULAR_DISCRETIZATION_H_

#include <Teuchos_Comm.hpp>
#include <Teuchos_ParameterList.hpp>

#include "puffrs_discretization.h"

/**
 * puffrs namespace description. Detailed description.
 */
namespace puffrs {

/**
 * Discretiation class for regular discretization.
 */
class RegularDiscretization : public puffrs::Discretization {

   public:

    /** Input file parser
     *
     * @param kInputFile input file
     * @return puffrs_parameters parsed input file
     */
    RegularDiscretization(
        const Teuchos::RCP<const Teuchos::Comm<int> >& kComm,
        const Teuchos::RCP<Teuchos::ParameterList>& kDiscretizationParameters);

    ~RegularDiscretization() {}

   private:
    // Private to prohibit copying
    RegularDiscretization(const RegularDiscretization&);

    // Private to prohibit copying
    RegularDiscretization& operator=(const Discretization&);

   protected:
    //  Communicator
    const Teuchos::RCP<const Teuchos::Comm<int> >& kComm_;
};
};

#endif
