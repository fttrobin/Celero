#include "celero/internal/celero-junit.h"
#include "celero/celero-utilities.h"
#include "celero/celero-benchmark_info.h"
#include "celero/internal/celero-timer.h"

#include <assert.h>

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <tuple>

using namespace celero;

///
/// \class Impl
///
class celero::JUnit::Impl
{
	public:
		Impl() : 
			totalTime(0)
		{
		}

		// Store the test case size, measured baseline, objective baseline, and total run time in seconds.
		typedef std::map<std::string, std::vector<std::shared_ptr<IBenchmarkInfo>>> ResultMap;

		std::ofstream os;
		ResultMap results;
		double totalTime;
};

JUnit::JUnit() : pimpl()
{
}

JUnit::~JUnit()
{
	this->pimpl->os.close();
}

JUnit& JUnit::Instance()
{
	static JUnit singleton;
	return singleton;
}

void JUnit::setFileName(const std::string& x)
{
	assert(x.empty() == false);

	this->pimpl->os.open(x);

	if(this->pimpl->os.is_open() == false)
	{
		std::cerr << "Celero: Could not open JUnit output file: \"" << x << "\"\n";
	}
}

void JUnit::add(std::shared_ptr<celero::IBenchmarkInfo> x)
{
	x->saveBaselineMeasurement();
	this->pimpl->results[x->getGroupName()].push_back(x);
}

void JUnit::save()
{
	if(this->pimpl->os.is_open() == true)
	{
		auto os = &(this->pimpl->os);

		*os << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";

		for(auto i : this->pimpl->results)
		{
			uint64_t testSuiteTime = 0;
			size_t testSuiteFailures = 0;

			auto runs = i.second;

			for(auto j : runs)
			{
				if(j->getBaselineMeasurement() > 1)
				{
					testSuiteFailures++;
				}

				testSuiteTime += j->getRunTime();
			}

			*os << "<testsuite errors=\"0\" ";
			*os << "tests=\"" << i.second.size() << "\" ";
			*os << "time=\"" << celero::timer::ConvertSystemTime(testSuiteTime) << "\" ";
			*os << "failures=\"" << testSuiteFailures << "\" ";
			*os << "name=\"" << i.first << "\">\n";
			
			for(auto j : runs)
			{
				*os << "\t<testcase ";
				*os << "time=\"" << celero::timer::ConvertSystemTime(j->getRunTime()) << "\" ";
				*os << "name=\"" << j->getTestName() << "#" << j->getProblemSetSize() << "\"";
								
				// Compare measured to objective
				if(j->getBaselineMeasurement() > j->getBaselineTarget())
				{
					// Failure
					*os << ">\n";

					*os << "\t\t<failure ";
					*os << "type=\"Performance objective not met.\" ";
					*os << "message=\"Measurement of " << j->getBaselineMeasurement() << " exceeds objective baseline of " << j->getBaselineTarget() << "\" ";
					*os << "/>\n";

					*os << "\t</testcase>\n";
				}
				else
				{
					// Success
					*os << "/>\n";
				}
			}
				
			*os << "</testsuite>\n";
		}
	}

	this->pimpl->os.close();
}
