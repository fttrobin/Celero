// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: gracjan.olbinski@gmail.com (Gracjan Olbinski)

#include <gmock/gmock.h>
#include "celero/celero-benchmark_info.h"

namespace celero
{
namespace test
{

struct BenchmarkInfoMock : celero::IBenchmarkInfo
{
	MOCK_METHOD0(reset, void());
    MOCK_CONST_METHOD0(getGroupName, std::string());
    MOCK_CONST_METHOD0(getTestName, std::string());
	MOCK_METHOD0(incrementSamples, void());
    MOCK_CONST_METHOD0(getSamples, uint64_t());
    MOCK_CONST_METHOD0(getOps, uint64_t());
    MOCK_CONST_METHOD0(getFactory, std::shared_ptr<Factory>());
    MOCK_CONST_METHOD0(get, std::string());
    MOCK_CONST_METHOD0(getShort, std::string());
    MOCK_METHOD1(setBaselineUnit, void(const double));
    MOCK_CONST_METHOD0(getBaselineUnit, double());
    MOCK_CONST_METHOD0(getBaselineMeasurement, double());
    MOCK_METHOD0(saveBaselineMeasurement, void());
    MOCK_CONST_METHOD0(getBaselineTarget, double());
    MOCK_METHOD1(setRunTime, void(const uint64_t));
    MOCK_CONST_METHOD0(getRunTime, uint64_t());
    MOCK_METHOD1(incrementTotalRunTime, void(const uint64_t));
    MOCK_CONST_METHOD0(getTotalRunTime, uint64_t());
    MOCK_CONST_METHOD0(getUsPerOp, double());
    MOCK_CONST_METHOD0(getOpsPerSecond, double());
    MOCK_METHOD1(setProblemSetSize, void(const size_t));
    MOCK_CONST_METHOD0(getProblemSetSize, size_t());
    MOCK_CONST_METHOD0(getProblemSetSizeIndex, size_t());
    MOCK_METHOD0(incrementProblemSetSizeIndex, void());
};  // struct BenchmarkInfoMock

}  // namespace test
}  // namespace celero
