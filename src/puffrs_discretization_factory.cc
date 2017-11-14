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
#include <Teuchos_Assert.hpp>

#include "puffrs_discretization_factory.h"
#include "puffrs_regular_discretization.h"

puffrs::DiscretizationFactory::DiscretizationFactory(
    const Teuchos::RCP<Teuchos::ParameterList>& kDiscretizationParameters)
    : kDiscretizationParameters_(kDiscretizationParameters) {
    // check to see if a geometry type has been given
    if (!kDiscretizationParameters_->isParameter("type")) {
        TEUCHOS_TEST_FOR_EXCEPTION(
            true, Teuchos::Exceptions::InvalidParameter,
            "Discretization type not specified, \"regular\" is "
            "the only currently available option.");
    }
}

Teuchos::RCP<puffrs::Discretization> puffrs::DiscretizationFactory::Create(
    const Teuchos::RCP<const Teuchos::Comm<puffrs::types::PuffrsComm> >&
        kComm) {
    Teuchos::RCP<puffrs::Discretization> discretization;

    auto type = kDiscretizationParameters_->get<std::string>("type");

    if (type == "regular") {
        discretization = Teuchos::rcp(new puffrs::RegularDiscretization(
            kComm, kDiscretizationParameters_));
    } else {
        TEUCHOS_TEST_FOR_EXCEPTION(
            true, Teuchos::Exceptions::InvalidParameter,
            "**** Invalid discretization type.  Valid types are "
            "\"regular\".\n");
    }

    return discretization;
}
