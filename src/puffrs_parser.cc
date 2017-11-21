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
#include "Teuchos_ParameterList.hpp"
#include "Teuchos_RCP.hpp"
#include "Teuchos_XMLParameterListHelpers.hpp"
#include "Teuchos_YamlParameterListCoreHelpers.hpp"
#include "Teuchos_YamlParser_decl.hpp"

#include "aprepro.h"

#include "puffrs_parser.h"

// Input file parser
Teuchos::RCP<Teuchos::ParameterList> puffrs::PuffrsParser::Parse(
    const std::string kInputFile) {
    // Set application parameters to default values
    auto puffrs_parameters = Teuchos::rcp(new Teuchos::ParameterList());

    SetPuffrsParameterDefaults(puffrs_parameters.ptr());

    // Create aprepro object
    SEAMS::Aprepro aprepro_parser;

    // get results from aprepro's parsing
    const auto return_value = aprepro_parser.parse_file(kInputFile);

    // Check for error in return value
    TEUCHOS_TEST_FOR_EXCEPTION(!return_value,
                               Teuchos::Exceptions::InvalidParameter,
                               "**** Aprepro input parsing error.\n");

    // Update parameters with data from yaml string
    Teuchos::Ptr<Teuchos::ParameterList> puffrs_parameters_ptr(
        puffrs_parameters.get());

    const auto is_empty = aprepro_parser.parsing_results().str().empty();

    if (!is_empty)
        Teuchos::updateParametersFromYamlString(
            aprepro_parser.parsing_results().str(), puffrs_parameters_ptr,
            true);

    return puffrs_parameters;
}

void puffrs::PuffrsParser::SetPuffrsParameterDefaults(
    Teuchos::Ptr<Teuchos::ParameterList> puffrs_parameters) {
    puffrs_parameters->set("verbose", false);
}
