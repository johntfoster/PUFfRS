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
#ifndef PUFFRS_DISCRETIZATION_FACTORY_H_
#define PUFFRS_DISCRETIZATION_FACTORY_H_

#include <Teuchos_Comm.hpp>
#include <Teuchos_ParameterList.hpp>
#include <Teuchos_RCP.hpp>

#include "puffrs_discretization.h"
#include "puffrs_types.h"

/**
 * puffrs namespace description. Detailed description.
 */
namespace puffrs {

/**
 * DiscretizationFactory class description. Detailed description.
 */
class DiscretizationFactory {

   public:

    /** Creates a Puffrs discritization factory.
     *
     * @param kComm                     pointer to list of RCPs(reference counting pointers)
     *                                  for a Teuchos distributted memeory communication
     *                                  interface
     * @param kDiscretizationParameters pointer to list of parameters used for discritization
     */
    DiscretizationFactory(
        const Teuchos::RCP<Teuchos::ParameterList>& kDiscretizationParameters);

    /**
     * ~DiscretizationFactory virtual member description.
     */
    virtual ~DiscretizationFactory() {}

    /** Creates a discretization based on type using Teuchos.
     *
     * @param kComm                     pointer to list of RCPs(reference counting pointers)
     *                                  for a Teuchos distributted memeory communication
     *                                  interface
     * @return discritization           discretized input from Teuchos
     */
    virtual Teuchos::RCP<Discretization> Create(
        const Teuchos::RCP<const Teuchos::Comm<types::PuffrsComm> >& kComm);

   private:
    //! Private to prohibit copying
    DiscretizationFactory(const DiscretizationFactory&);

    //! Private to prohibit copying
    DiscretizationFactory& operator=(const DiscretizationFactory&);

   protected:
    //! Parameter list
    const Teuchos::RCP<Teuchos::ParameterList> kDiscretizationParameters_;
};
}

#endif  // PUFFRS_DISCRETIZATIONFACTORY_H
