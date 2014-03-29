#ifndef H_CELERO_TESTFIXTURE_H
#define H_CELERO_TESTFIXTURE_H

// www.helleboreconsulting.com

#include <cstddef>
#include <stdint.h>

#include "celero/internal/celero-timer.h"
#include "celero/internal/celero-export.h"

#include <vector>

namespace celero
{
	///
	/// \class TestFixture
	///
	/// \author John Farrier
	///
	class CELERO_EXPORT TestFixture
	{
		public:
			///
			/// Default Constructor.
			///
			TestFixture();

			///
			/// Virtual destructor for inheritance.
			///
			virtual ~TestFixture();

			///
			/// Set up the test fixture before benchmark execution.
			///
			virtual void SetUp();
		
			///
			/// Set up the test fixture before benchmark execution.
			///
			virtual void SetUp(const int32_t problemSetValue);
		
			///
			/// Called after test completion to destroy the fixture.
			///
			virtual void TearDown();
		
			///
			/// \param calls The number of times to loop over the UserBenchmark function.
			///
			/// \return Returns the number of microseconds the run took.
			///
			std::pair<uint64_t, int32_t> Run(const uint64_t calls, const size_t problemSetValueIndex);

			///
			///
			///
			size_t getProblemSetSize() const;

			///
			///
			///
			int32_t getProblemSetValue(const size_t x) const;

		protected:
			///
			/// Implemented by the classes that are built via macros.
			///
			virtual void setProblemSetSize(const size_t) {};

			/// Executed for each operation the benchmarking test is run.
			virtual void UserBenchmark();

			std::vector<int32_t> ProblemSetValues;

		private:
	};
}

#endif
