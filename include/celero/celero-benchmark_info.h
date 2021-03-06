#ifndef H_CELERO_BENCHMARKINFO_H
#define H_CELERO_BENCHMARKINFO_H

#include <string>

#include "celero/internal/celero-export.h"
#include "celero/internal/celero-pimpl.h"

namespace celero
{
	class Factory;

class CELERO_EXPORT IBenchmarkInfo
{
public:
    virtual ~IBenchmarkInfo() {}
	virtual void reset() = 0;
    virtual std::string getGroupName() const = 0;
    virtual std::string getTestName() const = 0;
	virtual void incrementSamples() = 0;
    virtual uint64_t getSamples() const = 0;
    virtual uint64_t getOps() const = 0;
    virtual std::shared_ptr<Factory> getFactory() const = 0;
    virtual std::string get() const = 0;
    virtual std::string getShort() const = 0;
    virtual void setBaselineUnit(const double x) = 0;
    virtual double getBaselineUnit() const = 0;
    virtual double getBaselineMeasurement() const = 0;
    virtual void saveBaselineMeasurement() = 0;
    virtual double getBaselineTarget() const = 0;
    virtual void setRunTime(const uint64_t x) = 0;
    virtual uint64_t getRunTime() const = 0;
    virtual void incrementTotalRunTime(const uint64_t x) = 0;
    virtual uint64_t getTotalRunTime() const = 0;
    virtual double getUsPerOp() const = 0;
    virtual double getOpsPerSecond() const = 0;
    virtual void setProblemSetSize(const size_t x) = 0;
    virtual size_t getProblemSetSize() const = 0;
    virtual size_t getProblemSetSizeIndex() const = 0;
    virtual void incrementProblemSetSizeIndex() = 0;
};  // class IBenchmarkInfo

	///
	/// \class BenchmarkInfo
	///
	/// \author	John Farrier
	///
	class CELERO_EXPORT BenchmarkInfo : public IBenchmarkInfo
	{
		public:
			///
			/// \brief	Default constructor
			///
			BenchmarkInfo();

			///
			/// \brief	Overloaded constructor.
			///
			/// \param groupName Name of the test group.
			/// \param benchmarkName Name of the test.
			/// \param samples Number of samples for the test.
			/// \param calls Number of calls per run.
			/// \param testFactory Test factory implementation for the test.
			/// \param baselineTarget The highest baseline multiple you want for this test (used to pass/fail test.)
			///
			BenchmarkInfo(const std::string& groupName, const std::string& benchmarkName, const uint64_t samples, const uint64_t calls, std::shared_ptr<Factory> testFactory, double baselineTarget = -1);
			
			///
			///
			///
			BenchmarkInfo(const BenchmarkInfo& other);

			///
			/// \brief	Default destructor.
			///
			~BenchmarkInfo();

			///
			///
			///
			void reset();

			///
			///
			///
			std::string getGroupName() const;

			///
			///
			///
			std::string getTestName() const;

			///
			///
			///
			void incrementSamples();

			///
			///
			///
			uint64_t getSamples() const;

			///
			///
			///
			uint64_t getOps() const;

			///
			///
			///
			std::shared_ptr<Factory> getFactory() const;

			///
			///
			///
			std::string get() const;

			///
			///
			///
			std::string getShort() const;

			///
			///
			///
			void setBaselineUnit(const double x);
			
			///
			///
			///
			double getBaselineUnit() const;

			///
			/// \brief	Compute the baseline measurement of an executed benchmark.
			///
			double getBaselineMeasurement() const;

			///
			/// \brief	References can be cleared out during complex runs.  This saves state for reporting purposes.
			///
			void saveBaselineMeasurement();

			///
			///
			///
			double getBaselineTarget() const;

			///
			/// \brief	Sets the test's best run time.
			///
			/// The function will only update the run time if x is smaller than the current value.
			///
			/// \param	x	An individual run's execution time in usec.
			///
			void setRunTime(const uint64_t x);

			///
			///
			///
			uint64_t getRunTime() const;

			///
			///
			///
			void incrementTotalRunTime(const uint64_t x);

			///
			///
			///
			uint64_t getTotalRunTime() const;

			///
			/// \brief	Get the number of computed microseconds per operation.
			///
			///	An operation is defined as one operation of one run.
			///
			double getUsPerOp() const;

			///
			/// \brief	Get the number of computer operations per second.
			///
			///	An operation is defined as one operation of one run.
			///
			double getOpsPerSecond() const;

			///
			///
			///
			void setProblemSetSize(const size_t x);
			
			///
			///
			///
			size_t getProblemSetSize() const;
			
			///
			///
			///
			size_t getProblemSetSizeIndex() const;
			
			///
			///
			///
			void incrementProblemSetSizeIndex();

		private:
			///
			/// \brief	Pimpl Idiom
			///
			class Impl;

			///
			/// \brief	Pimpl Idiom
			///
            internal::pimpl<Impl> pimpl;	
	};
}

#endif
