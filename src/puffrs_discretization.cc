// Copyright 2017 John T. Foster
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
#include "Teuchos_RCP.hpp"

#include "puffrs_discretization.h"

/** Creates a Puffrs discretizer.
 *
 * @param kComm                     pointer to list of RCPs(reference counting pointers)
 *                                  for a Teuchos distributted memeory communication
 *                                  interface
 * @param kDiscretizationParameters pointer to list of parameters used for discretization
 */
puffrs::Discretization::Discretization(
    const Teuchos::RCP<const Teuchos::Comm<puffrs::types::PuffrsComm>> &kComm,
    const Teuchos::RCP<Teuchos::ParameterList> &kDiscretizationParameters) {}

void puffrs::Discretization::initialize() {}
