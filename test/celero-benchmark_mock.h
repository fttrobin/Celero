
#include <gmock/gmock.h>
#include "celero/celero-test_fixture.h"

namespace celero
{
namespace test
{

struct BenchmarkMock : celero::IBenchmark
{
     MOCK_METHOD0(SetUp, void());
     MOCK_METHOD1(SetUp, void(const int32_t));
     MOCK_METHOD0(TearDown, void());
     MOCK_METHOD2(Run, std::pair<uint64_t, int32_t>(const uint64_t, const size_t));
     MOCK_CONST_METHOD0(getProblemSetSize, size_t());
     MOCK_CONST_METHOD1(getProblemSetValue, int32_t(const size_t));
};  // sturct BenchmarkMock

}  // namespace test
}  // namespace celero
