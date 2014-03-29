#ifndef H_CELERO_TESTVECTOR_H
#define H_CELERO_TESTVECTOR_H

// www.helleboreconsulting.com

#include "celero/internal/celero-export.h"
#include "celero/internal/celero-pimpl.h"
#include <functional>

namespace celero
{
	class BenchmarkInfo;

	///
	/// \class TestVector
	///
	/// \author	John Farrier
	///
	/// \brief	Don't give me crap about a static global...
	///
	class TestVector
	{
		public:
			static TestVector& Instance();

			void pushBackTest(std::shared_ptr<BenchmarkInfo> x);
			size_t getTestSize() const;
			size_t getTestSize(const std::string& groupName) const;
			void forEachTest(std::function<void(std::shared_ptr<BenchmarkInfo>)> f);

			void pushBackBaseline(std::shared_ptr<BenchmarkInfo> x);
			size_t getBaselineSize() const;
			size_t getBaselineSize(const std::string& groupName) const;
			void forEachBaseline(std::function<void(std::shared_ptr<BenchmarkInfo>)> f);
			std::shared_ptr<BenchmarkInfo> getBaseline(const std::string& groupName);

		private:
			///
			/// Default Constructor
			///
			TestVector();

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
