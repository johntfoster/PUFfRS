# Copyright 2017 John T. Foster

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#    http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Get the latest abbreviated commit hash of the working branch
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE Puffrs_GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
mark_as_advanced(Puffrs_GIT_COMMIT_HASH)

# Pass version info to source code
configure_file(
  ${PROJECT_SOURCE_DIR}/src/puffrs_version.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/src/puffrs_version.h
)

set(PUFFRS_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/puffrs.cc
    ${CMAKE_CURRENT_LIST_DIR}/puffrs_parser.cc
    ${CMAKE_CURRENT_LIST_DIR}/puffrs_factory.cc
    ${CMAKE_CURRENT_LIST_DIR}/puffrs_discretization_factory.cc
    ${CMAKE_CURRENT_LIST_DIR}/puffrs_discretization.cc
    ${CMAKE_CURRENT_LIST_DIR}/puffrs_regular_discretization.cc
)
mark_as_advanced(PUFFRS_SOURCES)


add_library(puffrs_library ${PUFFRS_SOURCES})
target_link_libraries(puffrs_library PRIVATE trilinos)
if(MPI_FOUND)
    target_link_libraries(puffrs_library PRIVATE mpi)
endif()
set_property(TARGET puffrs_library PROPERTY OUTPUT_NAME puffrs)
set_property(TARGET puffrs_library PROPERTY CXX_STANDARD 14)
target_include_directories(puffrs_library PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(puffrs_library PUBLIC cxx_auto_type cxx_return_type_deduction)

#
# Link the main PUFfRS executable
#
add_executable(puffrs puffrs_main.cc)
target_include_directories(puffrs PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src)
target_link_libraries(puffrs puffrs_library)
set_property(TARGET puffrs PROPERTY CXX_STANDARD 14)

#
# Install target for PUFfRS main executable
#
install(TARGETS puffrs RUNTIME DESTINATION bin)

add_subdirectory(test)
