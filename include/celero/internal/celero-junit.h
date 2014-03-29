#ifndef H_CELERO_JUNIT_H
#define H_CELERO_JUNIT_H

// www.helleboreconsulting.com

#include "celero/internal/celero-pimpl.h"
#include <string>

namespace celero
{
	class IBenchmarkInfo;

	///
	/// \class JUnit
	///
	/// \author	John Farrier
	///
	class JUnit
	{
		public:
			///
			/// Singleton 
			///
			static JUnit& Instance();

			///
			/// Specify a file name for a results output file.
			///
			/// \param x	The name of the output file in which to store Celero's results.
			///
			void setFileName(const std::string& x);

			///
			///
			///
			void add(std::shared_ptr<celero::IBenchmarkInfo> x);

			///
			///
			///
			void save();

		private:
			///
			/// Default Constructor
			///
			JUnit();

			///
			/// Default Destructor
			///
			~JUnit();

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
