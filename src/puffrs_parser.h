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
#ifndef PUFFRS_PARSER_H_
#define PUFFRS_PARSER_H_

#include <Teuchos_ParameterList.hpp>
#include <Teuchos_RCP.hpp>

namespace puffrs {

class PuffrsParser {
   public:
    PuffrsParser() {}

    static Teuchos::RCP<Teuchos::ParameterList> Parse(
        const std::string kInputFile);

   private:
    // Private function to set default problem parameter values
    static void SetPuffrsParameterDefaults(
        Teuchos::Ptr<Teuchos::ParameterList> puffrs_parameters);

    // Private copy constructor to prohibit copying.
    PuffrsParser(const PuffrsParser&);

    // Private assignment operator to prohibit copying.
    PuffrsParser& operator=(const PuffrsParser&);
};
}
#endif  // PUFFRS_PARSER_H_
