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
    EXPECT_CALL(*benchmarkInfoMock, getFactory())
        .WillRepeatedly(::testing::Return(factoryMock));
    EXPECT_CALL(*factoryMock, Create())
        .WillRepeatedly(::testing::Return(benchmarkMock));
    EXPECT_CALL(*benchmarkInfoMock, getProblemSetSizeIndex())
        .WillOnce(::testing::Return(1));
    EXPECT_CALL(*benchmarkInfoMock, getSamples())
        .WillRepeatedly(::testing::Return(1));
    EXPECT_CALL(*benchmarkInfoMock, getOps())
        .WillOnce(::testing::Return(1));
    EXPECT_CALL(*benchmarkMock, Run(1, 1))
        .WillOnce(::testing::Return(std::make_pair(1, 1)));
    EXPECT_CALL(*benchmarkInfoMock, setRunTime(1));
    EXPECT_CALL(*benchmarkInfoMock, incrementTotalRunTime(1));
    EXPECT_CALL(*benchmarkInfoMock, getGroupName())
        .WillRepeatedly(::testing::Return("test"));
    EXPECT_CALL(*benchmarkInfoMock, getTestName())
        .WillOnce(::testing::Return("test"));
    EXPECT_CALL(*benchmarkMock, getProblemSetValue(1))
        .WillOnce(::testing::Return(1));
    EXPECT_CALL(*benchmarkInfoMock, getUsPerOp())
        .WillOnce(::testing::Return(1.0));
    EXPECT_CALL(*benchmarkInfoMock, saveBaselineMeasurement());
    
    celero::executor::Execute(benchmarkInfoMock);
}

}  // namespace test
}  // namespace celero
