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
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

#include "Teuchos_UnitTestHarness.hpp"
#include "Xpetra_DefaultPlatform.hpp"

#include "Teuchos_YamlParser_decl.hpp"

#include "puffrs_parser.h"
#include "puffrs_types.h"

namespace puffrs_test {

class TestSetup {
   public:
    TestSetup() {
        CreateTempFileName();
        temp_file_ = std::fopen(temp_file_name_.c_str(), "w+");
    }

    ~TestSetup() {
        std::fclose(temp_file_);
        std::remove(temp_file_name_.c_str());
    };

    std::string GetFileName() { return temp_file_name_; }

   private:
    // Creates a temporary filename based on the system time
    void CreateTempFileName() {
        const auto system_time = std::chrono::system_clock::now();
        const auto date_time =
            std::chrono::system_clock::to_time_t(system_time);
        temp_file_name_ = std::ctime(&date_time);
        // Remove colons
        temp_file_name_.erase(
            remove(temp_file_name_.begin(), temp_file_name_.end(), ':'),
            temp_file_name_.end());
        // Remove spaces
        temp_file_name_.erase(
            remove_if(temp_file_name_.begin(), temp_file_name_.end(),
                      [](unsigned char x) { return std::isspace(x); }),
            temp_file_name_.end());
    }

    // Get communicator from test runner
    Teuchos::RCP<const Teuchos::Comm<puffrs::types::PuffrsComm>> kComm_ =
        Xpetra::DefaultPlatform::getDefaultPlatform().getComm();

    // Create temporary file
    std::string temp_file_name_;
    std::FILE* temp_file_;
};

// Tests the default value of "Verbose" is correctly set to false
// if an empty parameter list is given as an input to the parser
TEUCHOS_UNIT_TEST(Parser, Default) {
    const auto kTestFixture = Teuchos::rcp(new TestSetup());

    // Retrieve parsed parameter list from file
    const auto parameters =
        puffrs::PuffrsParser::Parse(kTestFixture->GetFileName());

    // Retrieve value of "Verbose"
    const auto default_verbose_value = parameters->get<bool>("verbose");

    TEST_EQUALITY(default_verbose_value, false)
}

// Tests the value of "Verbose" is true if we first create a parameter list
// and write it to file
TEUCHOS_UNIT_TEST(Parser, File) {
    const auto kTestFixture = Teuchos::rcp(new TestSetup());

    auto parameters = Teuchos::rcp(new Teuchos::ParameterList());

    parameters->set("verbose", true);

    const auto& kParameters = *parameters;

    Teuchos::YAMLParameterList::writeYamlFile(kTestFixture->GetFileName(),
                                              kParameters);

    // Reads the parsed parameters
    parameters = puffrs::PuffrsParser::Parse(kTestFixture->GetFileName());

    // Retrieve
    const auto verbose_value = parameters->get<bool>("verbose");

    TEST_EQUALITY(verbose_value, true)
}

// Tests the aprepro algebra functionality for mutiplication
TEUCHOS_UNIT_TEST(Parser, Double_Multiplication) {
    const auto kTestFixture = Teuchos::rcp(new TestSetup());

    auto parameters = Teuchos::rcp(new Teuchos::ParameterList());

    parameters->set("double multiply", "{2.2 * 2.0}");

    const auto& kParameters = *parameters;

    Teuchos::YAMLParameterList::writeYamlFile(kTestFixture->GetFileName(),
                                              kParameters);

    // Reads the parsed parameters
    parameters = puffrs::PuffrsParser::Parse(kTestFixture->GetFileName());

    // Retrieve
    const auto double_string_value =
        parameters->get<std::string>("double multiply");
    // Convert to double
    const auto double_value = std::stod(double_string_value, nullptr);

    TEST_FLOATING_EQUALITY(double_value, 4.4, 1e-14)
}

// Tests the aprepro algebra functionality for predefined constant
// substitution
TEUCHOS_UNIT_TEST(Parser, Pi_Value) {
    const auto kTestFixture = Teuchos::rcp(new TestSetup());

    auto parameters = Teuchos::rcp(new Teuchos::ParameterList());

    parameters->set("pi", "{PI}");

    const auto& kParameters = *parameters;

    Teuchos::YAMLParameterList::writeYamlFile(kTestFixture->GetFileName(),
                                              kParameters);

    // Reads the parsed parameters
    parameters = puffrs::PuffrsParser::Parse(kTestFixture->GetFileName());

    // Retrieve
    const auto pi_string_value = parameters->get<std::string>("pi");
    // Convert to double
    const auto pi_value = std::stod(pi_string_value, nullptr);

    TEST_FLOATING_EQUALITY(pi_value, 3.1415, 1e-4)
}

// Tests the aprepro algebra functionality for function parsing
TEUCHOS_UNIT_TEST(Parser, Function) {
    const auto kTestFixture = Teuchos::rcp(new TestSetup());

    auto parameters = Teuchos::rcp(new Teuchos::ParameterList());

    parameters->set("function", "{4.0 * atan(1.0)}");

    const auto& kParameters = *parameters;

    Teuchos::YAMLParameterList::writeYamlFile(kTestFixture->GetFileName(),
                                              kParameters);

    // Reads the parsed parameters
    parameters = puffrs::PuffrsParser::Parse(kTestFixture->GetFileName());

    // Retrieve
    const auto function_string_value = parameters->get<std::string>("function");
    // Convert to double
    const auto function_value = std::stod(function_string_value, nullptr);

    TEST_FLOATING_EQUALITY(function_value, 3.1415, 1e-4)
}

// Tests the aprepro algebra functionality for relational operations
TEUCHOS_UNIT_TEST(Parser, Relational) {
    const auto kTestFixture = Teuchos::rcp(new TestSetup());

    auto parameters = Teuchos::rcp(new Teuchos::ParameterList());

    parameters->set("relational", "{8 < 10}");

    const auto& kParameters = *parameters;

    Teuchos::YAMLParameterList::writeYamlFile(kTestFixture->GetFileName(),
                                              kParameters);

    // Reads the parsed parameters
    parameters = puffrs::PuffrsParser::Parse(kTestFixture->GetFileName());

    // Retrieve
    const auto int_string_value = parameters->get<std::string>("relational");
    // Convert to int
    const auto int_value = std::stoi(int_string_value, nullptr);

    TEST_EQUALITY(int_value, 1)
}
}
