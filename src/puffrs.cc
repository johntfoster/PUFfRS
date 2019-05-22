// Copyright 2017 John T. Foster

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not us
// this file except in compliance with the License.
// You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "puffrs.h"
#include "puffrs_discretization_factory.h"


/** Creates a Puffrs object and ensures that it has the necessary parameters
 * and descritizer.
 *
 * @param kComm                 pointer to list of RCPs(reference counting pointers)
 *                              for a Teuchos distributted memeory communication
 *                              interface
 * @param parameters            list of parameters of arbitrary type
 *                              needed by Puffrs to run simulations
 * @param puffrs_discretization list of RCP for a Teuchos distribution of a
 *                              discretization algorithm for Puffrs
 */
puffrs::Puffrs::Puffrs(
    const Teuchos::RCP<const Teuchos::Comm<int> >& kComm,
    Teuchos::RCP<Teuchos::ParameterList> parameters,
    Teuchos::RCP<puffrs::Discretization> puffrs_discretization) {
    const auto kDiscretizationParameters =
        Teuchos::rcpFromRef(parameters->sublist("discretization", true));

    if (puffrs_discretization.is_null()) {
        puffrs::DiscretizationFactory discretiztaion_factory(
            kDiscretizationParameters);
        auto puffrs_discretization = discretiztaion_factory.Create(kComm);
    }
}
