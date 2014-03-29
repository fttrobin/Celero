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

#include <memory>
#include <gtest/gtest.h>
#include "celero/internal/celero-executor.h"

#include "celero-factory_mock.h"
#include "celero-benchmark_mock.h"
#include "celero-benchmark_info_mock.h"

namespace celero
{
namespace test
{

struct CeleroExecutorShould : public ::testing::Test
{
    CeleroExecutorShould()
    : benchmarkInfoMock(new celero::test::BenchmarkInfoMock())
    , benchmarkMock(new celero::test::BenchmarkMock())
    , factoryMock(new celero::test::FactoryMock())
    {
    }

protected:
    std::shared_ptr<celero::test::BenchmarkInfoMock> benchmarkInfoMock;
    std::shared_ptr<celero::test::BenchmarkMock>     benchmarkMock;
    std::shared_ptr<celero::test::FactoryMock>       factoryMock;
};  // test fixture CeleroExecutorShould

TEST_F(CeleroExecutorShould, succeed)
{
//    EXPECT_CALL(*benchmarkInfoMock, getFactory())
//        .WillOnce(::testing::Return(factoryMock));
}

}  // namespace test
}  // namespace celero
