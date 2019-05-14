// Copyright 2015 John T. Foster

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//    http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "puffrs_factory.h"
#include "puffrs_parser.h"

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
Teuchos::RCP<puffrs::Puffrs> puffrs::PuffrsFactory::Create(
    const std::string kInputFile,
    const Teuchos::RCP<const Teuchos::Comm<puffrs::types::PuffrsComm> >& kComm,
    Teuchos::RCP<puffrs::Discretization> puffrs_discretization) {
    const auto kPuffrsParameters = puffrs::PuffrsParser::Parse(kInputFile);

    // Create new puffrs object
    return Teuchos::rcp(
        new puffrs::Puffrs(kComm, kPuffrsParameters, puffrs_discretization));
}


/** Factory Method to create puffrs objects. This function is overloaded and
 * will take a set of two arguments here.
 *
 * @param kInputFile            the input file
 * @param puffrs_discretization Discretization
 * @return kInputFile
 * @return kComm
 * @return null_discretization null discretization from Teuchos
 */
Teuchos::RCP<puffrs::Puffrs> puffrs::PuffrsFactory::Create(
    const std::string kInputFile,
    const Teuchos::RCP<const Teuchos::Comm<puffrs::types::PuffrsComm> >&
        kComm) {
    Teuchos::RCP<puffrs::Discretization> null_discretization;
    return Create(kInputFile, kComm, null_discretization);
}
