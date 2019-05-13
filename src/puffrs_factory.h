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
#ifndef PUFFRS_FACTORY_H_
#define PUFFRS_FACTORY_H_

#include <Teuchos_ParameterList.hpp>
#include <Teuchos_RCP.hpp>

#include "puffrs.h"
#include "puffrs_discretization.h"
#include "puffrs_types.h"

/**
 * puffrs namespace description. Detailed description.
 */
namespace puffrs {

/**
 * PuffrsFactory class description. Detailed description.
 */
class PuffrsFactory {

   public:

    PuffrsFactory() {}

    /**
     * ~PuffrsFactory virtual member description.
     */
    virtual ~PuffrsFactory(){};

    /** Factory Method to create puffrs objects. This function is overloaded and
     * will take a set of three arguments here.
     *
     * @param kInputFile             the input file
     * @param kComm                  pointer to the Xpetra communicator
     * @param puffrs_discretization  Discretization
     * @return kComm                 puffrs kComm
     * @return kPuffrsParameters     parameters from input file as puffrs object
     * @return puffrs_discretization puffrs discretization
     */
    virtual Teuchos::RCP<puffrs::Puffrs> Create(
        const std::string kInputFile,
        const Teuchos::RCP<const Teuchos::Comm<types::PuffrsComm> >& kComm,
        Teuchos::RCP<puffrs::Discretization> puffrs_discretization);

    /** Factory Method to create puffrs objects. This function is overloaded and
     * will take a set of two arguments here.
     *
     * @param kInputFile            the input file
     * @param puffrs_discretization Discretization
     * @return kInputFile
     * @return kComm
     * @return null_discretization null discretization from Teuchos
     */
    virtual Teuchos::RCP<puffrs::Puffrs> Create(
        const std::string kInputFile,
        const Teuchos::RCP<const Teuchos::Comm<types::PuffrsComm> >& kComm);

   private:
    // Private copy constructor to prohibit copying.
    PuffrsFactory(const PuffrsFactory&);

    // Private assignment operator to prohibit copying.
    PuffrsFactory& operator=(const PuffrsFactory&);
};
}
#endif  // PUFFRS_FACTORY_H
