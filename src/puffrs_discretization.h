// Copyright 2017 John T. Foster
//

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef PUFFRS_DISCRETIZATION_H_
#define PUFFRS_DISCRETIZATION_H_
#include <vector>

#include <Teuchos_Comm.hpp>
#include <Teuchos_ParameterList.hpp>

#include "puffrs_types.h"

namespace puffrs {

class Discretization {
   public:
    Discretization(
        const Teuchos::RCP<const Teuchos::Comm<types::PuffrsComm>> &kComm,
        const Teuchos::RCP<Teuchos::ParameterList> &kDiscretizationParameters);

    virtual ~Discretization(){};

   private:
    //! Private to prohibit copying.
    Discretization(const Discretization &);

    Discretization &operator=(const Discretization &);

   protected:
    void initialize();
};
}

#endif
